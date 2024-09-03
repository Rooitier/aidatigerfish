#define evt_cxx
// The class definition in evt.h has been generated automatically
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
// root> T->Process("evt.C")
// root> T->Process("evt.C","some options")
// root> T->Process("evt.C+")
//



// Load cuts



#include "evt.h"
#include <TH2.h>
#include <TStyle.h>

TH2F* aida_implants_strip_xy;
TH2F* aida_decays_strip_xy;
TH1F* aida_fati_decay_time_diff;
TH1F* aida_bplast_decay_time_diff;
TH2F* aida_frontback_energy_decays;
TH2F* aida_frontback_energy_implants;
TH1F* aida_frontback_time_diff_decays;
TH1F* aida_frontback_time_diff_implants;
TH2F* aida_decays_offspill_strip_xy;
TH2F* aida_decays_onspill_strip_xy;

TH2F* frs_zvsaoq;
TH2F* frs_z1vsz2;
TH2F* frs_x2vsz1;
TH2F* frs_x4vsz2;
TH2F* frs_z1vsdE;

void evt::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void evt::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   // aida_implants_strip_xy = new TH2F("aida_implants_xy", "AIDA Implants XY DSSSD 1", 386, 0, 386, 128, 0, 128);
   // aida_decays_strip_xy = new TH2F("aida_decays_xy", "AIDA Decays XY DSSSD 1", 386, 0, 386, 128, 0, 128);
   // aida_fati_decay_time_diff = new TH1F("aida_fati_decay_time_diff", "AIDA FATIMA Decay Time Difference", 1e4, -1e5, 1e5);
   // aida_bplast_decay_time_diff = new TH1F("aida_bplast_decay_time_diff", "AIDA BPlast Decay Time Difference", 1e4, -1e5, 1e5);
   // aida_germanium_decay_time_diff = new TH1F("aida_germanium_decay_time_diff", "AIDA Germanium Decay Time Difference", 1e4, -1e5, 1e5);
   // aida_frontback_energy_decays = new TH2F("aida_frontback_energy_decays", "AIDA Front vs Back Energy Decays", 1e3, 0, 4000, 1e3, 0, 4000);
   // aida_frontback_energy_implants = new TH2F("aida_frontback_energy_implants", "AIDA Front vs Back Energy Implants", 1e3, 0, 10e3, 1e3, 0, 10e3);
   // aida_frontback_time_diff_decays = new TH1F("aida_frontback_time_diff_decays", "AIDA Front vs Back Time Difference Decays", 1e3, -1e3, 1e3);
   // aida_frontback_time_diff_implants = new TH1F("aida_frontback_time_diff_implants", "AIDA Front vs Back Time Difference Implants", 1e3, -1e3, 1e3);
   // aida_decays_offspill_strip_xy = new TH2F("aida_decays_offspill_xy", "AIDA Decays XY DSSSD 1 Offspill", 386, 0, 386, 128, 0, 128);
   // aida_decays_onspill_strip_xy = new TH2F("aida_decays_onspill_xy", "AIDA Decays XY DSSSD 1 Onspill", 386, 0, 386, 128, 0, 128);
   frs_zvsaoq = new TH2F("frs_zvsaoq", "FRS Z vs A/Q", 1e3, 0, 5, 1e3,0, 100);
   frs_z1vsz2 = new TH2F("frs_z1vsz2", "FRS Z1 vs Z2", 1e3, 30, 50, 1e3, 0, 50);
   frs_x2vsz1 = new TH2F("frs_x2vsz1", "FRS X2 vs Z1", 1e3, 0, 100, 1e3, -100, 100);
   frs_x4vsz2 = new TH2F("frs_x4vsz2", "FRS X4 vs Z2", 1e3, 0, 100, 1e3, -100, 100);
   frs_z1vsdE = new TH2F("frs_z1vsdE", "FRS Z1 vs dE", 1e3, 0, 100, 1e3, 0, 100);


   fOutput->AddAll(gDirectory->GetList());
}

