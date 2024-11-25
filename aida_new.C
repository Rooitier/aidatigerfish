#define aida_new_cxx
// The class definition in aida_new.h has been generated automatically
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
// root> T->Process("aida_new.C")
// root> T->Process("aida_new.C","some options")
// root> T->Process("aida_new.C+")
//


#include "aida_new.h"
#include <TH2.h>
#include <TStyle.h>


// Histograms

TH2F* aida_strip_multiplicity;
TH2F* aida_strip_x_energy;
TH2F* aida_strip_y_energy;
TH2F* aida_front_back_energy_dssd1;
TH1F*  aida_cluster_x;
TH1F*  aida_cluster_y;
TH2F* aida_cluster_xy;

TH1F* aida_fb_time_offspill;
TH1F* aida_fb_time_onspill;

TH1F* aida_cluster_implant_x;
TH1F* aida_cluster_implant_y;
TH2F* aida_cluster_implant_xy;


TH1F* aida_degas_wr_time_diff_offspill;
TH1F* aida_degas_wr_time_diff_onspill;

TH1F* germanium_frs_wr_time_diff_offspill;
TH1F* germanium_frs_wr_time_diff_onspill;

TH1F* aida_frs_wr_time_diff_offspill;
TH1F* aida_frs_wr_time_diff_onspill;

TH1F* degas_bplast_wr_time_diff_offspill;
TH1F* degas_bplast_wr_time_diff_onspill;

void aida_new::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void aida_new::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   aida_strip_multiplicity = new TH2F("aida_strip_multiplicity", "AIDA Strip Multiplicity X Y", 384, 0, 384, 384, 0, 384);

   aida_strip_x_energy = new TH2F("aida_strip_x_energy", "AIDA Strip X Energy", 384, 0, 384, 1.5e3, 0, 1.5e4);

   aida_strip_y_energy = new TH2F("aida_strip_y_energy", "AIDA Strip Y Energy", 128, 0, 128, 1.5e3, 0, 1.5e4);

   aida_front_back_energy_dssd1 = new TH2F("aida_front_back_energy_dssd1", "AIDA Front Back Energy DSSD1", 1e3, 0, 1e4, 1e3, 0, 1e4);

   aida_cluster_x = new TH1F("aida_cluster_x", "AIDA Cluster X", 384, 0, 384);

   aida_cluster_y = new TH1F("aida_cluster_y", "AIDA Cluster Y", 128, 0, 128);

   aida_cluster_xy = new TH2F("aida_cluster_xy", "AIDA Cluster XY", 384, 0, 384, 128, 0, 128);

   aida_fb_time_offspill = new TH1F("aida_fb_time_offspill", "AIDA Front Back Time Offspill", 1e3, -8e4, 8e4);

   aida_fb_time_onspill = new TH1F("aida_fb_time_onspill", "AIDA Front Back Time Onspill", 1e3, -8e4, 8e4);

   aida_cluster_implant_x = new TH1F("aida_cluster_implant_x", "AIDA Cluster Implant X", 384, 0, 384);

   aida_cluster_implant_y = new TH1F("aida_cluster_implant_y", "AIDA Cluster Implant Y", 128, 0, 128);

   aida_cluster_implant_xy = new TH2F("aida_cluster_implant_xy", "AIDA Cluster Implant XY", 384, 0, 384, 128, 0, 128);

   aida_degas_wr_time_diff_offspill = new TH1F("aida_degas_wr_time_diff_offspill", "AIDA Degas WR Time Difference Offspill", 1e3, -8e4, 8e4);

   aida_degas_wr_time_diff_onspill = new TH1F("aida_degas_wr_time_diff_onspill", "AIDA Degas WR Time Difference Onspill", 1e3, -8e4, 8e4);

   germanium_frs_wr_time_diff_offspill = new TH1F("germanium_frs_wr_time_diff_offspill", "Germanium FRS WR Time Difference Offspill", 1e3, -8e4, 8e4);

   germanium_frs_wr_time_diff_onspill = new TH1F("germanium_frs_wr_time_diff_onspill", "Germanium FRS WR Time Difference Onspill", 1e3, -8e4, 8e4);

   aida_frs_wr_time_diff_offspill = new TH1F("aida_frs_wr_time_diff_offspill", "AIDA FRS WR Time Difference Offspill", 1e3, -8e4, 8e4);

   aida_frs_wr_time_diff_onspill = new TH1F("aida_frs_wr_time_diff_onspill", "AIDA FRS WR Time Difference Onspill", 1e3, -8e4, 8e4);

   degas_bplast_wr_time_diff_offspill = new TH1F("degas_bplast_wr_time_diff_offspill", "Degas BPlast WR Time Difference Offspill", 1e3, -8e4, 8e4);

   degas_bplast_wr_time_diff_onspill = new TH1F("degas_bplast_wr_time_diff_onspill", "Degas BPlast WR Time Difference Onspill", 1e3, -8e4, 8e4);

   fOutput->AddAll(gDirectory->GetList());

}

