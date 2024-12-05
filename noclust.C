#define noclust_cxx
// The class definition in noclust.h has been generated automatically
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
// root> T->Process("noclust.C")
// root> T->Process("noclust.C","some options")
// root> T->Process("noclust.C+")
//


#include "noclust.h"
#include <TH2.h>
#include <TStyle.h>

TH2D* aida_decays_xy;
TH2D* aida_decay_frontback;
TH2D* aida_implant_xy;
TH2D* aida_implant_frontback;

TH2D* aida_decay_mult_x_y;
TH2D* aida_implant_mult_x_y;

TH2D* aida_decay_mult_x_vs_ex;
TH2D* aida_implant_mult_x_vs_ex;

TH2D* aida_decay_mult_y_vs_ey;
TH2D* aida_implant_mult_y_vs_ey;

TH1D* bplast_rates_every_1s;
TH1D* bplast_rates_every_1s_down;
TH1D* bplast_slow;
TH1D* bplast_fast;

TH1D* bplast_slow_down;
TH1D* bplast_fast_down;

TH1D* bplast_channels;

TH1D* bplast_fast_gated_onspill;
TH1D* bplast_fast_gated_offspill;
TH1D* bplast_slow_gated_onspill;
TH1D* bplast_slow_gated_offspill;

TH1D* bplast_fast_gated_onspill_down;
TH1D* bplast_fast_gated_offspill_down;
TH1D* bplast_slow_gated_onspill_down;
TH1D* bplast_slow_gated_offspill_down;

TH1D* bplast_fast_gated_down;
TH1D* bplast_slow_gated_down;

TH2D * bplast_fast_vs_slow[65];
TH2D * bplast_fast_vs_slow_down[65];
TH2D * bplast_fast_vs_slow_all;
TH2D * bplast_fast_vs_slow_all_down;

TH1D* bplast_aida_wr_dt;

TH1D* bplast_fast_onspill_wrgated;
TH1D* bplast_slow_onspill_wrgated;

TH1D* bplast_fast_offspill_wrgated;
TH1D* bplast_slow_offspill_wrgated;

TH1D* bplast_fast_onspill_wrgated_down;
TH1D* bplast_slow_onspill_wrgated_down;

TH1D* bplast_fast_offspill_wrgated_down;
TH1D* bplast_slow_offspill_wrgated_down;

TH2D* bplast_fast_vs_slow_wrgated_onspill;
TH2D* bplast_fast_vs_slow_wrgated_down_onspill;

TH2D* bplast_fast_vs_slow_wrgated_offspill;
TH2D* bplast_fast_vs_slow_wrgated_down_offspill;

uint64_t wr_experiment_start = 1.7137464e+18;
uint64_t wr_experiment_end = 1.7143668e+18;
int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
int64_t slices_every = 1; //s
int64_t number_of_slices = duration_in_seconds/slices_every;

