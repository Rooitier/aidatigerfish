#define bgam_cxx
// The class definition in bgam.h has been generated automatically
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
// root> T->Process("bgam.C")
// root> T->Process("bgam.C","some options")
// root> T->Process("bgam.C+")
//


#include "bgam.h"
#include <TH2.h>
#include <TStyle.h>
#include <TTreeReaderArray.h>


TH1D * h1_time_diff;
TH1D * h1_time_diff_up;
TH1D * h1_time_diff_down;
TH1D * h1_germergy;
TH1D * h1_germergy_up;
TH1D * h1_germergy_down;
TH2D * h2_germergy_germergy;
TH1D * h1_germergy_gate;
TH1D * h1_bslow;
TH1D * h1_germergy_aida;
TH1D * h1_germergy_aida_noprompt;

TH2D * h2_aida_decays_vs_aidagermdt;
TH2D * h2_aida_decays_vs_aidabplastdt;

TH1D * h1_aida1_multiplicity;
TH1D * h1_aida2_multiplicity;
TH1D * h1_bplast_multiplicity;
TH1D * h1_germ_multiplicity;

TH2D * h2_bplastmult_vs_germergy;

TH1D * h1_aida_frontbacktime;
TH2D * h2_aida_frontbackenergy;
TH1D * h1_aida_clusterx;
TH1D * h1_aida_clustery;

TH1D * h1_aida_frontbacktime_166Tb;
TH2D * h2_aida_frontbackenergy_166Tb;

TH1D * h1_aida_frontbacktime_160Eu;
TH2D * h2_aida_frontbackenergy_160Eu;

TH1D * h1_aida_germanium_35us;
TH2D * h1_aida_frontback_35us;
TH2D * h1_aida_decays_35us;


TH2D * h2_aida_decays_dssd1;
TH2D * h2_aida_decays_dssd2;
TH1D * h1_aida_bplast_timediff;
TH1D * h1_aida_germanium_timediff;
TH1D * h1_aida_germanium_timediff_only;

TH2D* h2_aida_decays_dssd1_160Eu;
TH2D* h2_aida_decays_dssd2_160Eu;
TH1D* h1_germergy_gate_160Eu_822;
TH1D* h1_aida_bplast_time_diff_160Eu;
TH1D* h1_aida_germanium_time_diff_160Eu;

TH2D * h2_germergy_germergy_aida_dt;

TH1D* h1_aida_decay_distance;

TH1D* h1_germergy_aida_bplast;
TH1D* h1_germergy_germ_bplast;

TH2F* frs_zvsaoq;
TH2F* frs_z1vsz2;
TH2F* frs_x2vsz1;
TH2F* frs_x4vsz2;
TH2F* frs_z1vsdE;
TH2F* frs_x2vsx4;

TH2D* h2_aida1_166Tb_implants;
TH2D* h2_aida2_166Tb_implants;
TH2D* h2_aida1_160Eu_implants;
TH2D* h2_aida2_160Eu_implants;

TH1D* h1_germergy_gated_aida;
TH2D* h2_aidagerm_decays_dssd1;
TH2D* h2_aidagerm_decays_dssd2;
TH2D* h2_germergy_germergy_aida;

TH1D* h1_germergy_gate_160Eu_822_aida;
TH2D* h2_aidagerm_decays_dssd1_160Eu;

TH1D* h1_aida_implant_decay_dt;

// Load TCutG

TFile *Eucut_file = new TFile("/lustre/gamma/jeroen/S100/analysis/betaion/160Eu_1609.root");

TCutG *Eu_Z_AoQ = (TCutG*)Eucut_file->Get("cut_Z_AoQ");

TCutG *Eu_Z_Z2 = (TCutG*)Eucut_file->Get("cut_Z_Z2");

TFile *Tbcut_file = new TFile("/lustre/gamma/jeroen/S100/analysis/betaion/X2_Z1_65.root");

TCutG *Tb_x2_Z = (TCutG*)Tbcut_file->Get("CUTG");

TFile *Tbcut_file1 = new TFile("/lustre/gamma/jeroen/S100/analysis/betaion/166Tb_Z_AoQ.root");

TCutG *Tb_Z_AoQ = (TCutG*)Tbcut_file1->Get("CUTG");

TFile *Tbdecaycut = new TFile("/lustre/gamma/jeroen/S100/analysis/betaion/166Tbcut.root");

TCutG *Tbdecay = (TCutG*)Tbdecaycut->Get("166Tbcut");

TFile *Eudecaycut = new TFile("/lustre/gamma/jeroen/S100/analysis/betaion/160Eucut.root");

TCutG *Eudecay = (TCutG*)Eudecaycut->Get("160Eucut");



