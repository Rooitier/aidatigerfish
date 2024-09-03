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
TH2F* aida2_implants_strip_xy;

TH2F* aida_frontback_energy_implants;
TH2F* aida2_frontback_energy_implants;

TH2F* aida_implants_166Tb;
TH2F* aida2_implants_166Tb;

TH2F* aida_implants_162Eu;
TH2F* aida2_implants_162Eu;

TH2F* aida_frontback_energy_implants_166Tb;
TH2F* aida2_frontback_energy_implants_166Tb;

TH2F* aida_frontback_energy_implants_162Eu;
TH2F* aida2_frontback_energy_implants_162Eu;

TH1F* aida_front_ex;
TH1F* aida_back_ey;

TH1F* aida2_front_ex;
TH1F* aida2_back_ey;

//Decays
TH1F* aida_frontdecay_ex;
TH1F* aida2_frontdecay_ex;

TH1F* aida_backdecay_ey;
TH1F* aida2_backdecay_ey;

TH2F* aida_decays_strip_xy_onspill;
TH2F* aida2_decays_strip_xy_onspill;

TH2F* aida_decays_strip_xy_offspill;
TH2F* aida2_decays_strip_xy_offspill;

TH1F* aida_bplast_decay_time_diff_onspill;
TH1F* aida2_bplast_decay_time_diff_onspill;

TH1F* aida_bplast_decay_time_diff_offspill;
TH1F* aida2_bplast_decay_time_diff_offspill;

TH1F* aida_germanium_decay_time_diff_offspill;
TH1F* aida2_germanium_decay_time_diff_offspill;

TH1F* aida_germanium_decay_time_diff_onspill;
TH1F* aida2_germanium_decay_time_diff_onspill;

TH2F* frs_zvsaoq;
TH2F* frs_z1vsz2;
TH2F* frs_x2vsz1;
TH2F* frs_x4vsz2;
TH2F* frs_z1vsdE;
TH2F* frs_x2vsx4;

TH1F* germanium_energy_dssd1;
TH1F* germanium_energy_dssd2;

std::map<int64_t, std::pair<int, int>> aida_implants_map1;
std::map<int64_t, std::pair<int, int>> aida_implants_map2;
std::map<int64_t, std::pair<int, int>> aida_decay_map;

// Load TCutG .root file

TFile *cut_file = new TFile("/u/jbormans/S100/analysis/aida_ana/X2_Z1_65.root");
TCutG *cutg = (TCutG*)cut_file->Get("CUTG");

TFile *cut_file1 = new TFile("/u/jbormans/S100/analysis/aida_ana/166Tb_Z_AoQ.root");
TCutG *cutg1 = (TCutG*)cut_file1->Get("CUTG");

TFile *cut_file2 = new TFile("/u/jbormans/S100/analysis/aida_ana/Z63_X2.root");
TCutG *cutg2 = (TCutG*)cut_file2->Get("CUTG");

TFile *cut_file3 = new TFile("/u/jbormans/S100/analysis/aida_ana/162Eu_AoQ.root");