void noclust::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void noclust::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   aida_decays_xy = new TH2D("aida_decays_xy","aida_decays_xy",384,0,384,128,0,128);
   aida_decay_frontback = new TH2D("aida_decay_frontback","aida_decay_frontback",1e3,0,10e3,1e3,0,10e3);
   aida_implant_xy = new TH2D("aida_implant_xy","aida_implant_xy",384,0,384,128,0,128);
   aida_implant_frontback = new TH2D("aida_implant_frontback","aida_implant_frontback",1e3,0,10e3,1e3,0,10e3);

   aida_decay_mult_x_y = new TH2D("aida_decay_mult_x_y","aida_decay_mult_x_y",500,0,500,500,0,500);
   aida_implant_mult_x_y = new TH2D("aida_implant_mult_x_y","aida_implant_mult_x_y",500,0,500,500,0,500);

   aida_decay_mult_x_vs_ex = new TH2D("aida_decay_mult_x_vs_ex","aida_decay_mult_x_vs_ex",500,0,500,500,0,500);
   aida_implant_mult_x_vs_ex = new TH2D("aida_implant_mult_x_vs_ex","aida_implant_mult_x_vs_ex",500,0,500,500,0,500);

   aida_decay_mult_y_vs_ey = new TH2D("aida_decay_mult_y_vs_ey","aida_decay_mult_y_vs_ey",500,0,500,1e3,0,10e3);
   aida_implant_mult_y_vs_ey = new TH2D("aida_implant_mult_y_vs_ey","aida_implant_mult_y_vs_ey",500,0,500,1e3,0,10e3);

   bplast_rates_every_1s = new TH1D("bplast_rates_every_1s","bplast_rates_every_1s",number_of_slices,0,duration_in_seconds);
   bplast_slow = new TH1D("bplast_slow","bplast_slow",3000,0,3000);
   bplast_fast = new TH1D("bplast_fast","bplast_fast",3000,0,3000);

   bplast_slow_down = new TH1D("bplast_slow_down","bplast_slow_down",3000,0,3000);
   bplast_fast_down = new TH1D("bplast_fast_down","bplast_fast_down",3000,0,3000);

   bplast_channels = new TH1D("bplast_channels","bplast_channels",129,0,129);

   bplast_rates_every_1s_down = new TH1D("bplast_rates_every_1s_down","bplast_rates_every_1s_down",number_of_slices,0,duration_in_seconds);

   bplast_fast_gated_onspill = new TH1D("bplast_fast_gated_onspill","bplast_gated",3000,0,3000);
   bplast_fast_gated_offspill = new TH1D("bplast_fast_gated_offspill","bplast_gated",3000,0,3000);
   bplast_slow_gated_onspill = new TH1D("bplast_slow_gated_onspill","bplast_slow_gated",3000,0,3000);
   bplast_slow_gated_offspill = new TH1D("bplast_slow_gated_offspill","bplast_slow_gated",3000,0,3000);

   bplast_fast_gated_onspill_down = new TH1D("bplast_fast_gated_onspill_down","bplast_gated",3000,0,3000);
   bplast_fast_gated_offspill_down = new TH1D("bplast_fast_gated_offspill_down","bplast_gated",3000,0,3000);
   bplast_slow_gated_onspill_down = new TH1D("bplast_slow_gated_onspill_down","bplast_slow_gated",3000,0,3000);
   bplast_slow_gated_offspill_down = new TH1D("bplast_slow_gated_offspill_down","bplast_slow_gated",3000,0,3000);

   bplast_fast_gated_down = new TH1D("bplast_fast_gated_down","bplast_gated_down",3000,0,3000);
   bplast_slow_gated_down = new TH1D("bplast_slow_gated_down","bplast_slow_gated_down",3000,0,3000);

   // for(int i = 1; i < 65; i++) {
   //    bplast_fast_vs_slow[i] = new TH2D(Form("bplast_fast_vs_slow_%d",i),Form("bplast_fast_vs_slow_%d",i),3000,0,3000,3000,0,3000);
   //    bplast_fast_vs_slow_down[i] = new TH2D(Form("bplast_fast_vs_slow_down_%d",i),Form("bplast_fast_vs_slow_down_%d",i),3000,0,3000,3000,0,3000);
   // }

   bplast_fast_vs_slow_all = new TH2D("bplast_fast_vs_slow_all","bplast_fast_vs_slow_all",3000,0,3000,3000,0,3000);

   bplast_fast_vs_slow_all_down = new TH2D("bplast_fast_vs_slow_all_down","bplast_fast_vs_slow_all_down",3000,0,3000,3000,0,3000);

   bplast_aida_wr_dt = new TH1D("bplast_aida_wr_dt","bplast_aida_wr_dt",1000,-8e4,8e4);

   bplast_fast_onspill_wrgated = new TH1D("bplast_fast_onspill_wrgated","bplast_fast_onspill_wrgated",3000,0,3000);
   bplast_slow_onspill_wrgated = new TH1D("bplast_slow_onspill_wrgated","bplast_slow_onspill_wrgated",3000,0,3000);

   bplast_fast_offspill_wrgated = new TH1D("bplast_fast_offspill_wrgated","bplast_fast_offspill_wrgated",3000,0,3000);
   bplast_slow_offspill_wrgated = new TH1D("bplast_slow_offspill_wrgated","bplast_slow_offspill_wrgated",3000,0,3000);

   bplast_fast_onspill_wrgated_down = new TH1D("bplast_fast_onspill_wrgated_down","bplast_fast_onspill_wrgated",3000,0,3000);
   bplast_slow_onspill_wrgated_down = new TH1D("bplast_slow_onspill_wrgated_down","bplast_slow_onspill_wrgated",3000,0,3000);

   bplast_fast_offspill_wrgated_down = new TH1D("bplast_fast_offspill_wrgated_down","bplast_fast_offspill_wrgated",3000,0,3000);
   bplast_slow_offspill_wrgated_down = new TH1D("bplast_slow_offspill_wrgated_down","bplast_slow_offspill_wrgated",3000,0,3000);

   bplast_fast_vs_slow_wrgated_onspill = new TH2D("bplast_fast_vs_slow_wrgated_onspill","bplast_fast_vs_slow_wrgated_onspill",3000,0,3000,3000,0,3000);
   bplast_fast_vs_slow_wrgated_down_onspill = new TH2D("bplast_fast_vs_slow_wrgated_down_onspill","bplast_fast_vs_slow_wrgated_down_onspill",3000,0,3000,3000,0,3000);

   bplast_fast_vs_slow_wrgated_offspill = new TH2D("bplast_fast_vs_slow_wrgated_offspill","bplast_fast_vs_slow_wrgated_offspill",3000,0,3000,3000,0,3000);
   bplast_fast_vs_slow_wrgated_down_offspill = new TH2D("bplast_fast_vs_slow_wrgated_down_offspill","bplast_fast_vs_slow_wrgated_down_offspill",3000,0,3000,3000,0,3000);


   fOutput->AddAll(gDirectory->GetList());
}