void bgam::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void bgam::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   h1_time_diff = new TH1D("h1_time_diff","h1_time_diff",1000,-2000,2000);
   // h1_time_diff_up = new TH1D("h1_time_diff_up","h1_time_diff_up",1000,-2000,2000);
   // h1_time_diff_down = new TH1D("h1_time_diff_down","h1_time_diff_down",1000,-2000,2000);
   // h1_germergy = new TH1D("h1_germergy","h1_germergy",2000,0,2000);
   // h1_germergy_up = new TH1D("h1_germergy_up","h1_germergy_up",2000,0,2000);
   // h1_germergy_down = new TH1D("h1_germergy_down","h1_germergy_down",2000,0,2000);
   // h2_germergy_germergy = new TH2D("h2_germergy_gemergy","h2_germergy_gemergy",2000,0,2000,2000,0,2000);
   // h1_germergy_gate = new TH1D("h1_germergy_gate","h1_germergy_gate",2000,0,2000);
   h1_bslow = new TH1D("h1_bslow","h1_bslow",2000,0,2000);

   h2_aida_decays_dssd1 = new TH2D("h2_aida_decays","h2_aida_decays",384,0,384,128,0,128);
   // h2_aida_decays_dssd2 = new TH2D("h2_aida_decays_dssd2","h2_aida_decays_dssd2",384,0,384,128,0,128);
   h1_aida_bplast_timediff = new TH1D("h1_aida_bplast_timediff","h1_aida_bplast_timediff",1000,-8e4,8e4);
   h1_aida_germanium_timediff = new TH1D("h1_aida_germanium_timediff","h1_aida_germanium_timediff",1000,-8e4,8e4);
   h1_germergy_aida_bplast = new TH1D("h1_germergy_aida_bplast","h1_germergy_aida_bplast",2000,0,2000);
   h1_germergy_germ_bplast = new TH1D("h1_germergy_germ_bplast","h1_germergy_germ_bplast",2000,0,2000);
   // h1_germergy_aida = new TH1D("h1_germergy_aida","h1_germergy_aida",2000,0,2000);
   // h1_germergy_aida_noprompt = new TH1D("h1_germergy_aida_noprompt","h1_germergy_aida_noprompt",2000,0,2000);

   // h2_aida_decays_vs_aidagermdt = new TH2D("h2_aida_decays_vs_aidagermdt","h2_aida_decays_vs_aidagermdt",1000,-8e4,8e4,3000,0,3000);
   // h2_aida_decays_vs_aidabplastdt = new TH2D("h2_aida_decays_vs_bplastdt","h2_aida_decays_vs_aidabplastdt",1000,-8e4,8e4,3000,0,3000);

   // h1_aida1_multiplicity = new TH1D("h1_aida_multiplicity","h1_aida1_multiplicity",512,0,512);
   // h1_aida2_multiplicity = new TH1D("h1_aida2_multiplicity","h1_aida2_multiplicity",512,0,512);
   // h1_bplast_multiplicity = new TH1D("h1_bplast_multiplicity","h1_bplast_multiplicity",128,0,128);
   // h1_germ_multiplicity = new TH1D("h1_germ_multiplicity","h1_germ_multiplicity",90,0,90);

   // h2_bplastmult_vs_germergy = new TH2D("h2_bplastmult_vs_germergy","h2_bplastmult_vs_germergy",64,0,64,2000,0,2000);

   // h1_aida_frontbacktime = new TH1D("h1_aida_frontbacktime","h1_aida_frontbacktime",1000,-10e3,10e3);
   // h2_aida_frontbackenergy = new TH2D("h2_aida_frontbackenergy","h2_aida_frontbackenergy",2000,0,2000,2000,0,2000);
   // h1_aida_clusterx = new TH1D("h1_aida_clusterx","h1_aida_clusterx",25,0,25);
   // h1_aida_clustery = new TH1D("h1_aida_clustery","h1_aida_clustery",25,0,25);

   // h1_aida_frontbacktime_166Tb = new TH1D("h1_aida_frontbacktime_166Tb","h1_aida_frontbacktime_166Tb",1000,-10e3,10e3);
   // h2_aida_frontbackenergy_166Tb = new TH2D("h2_aida_frontbackenergy_166Tb","h2_aida_frontbackenergy_166Tb",2000,0,2000,2000,0,2000);

   // h1_aida_frontbacktime_160Eu = new TH1D("h1_aida_frontbacktime_160Eu","h1_aida_frontbacktime_160Eu",1000,-10e3,10e3);
   // h2_aida_frontbackenergy_160Eu = new TH2D("h2_aida_frontbackenergy_160Eu","h2_aida_frontbackenergy_160Eu",2000,0,2000,2000,0,2000);

   // h2_germergy_germergy_aida_dt = new TH2D("h2_germergy_germergy_aida_dt","h2_germergy_germergy_aida_dt",1e3,-8e4,8e4,3000,0,3000);
   // h2_aida_decays_dssd1_160Eu = new TH2D("h2_aida_decays_dssd1_160Eu","h2_aida_decays_dssd1_160Eu",384,0,384,128,0,128);
   // h2_aida_decays_dssd2_160Eu = new TH2D("h2_aida_decays_dssd2_160Eu","h2_aida_decays_dssd2_160Eu",384,0,384,128,0,128);
   // h1_germergy_gate_160Eu_822 = new TH1D("h1_germergy_gate_160Eu_822","h1_germergy_gate_160Eu_822",2000,0,2000);
   // h1_aida_bplast_time_diff_160Eu = new TH1D("h1_aida_bplast_time_diff_160Eu","h1_aida_bplast_time_diff_160Eu",1000,-8e4,8e4);
   // h1_aida_germanium_time_diff_160Eu = new TH1D("h1_aida_germanium_time_diff_160Eu","h1_aida_germanium_time_diff_160Eu",1000,-8e4,8e4);
   // h1_aida_germanium_timediff_only = new TH1D("h1_aida_germanium_timediff_only","h1_aida_germanium_timediff_only",1000,-8e4,8e4);

   // h1_aida_decay_distance = new TH1D("h1_aida_decay_distance","h1_aida_decay_distance",100,0,100);

   // h1_aida_germanium_35us = new TH1D("h1_aida_germanium_35us","h1_aida_germanium_35us",2000,0,2000);
   // h1_aida_frontback_35us = new TH2D("h1_aida_frontback_35us","h1_aida_frontback_35us",2000,0,2000,2000,0,2000);
   // h1_aida_decays_35us = new TH2D("h1_aida_decays_35us","h1_aida_decays_35us",384,0,384,128,0,128);

   // frs_zvsaoq = new TH2F("frs_zvsaoq", "FRS Z vs A/Q", 1e3, 2.3, 2.7, 1e3,58, 68);
   // frs_z1vsz2 = new TH2F("frs_z1vsz2", "FRS Z1 vs Z2", 1e3, 58, 68, 1e3, 58, 68);
   // frs_x2vsz1 = new TH2F("frs_x2vsz1", "FRS X2 vs Z1", 1e3, 58, 68, 1e3, -100, 100);
   // frs_x4vsz2 = new TH2F("frs_x4vsz2", "FRS X4 vs Z2", 1e3, 58, 68, 1e3, -100, 100);
   // frs_z1vsdE = new TH2F("frs_z1vsdE", "FRS Z1 vs dE", 1e3, 30, 60, 1e3, 58, 68);
   // frs_x2vsx4 = new TH2F("frs_x2vsx4", "FRS X2 vs X4", 1e3, -100, 100, 1e3, -100, 100);

   // h2_aida1_166Tb_implants = new TH2D("h2_aida1_166Tb_implants","h2_aida1_166Tb_implants",384,0,384,128,0,128);
   // h2_aida2_166Tb_implants = new TH2D("h2_aida2_166Tb_implants","h2_aida2_166Tb_implants",384,0,384,128,0,128);
   // h2_aida1_160Eu_implants = new TH2D("h2_aida1_160Eu_implants","h2_aida1_160Eu_implants",384,0,384,128,0,128);
   // h2_aida2_160Eu_implants = new TH2D("h2_aida2_160Eu_implants","h2_aida2_160Eu_implants",384,0,384,128,0,128);

   // h1_germergy_gated_aida = new TH1D("h1_germergy_gated_aida","h1_germergy_gated_aida",2000,0,2000);
   // h2_aidagerm_decays_dssd1 = new TH2D("h2_aidagerm_decays_dssd1","h2_aidagerm_decays_dssd1",384,0,384,128,0,128);
   // h2_aidagerm_decays_dssd2 = new TH2D("h2_aidagerm_decays_dssd2","h2_aidagerm_decays_dssd2",384,0,384,128,0,128);
   // h2_germergy_germergy_aida = new TH2D("h2_germergy_germergy_aida","h2_germergy_germergy_aida",2000,0,2000,2000,0,2000);

   // h1_germergy_gate_160Eu_822_aida = new TH1D("h1_germergy_gated_aida_160Eu","h1_germergy_gated_aida_160Eu",2000,0,2000);
   // h2_aidagerm_decays_dssd1_160Eu = new TH2D("h2_aidagerm_decays_dssd1_160Eu","h2_aidagerm_decays_dssd1_160Eu",384,0,384,128,0,128);

   h1_aida_implant_decay_dt = new TH1D("h1_aida_implant_decay_dt","h1_aida_implant_decay_dt",1000,-1e6,1e6);

   
   fOutput->AddAll(gDirectory->GetList());

}

