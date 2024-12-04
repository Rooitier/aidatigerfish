#define aida_ana_cxx
// The class definition in aida_ana.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("aida_ana.C")
// root> T->Process("aida_ana.C","some options")
// root> T->Process("aida_ana.C+")
//


#include "aida_ana.h"
#include <TH2.h>
#include <TStyle.h>


// Implants
TH2F* aida_implants_strip_xy;
TH2F* aida_implants_strip_xy_pre;
TH2F* aida2_implants_strip_xy;

TH1F* sc41_hits;

//Decays

TH2F* aida_decays_strip_xy;
TH2F* aida2_decays_strip_xy;

TH2F* aida_decays_strip_xy_onspill;
TH2F* aida2_decays_strip_xy_onspill;

TH2F* aida_decays_strip_xy_offspill;
TH2F* aida2_decays_strip_xy_offspill;

TH2F* aida_decays_xy;

TH1F* implant_rate;
TH1F* decay_rate_onspill;
TH1F* decay_rate_offspill;

TH1F* aida_x_decays;
TH1F* aida_y_decays;

TH1F* aida2_x_decays;
TH1F* aida2_y_decays;

TH1F* aida_decays_time_xy;
TH1F* aida2_decays_time_xy;

TH2F* aida_decay_energy_xy;
TH2F* aida2_decay_energy_xy;

TH1F* aida_implant_decay_time_uncorrel;

TH1F* aida_implant_decay_time;

TH1F* aida_bplast_wr_time_diff;

TH1F* bplast_germanium_wr_time_diff;

TH1F* aida_degas_wr_time_diff;

TH1F* aida_wr_times;

TH1F* germanium_wr_times;

TH2F* aida_decay_frontback_energy_diff;

TH1F* aida_decay_frontback_time_diff;

TH2F* aida_decay_cluster_size;

TH1F* germanium_energy;


TH2F* frs_zvsaoq;
TH2F* frs_z1vsz2;
TH2F* frs_x2vsz1;
TH2F* frs_x4vsz2;
TH2F* frs_z1vsdE;
TH2F* frs_x2vsx4;

uint64_t wr_experiment_start = 1.71420318e+18;
uint64_t wr_experiment_end = 1.71420372e+18;
int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
int64_t slices_every = 1; //s
int64_t number_of_slices = duration_in_seconds/slices_every;

// 
TTree* aida_ana_tree;

struct implant_data
{
   int64_t time;
   int x;
   int y;
};

struct decay_data
{
   int64_t time;
   int x;
   int y;
};

struct germanium_data
{
   int64_t time;
   double energy;
};

implant_data aida_implant_data;
decay_data aida_decay_data;
germanium_data germanium_data;

// int64_t implant_time;
// int64_t decay_time;
// int64_t germanium_time;

// int implant_x;
// int implant_y;

// int decay_x;
// int decay_y;

// double germanium_energy;

// Load TCutG .root file

TFile *cut_file = new TFile("/u/jbormans/S100/analysis/aidatigerfish/X2_Z1_65.root");
TCutG *cutg = (TCutG*)cut_file->Get("CUTG");

TFile *cut_file1 = new TFile("/u/jbormans/S100/analysis/aidatigerfish/166Tb_Z_AoQ.root");
TCutG *cutg1 = (TCutG*)cut_file1->Get("CUTG");

TFile *cut_file2 = new TFile("/u/jbormans/S100/analysis/aidatigerfish/Z63_X2.root");
TCutG *cutg2 = (TCutG*)cut_file2->Get("CUTG");

TFile *cut_file3 = new TFile("/u/jbormans/S100/analysis/aidatigerfish/162Eu_AoQ.root");

TCutG *cut163Eu = (TCutG*)cut_file3->Get("CUTG");

std::vector<int> broken_xstrips;
std::vector<int> broken_ystrips;