Bool_t noclust::Process(Long64_t entry)
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

   

   int decayhits = AidaDecayHits_Time.GetSize();
   int implanthits = AidaImplantHits_Time.GetSize();
   int decayhitsx = AidaDecayHits_StripX.GetSize();
   int decayhitsy = AidaDecayHits_StripY.GetSize();
   int implanthitsx = AidaImplantHits_StripX.GetSize();
   int implanthitsy = AidaImplantHits_StripY.GetSize();

   int bplasthits = bPlastTwinpeaksCalData_fabsolute_event_time.GetSize();

   int aida_strip_x = 0;
   int aida_strip_y = 0;

   int aida_implant_x = 0;
   int aida_implant_y = 0;

   // Loop over aida cal adc items

   for(int i = 0; i < AidaDecayCalAdcData_strip.GetSize(); i++) {
      if(AidaDecayCalAdcData_dssd[i] == 2) continue;
      if(!(*EventHeader_fSpillFlag.Get())) continue; // spill condition ! off spill * on spill
      if(AidaDecayCalAdcData_side[i] == -1) {
         aida_strip_x++;
      }
      if(AidaDecayCalAdcData_side[i] == 1) {
         aida_strip_y++;
      }
   }

   for(int i = 0; i < AidaImplantCalAdcData_strip.GetSize(); i++) {
      if(AidaImplantCalAdcData_dssd[i] == 2) continue;
      if(!(*EventHeader_fSpillFlag.Get())) continue;
      if(AidaImplantCalAdcData_side[i] == -1) {
         aida_implant_x++;
      }
      if(AidaImplantCalAdcData_side[i] == 1) {
         aida_implant_y++;
      }
   }
   

   // Loop over the decay events


   for (int i = 0; i < decayhits; i++) {
      if(!(*EventHeader_fSpillFlag.Get())) continue;
      if (AidaDecayHits_DSSD[i] == 2) continue;
      if (AidaDecayHits_StripX.GetSize() > 4) continue;
      if (TMath::Abs(AidaDecayHits_EnergyX[i] - AidaDecayHits_EnergyY[i]) > 300) continue;
      aida_decays_xy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[i]);
      aida_decay_frontback->Fill(AidaDecayHits_EnergyX[i], AidaDecayHits_EnergyY[i]);
   }

   // Loop over the implant events

   for (int i = 0; i < implanthits; i++) {
      if(AidaImplantHits_DSSD[i] == 2) continue;
      aida_implant_xy->Fill(AidaImplantHits_StripX[i], AidaImplantHits_StripY[i]);
      aida_implant_frontback->Fill(AidaImplantHits_EnergyX[i], AidaImplantHits_EnergyY[i]);
   }

   if(aida_strip_x => 1 && aida_strip_y => 1) {

      aida_decay_mult_x_y->Fill(aida_strip_x, aida_strip_y);
   }

   if(aida_implant_x => 1 && aida_implant_y => 1) {
      aida_implant_mult_x_y->Fill(aida_implant_x, aida_implant_y);
   }

   // Loop over the bPlast events

   std::set<int> fill_aida{};

   for (int i = 0; i < bplasthits; i++) {
      int64_t time = bPlastTwinpeaksCalData_fabsolute_event_time[i];
      if(bPlastTwinpeaksCalData_fdetector_id[i] == 44) {
         bplast_rates_every_1s->Fill((time-wr_experiment_start)/1e9);
         bplast_slow->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
         bplast_fast->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
         // bplast_fast_vs_slow[bPlastTwinpeaksCalData_fdetector_id[i]]->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
         bplast_fast_vs_slow_all->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
      }
      if(bPlastTwinpeaksCalData_fdetector_id[i] == 105){
         bplast_rates_every_1s_down->Fill((time-wr_experiment_start)/1e9);
         bplast_slow_down->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
         bplast_fast_down->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
         // bplast_fast_vs_slow_down[bPlastTwinpeaksCalData_fdetector_id[i]-64]->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
         bplast_fast_vs_slow_all_down->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
      }
      bplast_channels->Fill(bPlastTwinpeaksCalData_fdetector_id[i]);
      if(bPlastTwinpeaksCalData_fdetector_id[i] < 65 && bPlastTwinpeaksCalData_fslow_ToT[i] > 1000) {
         // downstream gated on upstream
         for (int j = 0; j < bplasthits; j++) {
            int64_t time_down = bPlastTwinpeaksCalData_fabsolute_event_time[j];
            if(bPlastTwinpeaksCalData_fdetector_id[j] < 129 && bPlastTwinpeaksCalData_fdetector_id[j] > 64 && TMath::Abs(time_down-time) < 500) {
               bplast_fast_gated_down->Fill(bPlastTwinpeaksCalData_ffast_ToT[j]);
               bplast_slow_gated_down->Fill(bPlastTwinpeaksCalData_fslow_ToT[j]);
            }
         }
      }
      // upstream gated on and off spill
      if(bPlastTwinpeaksCalData_fdetector_id[i] == 44) {
         if(!(*EventHeader_fSpillFlag.Get())){
            bplast_fast_gated_offspill->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
            bplast_slow_gated_offspill->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
         } else {
            bplast_fast_gated_onspill->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
            bplast_slow_gated_onspill->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
         }
      }
      // downstream gated on and off spill
      if(bPlastTwinpeaksCalData_fdetector_id[i] == 105) {
         if(!(*EventHeader_fSpillFlag.Get())){
            bplast_fast_gated_offspill_down->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
            bplast_slow_gated_offspill_down->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
         } else {
            bplast_fast_gated_onspill_down->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
            bplast_slow_gated_onspill_down->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
         }
      }

      // Loop over the aida decay events
      for (int j = 0; j < decayhits; j++) {
         if(AidaDecayHits_DSSD[j] == 2) continue;
         int64_t decay_time = AidaDecayHits_Time[j];
         // if(AidaDecayHits_StripX.GetSize() > 4) continue;
         if(TMath::Abs(AidaDecayHits_EnergyX[j] - AidaDecayHits_EnergyY[j]) > 200) continue;
         if(fill_aida.count(i) == 0) {
            bplast_aida_wr_dt->Fill(((int64_t)AidaDecayHits_Time[j])-((int64_t)bPlastTwinpeaksCalData_fabsolute_event_time[i]));

            // bPlast-AIDA time difference
            if(decay_time - time > 14000 && decay_time - time < 18e3) {
               if(bPlastTwinpeaksCalData_fdetector_id[i] == 44){
                  if(*EventHeader_fSpillFlag.Get()){
                     bplast_fast_onspill_wrgated->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
                     bplast_slow_onspill_wrgated->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
                     bplast_fast_vs_slow_wrgated_onspill->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
                  }
                  else{
                     bplast_fast_offspill_wrgated->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
                     bplast_slow_offspill_wrgated->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
                     bplast_fast_vs_slow_wrgated_offspill->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
                  }
               }
               if(bPlastTwinpeaksCalData_fdetector_id[i] == 105){
                  if(*EventHeader_fSpillFlag.Get()){
                     bplast_fast_onspill_wrgated_down->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
                     bplast_slow_onspill_wrgated_down->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
                     bplast_fast_vs_slow_wrgated_down_onspill->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
                  }
                  else{
                     bplast_fast_offspill_wrgated_down->Fill(bPlastTwinpeaksCalData_ffast_ToT[i]);
                     bplast_slow_offspill_wrgated_down->Fill(bPlastTwinpeaksCalData_fslow_ToT[i]);
                     bplast_fast_vs_slow_wrgated_down_offspill->Fill(bPlastTwinpeaksCalData_ffast_ToT[i], bPlastTwinpeaksCalData_fslow_ToT[i]);
                  }
               }
            }
            fill_aida.insert(i);
         }
      }
   }


   return kTRUE;
}

void noclust::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void noclust::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   TString option = GetOption();
   TFile hfile (option, "RECREATE", "Analysis results");
   fOutput->Write();

}