Bool_t bgam::Process(Long64_t entry)
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
   
   std::set<int> filled_germ{};
   std::set<int> filled_germ_down{};
   std::set<int> filled_germ_up{};
   std::set<int> filled_bplast{};
   std::set<int> filled_aida_1039{};
   std::set<int> filled_aida_822{};

   int bplastup = 0;
   int bplastdown = 0;

   // int spflag = 0;
   // int64_t onsptime;
   // int64_t lastSpillTime = 0; // Record the last time the spill flag was true

   // // Track spill information
   // if ((*EventHeader_fSpillFlag.Get())) {
   //    spflag = 1;
   //    lastSpillTime = getLastTimestamp(AidaImplantHits_Time);
   // }

   // if (!(*EventHeader_fSpillFlag.Get())) {
   //    int64_t currentImplantTime = getLastTimestamp(AidaImplantHits_Time);
   //    int64_t currentDecayTime = getLastTimestamp(AidaDecayHits_Time);
      
   //    // 400 ms = 400,000,000 ns
   //    if ((currentImplantTime - lastSpillTime < 400000000) || (currentDecayTime - lastSpillTime < 400000000)) {
   //       // Skip event
   //       return kTRUE;
   //    }
   // }

   // bplast checks
   for (int i = 0; i<bPlastTwinpeaksCalData_fabsolute_event_time.GetSize(); i++)
   {
      if (bPlastTwinpeaksCalData_fdetector_id[i] < 65)
      {
         bplastup = 1;
         // std::cout << "bPlastTwinpeaksCalData_fdetector_id[i]: " << bPlastTwinpeaksCalData_fdetector_id[i] << std::endl;
      }
      else if (bPlastTwinpeaksCalData_fdetector_id[i] >= 65 && bPlastTwinpeaksCalData_fdetector_id[i] < 129)
      {
         bplastdown = 1;
         // std::cout << "bPlastTwinpeaksCalData_fdetector_id[i]: " << bPlastTwinpeaksCalData_fdetector_id[i] << std::endl;
      }
   }


   // if (bPlastTwinpeaksCalData_fabsolute_event_time.GetSize() > 0 && GermaniumCalData_fabsolute_event_time.GetSize() > 0 && AidaDecayHits_Time.GetSize() > 0){
   //    for (int ib = 0; ib<bPlastTwinpeaksCalData_fabsolute_event_time.GetSize(); ib++){
   //       for (int ig = 0; ig<GermaniumCalData_fabsolute_event_time.GetSize(); ig++){
   //          if (bplastup == 1 && bplastdown == 1 && GermaniumCalData_fdetector_id.At(ig) <= 12){
   //             if (!(*EventHeader_fSpillFlag.Get())){
   //                h1_time_diff->Fill(((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));

   //                if ( ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) > 460 && ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) < 560){
   //                   if (bPlastTwinpeaksCalData_fslow_ToT.At(ib) > 900) continue;
   //                   if (filled_bplast.count(ib) == 0)  h1_bslow->Fill(bPlastTwinpeaksCalData_fslow_ToT.At(ib));
   //                   if (filled_germ.count(ig) == 0) {
   //                      h1_germergy->Fill(GermaniumCalData_fchannel_energy.At(ig));
   //                      for (int ig2 = 0; ig2<GermaniumCalData_fabsolute_event_time.GetSize(); ig2++){
   //                            if (ig2 == ig) continue;
   //                            if (TMath::Abs((int64_t)GermaniumCalData_fabsolute_event_time.At(ig) - (int64_t)GermaniumCalData_fabsolute_event_time.At(ig2))<250) {
   //                               if (GermaniumCalData_fchannel_energy.At(ig) > 1035 && GermaniumCalData_fchannel_energy.At(ig) < 1045){
   //                                  h1_germergy_gate->Fill(GermaniumCalData_fchannel_energy.At(ig2));
   //                               }
   //                               if (GermaniumCalData_fchannel_energy.At(ig) > 815 && GermaniumCalData_fchannel_energy.At(ig) < 826){
   //                                  h1_germergy_gate_160Eu_822->Fill(GermaniumCalData_fchannel_energy.At(ig2));
   //                               }

   //                               if (ig2 > ig) h2_germergy_germergy->Fill(GermaniumCalData_fchannel_energy.At(ig), GermaniumCalData_fchannel_energy.At(ig2));
   //                            }
   //                      }
   //                      if (GermaniumCalData_fchannel_energy.At(ig) > 1035 && GermaniumCalData_fchannel_energy.At(ig) < 1045){
   //                         // Loop over AIDA decays
   //                         for(int ia =0; ia<AidaDecayHits_Time.GetSize() ; ia++){
   //                            if(AidaDecayHits_DSSD.At(ia) == 1) h2_aida_decays_dssd1->Fill(AidaDecayHits_StripX[ia], AidaDecayHits_StripY[ia]);
   //                            if(AidaDecayHits_DSSD.At(ia) == 2) h2_aida_decays_dssd2->Fill(AidaDecayHits_StripX[ia], AidaDecayHits_StripY[ia]);
                              
   //                            // if (filled_aida_1039.count(ia) == 0) h1_aida_bplast_timediff->Fill(((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));
   //                            if (filled_aida_1039.count(ia) == 0) h1_aida_germanium_timediff->Fill(((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)));
   //                            filled_aida_1039.insert(ia);
   //                         }
   //                      }

   //                      if (GermaniumCalData_fchannel_energy.At(ig) > 815 && GermaniumCalData_fchannel_energy.At(ig) < 826){
   //                         // Loop over AIDA decays
   //                         for(int ia =0; ia<AidaDecayHits_Time.GetSize() ; ia++){
   //                            if(AidaDecayHits_DSSD.At(ia) == 1) h2_aida_decays_dssd1_160Eu->Fill(AidaDecayHits_StripX[ia], AidaDecayHits_StripY[ia]);
   //                            if(AidaDecayHits_DSSD.At(ia) == 2) h2_aida_decays_dssd2_160Eu->Fill(AidaDecayHits_StripX[ia], AidaDecayHits_StripY[ia]);
                              
   //                            if (filled_aida_822.count(ia) == 0) h1_aida_bplast_time_diff_160Eu->Fill(((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));
   //                            if (filled_aida_822.count(ia) == 0) h1_aida_germanium_time_diff_160Eu->Fill(((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)));
   //                            filled_aida_822.insert(ia);
   //                         }
   //                      }
   //                   }
   //                   filled_germ.insert(ig);
   //                   filled_bplast.insert(ib);
   //                }
   //             }
   //          }
   //          if(bplastup == 1 && bplastdown ==0 && GermaniumCalData_fdetector_id.At(ig) <= 12){
   //             if (!(*EventHeader_fSpillFlag.Get())){
   //                // h1_time_diff->Fill(((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));

   //                if ( ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) > 460 && ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) < 560){
   //                   // if (filled_bplast.count(ib) == 0)  h1_bslow->Fill(bPlastTwinpeaksCalData_fslow_ToT.At(ib));
   //                   if (bPlastTwinpeaksCalData_fslow_ToT.At(ib) > 900) continue;
   //                   if (filled_germ_up.count(ig) == 0) h1_germergy_up->Fill(GermaniumCalData_fchannel_energy.At(ig));
   //                   filled_germ_up.insert(ig);
   //                   // filled_bplast.insert(ib);
   //                }
   //             }
   //          }
   //          if(bplastdown == 1 && bplastup ==0 && GermaniumCalData_fdetector_id.At(ig) <= 12){
   //             if (!(*EventHeader_fSpillFlag.Get())){
   //                // h1_time_diff->Fill(((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));

   //                if ( ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) > 460 && ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) < 560){
   //                   // if (filled_bplast.count(ib) == 0)  h1_bslow->Fill(bPlastTwinpeaksCalData_fslow_ToT.At(ib));
   //                   if (bPlastTwinpeaksCalData_fslow_ToT.At(ib) > 900) continue;
   //                   if (filled_germ_down.count(ig) == 0) h1_germergy_down->Fill(GermaniumCalData_fchannel_energy.At(ig));
   //                   filled_germ_down.insert(ig);
   //                   // filled_bplast.insert(ib);
   //                }
   //             }
   //          }
   //       }
   //    }
   // }

   // Look at WR coincidence between bplast, germanium and AIDA
   std::set<int> filled_aidabplast{};
   std::set<int> filled_frs{};
   std::set<int> filled_aida_implants_166Tb{};
   std::set<int> filled_aida_implants_160Eu{};


   std::set<int> filled_germ2{};
   std::set<int> filled_germ3{};
   std:set<int> filled_germ4{};
   std::set<int> filled_aida2{};
   std::set<int> filled_aida3{};
   std::set<int> filled_aida4{};

   std::set<int> filled_aida35us{};
   std::set<int> filled_bplast1{};
   int aida_mult = 0;
   int aida1_mult = 0;
   int aida2_mult = 0;

   int bplast_mult = 0;
   int bplast_mult_count = 0;

   int germ_mult = 0;
   int germ_mult_count = 0;



   // if (bPlastTwinpeaksCalData_fabsolute_event_time.GetSize() > 0 && AidaDecayHits_Time.GetSize() > 0 && GermaniumCalData_fabsolute_event_time.GetSize() > 0){
   //    for (int ib = 0; ib<bPlastTwinpeaksCalData_fabsolute_event_time.GetSize(); ib++){
   //       for (int ia = 0; ia<AidaDecayHits_Time.GetSize(); ia++){
   //          for (int ig =0; ig<GermaniumCalData_fabsolute_event_time.GetSize(); ig++){
   //             if (!(*EventHeader_fSpillFlag.Get()) && bPlastTwinpeaksCalData_fdetector_id[ib] < 65 && AidaDecayHits_DSSD[ia] == 1){
   //                if(filled_aida3.count(ia) == 0) h1_aida_bplast_timediff->Fill(((int64_t)AidaDecayHits_Time.At(ia))-((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));
   //                filled_aidabplast.insert(ia);
   //                h1_bslow->Fill(bPlastTwinpeaksCalData_fslow_ToT[ib]);
   //             }
               
   //             if(!(*EventHeader_fSpillFlag.Get()) && bPlastTwinpeaksCalData_fdetector_id[ib] < 65 && filled_bplast1.count(ib) == 0 && GermaniumCalData_fdetector_id[ig] <= 12){
   //                if (bPlastTwinpeaksCalData_fslow_ToT[ib] > 900) continue;
   //                h1_time_diff->Fill(((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));
   //             }
   //             filled_bplast1.insert(ib);
   //             if(!(*EventHeader_fSpillFlag.Get()) && bPlastTwinpeaksCalData_fdetector_id[ib] < 65 && AidaDecayHits_DSSD[ia] == 1 && GermaniumCalData_fdetector_id[ig] <= 12){
   //                if ( ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) > 460 && ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)) < 560){
   //                   if (bPlastTwinpeaksCalData_fslow_ToT[ib] > 1000) continue;
   //                   if (bPlastTwinpeaksCalData_fslow_ToT[ib] < 300) continue;
   //                   if (filled_aida2.count(ia) == 0) h1_aida_germanium_timediff->Fill(((int64_t)AidaDecayHits_Time.At(ia))-((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)));
   //                   filled_aida2.insert(ia);
   //                   // gate on aida-germanium time diff
   //                   if (((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) > 12000 && ((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) < 20000){
   //                      if (TMath::Abs(AidaDecayHits_TimeX[ia] - AidaDecayHits_TimeY[ia]) > 2.1e3) continue; // FBdT < +/- 6 us
   //                      if (TMath::Abs(AidaDecayHits_EnergyX[ia] - AidaDecayHits_EnergyY[ia]) > 150) continue; // FBdE < 200 keV
   //                      if(filled_germ2.count(ig) == 0) h1_germergy_aida_bplast->Fill(GermaniumCalData_fchannel_energy.At(ig));
   //                      filled_germ2.insert(ig);
   //                      if (GermaniumCalData_fchannel_energy.At(ig) > 1035 && GermaniumCalData_fchannel_energy.At(ig) < 1045){
   //                         if(filled_aida4.count(ia) == 0) h2_aida_decays_dssd1->Fill(AidaDecayHits_StripX[ia], AidaDecayHits_StripY[ia]);
   //                         filled_aida4.insert(ia);
   //                      }
   //                   }
   //                }
   //             }
   //          }
   //       }
   //    }
   // }

   // Look at time difference between AIDA decays after an implant

   // if (AidaDecayHits_Time.GetSize() > 0 && AidaImplantHits_Time.GetSize() > 0){
      // Loop over implants
      // for(int i = 0; i<AidaImplantHits_Time.GetSize(); i++){
      //    // Loop over decays
      //    for(int j = 0; j<AidaDecayHits_Time.GetSize(); j++){
      //       // if(AidaDecayHits_DSSD[j] == 1 && AidaImplantHits_DSSD[i] == 1){
      //          h1_aida_implant_decay_dt->Fill(((long long)AidaDecayHits_Time.At(j)) - ((long long)AidaImplantHits_Time.At(i)));
      //       // }
      //       std::cout << "Decay time: " << AidaDecayHits_Time.At(j) << std::endl;
      //       std::cout << "Implant time: " << AidaImplantHits_Time.At(i) << std::endl;
      //    }
         
      // }
   // }

   // bPlast Germanium time diff offspill
   // if (bPlastTwinpeaksCalData_fabsolute_event_time.GetSize() > 0 && GermaniumCalData_fabsolute_event_time.GetSize() > 0){
   //    for (int ib = 0; ib<bPlastTwinpeaksCalData_fabsolute_event_time.GetSize(); ib++){
   //       for (int ig = 0; ig<GermaniumCalData_fabsolute_event_time.GetSize(); ig++){
   //          if (!(*EventHeader_fSpillFlag.Get()) && bPlastTwinpeaksCalData_fdetector_id[ib] < 65 && GermaniumCalData_fdetector_id[ig] <= 12){
   //             if (bPlastTwinpeaksCalData_fslow_ToT[ib] > 900) continue;
   //             h1_time_diff->Fill(((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));
   //          }
   //       }
   //    }
   // }

   // Germanium AIDA decays offspill

   // if(GermaniumCalData_fabsolute_event_time.GetSize() > 0 && AidaDecayHits_Time.GetSize() > 0){
   //    for (int ig = 0; ig<GermaniumCalData_fabsolute_event_time.GetSize(); ig++){
   //       if(germ_mult == 0 && GermaniumCalData_fdetector_id.At(ig) <= 12 && !(*EventHeader_fSpillFlag.Get())){
   //          germ_mult_count++;
   //       }
   //       for(int ia = 0; ia<AidaDecayHits_Time.GetSize(); ia++){
   //          if (GermaniumCalData_fdetector_id.At(ig) <= 12){
   //             if (!(*EventHeader_fSpillFlag.Get())){
   //                // if(filled_germ2.count(ig) == 0) h1_germ_multiplicity->Fill(GermaniumCalData_fabsolute_event_time.GetSize()); // this is wrong

   //                // if (TMath::Abs(AidaDecayHits_TimeX[ia] - AidaDecayHits_TimeY[ia]) > 6e3) continue; // FBdT < +/- 6 us
   //                if (TMath::Abs(AidaDecayHits_EnergyX[ia] - AidaDecayHits_EnergyY[ia]) > 150) continue; // FBdE < 200 keV
   //                if(filled_germ4.count(ig) == 0 && AidaDecayHits_Time.GetSize() < 8){
   //                   h1_aida_germanium_timediff_only->Fill(((int64_t)AidaDecayHits_Time.At(ia))-((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)));
   //                   h2_germergy_germergy_aida_dt->Fill(((int64_t)AidaDecayHits_Time[ia]) - ((int64_t)GermaniumCalData_fabsolute_event_time[ig]),GermaniumCalData_fchannel_energy.At(ig));
   //                   h2_aida_decays_vs_aidagermdt->Fill(((int64_t)AidaDecayHits_Time[ia]) - ((int64_t)GermaniumCalData_fabsolute_event_time[ig]),AidaDecayHits_Energy[ia]);
   //                }
   //                filled_germ4.insert(ig);
   //                if(bPlastTwinpeaksCalData_fabsolute_event_time.GetSize() > 0){
   //                   for(int ib = 0; ib < bPlastTwinpeaksCalData_fabsolute_event_time.GetSize(); ib++){
   //                      if(!(*EventHeader_fSpillFlag.Get()) && bPlastTwinpeaksCalData_fdetector_id[ib] < 65){
   //                         if(bplast_mult == 0 ){
   //                            bplast_mult_count++;
   //                            // h1_bplast_multiplicity->Fill(bPlastTwinpeaksCalData_fabsolute_event_time.GetSize()); // this is wrong 
   //                         }
   //                         if(filled_bplast.count(ib) == 0){
   //                            // h1_aida_bplast_timediff->Fill(((int64_t)AidaDecayHits_Time.At(ia))-((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));
   //                            h2_aida_decays_vs_aidabplastdt->Fill(((int64_t)AidaDecayHits_Time[ia]) - ((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time[ib]),AidaDecayHits_Energy[ia]);

   //                            h1_time_diff->Fill(((int64_t)GermaniumCalData_fabsolute_event_time.At(ig))-((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time.At(ib)));
   //                         }
   //                         filled_bplast.insert(ib);
   //                      }
   //                   }
   //                   if(bplast_mult == 0 && bplast_mult_count > 0) h1_bplast_multiplicity->Fill(bplast_mult_count);
   //                   bplast_mult = 1;
   //                }
   //                if (((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) > 14458 && ((int64_t)AidaDecayHits_Time.At(ia)) - ((int64_t)GermaniumCalData_fabsolute_event_time.At(ig)) < 16458){
                     
   //                   if(AidaDecayHits_DSSD.At(ia) == 2) continue; // DSSSD 1 for now
   //                   if (GermaniumCalData_fchannel_energy.At(ig) > 1035 && GermaniumCalData_fchannel_energy.At(ig) < 1045){
   //                      if (aida_mult == 0){
   //                         if(AidaDecayHits_DSSD[ia] == 1) aida1_mult++;
   //                         if(AidaDecayHits_DSSD[ia] == 2) aida2_mult++;
   //                      }
   //                      // Find distance using positions between each pair of AIDA decays
   //                      for (int ia2 = 0; ia2<AidaDecayHits_Time.GetSize(); ia2++){
   //                         if (ia2 == ia) continue;
   //                         if (TMath::Abs((int64_t)AidaDecayHits_Time[ia] - (int64_t)AidaDecayHits_Time[ia2])<250) {
   //                            if (ia2 > ia) h1_aida_decay_distance->Fill(TMath::Sqrt(TMath::Power(AidaDecayHits_StripX[ia] - AidaDecayHits_StripX[ia2],2) + TMath::Power(AidaDecayHits_StripY[ia] - AidaDecayHits_StripY[ia2],2)));
   //                         }
   //                      }

   //                   }

                     
   //                   // if (TMath::Abs(AidaDecayHits_EnergyX[ia] - AidaDecayHits_EnergyY[ia]) > 50) continue; // FBdE < 200 keV
   //                   if (filled_germ2.count(ig) == 0) {
   //                      h1_germergy_aida->Fill(GermaniumCalData_fchannel_energy.At(ig));
   //                      h2_bplastmult_vs_germergy->Fill(bplast_mult_count,GermaniumCalData_fchannel_energy.At(ig));
   //                      for (int ig2 = 0; ig2<GermaniumCalData_fabsolute_event_time.GetSize(); ig2++){
   //                         if (ig2 == ig) continue;
   //                         if (TMath::Abs((int64_t)GermaniumCalData_fabsolute_event_time.At(ig) - (int64_t)GermaniumCalData_fabsolute_event_time.At(ig2))<250) {
   //                            if (ig2 > ig) h2_germergy_germergy_aida->Fill(GermaniumCalData_fchannel_energy.At(ig), GermaniumCalData_fchannel_energy.At(ig2));
   //                            if(GermaniumCalData_fchannel_energy.At(ig) > 1035 && GermaniumCalData_fchannel_energy.At(ig) < 1045){
   //                               h1_germergy_gated_aida->Fill(GermaniumCalData_fchannel_energy.At(ig2));
   //                            }
   //                            if(GermaniumCalData_fchannel_energy.At(ig) > 815 && GermaniumCalData_fchannel_energy.At(ig) < 826){
   //                               h1_germergy_gate_160Eu_822_aida->Fill(GermaniumCalData_fchannel_energy.At(ig2));
   //                            }
   //                         }
   //                      }
   //                   }
   //                   filled_germ2.insert(ig); // add germanium fill tracker
   //                   if(filled_aida2.count(ia) == 0){
   //                      h2_aida_frontbackenergy->Fill(AidaDecayHits_EnergyX[ia], AidaDecayHits_EnergyY[ia]);
   //                      h1_aida_frontbacktime->Fill(AidaDecayHits_TimeX[ia] - AidaDecayHits_TimeY[ia]);
   //                      if (GermaniumCalData_fchannel_energy.At(ig) > 1035 && GermaniumCalData_fchannel_energy.At(ig) < 1045){
   //                         if(AidaDecayHits_DSSD.At(ia) == 1 && AidaDecayHits_ClusterSizeX[ia] == 1 && AidaDecayHits_ClusterSizeY[ia] == 1){
   //                               h2_aidagerm_decays_dssd1->Fill(AidaDecayHits_StripX[ia], AidaDecayHits_StripY[ia]);
   //                               h2_aida_frontbackenergy_166Tb->Fill(AidaDecayHits_EnergyX[ia], AidaDecayHits_EnergyY[ia]);
   //                               h1_aida_frontbacktime_166Tb->Fill(AidaDecayHits_TimeX[ia] - AidaDecayHits_TimeY[ia]);
   //                               h1_aida_clusterx->Fill(AidaDecayHits_ClusterSizeX[ia]);
   //                               h1_aida_clustery->Fill(AidaDecayHits_ClusterSizeY[ia]);
   //                         } 
   //                      }
   //                      if(GermaniumCalData_fchannel_energy.At(ig) > 815 && GermaniumCalData_fchannel_energy.At(ig) < 826){
   //                         if(AidaDecayHits_DSSD.At(ia) == 1 && AidaDecayHits_ClusterSizeX[ia] == 1 && AidaDecayHits_ClusterSizeY[ia] == 1){
   //                            h2_aidagerm_decays_dssd1_160Eu->Fill(AidaDecayHits_StripX[ia], AidaDecayHits_StripY[ia]);
   //                            h2_aida_frontbackenergy_160Eu->Fill(AidaDecayHits_EnergyX[ia], AidaDecayHits_EnergyY[ia]);
   //                            h1_aida_frontbacktime_160Eu->Fill(AidaDecayHits_TimeX[ia] - AidaDecayHits_TimeY[ia]);
   //                         } 
   //                      }
   //                   }
   //                   filled_aida2.insert(ia); // add aida fill tracker
   //                } // prompt time condition
   //                else{
   //                   if (AidaDecayHits_DSSD.At(ia) == 2) continue; // DSSSD 1 for now
   //                   if (filled_germ3.count(ig) == 0) {
   //                      h1_germergy_aida_noprompt->Fill(GermaniumCalData_fchannel_energy.At(ig));       
   //                   }
   //                   filled_germ3.insert(ig); // add germanium fill tracker
   //                }
   //             } // off spill
   //          } // relevant germanium detectors
   //       } // aida decay loop
   //       if(!(*EventHeader_fSpillFlag.Get()) && aida_mult == 0){
   //          if(aida1_mult > 0) h1_aida1_multiplicity->Fill(aida1_mult);
   //          if(aida2_mult > 0) h1_aida2_multiplicity->Fill(aida2_mult);
   //          aida_mult = 1; //ensures we check the multiplicity only once
   //       }
   //    } // germanium loop
   //    if(germ_mult == 0 && germ_mult_count > 0) h1_germ_multiplicity->Fill(germ_mult_count); // germ_mult_count = 0 represents on spill hits
   //    germ_mult = 1;
   // } // germanium and aida decay size check



   return kTRUE;
}

void bgam::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void bgam::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   TString option = GetOption();
   TFile hfile (option, "RECREATE", "Analysis results");
   fOutput->Write();


}