void aida_ana::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void aida_ana::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   // Maps for storing data

   aida_implants_map1 = new std::map<int64_t, std::pair<int, int>>();
   aida_implants_map2 = new std::map<int64_t, std::pair<int, int>>();
   aida_decay_map1 = new std::map<int64_t, std::pair<int, int>>();
   aida_decay_map2 = new std::map<int64_t, std::pair<int, int>>();

   germanium_map = new std::map<int64_t, double>();

   // TTree for storing data

   aida_ana_tree = new TTree("aida_ana_tree", "AIDA Analysis Tree");

   // Create the branches
   aida_ana_tree->Branch("implants", &aida_implant_data, "time/L:x/I:y/I");
   aida_ana_tree->Branch("decays", &aida_decay_data, "time/L:x/I:y/I");
   aida_ana_tree->Branch("germanium", &germanium_data, "time/L:energy/D");


   // Read in AIDA strips thresholds from AIDA_strips.txt file

   std::ifstream aida_strips_file("/u/jbormans/S100/analysis/aidatigerfish/AIDA_strips.txt");

   int dssd_number;
   std::string xy;
   int strip_number;
   int threshold;

   std::string line;

   while(std::getline(aida_strips_file, line))
   {
      if(line[0] == '#') continue;

      std::istringstream iss(line);
      iss >> dssd_number >> xy >> strip_number >> threshold;
      
      // If the threshold is -1, add the strip to the list of strips to skip
      if (threshold == -1) {
         if (xy == "X") {
            broken_xstrips.push_back(strip_number);
         } else if (xy == "Y") {
            broken_ystrips.push_back(strip_number);
         }
      }
   }

   //Implants
   aida_implants_strip_xy = new TH2F("aida_implants_xy", "AIDA Implants XY DSSSD 1", 386, 0, 386, 128, 0, 128);
   aida_implants_strip_xy_pre = new TH2F("aida_implants_xy_pre", "AIDA Implants XY DSSSD 1 Preprocessing", 386, 0, 386, 128, 0, 128);
   aida2_implants_strip_xy = new TH2F("aida2_implants_xy", "AIDA Implants XY DSSSD 2", 386, 0, 386, 128, 0, 128);

   sc41_hits = new TH1F("sc41_hits", "SC41 hits", number_of_slices, 0, duration_in_seconds);

   // Decays

   aida_decays_strip_xy = new TH2F("aida_decays_strip_xy", "AIDA Decays XY", 386, 0, 386, 128, 0, 128);
   aida2_decays_strip_xy = new TH2F("aida2_decays_strip_xy", "AIDA2 Decays XY", 386, 0, 386, 128, 0, 128);

   aida_decays_xy = new TH2F("aida_decays_xy", "AIDA Decays XY", 386, 0, 386, 128, 0, 128);
   aida_decays_strip_xy_onspill = new TH2F("aida_decays_xy_onspill", "AIDA Decays XY DSSSD 1 Onspill", 386, 0, 386, 128, 0, 128);

   aida_wr_times = new TH1F("aida_wr_times", "AIDA WR Times", number_of_slices, 0, duration_in_seconds);

   germanium_wr_times = new TH1F("germanium_wr_times", "Germanium WR Times", number_of_slices, 0, duration_in_seconds);

   aida_decays_strip_xy_offspill = new TH2F("aida_decays_xy_offspill", "AIDA Decays XY DSSSD 1 Offspill", 386, 0, 386, 128, 0, 128);

   aida_implant_decay_time_uncorrel = new TH1F("aida_implant_decay_time_uncorrel", "AIDA Implant Decay Time Random", 2e3, -1e4, 1e5);

   aida_implant_decay_time = new TH1F("aida_implant_decay_time", "AIDA Implant Decay Time", 4e2, -1e4, 1e5);

   aida_bplast_wr_time_diff = new TH1F("aida_bplast_wr_time_diff", "AIDA BPlast WR Time Difference", 1e3, -8e4, 8e4);

   bplast_germanium_wr_time_diff = new TH1F("bplast_germanium_wr_time_diff", "BPlast Germanium WR Time Difference", 1e3, -8e4, 8e4);

   aida_degas_wr_time_diff = new TH1F("aida_degas_wr_time_diff", "AIDA Degas WR Time Difference", 1e3, -8e4, 8e4);

   aida_decay_frontback_energy_diff = new TH2F("aida_decay_frontback_energy_diff", "AIDA Decay Front vs Back Energy Difference", 1e3, 0, 1e4, 1e3, 0, 1e4);

   aida_decay_frontback_time_diff = new TH1F("aida_decay_frontback_time_diff", "AIDA Decay Front vs Back Time Difference", 1e3, -5e3,5e3);

   aida_decay_cluster_size = new TH2F("aida_decay_cluster_size", "AIDA Decay Cluster Size", 10, 0, 10, 10, 0, 10);

   germanium_energy = new TH1F("germanium_energy", "Germanium Energy", 1.5e3, 0, 1.5e3);

   frs_zvsaoq = new TH2F("frs_zvsaoq", "FRS Z vs A/Q", 1e3, 2.3, 2.7, 1e3,58, 68);
   frs_z1vsz2 = new TH2F("frs_z1vsz2", "FRS Z1 vs Z2", 1e3, 58, 68, 1e3, 58, 68);
   frs_x2vsz1 = new TH2F("frs_x2vsz1", "FRS X2 vs Z1", 1e3, 58, 68, 1e3, -100, 100);
   frs_x4vsz2 = new TH2F("frs_x4vsz2", "FRS X4 vs Z2", 1e3, 58, 68, 1e3, -100, 100);
   frs_z1vsdE = new TH2F("frs_z1vsdE", "FRS Z1 vs dE", 1e3, 30, 60, 1e3, 58, 68);
   frs_x2vsx4 = new TH2F("frs_x2vsx4", "FRS X2 vs X4", 1e3, -100, 100, 1e3, -100, 100);


   fOutput->AddAll(gDirectory->GetList());
}