Bool_t aida_new::Process(Long64_t entry)
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

   int64_t degas_time = 0;
   int64_t aida_decay_time = 0;
   int64_t frs_time = 0;

   int aidaimplanthits = AidaImplantHits_Time.GetSize();
   int aidadecayhits = AidaDecayHits_Time.GetSize();
   int frshits = FrsHitData_fwr_t.GetSize();
   int germaniumhits = GermaniumAnlData_fwr_t.GetSize();

   double strip_mult_x = AidaDecayHits_StripX.GetSize();
   double strip_mult_y = AidaDecayHits_StripY.GetSize();

   aida_strip_multiplicity->Fill(strip_mult_x, strip_mult_y);

   if(aidadecayhits > 0){
      for(int i = 0; i < aidadecayhits; i++){
         if(AidaDecayHits_DSSD[i] != 1) continue;

         aida_strip_x_energy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_EnergyX[i]);
         aida_strip_y_energy->Fill(AidaDecayHits_StripY[i], AidaDecayHits_EnergyY[i]);
         
         aida_cluster_x->Fill(AidaDecayHits_ClusterSizeX[i]);
         aida_cluster_y->Fill(AidaDecayHits_ClusterSizeY[i]);
         aida_cluster_xy->Fill(AidaDecayHits_ClusterSizeX[i], AidaDecayHits_ClusterSizeY[i]);

         if(TMath::Abs(AidaDecayHits_EnergyX[i] - AidaDecayHits_EnergyY[i]) < 50){
            aida_front_back_energy_dssd1->Fill(AidaDecayHits_EnergyX[i], AidaDecayHits_EnergyY[i]);
         }

         if(*EventHeader_fSpillFlag == false) aida_fb_time_offspill->Fill(AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i]);
         if(*EventHeader_fSpillFlag == true) aida_fb_time_onspill->Fill(AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[i]);
      }

   }

   if(aidaimplanthits > 0){
      for(int i = 0; i < aidaimplanthits; i++){
         if(AidaImplantHits_DSSD[i] != 1) continue;

         aida_cluster_implant_x->Fill(AidaImplantHits_ClusterSizeX[i]);
         aida_cluster_implant_y->Fill(AidaImplantHits_ClusterSizeY[i]);
         aida_cluster_implant_xy->Fill(AidaImplantHits_ClusterSizeX[i], AidaImplantHits_ClusterSizeY[i]);
      }
   }

   if(germaniumhits >0 && frshits > 0){
      for(int i = 0; i < germaniumhits; i++){
         degas_time = GermaniumAnlData_fwr_t[i];
         for(int j = 0; j < frshits; j++){
            frs_time = FrsHitData_fwr_t[j];
            if(*EventHeader_fSpillFlag == false) germanium_frs_wr_time_diff_offspill->Fill(degas_time - frs_time);
            if(*EventHeader_fSpillFlag == true) germanium_frs_wr_time_diff_onspill->Fill(degas_time - frs_time);
         }
      }
      
   }





   return kTRUE;
}

void aida_new::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void aida_new::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   TString option = GetOption();
   TFile hfile (option, "RECREATE", "Analysis results");
   fOutput->Write();

}