//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 25 09:45:35 2024 by ROOT version 6.26/10
// from TTree evt//cbmout_0
// found on file: 162Eu_new_0025_0001_aidaana.root
//////////////////////////////////////////////////////////

#ifndef aida_ana_h
#define aida_ana_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include "TClonesArray.h"

#include <vector>



class aida_ana : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<uint64_t> EventHeader_fEventno = {fReader, "EventHeader.fEventno"};
   TTreeReaderValue<int> EventHeader_fTrigger = {fReader, "EventHeader.fTrigger"};
   TTreeReaderValue<uint64_t> EventHeader_fTimeStamp = {fReader, "EventHeader.fTimeStamp"};
   TTreeReaderValue<bool> EventHeader_fSpillFlag = {fReader, "EventHeader.fSpillFlag"};
   TTreeReaderArray<unsigned int> GermaniumCalData_fUniqueID = {fReader, "GermaniumCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> GermaniumCalData_fBits = {fReader, "GermaniumCalData.fBits"};
   TTreeReaderArray<ULong_t> GermaniumCalData_fevent_trigger_time = {fReader, "GermaniumCalData.fevent_trigger_time"};
   TTreeReaderArray<UChar_t> GermaniumCalData_fpileup = {fReader, "GermaniumCalData.fpileup"};
   TTreeReaderArray<UChar_t> GermaniumCalData_foverflow = {fReader, "GermaniumCalData.foverflow"};
   TTreeReaderArray<Double_t> GermaniumCalData_fchannel_trigger_time = {fReader, "GermaniumCalData.fchannel_trigger_time"};
   TTreeReaderArray<Double_t> GermaniumCalData_fchannel_energy = {fReader, "GermaniumCalData.fchannel_energy"};
   TTreeReaderArray<unsigned int> GermaniumCalData_fcrystal_id = {fReader, "GermaniumCalData.fcrystal_id"};
   TTreeReaderArray<unsigned int> GermaniumCalData_fdetector_id = {fReader, "GermaniumCalData.fdetector_id"};
   TTreeReaderArray<unsigned int> GermaniumCalData_fwr_subsystem_id = {fReader, "GermaniumCalData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> GermaniumCalData_fwr_t = {fReader, "GermaniumCalData.fwr_t"};
   TTreeReaderArray<Long_t> GermaniumCalData_fabsolute_event_time = {fReader, "GermaniumCalData.fabsolute_event_time"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksCalData_fUniqueID = {fReader, "bPlastTwinpeaksCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksCalData_fBits = {fReader, "bPlastTwinpeaksCalData.fBits"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fboard_id = {fReader, "bPlastTwinpeaksCalData.fboard_id"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fch_ID = {fReader, "bPlastTwinpeaksCalData.fch_ID"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fdetector_id = {fReader, "bPlastTwinpeaksCalData.fdetector_id"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_fslow_lead_time = {fReader, "bPlastTwinpeaksCalData.fslow_lead_time"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_fslow_trail_time = {fReader, "bPlastTwinpeaksCalData.fslow_trail_time"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_ffast_lead_time = {fReader, "bPlastTwinpeaksCalData.ffast_lead_time"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_ffast_trail_time = {fReader, "bPlastTwinpeaksCalData.ffast_trail_time"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_ffast_ToT = {fReader, "bPlastTwinpeaksCalData.ffast_ToT"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_fslow_ToT = {fReader, "bPlastTwinpeaksCalData.fslow_ToT"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fwr_subsystem_id = {fReader, "bPlastTwinpeaksCalData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> bPlastTwinpeaksCalData_fwr_t = {fReader, "bPlastTwinpeaksCalData.fwr_t"};
   TTreeReaderArray<unsigned int> AidaDecayHits_fUniqueID = {fReader, "AidaDecayHits.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaDecayHits_fBits = {fReader, "AidaDecayHits.fBits"};
   TTreeReaderArray<Int_t> AidaDecayHits_DSSD = {fReader, "AidaDecayHits.DSSD"};
   TTreeReaderArray<Double_t> AidaDecayHits_StripX = {fReader, "AidaDecayHits.StripX"};
   TTreeReaderArray<Double_t> AidaDecayHits_StripY = {fReader, "AidaDecayHits.StripY"};
   TTreeReaderArray<Double_t> AidaDecayHits_PosX = {fReader, "AidaDecayHits.PosX"};
   TTreeReaderArray<Double_t> AidaDecayHits_PosY = {fReader, "AidaDecayHits.PosY"};
   TTreeReaderArray<Double_t> AidaDecayHits_Energy = {fReader, "AidaDecayHits.Energy"};
   TTreeReaderArray<Double_t> AidaDecayHits_EnergyX = {fReader, "AidaDecayHits.EnergyX"};
   TTreeReaderArray<Double_t> AidaDecayHits_EnergyY = {fReader, "AidaDecayHits.EnergyY"};
   TTreeReaderArray<Int_t> AidaDecayHits_StripXMin = {fReader, "AidaDecayHits.StripXMin"};
   TTreeReaderArray<Int_t> AidaDecayHits_StripXMax = {fReader, "AidaDecayHits.StripXMax"};
   TTreeReaderArray<Int_t> AidaDecayHits_StripYMin = {fReader, "AidaDecayHits.StripYMin"};
   TTreeReaderArray<Int_t> AidaDecayHits_StripYMax = {fReader, "AidaDecayHits.StripYMax"};
   TTreeReaderArray<Int_t> AidaDecayHits_ClusterSizeX = {fReader, "AidaDecayHits.ClusterSizeX"};
   TTreeReaderArray<Int_t> AidaDecayHits_ClusterSizeY = {fReader, "AidaDecayHits.ClusterSizeY"};
   TTreeReaderArray<Long_t> AidaDecayHits_Time = {fReader, "AidaDecayHits.Time"};
   TTreeReaderArray<Long_t> AidaDecayHits_TimeX = {fReader, "AidaDecayHits.TimeX"};
   TTreeReaderArray<Long_t> AidaDecayHits_TimeY = {fReader, "AidaDecayHits.TimeY"};
   TTreeReaderArray<Long_t> AidaDecayHits_FastTime = {fReader, "AidaDecayHits.FastTime"};
   TTreeReaderArray<Long_t> AidaDecayHits_FastTimeX = {fReader, "AidaDecayHits.FastTimeX"};
   TTreeReaderArray<Long_t> AidaDecayHits_FastTimeY = {fReader, "AidaDecayHits.FastTimeY"};
   TTreeReaderArray<Bool_t> AidaDecayHits_Stopped = {fReader, "AidaDecayHits.Stopped"};
   TTreeReaderArray<unsigned int> AidaImplantHits_fUniqueID = {fReader, "AidaImplantHits.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaImplantHits_fBits = {fReader, "AidaImplantHits.fBits"};
   TTreeReaderArray<Int_t> AidaImplantHits_DSSD = {fReader, "AidaImplantHits.DSSD"};
   TTreeReaderArray<Double_t> AidaImplantHits_StripX = {fReader, "AidaImplantHits.StripX"};
   TTreeReaderArray<Double_t> AidaImplantHits_StripY = {fReader, "AidaImplantHits.StripY"};
   TTreeReaderArray<Double_t> AidaImplantHits_PosX = {fReader, "AidaImplantHits.PosX"};
   TTreeReaderArray<Double_t> AidaImplantHits_PosY = {fReader, "AidaImplantHits.PosY"};
   TTreeReaderArray<Double_t> AidaImplantHits_Energy = {fReader, "AidaImplantHits.Energy"};
   TTreeReaderArray<Double_t> AidaImplantHits_EnergyX = {fReader, "AidaImplantHits.EnergyX"};
   TTreeReaderArray<Double_t> AidaImplantHits_EnergyY = {fReader, "AidaImplantHits.EnergyY"};
   TTreeReaderArray<Int_t> AidaImplantHits_StripXMin = {fReader, "AidaImplantHits.StripXMin"};
   TTreeReaderArray<Int_t> AidaImplantHits_StripXMax = {fReader, "AidaImplantHits.StripXMax"};
   TTreeReaderArray<Int_t> AidaImplantHits_StripYMin = {fReader, "AidaImplantHits.StripYMin"};
   TTreeReaderArray<Int_t> AidaImplantHits_StripYMax = {fReader, "AidaImplantHits.StripYMax"};
   TTreeReaderArray<Int_t> AidaImplantHits_ClusterSizeX = {fReader, "AidaImplantHits.ClusterSizeX"};
   TTreeReaderArray<Int_t> AidaImplantHits_ClusterSizeY = {fReader, "AidaImplantHits.ClusterSizeY"};
   TTreeReaderArray<Long_t> AidaImplantHits_Time = {fReader, "AidaImplantHits.Time"};
   TTreeReaderArray<Long_t> AidaImplantHits_TimeX = {fReader, "AidaImplantHits.TimeX"};
   TTreeReaderArray<Long_t> AidaImplantHits_TimeY = {fReader, "AidaImplantHits.TimeY"};
   TTreeReaderArray<Long_t> AidaImplantHits_FastTime = {fReader, "AidaImplantHits.FastTime"};
   TTreeReaderArray<Long_t> AidaImplantHits_FastTimeX = {fReader, "AidaImplantHits.FastTimeX"};
   TTreeReaderArray<Long_t> AidaImplantHits_FastTimeY = {fReader, "AidaImplantHits.FastTimeY"};
   TTreeReaderArray<Bool_t> AidaImplantHits_Stopped = {fReader, "AidaImplantHits.Stopped"};
   TTreeReaderArray<unsigned int> FrsHitData_fUniqueID = {fReader, "FrsHitData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsHitData_fBits = {fReader, "FrsHitData.fBits"};
   TTreeReaderArray<ULong_t> FrsHitData_fwr_t = {fReader, "FrsHitData.fwr_t"};
   TTreeReaderArray<unsigned short> FrsHitData_ftpat = {fReader, "FrsHitData.ftpat"};
   TTreeReaderArray<Float_t> FrsHitData_fID_x2 = {fReader, "FrsHitData.fID_x2"};
   TTreeReaderArray<Float_t> FrsHitData_fID_y2 = {fReader, "FrsHitData.fID_y2"};
   TTreeReaderArray<Float_t> FrsHitData_fID_x4 = {fReader, "FrsHitData.fID_x4"};
   TTreeReaderArray<Float_t> FrsHitData_fID_y4 = {fReader, "FrsHitData.fID_y4"};
   TTreeReaderArray<Float_t> FrsHitData_fID_a2 = {fReader, "FrsHitData.fID_a2"};
   TTreeReaderArray<Float_t> FrsHitData_fID_b2 = {fReader, "FrsHitData.fID_b2"};
   TTreeReaderArray<Float_t> FrsHitData_fID_a4 = {fReader, "FrsHitData.fID_a4"};
   TTreeReaderArray<Float_t> FrsHitData_fID_b4 = {fReader, "FrsHitData.fID_b4"};
   TTreeReaderArray<Float_t> FrsHitData_fID_AoQ = {fReader, "FrsHitData.fID_AoQ"};
   TTreeReaderArray<Float_t> FrsHitData_fID_AoQ_corr = {fReader, "FrsHitData.fID_AoQ_corr"};
   TTreeReaderArray<Float_t> FrsHitData_fID_z = {fReader, "FrsHitData.fID_z"};
   TTreeReaderArray<Float_t> FrsHitData_fID_z2 = {fReader, "FrsHitData.fID_z2"};
   TTreeReaderArray<Float_t> FrsHitData_fID_z_travmus = {fReader, "FrsHitData.fID_z_travmus"};
   TTreeReaderArray<Float_t> FrsHitData_fID_beta = {fReader, "FrsHitData.fID_beta"};
   TTreeReaderArray<Float_t> FrsHitData_fID_dEdeg = {fReader, "FrsHitData.fID_dEdeg"};
   TTreeReaderArray<Float_t> FrsHitData_fID_dEdegoQ = {fReader, "FrsHitData.fID_dEdegoQ"};
   TTreeReaderArray<Float_t> FrsHitData_ftravmusic_dE = {fReader, "FrsHitData.ftravmusic_dE"};
   TTreeReaderArray<Float_t> FrsHitData_ftravmusic_dE_cor = {fReader, "FrsHitData.ftravmusic_dE_cor"};
   TTreeReaderArray<Float_t> FrsHitData_fsci_tof2 = {fReader, "FrsHitData.fsci_tof2"};



   aida_ana(TTree * /*tree*/ =0) { }
   virtual ~aida_ana() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(aida_ana,0);

};

#endif

#ifdef aida_ana_cxx
void aida_ana::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t aida_ana::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef aida_ana_cxx