TCutG *cut163Eu = (TCutG*)cut_file3->Get("CUTG");


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

   //Implants
   aida_implants_strip_xy = new TH2F("aida_implants_xy", "AIDA Implants XY DSSSD 1", 386, 0, 386, 128, 0, 128);
   aida2_implants_strip_xy = new TH2F("aida2_implants_xy", "AIDA Implants XY DSSSD 2", 386, 0, 386, 128, 0, 128);

   aida_frontback_energy_implants = new TH2F("aida_frontback_energy_implants", "AIDA Front vs Back Energy Implants", 1e3, 0, 10e3, 1e3, 0, 10e3);
   aida2_frontback_energy_implants = new TH2F("aida2_frontback_energy_implants", "AIDA Front vs Back Energy Implants", 1e3, 0, 10e3, 1e3, 0, 10e3);

   aida_implants_166Tb = new TH2F("aida_implants_166Tb", "AIDA Implants 166Tb", 386, 0, 386, 128, 0, 128);
   aida2_implants_166Tb = new TH2F("aida2_implants_166Tb", "AIDA Implants 166Tb", 386, 0, 386, 128, 0, 128);

   aida_implants_162Eu = new TH2F("aida_implants_162Eu", "AIDA Implants 162Eu", 386, 0, 386, 128, 0, 128);
   aida2_implants_162Eu = new TH2F("aida2_implants_162Eu", "AIDA Implants 162Eu", 386, 0, 386, 128, 0, 128);

   aida_frontback_energy_implants_166Tb = new TH2F("aida_frontback_energy_implants_166Tb", "AIDA Front vs Back Energy Implants of 166Tb", 1e3, 0, 10e3, 1e3, 0, 10e3);
   aida2_frontback_energy_implants_166Tb = new TH2F("aida2_frontback_energy_implants_166Tb", "AIDA Front vs Back Energy Implants of 166Tb", 1e3, 0, 10e3, 1e3, 0, 10e3);

   aida_frontback_energy_implants_162Eu = new TH2F("aida_frontback_energy_implants_162Eu", "AIDA Front vs Back Energy Implants of 162Eu", 1e3, 0, 10e3, 1e3, 0, 10e3);
   aida2_frontback_energy_implants_162Eu = new TH2F("aida2_frontback_energy_implants_162Eu", "AIDA Front vs Back Energy Implants of 162Eu", 1e3, 0, 10e3, 1e3, 0, 10e3);

   aida_front_ex = new TH1F("aida_front_ex", "AIDA Front Energy", 1e3, 0, 10e3);
   aida_back_ey = new TH1F("aida_back_ey", "AIDA Back Energy", 1e3, 0, 10e3);

   aida2_front_ex = new TH1F("aida2_front_ex", "AIDA Front Energy", 1e3, 0, 10e3);
   aida2_back_ey = new TH1F("aida2_back_ey", "AIDA Back Energy", 1e3, 0, 10e3);

   // Decays

   aida_frontdecay_ex = new TH1F("aida_frontdecay_ex", "AIDA Front Energy", 1e3, 0, 10e3);
   aida2_frontdecay_ex = new TH1F("aida2_frontdecay_ex", "AIDA Front Energy", 1e3, 0, 10e3);

   aida_backdecay_ey = new TH1F("aida_backdecay_ex", "AIDA Back Energy", 1e3, 0, 10e3);
   aida2_backdecay_ey = new TH1F("aida2_backdecay_ex", "AIDA Back Energy", 1e3, 0, 10e3);

   aida_decays_strip_xy_onspill = new TH2F("aida_decays_xy_onspill", "AIDA Decays XY DSSSD 1 Onspill", 386, 0, 386, 128, 0, 128);
   aida2_decays_strip_xy_onspill = new TH2F("aida2_decays_xy_onspill", "AIDA Decays XY DSSSD 2 Onspill", 386, 0, 386, 128, 0, 128);

   aida_decays_strip_xy_offspill = new TH2F("aida_decays_xy_offspill", "AIDA Decays XY DSSSD 1 Offspill", 386, 0, 386, 128, 0, 128);
   aida2_decays_strip_xy_offspill = new TH2F("aida2_decays_xy_offspill", "AIDA Decays XY DSSSD 2 Offspill", 386, 0, 386, 128, 0, 128);

   aida_bplast_decay_time_diff_onspill = new TH1F("aida_bplast_decay_time_diff_onspill", "AIDA BPlast Decay Time Difference Onspill", 1e3, -5e4, 3e4);
   aida2_bplast_decay_time_diff_onspill = new TH1F("aida2_bplast_decay_time_diff_onspill", "AIDA BPlast Decay Time Difference Onspill", 1e3, -5e4, 3e4);

   aida_bplast_decay_time_diff_offspill = new TH1F("aida_bplast_decay_time_diff_offspill", "AIDA BPlast Decay Time Difference Offspill", 1e3, -3e4, 3e4);
   aida2_bplast_decay_time_diff_offspill = new TH1F("aida2_bplast_decay_time_diff_offspill", "AIDA BPlast Decay Time Difference Offspill", 1e3, -3e4, 3e4);

   aida_germanium_decay_time_diff_offspill = new TH1F("aida_germanium_decay_time_diff_offspill", "AIDA Germanium Decay Time Difference Offspill", 1e3, -3e4, 3e4);
   aida2_germanium_decay_time_diff_offspill = new TH1F("aida2_germanium_decay_time_diff_offspill", "AIDA Germanium Decay Time Difference Offspill", 1e3, -3e4, 3e4);

   aida_germanium_decay_time_diff_onspill = new TH1F("aida_germanium_decay_time_diff_onspill", "AIDA Germanium Decay Time Difference Onspill", 1e3, -3e4, 3e4);
   aida2_germanium_decay_time_diff_onspill = new TH1F("aida2_germanium_decay_time_diff_onspill", "AIDA Germanium Decay Time Difference Onspill", 1e3, -3e4, 3e4);

   germanium_energy_dssd1 = new TH1F("germanium_energy_DSSD1", "Germanium Energy", 1500, 0, 1500);
   germanium_energy_dssd2 = new TH1F("germanium_energy_DSSD2", "Germanium Energy", 1500, 0, 1500);

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

   // if(*EventHeader_fSpillFlag == true) return kTRUE;

   int64_t time_diff_aida_bplast = 0;
   int64_t time_diff_aida_germanium = 0;
   int64_t frontback_decay_dt = 0;
   int64_t frontback_implant_dt = 0;
   int64_t time_diff_aida_sc41 = 0;
   int aida_implant_decay_dt = 0;
   int64_t aida_implant_time = 0;
   int64_t aida_decay_time = 0;
   int64_t degas_time = 0;

   // make a map for the AIDA implants hits where I save the whiterabbit time of the implants and x-y strip position

   int frshits = FrsHitData_fwr_t.GetSize();
   int aidaimphits = AidaImplantHits_Time.GetSize();

   for(int i = 0; i < aidaimphits; i++)
   {
      if(AidaImplantHits_DSSD[i] == 1 && AidaImplantHits_Stopped[i] == true)
      {
         aida_implants_strip_xy->Fill(AidaImplantHits_StripX[i], AidaImplantHits_StripY[i]);
         aida_frontback_energy_implants->Fill(AidaImplantHits_EnergyX[i], AidaImplantHits_EnergyY[i]);
         aida_front_ex -> Fill(AidaImplantHits_EnergyX[i]);
         aida_back_ey->Fill(AidaImplantHits_EnergyY[i]);
      }
      if(AidaImplantHits_DSSD[i] == 2 && AidaImplantHits_Stopped[i] == true)
      {
         aida2_implants_strip_xy->Fill(AidaImplantHits_StripX[i], AidaImplantHits_StripY[i]);
         aida2_frontback_energy_implants->Fill(AidaImplantHits_EnergyX[i], AidaImplantHits_EnergyY[i]);
         aida2_front_ex -> Fill(AidaImplantHits_EnergyX[i]);
         aida2_back_ey->Fill(AidaImplantHits_EnergyY[i]);
      }
   }

   // 166Tb
   for (int i =0; i < frshits; i++)
   {
      if(cutg->IsInside(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(i)) && cutg1->IsInside(FrsHitData_fID_AoQ_corr.At(i),FrsHitData_fID_z.At(i))){
         for(int k = 0; k < aidaimphits; k++)
         {
            if(AidaImplantHits_DSSD[k] == 1 && AidaImplantHits_Stopped[k] == true)
            {
               aida_implants_166Tb->Fill(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
               aida_frontback_energy_implants_166Tb->Fill(AidaImplantHits_EnergyX[k], AidaImplantHits_EnergyY[k]);
               aida_implant_time = AidaImplantHits_Time[k];
               aida_implants_map1[aida_implant_time] = std::make_pair(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
            }
            if(AidaImplantHits_DSSD[k] == 2 && AidaImplantHits_Stopped[k] == true)
            {
               aida2_implants_166Tb->Fill(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
               aida2_frontback_energy_implants_166Tb->Fill(AidaImplantHits_EnergyX[k], AidaImplantHits_EnergyY[k]);
               aida_implant_time = AidaImplantHits_Time[k];
               aida_implants_map2[aida_implant_time] = std::make_pair(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
            }

         }
      }
   }
   // // 162Eu
   // for (int i =0; i < frshits; i++)
   // {
   //    if(cutg2->IsInside(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(i)) && cut163Eu->IsInside(FrsHitData_fID_AoQ_corr.At(i),FrsHitData_fID_z.At(i))){
   //       for(int k = 0; k < aidaimphits; k++)
   //       {
   //          if(AidaImplantHits_DSSD[k] == 1 && AidaImplantHits_Stopped[k] == true)
   //          {
   //             aida_implants_162Eu->Fill(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
   //             aida_frontback_energy_implants_162Eu->Fill(AidaImplantHits_EnergyX[k], AidaImplantHits_EnergyY[k]);
   //             aida_implant_time = AidaImplantHits_Time[k];
   //             aida_implants_map1[aida_implant_time] = std::make_pair(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
   //          }
   //          if(AidaImplantHits_DSSD[k] == 2 && AidaImplantHits_Stopped[k] == true)
   //          {
   //             aida2_implants_162Eu->Fill(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
   //             aida2_frontback_energy_implants_162Eu->Fill(AidaImplantHits_EnergyX[k], AidaImplantHits_EnergyY[k]);
   //             aida_implant_time = AidaImplantHits_Time[k];
   //             aida_implants_map2[aida_implant_time] = std::make_pair(AidaImplantHits_StripX[k], AidaImplantHits_StripY[k]);
   //          }
   //       }
   //    }
   // }

   // Now loop over the decay hits in the map and correlate them with the implants in Time and x-y strip position
   // Investigate properties of decay events of 166Tb
   // for (int i = 0; i < AidaDecayHits_Time.GetSize(); i++)
   // {
   //    //Check offspill
   //    // if(*EventHeader_fSpillFlag == true) continue;
   //    // loop over the implants map and check if the decay event is within 75s of the implant event DSSD 1
   //    for (auto it = aida_implants_map1.begin(); it != aida_implants_map1.end(); it++)
   //    {
   //       // time condition window: Take an implant event and then look for a decay event up to three half lives later (70s)
   //       // Position condition: Check that the x-y strip position is within 2 strips
   //       aida_decay_time = AidaDecayHits_Time.At(i);
   //       aida_implant_decay_dt = aida_decay_time - it->first;
   //       // Clear the first events after 75s has elapsed in the implant event
   //       if(aida_implant_decay_dt > 70e9) aida_implants_map1.erase(it);

   //       if (aida_implant_decay_dt > 0 && aida_implant_decay_dt < 70e9 && TMath::Abs(AidaDecayHits_StripX[i] - it->second.first) < 2 && TMath::Abs(AidaDecayHits_StripY[i] - it->second.second) < 2
   //       && TMath::Abs(AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i]) < 3000 && TMath::Abs(AidaDecayHits_EnergyX[i] - AidaDecayHits_EnergyY[i]) < 200)
   //       {
   //          //Upstream AIDA
   //          if(AidaDecayHits_DSSD[i] == 1)
   //          {
   //             // loop over germanium and fill prompt gamma spectra
   //             for (int j = 0; j < GermaniumCalData_fchannel_energy.GetSize(); j++)
   //             {
   //                degas_time = GermaniumCalData_fwr_t.At(j);
   //                time_diff_aida_germanium = degas_time - aida_decay_time;
   //                if(time_diff_aida_germanium < -18000 || time_diff_aida_germanium > -12000) continue;
   //                double energy = GermaniumCalData_fchannel_energy.At(j);
   //                int det = GermaniumCalData_fdetector_id.At(j);
   //                int cry = GermaniumCalData_fcrystal_id.At(j);

   //                if (det < 1 || det > 12) continue; // detectors are labelled 1-12
   //                if (cry < 0 || cry > 2) continue; // crystals are indexed 0,1,2

   //                // Fill aida-germanium time difference on and off spill
   //                if(*EventHeader_fSpillFlag == true) aida_germanium_decay_time_diff_onspill->Fill(time_diff_aida_germanium);
   //                else aida_germanium_decay_time_diff_offspill->Fill(time_diff_aida_germanium);

   //                // bPlast coincidence
   //                for(int k = 0; k < bPlastTwinpeaksCalData_fwr_t.GetSize(); k++){
   //                   time_diff_aida_bplast = bPlastTwinpeaksCalData_fwr_t[k] - aida_decay_time;
   //                   if(* == true) aida_bplast_decay_time_diff_onspill->Fill(time_diff_aida_bplast);
   //                   else aida_bplast_decay_time_diff_offspill->Fill(time_diff_aida_bplast);

   //                   // If bPlast coincidence, fill germanium energy and AIDA spectra
   //                   if(time_diff_aida_bplast < -17500 || time_diff_aida_bplast > -13500) continue;
   //                   germanium_energy_dssd1->Fill(GermaniumCalData_fchannel_energy.At(j));

   //                   //Front-back energy
   //                   aida_frontdecay_ex->Fill(AidaDecayHits_EnergyX[i]);
   //                   aida_backdecay_ey->Fill(AidaDecayHits_EnergyY[i]);

   //                   // Strip decay hit pattern on and off spill
   //                   if(*EventHeader_fSpillFlag == true) aida_decays_strip_xy_onspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
   //                   else aida_decays_strip_xy_offspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
   //                }
   //             }
   //          }
   //       }
   //    }
   //    // loop over the implants map and check if the decay event is within 75s of the implant event for DSSD 2
   //    for (auto it = aida_implants_map2.begin(); it != aida_implants_map2.end(); it++)
   //    {
   //       // time condition window: Take an implant event and then look for a decay event up to three half lives later (70s)
   //       // Position condition: Check that the x-y strip position is within 2 strips
   //       aida_decay_time = AidaDecayHits_Time.At(i);
   //       aida_implant_decay_dt = aida_decay_time - it->first;
   //       // Clear the first events after 75s has elapsed in the implant event
   //       if(aida_implant_decay_dt > 70e9) aida_implants_map2.erase(it);

   //       if (aida_implant_decay_dt > 0 && aida_implant_decay_dt < 70e9 && TMath::Abs(AidaDecayHits_StripX[i] - it->second.first) < 2 && TMath::Abs(AidaDecayHits_StripY[i] - it->second.second) < 2
   //       && TMath::Abs(AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i]) < 3000 && TMath::Abs(AidaDecayHits_EnergyX[i] - AidaDecayHits_EnergyY[i]) < 200)
   //       {
   //          //Upstream AIDA
   //          if(AidaDecayHits_DSSD[i] == 2)
   //          {
   //             // loop over germanium and fill prompt gamma spectra
   //             for (int j = 0; j < GermaniumCalData_fchannel_energy.GetSize(); j++)
   //             {
   //                degas_time = GermaniumCalData_fwr_t.At(j);
   //                time_diff_aida_germanium = degas_time - aida_decay_time;
   //                if(time_diff_aida_germanium < -18000 || time_diff_aida_germanium > -12000) continue;
   //                double energy = GermaniumCalData_fchannel_energy.At(j);
   //                int det = GermaniumCalData_fdetector_id.At(j);
   //                int cry = GermaniumCalData_fcrystal_id.At(j);

   //                if (det < 1 || det > 12) continue; // detectors are labelled 1-12
   //                if (cry < 0 || cry > 2) continue; // crystals are indexed 0,1,2

   //                if(*EventHeader_fSpillFlag == true) aida2_germanium_decay_time_diff_onspill->Fill(time_diff_aida_germanium);
   //                else aida2_germanium_decay_time_diff_offspill->Fill(time_diff_aida_germanium);

   //                // bPlast coincidence
   //                for(int k = 0; k < bPlastTwinpeaksCalData_fwr_t.GetSize(); k++){
   //                   time_diff_aida_bplast = bPlastTwinpeaksCalData_fwr_t[k] - aida_decay_time;
   //                   if(*EventHeader_fSpillFlag == true) aida2_bplast_decay_time_diff_onspill->Fill(time_diff_aida_bplast);
   //                   else aida2_bplast_decay_time_diff_offspill->Fill(time_diff_aida_bplast);

   //                   // If bPlast coincidence, fill germanium energy and AIDA spectra
   //                   if(time_diff_aida_bplast < -19000 || time_diff_aida_bplast > -13000) continue;
   //                   germanium_energy_dssd2->Fill(GermaniumCalData_fchannel_energy.At(j));

   //                   if(*EventHeader_fSpillFlag == true) aida2_bplast_decay_time_diff_onspill->Fill(time_diff_aida_bplast);
   //                   else aida2_bplast_decay_time_diff_offspill->Fill(time_diff_aida_bplast);

   //                   //Front-back energy
   //                   aida2_frontdecay_ex->Fill(AidaDecayHits_EnergyX[i]);
   //                   aida2_backdecay_ey->Fill(AidaDecayHits_EnergyY[i]);

   //                   // Strip decay hit pattern on and off spill
   //                   if(*EventHeader_fSpillFlag == true) aida2_decays_strip_xy_onspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
   //                   else aida2_decays_strip_xy_offspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
   //                }
   //             }
   //          }
   //       }
   //    }
   // }


   // Investigate properties of decay events of 166Tb
   for (int i = 0; i < AidaDecayHits_Time.GetSize(); i++)
   {
      //Check offspill
      if(*EventHeader_fSpillFlag == true) continue;
      // loop over the implants map and check if the decay event is within 75s of the implant event DSSD 1
      // for (auto it = aida_implants_map1.begin(); it != aida_implants_map1.end(); it++)
      // {
      // time condition window: Take an implant event and then look for a decay event up to three half lives later (70s)
      // Position condition: Check that the x-y strip position is within 2 strips
      aida_decay_time = AidaDecayHits_Time.At(i);
      // aida_implant_decay_dt = aida_decay_time - it->first;
      // Clear the first events after 75s has elapsed in the implant event
      // if(aida_implant_decay_dt > 70e9) aida_implants_map1.erase(it);

      if (/* aida_implant_decay_dt > 0 && aida_implant_decay_dt < 70e9 && TMath::Abs(AidaDecayHits_StripX[i] - it->second.first) < 2 && TMath::Abs(AidaDecayHits_StripY[i] - it->second.second) < 2
      && */ TMath::Abs(AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i]) < 3000 && TMath::Abs(AidaDecayHits_EnergyX[i] - AidaDecayHits_EnergyY[i]) < 200)
      {
         //Upstream AIDA
         if(AidaDecayHits_DSSD[i] == 1)
         {
            // fill decay map
            aida_decay_map[aida_decay_time] = std::make_pair(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
         }
      }
   }

   // fill germaniusm data

   // loop over germanium and fill prompt gamma spectra
   for (int j = 0; j < GermaniumCalData_fchannel_energy.GetSize(); j++)
   {
      for (auto it = aida_decay_map.begin(); it != aida_decay_map.end(); it++){
         degas_time = GermaniumCalData_fwr_t.At(j);
         time_diff_aida_germanium = degas_time - it->first;
         if(time_diff_aida_germanium < -18000 || time_diff_aida_germanium > -12000) continue;
         double energy = GermaniumCalData_fchannel_energy.At(j);
         int det = GermaniumCalData_fdetector_id.At(j);
         int cry = GermaniumCalData_fcrystal_id.At(j);

         if (det < 1 || det > 12) continue; // detectors are labelled 1-12
         if (cry < 0 || cry > 2) continue; // crystals are indexed 0,1,2

         // Fill aida-germanium time difference on and off spill
         if(*EventHeader_fSpillFlag == true) aida_germanium_decay_time_diff_onspill->Fill(time_diff_aida_germanium);
         else aida_germanium_decay_time_diff_offspill->Fill(time_diff_aida_germanium);

         // // bPlast coincidence
         // for(int k = 0; k < bPlastTwinpeaksCalData_fwr_t.GetSize(); k++){
         //    time_diff_aida_bplast = bPlastTwinpeaksCalData_fwr_t[k] - aida_decay_time;
         //    if(*EventHeader_fSpillFlag == true) aida_bplast_decay_time_diff_onspill->Fill(time_diff_aida_bplast);
         //    else aida_bplast_decay_time_diff_offspill->Fill(time_diff_aida_bplast);

         //    // If bPlast coincidence, fill germanium energy and AIDA spectra
         //    if(time_diff_aida_bplast < -17500 || time_diff_aida_bplast > -13500) continue;
         //    germanium_energy_dssd1->Fill(GermaniumCalData_fchannel_energy.At(j));

         //    //Front-back energy
         //    aida_frontdecay_ex->Fill(AidaDecayHits_EnergyX[i]);
         //    aida_backdecay_ey->Fill(AidaDecayHits_EnergyY[i]);

         //    // Strip decay hit pattern on and off spill
         //    if(*EventHeader_fSpillFlag == true) aida_decays_strip_xy_onspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
         //    else aida_decays_strip_xy_offspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
         // }
      }
   }
      // loop over the implants map and check if the decay event is within 75s of the implant event for DSSD 2
      // for (auto it = aida_implants_map2.begin(); it != aida_implants_map2.end(); it++)
      // {
      //    // time condition window: Take an implant event and then look for a decay event up to three half lives later (70s)
      //    // Position condition: Check that the x-y strip position is within 2 strips
      //    aida_decay_time = AidaDecayHits_Time.At(i);
      //    aida_implant_decay_dt = aida_decay_time - it->first;
      //    // Clear the first events after 75s has elapsed in the implant event
      //    if(aida_implant_decay_dt > 70e9) aida_implants_map2.erase(it);

      //    if (aida_implant_decay_dt > 0 && aida_implant_decay_dt < 70e9 && TMath::Abs(AidaDecayHits_StripX[i] - it->second.first) < 2 && TMath::Abs(AidaDecayHits_StripY[i] - it->second.second) < 2
      //    && TMath::Abs(AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i]) < 3000 && TMath::Abs(AidaDecayHits_EnergyX[i] - AidaDecayHits_EnergyY[i]) < 200)
      //    {
      //       //Upstream AIDA
      //       if(AidaDecayHits_DSSD[i] == 2)
      //       {
      //          // loop over germanium and fill prompt gamma spectra
      //          for (int j = 0; j < GermaniumCalData_fchannel_energy.GetSize(); j++)
      //          {
      //             degas_time = GermaniumCalData_fwr_t.At(j);
      //             time_diff_aida_germanium = degas_time - aida_decay_time;
      //             if(time_diff_aida_germanium < -18000 || time_diff_aida_germanium > -12000) continue;
      //             double energy = GermaniumCalData_fchannel_energy.At(j);
      //             int det = GermaniumCalData_fdetector_id.At(j);
      //             int cry = GermaniumCalData_fcrystal_id.At(j);

      //             if (det < 1 || det > 12) continue; // detectors are labelled 1-12
      //             if (cry < 0 || cry > 2) continue; // crystals are indexed 0,1,2

      //             if(*EventHeader_fSpillFlag == true) aida2_germanium_decay_time_diff_onspill->Fill(time_diff_aida_germanium);
      //             else aida2_germanium_decay_time_diff_offspill->Fill(time_diff_aida_germanium);

      //             // bPlast coincidence
      //             for(int k = 0; k < bPlastTwinpeaksCalData_fwr_t.GetSize(); k++){
      //                time_diff_aida_bplast = bPlastTwinpeaksCalData_fwr_t[k] - aida_decay_time;
      //                if(*EventHeader_fSpillFlag == true) aida2_bplast_decay_time_diff_onspill->Fill(time_diff_aida_bplast);
      //                else aida2_bplast_decay_time_diff_offspill->Fill(time_diff_aida_bplast);

      //                // If bPlast coincidence, fill germanium energy and AIDA spectra
      //                if(time_diff_aida_bplast < -19000 || time_diff_aida_bplast > -13000) continue;
      //                germanium_energy_dssd2->Fill(GermaniumCalData_fchannel_energy.At(j));

      //                if(*EventHeader_fSpillFlag == true) aida2_bplast_decay_time_diff_onspill->Fill(time_diff_aida_bplast);
      //                else aida2_bplast_decay_time_diff_offspill->Fill(time_diff_aida_bplast);

      //                //Front-back energy
      //                aida2_frontdecay_ex->Fill(AidaDecayHits_EnergyX[i]);
      //                aida2_backdecay_ey->Fill(AidaDecayHits_EnergyY[i]);

      //                // Strip decay hit pattern on and off spill
      //                if(*EventHeader_fSpillFlag == true) aida2_decays_strip_xy_onspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
      //                else aida2_decays_strip_xy_offspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
      //             }
      //          }
      //       }
      //    }
      // }
   // }
   // Analysis loop

   // for (int i = 0; i < AidaDecayHits_Time.GetSize(); i++)
   // {
   //    //Choose events only with multiplicity less than three
   //    if(AidaDecayHits_StripXMin.At(i) > 5 || AidaDecayHits_StripYMin.At(i) > 5) continue;
   //    // Front-back matching time difference
   //    frontback_decay_dt = AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i];
   //    if(frontback_decay_dt < 0) continue;
   //    if 
   //    // loop over the implants map and check if the decay event is within 75s of the implant event
   //    for (auto it = aida_implants_map.begin(); it != aida_implants_map.end(); it++)
   //    {
   //       // time condition window: Take an implant event and then look for a decay event up to three half lives later (75s)
   //       // Position condition: Check that the x-y strip position is within 3 strips
   //       aida_decay_time = AidaDecayHits_Time.At(i);
   //       aida_implant_decay_dt = aida_decay_time - it->first;
   //       // Clear the first events after 75s has elapsed in the implant event
   //       if(aida_implant_decay_dt > 75e9) aida_implants_map.erase(it);

   //       if (aida_implant_decay_dt > 0 && aida_implant_decay_dt < 75e9 && TMath::Abs(AidaDecayHits_StripX[i] - it->second.first) < 3 && TMath::Abs(AidaDecayHits_StripY[i] - it->second.second) < 3)
   //       {
   //          // aida_implants_strip_xy->Fill(it->second.first, it->second.second);
   //          aida_decays_strip_xy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
   //          // loop over germanium and fill prompt gamma time difference
   //          for (int j = 0; j < GermaniumCalData_fwr_t.GetSize(); j++)
   //          {
   //             time_diff_aida_germanium = GermaniumCalData_fwr_t.At(j) - AidaDecayHits_Time.At(i);
   //             aida_germanium_decay_time_diff->Fill(time_diff_aida_germanium);
   //          }
   //          // fill germanium energy spectrum
   //          for (int j = 0; j < GermaniumCalData_fchannel_energy.GetSize(); j++)
   //          {
   //             germanium_energy->Fill(GermaniumCalData_fchannel_energy.At(j));
   //          }
   //       }
   //    }
   // }

   
   // for (int i =0; i < FrsHitData_fID_z.GetSize(); i++)
   // {
   //    for(int j = 0; j < FrsHitData_fID_x2.GetSize(); j++)
   //    {
   //       if(cutg2->IsInside(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(j))){
   //          frs_x2vsz1->Fill(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(j));

   //          for (int i =0; i < FrsHitData_fID_AoQ_corr.GetSize(); i++)
   //          {
   //             for(int j = 0; j < FrsHitData_fID_z.GetSize(); j++)
   //             {
   //                for(int k = 0; k < FrsHitData_fID_z2.GetSize(); k++)
   //                {  
   //                if(TMath::Abs(FrsHitData_fID_z.At(j)-FrsHitData_fID_z2.At(k)< 0.4)) frs_zvsaoq->Fill( FrsHitData_fID_AoQ_corr.At(i),FrsHitData_fID_z.At(j));
   //                }
   //             }
   //          }

   //          for (int i =0; i < FrsHitData_fID_z.GetSize(); i++)
   //          {
   //             for(int j = 0; j < FrsHitData_fID_z2.GetSize(); j++)\
   //             {
   //                frs_z1vsz2->Fill(FrsHitData_fID_z2.At(j), FrsHitData_fID_z.At(i));
   //             }
   //          }

   //          for (int i =0; i < FrsHitData_fID_z2.GetSize(); i++)
   //          {
   //             for(int j = 0; j < FrsHitData_fID_x4.GetSize(); j++)\
   //             {
   //                frs_x4vsz2->Fill(FrsHitData_fID_z2.At(i), FrsHitData_fID_x4.At(j));
   //             }
   //          }

   //          for (int i =0; i < FrsHitData_fID_z.GetSize(); i++)
   //          {
   //             for(int j = 0; j < FrsHitData_fID_dEdeg.GetSize(); j++)
   //             {
   //                frs_z1vsdE->Fill(FrsHitData_fID_dEdeg.At(j),FrsHitData_fID_z.At(i) );
   //             }
   //          } 
   //       }    
   //    }
   // }

   for (int i =0; i < frshits; i++)
   {
      if(TMath::Abs(FrsHitData_fID_z.At(i)-FrsHitData_fID_z2.At(i)< 0.4)) frs_zvsaoq->Fill( FrsHitData_fID_AoQ_corr.At(i),FrsHitData_fID_z.At(i));
   }

   for (int i =0; i < frshits; i++)
   {
      frs_z1vsz2->Fill(FrsHitData_fID_z2.At(i), FrsHitData_fID_z.At(i));
   }

   for (int i =0; i < frshits; i++)
   {
      frs_x4vsz2->Fill(FrsHitData_fID_z2.At(i), FrsHitData_fID_x4.At(i));
   }

   for(int i = 0; i < frshits; i++)
   {
      frs_x2vsz1->Fill(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(i));
   }

   for (int i =0; i < frshits; i++)
   {
      frs_z1vsdE->Fill(FrsHitData_fID_dEdeg.At(i),FrsHitData_fID_z.At(i) );
   }

   for (int i =0; i < frshits; i++)
   {
      frs_x2vsx4->Fill(FrsHitData_fID_x4.At(i), FrsHitData_fID_x2.At(i));
   }


   return kTRUE;
}

void aida_ana::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void aida_ana::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   TString option = GetOption();
   TFile hfile (option, "RECREATE", "Analysis results");
   fOutput->Write();

}