Bool_t aida_ana::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

   int64_t time_diff_aida_bplast = 0;
   int64_t time_diff_aida_germanium = 0;
   int64_t frontback_decay_dt = 0;
   int64_t frontback_implant_dt = 0;
   int64_t time_diff_aida_sc41 = 0;
   int aida_implant_decay_dt = 0;
   int64_t aida_implant_time = 0;
   int64_t aida_decay_time = 0;
   int64_t degas_time = 0;
   int64_t bplast_time = 0;
   int aida_decay_counter_onspill = 0;
   int aida_decay_counter_offspill = 0;
   int aida_implant_counter = 0;
   int sc41counter = 0;

   // make a map for the AIDA implants hits where I save the whiterabbit time of the implants and x-y strip position


   int frshits = FrsHitData_fwr_t.GetSize();
   int aidaimphits = AidaImplantHits_Time.GetSize();
   int aidadecayhits = AidaDecayHits_Time.GetSize();
   int bplasthits = bPlastTwinpeaksCalData_fwr_t.GetSize();
   int germaniumhits = GermaniumCalData_fchannel_energy.GetSize();

   // Implanted ion map
   for (int i =0; i < frshits; i++)
   {
      if(cutg->IsInside(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(i)) && cutg1->IsInside(FrsHitData_fID_AoQ_corr.At(i), FrsHitData_fID_z.At(i))) // currently set for 166Tb
      {
         if(TMath::Abs(FrsHitData_fID_z.At(i)-FrsHitData_fID_z2.At(i)< 0.4)) frs_zvsaoq->Fill( FrsHitData_fID_AoQ_corr.At(i),FrsHitData_fID_z.At(i));
         frs_z1vsz2->Fill(FrsHitData_fID_z2.At(i), FrsHitData_fID_z.At(i));
         frs_x4vsz2->Fill(FrsHitData_fID_z2.At(i), FrsHitData_fID_x4.At(i));
         frs_x2vsz1->Fill(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(i));
         frs_z1vsdE->Fill(FrsHitData_fID_dEdeg.At(i),FrsHitData_fID_z.At(i) );
         frs_x2vsx4->Fill(FrsHitData_fID_x4.At(i), FrsHitData_fID_x2.At(i));

         for(int j = 0; j < aidaimphits; j++)
         {
            if(AidaImplantHits_DSSD[j] == 1 && AidaImplantHits_Stopped[j] == true)
            {
               aida_implants_strip_xy_pre->Fill(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
               aida_implant_counter++;
               // aida_implants_map1[AidaImplantHits_Time[j]] = std::make_pair(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
               // (*aida_implants_map1)[AidaImplantHits_Time[j]] = std::make_pair(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
               aida_implant_data.time = AidaImplantHits_Time[j];
               aida_implant_data.x = AidaImplantHits_StripX[j];
               aida_implant_data.y = AidaImplantHits_StripY[j];
               aida_ana_tree->Fill();
            }
            if(AidaImplantHits_DSSD[j] == 2 && AidaImplantHits_Stopped[j] == true)
            {
               aida2_implants_strip_xy->Fill(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
               // aida_implants_map2[AidaImplantHits_Time[j]] = std::make_pair(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
               // (*aida_implants_map2)[AidaImplantHits_Time[j]] = std::make_pair(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
            }
         }
      }
   }

   // Decay maps

   // on and off spill decays

   for(int i = 0; i < aidadecayhits; i++)
   {
      aida_decay_time = AidaDecayHits_Time[i];

      // aida_wr_times->Fill((aida_decay_time - wr_experiment_start)/1e9);

      // check if the strips is in the list of broken strips

      if(AidaDecayHits_DSSD[i] == 2){
         aida2_decays_strip_xy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
      }

      if(AidaDecayHits_DSSD[i] == 1 && TMath::Abs(AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i]) < 1e3)
      {

         // conditions for the decay event

         // removing broken strips

         if (std::find(broken_xstrips.begin(), broken_xstrips.end(), AidaDecayHits_StripX[i]) != broken_xstrips.end() || std::find(broken_ystrips.begin(), broken_ystrips.end(), AidaDecayHits_StripY[i]) != broken_ystrips.end()) continue;
         
         // FB low dE noise cut
         if (AidaDecayHits_EnergyX[i] < 250 && AidaDecayHits_EnergyY[i] < 250) continue;

         // FB energy difference 200 keV
         if (TMath::Abs(AidaDecayHits_EnergyX[i] - AidaDecayHits_EnergyY[i]) > 200) continue;
         
         

         aida_decay_frontback_energy_diff->Fill(AidaDecayHits_EnergyX[i], AidaDecayHits_EnergyY[i]);
         aida_decay_frontback_time_diff->Fill(AidaDecayHits_TimeX[i]- AidaDecayHits_TimeY[i]);
         aida_decay_cluster_size->Fill(AidaDecayHits_ClusterSizeX[i], AidaDecayHits_ClusterSizeY[i]);
         aida_decays_strip_xy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);

         if(*EventHeader_fSpillFlag == true)
         {
            
            aida_decays_strip_xy_onspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
         }
            
         if(*EventHeader_fSpillFlag == false)
         {
            // aida_decay_map1[AidaDecayHits_Time[i]] = std::make_pair(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
            // (*aida_decay_map1)[AidaDecayHits_Time[i]] = std::make_pair(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
            aida_decay_data.time = AidaDecayHits_Time[i];
            aida_decay_data.x = AidaDecayHits_StripX[i];
            aida_decay_data.y = AidaDecayHits_StripY[i];
            aida_ana_tree->Fill();
            aida_decays_strip_xy_offspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
            for(int j = 0; j < bplasthits; j++)
            {
               if(bPlastTwinpeaksCalData_fdetector_id[j] > 128) continue;
               bplast_time = bPlastTwinpeaksCalData_fwr_t[j];
               time_diff_aida_bplast = aida_decay_time - bplast_time;
               aida_bplast_wr_time_diff->Fill(time_diff_aida_bplast);
            }
         }
      }
   }

   // filling germanium map
   if (germaniumhits > 0)
   {
         for(int i = 0; i < germaniumhits; i++)
         {
            degas_time = GermaniumCalData_fwr_t.At(i);
            double energy = GermaniumCalData_fchannel_energy.At(i);
            int det = GermaniumCalData_fdetector_id.At(i);
            int cry = GermaniumCalData_fcrystal_id.At(i);
            
            if(det == 1)
            {
               germanium_data.time = degas_time;
               germanium_data.energy = energy;
               

               germanium_energy->Fill(energy);
               germanium_wr_times->Fill((degas_time - wr_experiment_start)/1e9);
            }

            aida_ana_tree->Fill();
            // germanium_map[degas_time] = energy;
            // (*germanium_map)[degas_time] = energy;

            for(int l = 0; l < aidadecayhits; l++)
            {
               aida_decay_time = AidaDecayHits_Time[l];
               time_diff_aida_germanium = aida_decay_time - degas_time;
               aida_degas_wr_time_diff->Fill(time_diff_aida_germanium);
            }
      }
   }

   return kTRUE;
}

