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

TH1F* sc41_hits;

//Decays
TH2F* aida_decays_strip_xy_onspill;
TH2F* aida2_decays_strip_xy_onspill;

TH2F* aida_decays_strip_xy_offspill;
TH2F* aida2_decays_strip_xy_offspill;

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


TH2F* frs_zvsaoq;
TH2F* frs_z1vsz2;
TH2F* frs_x2vsz1;
TH2F* frs_x4vsz2;
TH2F* frs_z1vsdE;
TH2F* frs_x2vsx4;

uint64_t wr_experiment_start = 1.71420318e+18;
uint64_t wr_experiment_end = 1.71420372e+18;
int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e3;
int64_t slices_every = 20; //us
int64_t number_of_slices = duration_in_seconds/slices_every;

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

   sc41_hits = new TH1F("sc41_hits", "SC41 hits", number_of_slices, 0, duration_in_seconds);


   // Decays
   aida_decays_strip_xy_onspill = new TH2F("aida_decays_xy_onspill", "AIDA Decays XY DSSSD 1 Onspill", 386, 0, 386, 128, 0, 128);
   aida2_decays_strip_xy_onspill = new TH2F("aida2_decays_xy_onspill", "AIDA Decays XY DSSSD 2 Onspill", 386, 0, 386, 128, 0, 128);

   aida_decays_strip_xy_offspill = new TH2F("aida_decays_xy_offspill", "AIDA Decays XY DSSSD 1 Offspill", 386, 0, 386, 128, 0, 128);
   aida2_decays_strip_xy_offspill = new TH2F("aida2_decays_xy_offspill", "AIDA Decays XY DSSSD 2 Offspill", 386, 0, 386, 128, 0, 128);

   implant_rate = new TH1F("implant_rate", "Implant rate", number_of_slices, 0, duration_in_seconds);
   decay_rate_onspill = new TH1F("decay_rate_onspill", "Decay rate onspill", number_of_slices, 0, duration_in_seconds);
   decay_rate_offspill = new TH1F("decay_rate_offspill", "Decay rate offspill", number_of_slices, 0, duration_in_seconds);

   aida_x_decays = new TH1F("aida_x_decays", "AIDA X Decays", 386, 0,386);
   aida_y_decays = new TH1F("aida_y_decays", "AIDA Y Decays", 128, 0,128);

   aida2_x_decays = new TH1F("aida2_x_decays", "AIDA2 X Decays", 386, 0,386);
   aida2_y_decays = new TH1F("aida2_y_decays", "AIDA2 Y Decays", 128, 0,128);

   aida_decays_time_xy = new TH1F("aida_decays_time_xy", "AIDA Decays XY Time", 1e3,-5e3,5e3);
   aida2_decays_time_xy = new TH1F("aida2_decays_time_xy", "AIDA2 Decays XY Time", 1e3,-5e3,5e3);

   aida_decay_energy_xy = new TH2F("aida_decay_energy_xy", "AIDA Decay Energy XY", 1e3, 0, 1e4, 1e3, 0, 1e4);
   aida2_decay_energy_xy = new TH2F("aida2_decay_energy_xy", "AIDA2 Decay Energy XY", 1e3, 0, 1e4, 1e3, 0, 1e4);

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
   int aida_decay_counter_onspill = 0;
   int aida_decay_counter_offspill = 0;
   int aida_implant_counter = 0;
   int sc41counter = 0;


   // make a map for the AIDA implants hits where I save the whiterabbit time of the implants and x-y strip position


   int frshits = FrsHitData_fwr_t.GetSize();
   int aidaimphits = AidaImplantHits_Time.GetSize();
   int aidadecayhits = AidaDecayHits_Time.GetSize();

   for (int i =0; i < frshits; i++)
   {
      if(cutg->IsInside(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(i)) && cutg1->IsInside(FrsHitData_fID_AoQ_corr.At(i), FrsHitData_fID_z.At(i)))
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
               aida_implants_strip_xy->Fill(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
               aida_implant_counter++;
            }
            if(AidaImplantHits_DSSD[j] == 2 && AidaImplantHits_Stopped[j] == true)
            {
               aida2_implants_strip_xy->Fill(AidaImplantHits_StripX[j], AidaImplantHits_StripY[j]);
            }
         }
      }

      // sc41 counter
      if (*EventHeader_fSpillFlag == true)
      {
         sc41counter++;
      }

   }

   // Decays

   // on and off spill decays

   for(int i = 0; i < aidadecayhits; i++)
   {
      if(AidaDecayHits_DSSD[i] == 1)
      {
         aida_x_decays->Fill(AidaDecayHits_StripX[i]);
         aida_y_decays->Fill(AidaDecayHits_StripY[i]);
      }
      if(AidaDecayHits_DSSD[i] == 2)
      {
         aida2_x_decays->Fill(AidaDecayHits_StripX[i]);
         aida2_y_decays->Fill(AidaDecayHits_StripY[i]);
      }
      if(*EventHeader_fSpillFlag == true){
         if(AidaDecayHits_DSSD[i] == 1)
         {
            aida_decays_strip_xy_onspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
            aida_decay_counter_onspill++;
         }
         if(AidaDecayHits_DSSD[i] == 2)
         {
            aida2_decays_strip_xy_onspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
         }
      }
      if(*EventHeader_fSpillFlag == false){
         if(AidaDecayHits_DSSD[i] == 1)
         {
            aida_decays_strip_xy_offspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
            aida_decay_counter_offspill++;
         }
         if(AidaDecayHits_DSSD[i] == 2)
         {
            aida2_decays_strip_xy_offspill->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
         }
      }

      if(AidaDecayHits_DSSD[i] == 1){
         aida_decays_time_xy->Fill(AidaDecayHits_TimeX[i]- AidaDecayHits_TimeY[i]);
         aida_decay_energy_xy->Fill(AidaDecayHits_EnergyX[i], AidaDecayHits_EnergyY[i]);
      }

      if(AidaDecayHits_DSSD[i] == 2){
         aida2_decays_time_xy->Fill(AidaDecayHits_TimeX[i]- AidaDecayHits_TimeY[i]);
         aida2_decay_energy_xy->Fill(AidaDecayHits_EnergyX[i], AidaDecayHits_EnergyY[i]);
      }
   }

   if (frshits > 0){
      uint64_t wrt = FrsHitData_fwr_t.At(0);
      int64_t time_millisec = (wrt - wr_experiment_start)/1e3;
      // int64_t time_sec = (wrt - wr_experiment_start)/1e9;
      decay_rate_offspill->Fill(time_millisec, aida_decay_counter_offspill);
      decay_rate_onspill->Fill(time_millisec, aida_decay_counter_onspill);
      implant_rate->Fill(time_millisec, aida_implant_counter);
      sc41_hits->Fill(time_millisec, sc41counter);
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
   // decay_rate_offspill->Draw("HIST");
   // decay_rate_onspill->Draw("HIST");
   // implant_rate->Draw("HIST");
   TFile hfile (option, "RECREATE", "Analysis results");
   fOutput->Write();

}