Bool_t evt::Process(Long64_t entry)
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

   // for(int i = 0; i < AidaImplantHits_StripX.GetSize(); i++)
   // {
   //    for(int j = 0; j < AidaImplantHits_StripY.GetSize(); j++)
   //    {
   //       if(AidaImplantHits_DSSD[i] == 1 && AidaImplantHits_DSSD[j] == 1)
   //       {
   //             aida_implants_strip_xy->Fill(AidaImplantHits_StripX[i], AidaImplantHits_StripY[j]);
   //       }
   //    }
   // }

   // for(int i = 0; i < AidaDecayHits_StripX.GetSize(); i++)
   // {
   //    for(int j = 0; j < AidaDecayHits_StripY.GetSize(); j++)
   //    {
   //       if(AidaDecayHits_DSSD[i] == 1 && AidaDecayHits_DSSD[j] == 1)
   //       {
   //             aida_decays_strip_xy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[j]);
   //       }
   //    }
   // }

   // for(int i = 0; i < AidaDecayHits_StripX.GetSize(); i++)
   // {
   //    for(int j = 0; j < AidaDecayHits_StripY.GetSize(); j++)
   //    {
   //       if(AidaDecayHits_DSSD[i] == 1 && AidaDecayHits_DSSD[j] == 1 && *EventHeader_fSpillFlag == true)
   //       {
   //             aida_decays_offspill_strip_xy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[j]);
   //       }
   //    }
   // }

   // for(int i = 0; i < AidaDecayHits_StripX.GetSize(); i++)
   // {
   //    for(int j = 0; j < AidaDecayHits_StripY.GetSize(); j++)
   //    {
   //       if(AidaDecayHits_DSSD[i] == 1 && AidaDecayHits_DSSD[j] == 1 && *EventHeader_fSpillFlag == false)
   //       {
   //             aida_decays_onspill_strip_xy->Fill(AidaDecayHits_StripX[i], AidaDecayHits_StripY[j]);
   //       }
   //    }
   // }

   // int64_t time_diff_aida_fati = 0;
   // int64_t time_diff_aida_bplast = 0;
   // int64_t time_diff_aida_germanium = 0;

   // for (int i = 0; i < AidaDecayHits_Time.GetSize(); i++)
   // {
   //    for (int j = 0; j < GermaniumCalData_fwr_t.GetSize(); j++)
   //    {
   //       time_diff_aida_germanium = GermaniumCalData_fwr_t.At(j) - AidaDecayHits_Time.At(i);
   //       aida_germanium_decay_time_diff->Fill(time_diff_aida_germanium);
   //    }
   // }

   // for (int i = 0; i < AidaDecayHits_Time.GetSize(); i++)
   // {
   //    for (int j = 0; j < FatimaTwinpeaksCalData_fwr_t.GetSize(); j++)
   //    {
   //       time_diff_aida_fati = FatimaTwinpeaksCalData_fwr_t.At(j) - AidaDecayHits_Time.At(i);
   //       aida_fati_decay_time_diff->Fill(time_diff_aida_fati);
   //    }
   // }

   // for(int i = 0; i < bPlastTwinpeaksCalData_fwr_t.GetSize(); i++)
   // {
   //    for(int j = 0; j < AidaDecayHits_Time.GetSize(); j++)
   //    {
   //       time_diff_aida_bplast = bPlastTwinpeaksCalData_fwr_t.At(i) - AidaDecayHits_Time.At(j);
   //       aida_bplast_decay_time_diff_aida_bplast->Fill(time_diff_aida_bplast);
   //    }
   // }

   // for 

   // for (int i = 0; i < AidaDecayHits_EnergyX.GetSize(); i++)
   // {
   //    for (int j = 0; j < AidaDecayHits_EnergyY.GetSize(); j++)
   //    {
   //       if (AidaDecayHits_DSSD[i] == 1 && AidaDecayHits_DSSD[j] == 1)
   //       {
   //          aida_frontback_energy_decays->Fill(AidaDecayHits_EnergyX[i], AidaDecayHits_EnergyY[j]);
   //       }
   //    }
   // }

   // for (int i = 0; i < AidaImplantHits_EnergyX.GetSize(); i++)
   // {
   //    for (int j = 0; j < AidaImplantHits_EnergyY.GetSize(); j++)
   //    {
   //       if (AidaImplantHits_DSSD[i] == 1 && AidaImplantHits_DSSD[j] == 1)
   //       {
   //          aida_frontback_energy_implants->Fill(AidaImplantHits_EnergyX[i], AidaImplantHits_EnergyY[j]);
   //       }
   //    }
   // }

   // int64_t frontback_decay_dt = 0;

   // for (int i = 0; i < AidaDecayHits_TimeX.GetSize(); i++)
   // {
   //    for (int j = 0; j < AidaDecayHits_TimeY.GetSize(); j++)
   //    {
   //       frontback_decay_dt = AidaDecayHits_TimeX[i] - AidaDecayHits_TimeY[j];
   //       aida_frontback_time_diff_decays->Fill(frontback_decay_dt);
   //    }
   // }

   // int64_t frontback_implant_dt = 0;

   // for (int i = 0; i < AidaImplantHits_TimeX.GetSize(); i++)
   // {
   //    for (int j = 0; j < AidaImplantHits_TimeY.GetSize(); j++)
   //    {
   //       frontback_implant_dt = AidaImplantHits_TimeX[i] - AidaImplantHits_TimeY[j];
   //       aida_frontback_time_diff_implants->Fill(frontback_implant_dt);
   //    }
   // }

   for (int i =0; i < FrsHitData_fID_AoQ_corr.GetSize(); i++)
   {
      for(int j = 0; j < FrsHitData_fID_z.GetSize(); j++)\
      {
         for(int k = 0; k < FrsHitData_fID_z2.GetSize(); k++)
         {  
         if(TMath::Abs(FrsHitData_fID_z.At(j)-FrsHitData_fID_z2.At(k)< 0.4)) frs_zvsaoq->Fill( FrsHitData_fID_AoQ_corr.At(i),FrsHitData_fID_z.At(j));
         }
      }
   }

   for (int i =0; i < FrsHitData_fID_z.GetSize(); i++)
   {
      for(int j = 0; j < FrsHitData_fID_z2.GetSize(); j++)\
      {
         frs_z1vsz2->Fill(FrsHitData_fID_z2.At(j), FrsHitData_fID_z.At(i));
      }
   }

   for (int i =0; i < FrsHitData_fID_z.GetSize(); i++)
   {
      for(int j = 0; j < FrsHitData_fID_x2.GetSize(); j++)\
      {
         frs_x2vsz1->Fill(FrsHitData_fID_z.At(i), FrsHitData_fID_x2.At(j));
      }
   }

   for (int i =0; i < FrsHitData_fID_z2.GetSize(); i++)
   {
      for(int j = 0; j < FrsHitData_fID_x4.GetSize(); j++)\
      {
         frs_x4vsz2->Fill(FrsHitData_fID_z2.At(i), FrsHitData_fID_x4.At(j));
      }
   }

   for (int i =0; i < FrsHitData_fID_z.GetSize(); i++)
   {
      for(int j = 0; j < FrsHitData_fID_dEdeg.GetSize(); j++)
      {
         frs_z1vsdE->Fill(FrsHitData_fID_dEdeg.At(j),FrsHitData_fID_z.At(i) );
      }
   }

   return kTRUE;
}

void evt::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void evt::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   TString option = GetOption();
   TFile hfile (option, "RECREATE", "Analysis results");
   fOutput->Write();

}