void aida_ana::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   // for (auto impit = aida_implants_map1.begin(); impit != aida_implants_map1.end(); impit++)
   // {
   //    int64_t aida_implant_time = impit->first;
   //    // Reproduce the hit pattern
   //    aida_implants_strip_xy->Fill(impit->second.first, impit->second.second);
   //    for (auto decayit = aida_decay_map1.begin(); decayit != aida_decay_map1.end(); decayit++)
   //    {
   //       // //check position
   //       // if (impit->second.first == decayit->second.first && impit->second.second == decayit->second.second)
   //       // {

   //       // }
   //       int64_t aida_decay_time = decayit->first;
   //       int aida_implant_decay_dt = aida_decay_time - aida_implant_time;
   //       aida_implant_decay_time->Fill(aida_implant_decay_dt);
   //    }
   // }

   // for (auto decayit = aida_decay_map1.begin(); decayit != aida_decay_map1.end(); decayit++)
   // {
   //    int aida_decay_time = decayit->first;
   //    aida_decays_xy->Fill(decayit->second.first, decayit->second.second);
   // }

   // while (impit != aida_implants_map1.end())
   // {
   //    int64_t aida_implant_time = impit->first;
   //    // aida_implants_strip_xy->Fill(impit->second.first, impit->second.second);

   //    // Get the time of the next implant event
   //    auto next_impit = std::next(impit);
   //    int64_t next_implant_time = (next_impit != aida_implants_map1.end()) ? next_impit->first : INT64_MAX;

   //    // Consider all decay events that happened before the next implant event
   //    while (decayit != aida_decay_map1.end() && decayit->first < next_implant_time)
   //    {
   //       int64_t aida_decay_time = decayit->first;
   //       int aida_implant_decay_dt = (aida_decay_time - aida_implant_time)/1e6;
   //       aida_implant_decay_time->Fill(aida_implant_decay_dt);
   //       aida_decays_xy->Fill(decayit->second.first, decayit->second.second);
   //       ++decayit;
   //    }

   //    ++impit;
   // }

   // auto impit = aida_implants_map1->begin();
   // auto decayit = aida_decay_map1->begin();
   // auto germanit = germanium_map->begin();

   // while (decayit != aida_decay_map1->end())
   // {
   //    int64_t aida_decay_time = decayit->first;

   //    // Move impit to the first implant that is at or after the current decay
   //    while (impit != aida_implants_map1->end() && impit->first <= aida_decay_time)
   //    {
   //       ++impit;
   //    }

   //    // Start from the current implant and go backwards until we find a matching implant
   //    auto impit_back = impit;

   //    while (impit_back != aida_implants_map1->begin())
   //    {
   //       --impit_back;
   //       if (impit_back->second.first == decayit->second.first && impit_back->second.second == decayit->second.second)
   //       {
   //          int64_t aida_implant_time = impit_back->first;
   //          int aida_implant_decay_dt = (aida_decay_time - aida_implant_time)/1e6; // time in ms

   //          // If the decay is within a 400 us time window to the implant, skip this iteration
   //          if (aida_implant_decay_dt < 0.4) {
   //             break;
   //          }

   //          aida_implant_decay_time->Fill(aida_implant_decay_dt);
   //          aida_implants_strip_xy->Fill(impit_back->second.first, impit_back->second.second);
   //          aida_decays_xy->Fill(decayit->second.first, decayit->second.second);

   //          aida_wr_times->Fill((aida_decay_time - wr_experiment_start)/1e9);
   //          // Iterate over the germanit map and fill the germanium spectrum when a matching decay and implant is found
   //          // germanit = germanium_map.lower_bound(aida_decay_time); // Start from the first entry that is not less than aida_decay_time

   //          // Remove the matched implant from the implant map
   //          aida_implants_map1->erase(impit_back);
   //          break;
   //       }
   //    }

   //    ++decayit;
   // }

   // while (germanit != germanium_map->end())
   // {
   //    // Fill the germanium spectrum
   //    germanium_wr_times->Fill((germanit->first - wr_experiment_start)/1e9);
   //    germanium_energy->Fill(germanit->second);
   //    // int64_t degas_time = germanit->first;
   //    // int64_t time_diff_aida_germanium = degas_time - aida_decay_time;
   //    // aida_degas_wr_time_diff->Fill(time_diff_aida_germanium);
   //    ++germanit;
   // }
}

void aida_ana::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   TString option = GetOption();
   // decay_rate_offspill->Draw("HIST");
   // decay_rate_onspill->Draw("HIST");
   // implant_rate->Draw("HIST");


   TFile hfile (option, "RECREATE", "Analysis results");
   fOutput->Write();

   delete aida_ana_tree;

}