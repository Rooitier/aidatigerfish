#include "Tree_Structs.h"

#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>

#include <ROOT/TThreadedObject.hxx>
#include <ROOT/TTreeProcessorMT.hxx>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <memory>
#include <thread>

#include <FrsHitData.h>
#include "tqdm.h"

#define DEBUG_FILE 0

inline bool HitTest(AidaHit const& implant, AidaHit const& decay)
{
  int B = 1;
  if ((implant.DSSD != decay.DSSD)) return false;

  if ((implant.StripYMax >= decay.StripYMin - B) && (implant.StripYMin <= decay.StripYMax + B))
  {
    if ((implant.StripXMax >= decay.StripXMin - B) && (implant.StripXMin <= decay.StripXMax + B))
    {
      return true;
    }
  }
  return false;
}

void NewImplantDecay() {
  TChain AnalysisTree("evt");
  AnalysisTree.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_0043_00*");

  ROOT::TTreeProcessorMT multiTR(AnalysisTree);

  std::cout << "Initialising tree" << std::endl;

  //std::vector<ImplantEntry> implants;
  ROOT::TThreadedObject<std::vector<ImplantEntry>> multiImplants;
  ROOT::TThreadedObject<std::vector<Long64_t>> multiPulsers;
  ROOT::TThreadedObject<std::vector<Long64_t>> multiSciHits;

  Long64_t entries = 0;
  {
    TTreeReader tmp_tr(&AnalysisTree);
    entries = tmp_tr.GetEntries(true);
  }
  std::atomic<long long int> processed(0);

  // statistics
  std::atomic<int> implAll(0);
  std::atomic<int> rejStop(0);
  std::atomic<int> rejFrs(0);
  std::atomic<int> rejPid(0);
  std::atomic<int> rejPlas(0);
  // test statistics
  std::atomic<int> frsAll(0);
  std::atomic<int> scalerAll(0);

  // Better way?
  auto gTA = ROOT::Internal::GetGlobalTaskArena(0);
  auto threads = gTA->TaskArenaSize();
  std::cout << "Number of threads is: "<< threads << std::endl;

  tqdm bar;
  auto readerThread = [&](TTreeReader& tr)
  {
    static std::thread::id reporter = std::this_thread::get_id();
    auto tid = std::this_thread::get_id();

    auto implants = multiImplants.Get();
    auto pulsers = multiPulsers.Get();
    auto sciHits = multiSciHits.Get();

    TTreeReaderArray<AidaHit> tr_Aida(tr, "AidaImplantHits");
    TTreeReaderArray<AidaUnpackScalerItem> tr_AidaScaler(tr, "AidaScalerData");
    TTreeReaderArray<FrsHitItem> tr_Frs(tr, "FrsHitData");
    //TTreeReaderValue<Long64_t> tr_PlasWR(tr, "AnlEvent.pbPLAS_WR");
    //TTreeReaderArray<double> tr_PlasE(tr, "AnlEvent.pbPlas_ToTCalib[4][16][20]");

    while (tr.Next())
    {
      processed++;

      for (auto const& a : tr_AidaScaler)
      {
          if (a.Fee() == 1) pulsers->push_back(a.Time());
          if (a.Fee() == 7) { scalerAll++; sciHits->push_back(a.Time()); }
      }

      FrsData frs;
      if (tr_Frs.GetSize() > 0)
      {
        frs.WR = tr_Frs[0].Get_wr_t();
        frs.AoQ = tr_Frs[0].Get_ID_AoQ_corr();
        frs.Z = tr_Frs[0].Get_ID_z();
        frs.Z2 = tr_Frs[0].Get_ID_z2();
        frs.Sci41_E = tr_Frs[0].Get_sci_e(2);
        frs.Sci42_E = tr_Frs[0].Get_sci_e(4);
        frs.dE_S2 = tr_Frs[0].Get_ID_dEdeg();
        frs.beta = tr_Frs[0].Get_ID_beta();
        frs.x2 = tr_Frs[0].Get_ID_x2();
        frs.a2 = tr_Frs[0].Get_ID_a2();
        frs.x4 = tr_Frs[0].Get_ID_x4();
        frs.a4 = tr_Frs[0].Get_ID_a4();
        //frs.dE_S4 = frs.Z * frs.Z * (12720- 18597*frs.beta + 8089.2*frs.beta*frs.beta);
        frsAll++;
      }
      else
      {
        for (auto const& i : tr_Aida)
        {
          implAll++;
          rejFrs++;
        }
        continue;
      }

      for (auto const& i : tr_Aida)
      {
        implAll++;
        if (i.Stopped) { rejStop++; continue; }
        ImplantEntry e;
        e.Aida = i;
        e.Frs = frs;

        implants->push_back(e);
      }
    }
  };

  std::cout << "Building implant buffer" << std::endl;
  auto reporter = std::thread([&] () {
      while (processed < entries)
      {
        bar.progress(processed, entries);
        std::this_thread::sleep_for(std::chrono::milliseconds(0));
      }
      bar.progress(entries, entries);
  });
  multiTR.Process(readerThread);
  reporter.join();
  bar.finish();

  //std::cout << "Building implant buffer... " << processed << "/" << entries;
  //std::cout << std::endl;

  auto implants = multiImplants.Merge([] (std::shared_ptr<std::vector<ImplantEntry>> out, std::vector<std::shared_ptr<std::vector<ImplantEntry>>>& in) {
    std::cout << "Merging implant arrays" << std::endl;
    for (auto& i : in)
    {
      if (i && i != out) {
        out->insert(out->end(), i->begin(), i->end());
      }
    }
  });

  auto pulsers = multiPulsers.Merge([] (std::shared_ptr<std::vector<Long64_t>> out, std::vector<std::shared_ptr<std::vector<Long64_t>>>& in) {
    std::cout << "Merging pulser arrays" << std::endl;
    for (auto& i : in)
    {
      if (i && i != out) {
	      out->insert(out->end(), i->begin(), i->end());
      }
    }
  });

  auto sciHits = multiSciHits.Merge([] (std::shared_ptr<std::vector<Long64_t>> out, std::vector<std::shared_ptr<std::vector<Long64_t>>>& in) {
    std::cout << "Merging SCI41 arrays" << std::endl;
    for (auto& i : in)
    {
      if (i && i != out) {
	      out->insert(out->end(), i->begin(), i->end());
      }
    }
  });

  std::cout << "Sorting array by implant time" << std::endl;
  std::sort(implants->begin(), implants->end(), [] (ImplantEntry a, ImplantEntry b)
      {
	      return a.Aida.Time < b.Aida.Time;
      }
  );

  std::cout << "Sorting pulser array" << std::endl;
  std::sort(pulsers->begin(), pulsers->end());

  std::cout << "Sorting SCI41 array" << std::endl;
  std::sort(sciHits->begin(), sciHits->end());

  std::cout << "-----------------------------" << std::endl;
  std::cout << "Implant statistics: " << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "All Implants        | " << implAll << std::endl;
  std::cout << "Rejected by FRS     | " << rejFrs << std::endl;
  std::cout << "Rejected by Stopped | " << rejStop << std::endl;
  std::cout << "Good Implants       | " << implants->size() << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Pulser events       | " << pulsers->size() << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "FRS events          | " << frsAll << std::endl;
  std::cout << "AIDA Scaler FRS     | " << scalerAll << std::endl;
  std::cout << "-----------------------------" << std::endl;

  std::cout << std::endl << "Creating output file..." << std::endl;
  processed.store(0);
  TFile* out_file = new TFile("test.root", "RECREATE");
  out_file->cd();
  TTree* out_tree = new TTree("ImplantDecays", "ImplantDecays");
  DecayEntry entry;
  out_tree->Branch("Decay", &entry);
  std::mutex tree_mutex;

  std::cout << "Processing decays...";
  // Decay statistics
  std::atomic<int> decayAll(0);
  std::atomic<int> rejPulser(0);
  std::atomic<int> rejCluster(0);
  std::atomic<int> rejFBT(0);
  std::atomic<int> rejFBE(0);
  std::atomic<int> rejE(0);
  std::atomic<int> accNoI(0);
  std::atomic<int> accI(0);

  auto decayThread = [&](TTreeReader& tr)
  {
    static std::thread::id reporter = std::this_thread::get_id();
    auto tid = std::this_thread::get_id();

    TTreeReaderArray<AidaHit> tr_Aida(tr, "AidaDecayHits");
    TTreeReaderValue<bool> tr_OnSpill(tr, "EventHeader.fSpillFlag");
    std::vector<DecayEntry> buffer;
    buffer.reserve(1000);

    while (tr.Next())
    {
      processed++;


      for (auto const& a : tr_Aida)
      {
          decayAll++;
          // Cluster veto
          if (a.ClusterSizeX > 1 || a.ClusterSizeY > 1) continue;
          // Front-Back veto
          if (abs(a.TimeX - a.TimeY) >= 50) { rejFBT++; continue; }
          if (abs(a.EnergyY - a.EnergyX) >= 500) { rejFBE++; continue; }
          // Alpha veto
          //if (a.Energy < 2000) { rejE++; continue; }
          // Bad strip veto
          //
          // Sci41 veto
          // use lower_bound to find the first item in sciHits that occurs after the DecayTime (WR)
          auto sc41_last = std::lower_bound(sciHits->begin(), sciHits->end(), a.Time);

          // now can use d
          DecayEntry d;
          d.OnSpill = *tr_OnSpill;
          d.Aida = a;
          if (sc41_last != sciHits->begin())
          {
            // backtrack by 1 to find the last sciHit before DecayTime WR
            sc41_last--;
            auto lastFrsTime = d.Aida.Time - *sc41_last;
            d.LastFrsTime = lastFrsTime;
          }
          else {
            d.LastFrsTime = -1;
          }

          for (auto impl : *implants)
          {
            if (HitTest(impl.Aida, d.Aida))
            {
              impl.DecayTime = static_cast<double>(d.Aida.Time - impl.Aida.Time) / 1e6;
              impl.DecayTimeFine = 10e6;
              if (abs(impl.DecayTime) > 10e3) continue;
              if (impl.DecayTime < 1 && impl.DecayTime > -1) {
                impl.DecayTimeFine = static_cast<double>(d.Aida.Time - impl.Aida.Time);
              }
              d.Implants.push_back(impl);
            }
          }

          if (d.Implants.size() > 0) {
            accI++;
          }
          else {
            accNoI++;
          }

          buffer.push_back(d);
      }

      if (buffer.size() > 1000)
      {
        std::lock_guard<std::mutex> guard(tree_mutex);
        for (auto& e : buffer)
        {
          entry = e;
          out_tree->Fill();
        }
	      // write the buffer to tree
        buffer.clear();
      }
    }

    std::lock_guard<std::mutex> guard(tree_mutex);
    for (auto& e : buffer)
    {
      entry = e;
      out_tree->Fill();
    }
    // write the buffer to tree
    buffer.clear();
  };

  bar.reset();
  reporter = std::thread([&] () {
      while (processed < entries)
      {
        bar.progress(processed, entries);
        std::this_thread::sleep_for(std::chrono::milliseconds(0));
      }
      bar.progress(entries, entries);
  });
  multiTR.Process(decayThread);
  bar.finish();

  std::cout << "\rProcessing decays... " << processed << "/" << entries;
  std::cout << std::endl;

  std::cout << "-------------------------------------" << std::endl;
  std::cout << "Decay statistics: " << std::endl;
  std::cout << "-------------------------------------" << std::endl;
  std::cout << "All Decays                    | " << decayAll << std::endl;
  std::cout << "Rejected by Cluster Size      | " << rejCluster << std::endl;
  std::cout << "Rejected by Front-Back Time   | " << rejFBT << std::endl;
  std::cout << "Rejected by Front-Back Energy | " << rejFBE << std::endl;
  std::cout << "Rejected by Energy            | " << rejE << std::endl;
  std::cout << "Rejected by Pulser            | " << rejPulser << std::endl;
  std::cout << "Good Decays                   | " << accI + accNoI << std::endl;
  std::cout << ".. With 1+ implants           | " << accI << std::endl;
  std::cout << ".. With no implants           | " << accNoI << std::endl;
  std::cout << "------------------------------------" << std::endl;

  std::cout << "Closing tree file" << std::endl;
  out_tree->Write();
  delete out_tree;
  delete out_file;
}
