//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct  8 08:54:41 2024 by ROOT version 6.26/10
// from TTree evt//cbmout_0
// found on file: 162Eu_new_0024_0001_aida.root
//////////////////////////////////////////////////////////

#ifndef aida_new_h
#define aida_new_h

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



class aida_new : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<uint64_t> EventHeader_fEventno = {fReader, "EventHeader.fEventno"};
   TTreeReaderValue<int> EventHeader_fTrigger = {fReader, "EventHeader.fTrigger"};
   TTreeReaderValue<uint64_t> EventHeader_fTimeStamp = {fReader, "EventHeader.fTimeStamp"};
   TTreeReaderValue<bool> EventHeader_fSpillFlag = {fReader, "EventHeader.fSpillFlag"};
   TTreeReaderArray<unsigned int> GermaniumFebexData_fUniqueID = {fReader, "GermaniumFebexData.fUniqueID"};
   TTreeReaderArray<unsigned int> GermaniumFebexData_fBits = {fReader, "GermaniumFebexData.fBits"};
   TTreeReaderArray<unsigned int> GermaniumFebexData_fnum_channels_fired = {fReader, "GermaniumFebexData.fnum_channels_fired"};
   TTreeReaderArray<ULong_t> GermaniumFebexData_fevent_trigger_time = {fReader, "GermaniumFebexData.fevent_trigger_time"};
   TTreeReaderArray<unsigned short> GermaniumFebexData_fhit_pattern = {fReader, "GermaniumFebexData.fhit_pattern"};
   TTreeReaderArray<UChar_t> GermaniumFebexData_fboard_id = {fReader, "GermaniumFebexData.fboard_id"};
   TTreeReaderArray<UChar_t> GermaniumFebexData_fpileup = {fReader, "GermaniumFebexData.fpileup"};
   TTreeReaderArray<UChar_t> GermaniumFebexData_foverflow = {fReader, "GermaniumFebexData.foverflow"};
   TTreeReaderArray<UChar_t> GermaniumFebexData_fchannel_id = {fReader, "GermaniumFebexData.fchannel_id"};
   TTreeReaderArray<Double_t> GermaniumFebexData_fchannel_trigger_time = {fReader, "GermaniumFebexData.fchannel_trigger_time"};
   TTreeReaderArray<Int_t> GermaniumFebexData_fchannel_energy = {fReader, "GermaniumFebexData.fchannel_energy"};
   TTreeReaderArray<unsigned int> GermaniumFebexData_fwr_subsystem_id = {fReader, "GermaniumFebexData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> GermaniumFebexData_fwr_t = {fReader, "GermaniumFebexData.fwr_t"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_fUniqueID = {fReader, "bPlastTwinpeaksData.fUniqueID"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_fBits = {fReader, "bPlastTwinpeaksData.fBits"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksData_fboard_id = {fReader, "bPlastTwinpeaksData.fboard_id"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_fch_ID = {fReader, "bPlastTwinpeaksData.fch_ID"};
   TTreeReaderArray<Long_t> bPlastTwinpeaksData_faccepted_trigger_time = {fReader, "bPlastTwinpeaksData.faccepted_trigger_time"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_faccepted_lead_epoch_counter = {fReader, "bPlastTwinpeaksData.faccepted_lead_epoch_counter"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_faccepted_lead_coarse_T = {fReader, "bPlastTwinpeaksData.faccepted_lead_coarse_T"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksData_faccepted_lead_fine_T = {fReader, "bPlastTwinpeaksData.faccepted_lead_fine_T"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_flead_epoch_counter = {fReader, "bPlastTwinpeaksData.flead_epoch_counter"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_flead_coarse_T = {fReader, "bPlastTwinpeaksData.flead_coarse_T"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksData_flead_fine_T = {fReader, "bPlastTwinpeaksData.flead_fine_T"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_ftrail_epoch_counter = {fReader, "bPlastTwinpeaksData.ftrail_epoch_counter"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_ftrail_coarse_T = {fReader, "bPlastTwinpeaksData.ftrail_coarse_T"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksData_ftrail_fine_T = {fReader, "bPlastTwinpeaksData.ftrail_fine_T"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksData_fwr_subsystem_id = {fReader, "bPlastTwinpeaksData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> bPlastTwinpeaksData_fwr_t = {fReader, "bPlastTwinpeaksData.fwr_t"};
   TTreeReaderArray<unsigned int> BGOTwinpeaksCalData_fUniqueID = {fReader, "BGOTwinpeaksCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> BGOTwinpeaksCalData_fBits = {fReader, "BGOTwinpeaksCalData.fBits"};
   TTreeReaderArray<unsigned short> BGOTwinpeaksCalData_fboard_id = {fReader, "BGOTwinpeaksCalData.fboard_id"};
   TTreeReaderArray<unsigned short> BGOTwinpeaksCalData_fch_ID = {fReader, "BGOTwinpeaksCalData.fch_ID"};
   TTreeReaderArray<Int_t> BGOTwinpeaksCalData_fdetector_id = {fReader, "BGOTwinpeaksCalData.fdetector_id"};
   TTreeReaderArray<Int_t> BGOTwinpeaksCalData_fcrystal_id = {fReader, "BGOTwinpeaksCalData.fcrystal_id"};
   TTreeReaderArray<Long_t> BGOTwinpeaksCalData_fslow_lead_epoch = {fReader, "BGOTwinpeaksCalData.fslow_lead_epoch"};
   TTreeReaderArray<Double_t> BGOTwinpeaksCalData_fslow_lead_time = {fReader, "BGOTwinpeaksCalData.fslow_lead_time"};
   TTreeReaderArray<Long_t> BGOTwinpeaksCalData_fslow_trail_epoch = {fReader, "BGOTwinpeaksCalData.fslow_trail_epoch"};
   TTreeReaderArray<Double_t> BGOTwinpeaksCalData_fslow_trail_time = {fReader, "BGOTwinpeaksCalData.fslow_trail_time"};
   TTreeReaderArray<Long_t> BGOTwinpeaksCalData_ffast_lead_epoch = {fReader, "BGOTwinpeaksCalData.ffast_lead_epoch"};
   TTreeReaderArray<Double_t> BGOTwinpeaksCalData_ffast_lead_time = {fReader, "BGOTwinpeaksCalData.ffast_lead_time"};
   TTreeReaderArray<Long_t> BGOTwinpeaksCalData_ffast_trail_epoch = {fReader, "BGOTwinpeaksCalData.ffast_trail_epoch"};
   TTreeReaderArray<Double_t> BGOTwinpeaksCalData_ffast_trail_time = {fReader, "BGOTwinpeaksCalData.ffast_trail_time"};
   TTreeReaderArray<Double_t> BGOTwinpeaksCalData_ffast_ToT = {fReader, "BGOTwinpeaksCalData.ffast_ToT"};
   TTreeReaderArray<Double_t> BGOTwinpeaksCalData_fslow_ToT = {fReader, "BGOTwinpeaksCalData.fslow_ToT"};
   TTreeReaderArray<Double_t> BGOTwinpeaksCalData_fenergy = {fReader, "BGOTwinpeaksCalData.fenergy"};
   TTreeReaderArray<unsigned short> BGOTwinpeaksCalData_fwr_subsystem_id = {fReader, "BGOTwinpeaksCalData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> BGOTwinpeaksCalData_fwr_t = {fReader, "BGOTwinpeaksCalData.fwr_t"};
   TTreeReaderArray<ULong_t> BGOTwinpeaksCalData_fabsolute_event_time = {fReader, "BGOTwinpeaksCalData.fabsolute_event_time"};
   TTreeReaderArray<unsigned int> BGOTimeMachineData_fUniqueID = {fReader, "BGOTimeMachineData.fUniqueID"};
   TTreeReaderArray<unsigned int> BGOTimeMachineData_fBits = {fReader, "BGOTimeMachineData.fBits"};
   TTreeReaderArray<Double_t> BGOTimeMachineData_fundelayed_time = {fReader, "BGOTimeMachineData.fundelayed_time"};
   TTreeReaderArray<Double_t> BGOTimeMachineData_fdelayed_time = {fReader, "BGOTimeMachineData.fdelayed_time"};
   TTreeReaderArray<unsigned int> BGOTimeMachineData_fwr_subsystem_id = {fReader, "BGOTimeMachineData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> BGOTimeMachineData_fwr_t = {fReader, "BGOTimeMachineData.fwr_t"};
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
   TTreeReaderArray<unsigned int> GermaniumTimeMachineData_fUniqueID = {fReader, "GermaniumTimeMachineData.fUniqueID"};
   TTreeReaderArray<unsigned int> GermaniumTimeMachineData_fBits = {fReader, "GermaniumTimeMachineData.fBits"};
   TTreeReaderArray<Double_t> GermaniumTimeMachineData_fundelayed_time = {fReader, "GermaniumTimeMachineData.fundelayed_time"};
   TTreeReaderArray<Double_t> GermaniumTimeMachineData_fdelayed_time = {fReader, "GermaniumTimeMachineData.fdelayed_time"};
   TTreeReaderArray<unsigned int> GermaniumTimeMachineData_fwr_subsystem_id = {fReader, "GermaniumTimeMachineData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> GermaniumTimeMachineData_fwr_t = {fReader, "GermaniumTimeMachineData.fwr_t"};
   TTreeReaderArray<unsigned int> GermaniumAnlData_fUniqueID = {fReader, "GermaniumAnlData.fUniqueID"};
   TTreeReaderArray<unsigned int> GermaniumAnlData_fBits = {fReader, "GermaniumAnlData.fBits"};
   TTreeReaderArray<ULong_t> GermaniumAnlData_fevent_trigger_time = {fReader, "GermaniumAnlData.fevent_trigger_time"};
   TTreeReaderArray<UChar_t> GermaniumAnlData_fpileup = {fReader, "GermaniumAnlData.fpileup"};
   TTreeReaderArray<UChar_t> GermaniumAnlData_foverflow = {fReader, "GermaniumAnlData.foverflow"};
   TTreeReaderArray<Double_t> GermaniumAnlData_fchannel_trigger_time = {fReader, "GermaniumAnlData.fchannel_trigger_time"};
   TTreeReaderArray<Double_t> GermaniumAnlData_fchannel_energy = {fReader, "GermaniumAnlData.fchannel_energy"};
   TTreeReaderArray<unsigned int> GermaniumAnlData_fcrystal_id = {fReader, "GermaniumAnlData.fcrystal_id"};
   TTreeReaderArray<unsigned int> GermaniumAnlData_fdetector_id = {fReader, "GermaniumAnlData.fdetector_id"};
   TTreeReaderArray<unsigned int> GermaniumAnlData_fwr_subsystem_id = {fReader, "GermaniumAnlData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> GermaniumAnlData_fwr_t = {fReader, "GermaniumAnlData.fwr_t"};
   TTreeReaderArray<Long_t> GermaniumAnlData_fabsolute_event_time = {fReader, "GermaniumAnlData.fabsolute_event_time"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksCalData_fUniqueID = {fReader, "bPlastTwinpeaksCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksCalData_fBits = {fReader, "bPlastTwinpeaksCalData.fBits"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fboard_id = {fReader, "bPlastTwinpeaksCalData.fboard_id"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fch_ID = {fReader, "bPlastTwinpeaksCalData.fch_ID"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fdetector_id = {fReader, "bPlastTwinpeaksCalData.fdetector_id"};
   TTreeReaderArray<Long_t> bPlastTwinpeaksCalData_fslow_lead_epoch = {fReader, "bPlastTwinpeaksCalData.fslow_lead_epoch"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_fslow_lead_time = {fReader, "bPlastTwinpeaksCalData.fslow_lead_time"};
   TTreeReaderArray<Long_t> bPlastTwinpeaksCalData_fslow_trail_epoch = {fReader, "bPlastTwinpeaksCalData.fslow_trail_epoch"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_fslow_trail_time = {fReader, "bPlastTwinpeaksCalData.fslow_trail_time"};
   TTreeReaderArray<Long_t> bPlastTwinpeaksCalData_ffast_lead_epoch = {fReader, "bPlastTwinpeaksCalData.ffast_lead_epoch"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_ffast_lead_time = {fReader, "bPlastTwinpeaksCalData.ffast_lead_time"};
   TTreeReaderArray<Long_t> bPlastTwinpeaksCalData_ffast_trail_epoch = {fReader, "bPlastTwinpeaksCalData.ffast_trail_epoch"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_ffast_trail_time = {fReader, "bPlastTwinpeaksCalData.ffast_trail_time"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_ffast_ToT = {fReader, "bPlastTwinpeaksCalData.ffast_ToT"};
   TTreeReaderArray<Double_t> bPlastTwinpeaksCalData_fslow_ToT = {fReader, "bPlastTwinpeaksCalData.fslow_ToT"};
   TTreeReaderArray<unsigned short> bPlastTwinpeaksCalData_fwr_subsystem_id = {fReader, "bPlastTwinpeaksCalData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> bPlastTwinpeaksCalData_fwr_t = {fReader, "bPlastTwinpeaksCalData.fwr_t"};
   TTreeReaderArray<ULong_t> bPlastTwinpeaksCalData_fabsolute_event_time = {fReader, "bPlastTwinpeaksCalData.fabsolute_event_time"};
   TTreeReaderArray<unsigned int> bPlastTimeMachineData_fUniqueID = {fReader, "bPlastTimeMachineData.fUniqueID"};
   TTreeReaderArray<unsigned int> bPlastTimeMachineData_fBits = {fReader, "bPlastTimeMachineData.fBits"};
   TTreeReaderArray<Double_t> bPlastTimeMachineData_fundelayed_time = {fReader, "bPlastTimeMachineData.fundelayed_time"};
   TTreeReaderArray<Double_t> bPlastTimeMachineData_fdelayed_time = {fReader, "bPlastTimeMachineData.fdelayed_time"};
   TTreeReaderArray<unsigned int> bPlastTimeMachineData_fwr_subsystem_id = {fReader, "bPlastTimeMachineData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> bPlastTimeMachineData_fwr_t = {fReader, "bPlastTimeMachineData.fwr_t"};
   TTreeReaderArray<unsigned int> AidaTimeMachineData_fUniqueID = {fReader, "AidaTimeMachineData.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaTimeMachineData_fBits = {fReader, "AidaTimeMachineData.fBits"};
   TTreeReaderArray<Double_t> AidaTimeMachineData_fundelayed_time = {fReader, "AidaTimeMachineData.fundelayed_time"};
   TTreeReaderArray<Double_t> AidaTimeMachineData_fdelayed_time = {fReader, "AidaTimeMachineData.fdelayed_time"};
   TTreeReaderArray<unsigned int> AidaTimeMachineData_fwr_subsystem_id = {fReader, "AidaTimeMachineData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> AidaTimeMachineData_fwr_t = {fReader, "AidaTimeMachineData.fwr_t"};
   TTreeReaderArray<unsigned int> AidaAdcData_fUniqueID = {fReader, "AidaAdcData.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaAdcData_fBits = {fReader, "AidaAdcData.fBits"};
   TTreeReaderArray<ULong_t> AidaAdcData_rawTime = {fReader, "AidaAdcData.rawTime"};
   TTreeReaderArray<ULong_t> AidaAdcData_slowTime = {fReader, "AidaAdcData.slowTime"};
   TTreeReaderArray<ULong_t> AidaAdcData_fastTime = {fReader, "AidaAdcData.fastTime"};
   TTreeReaderArray<Int_t> AidaAdcData_fee = {fReader, "AidaAdcData.fee"};
   TTreeReaderArray<Int_t> AidaAdcData_channel = {fReader, "AidaAdcData.channel"};
   TTreeReaderArray<Bool_t> AidaAdcData_range = {fReader, "AidaAdcData.range"};
   TTreeReaderArray<unsigned short> AidaAdcData_value = {fReader, "AidaAdcData.value"};
   TTreeReaderArray<unsigned int> AidaDecayCalAdcData_fUniqueID = {fReader, "AidaDecayCalAdcData.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaDecayCalAdcData_fBits = {fReader, "AidaDecayCalAdcData.fBits"};
   TTreeReaderArray<ULong_t> AidaDecayCalAdcData_slowTime = {fReader, "AidaDecayCalAdcData.slowTime"};
   TTreeReaderArray<ULong_t> AidaDecayCalAdcData_fastTime = {fReader, "AidaDecayCalAdcData.fastTime"};
   TTreeReaderArray<Int_t> AidaDecayCalAdcData_fee = {fReader, "AidaDecayCalAdcData.fee"};
   TTreeReaderArray<Int_t> AidaDecayCalAdcData_channel = {fReader, "AidaDecayCalAdcData.channel"};
   TTreeReaderArray<Int_t> AidaDecayCalAdcData_dssd = {fReader, "AidaDecayCalAdcData.dssd"};
   TTreeReaderArray<Int_t> AidaDecayCalAdcData_side = {fReader, "AidaDecayCalAdcData.side"};
   TTreeReaderArray<Int_t> AidaDecayCalAdcData_strip = {fReader, "AidaDecayCalAdcData.strip"};
   TTreeReaderArray<Bool_t> AidaDecayCalAdcData_range = {fReader, "AidaDecayCalAdcData.range"};
   TTreeReaderArray<Double_t> AidaDecayCalAdcData_intensity = {fReader, "AidaDecayCalAdcData.intensity"};
   TTreeReaderArray<Double_t> AidaDecayCalAdcData_energy = {fReader, "AidaDecayCalAdcData.energy"};
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
   TTreeReaderArray<unsigned int> AidaFlowData_fUniqueID = {fReader, "AidaFlowData.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaFlowData_fBits = {fReader, "AidaFlowData.fBits"};
   TTreeReaderArray<ULong_t> AidaFlowData_time = {fReader, "AidaFlowData.time"};
   TTreeReaderArray<Int_t> AidaFlowData_fee = {fReader, "AidaFlowData.fee"};
   TTreeReaderArray<Bool_t> AidaFlowData_pause = {fReader, "AidaFlowData.pause"};
   TTreeReaderArray<unsigned int> AidaImplantCalAdcData_fUniqueID = {fReader, "AidaImplantCalAdcData.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaImplantCalAdcData_fBits = {fReader, "AidaImplantCalAdcData.fBits"};
   TTreeReaderArray<ULong_t> AidaImplantCalAdcData_slowTime = {fReader, "AidaImplantCalAdcData.slowTime"};
   TTreeReaderArray<ULong_t> AidaImplantCalAdcData_fastTime = {fReader, "AidaImplantCalAdcData.fastTime"};
   TTreeReaderArray<Int_t> AidaImplantCalAdcData_fee = {fReader, "AidaImplantCalAdcData.fee"};
   TTreeReaderArray<Int_t> AidaImplantCalAdcData_channel = {fReader, "AidaImplantCalAdcData.channel"};
   TTreeReaderArray<Int_t> AidaImplantCalAdcData_dssd = {fReader, "AidaImplantCalAdcData.dssd"};
   TTreeReaderArray<Int_t> AidaImplantCalAdcData_side = {fReader, "AidaImplantCalAdcData.side"};
   TTreeReaderArray<Int_t> AidaImplantCalAdcData_strip = {fReader, "AidaImplantCalAdcData.strip"};
   TTreeReaderArray<Bool_t> AidaImplantCalAdcData_range = {fReader, "AidaImplantCalAdcData.range"};
   TTreeReaderArray<Double_t> AidaImplantCalAdcData_intensity = {fReader, "AidaImplantCalAdcData.intensity"};
   TTreeReaderArray<Double_t> AidaImplantCalAdcData_energy = {fReader, "AidaImplantCalAdcData.energy"};
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
   TTreeReaderArray<unsigned int> AidaScalerData_fUniqueID = {fReader, "AidaScalerData.fUniqueID"};
   TTreeReaderArray<unsigned int> AidaScalerData_fBits = {fReader, "AidaScalerData.fBits"};
   TTreeReaderArray<ULong_t> AidaScalerData_time = {fReader, "AidaScalerData.time"};
   TTreeReaderArray<ULong_t> AidaScalerData_value = {fReader, "AidaScalerData.value"};
   TTreeReaderArray<Int_t> AidaScalerData_fee = {fReader, "AidaScalerData.fee"};
   TTreeReaderArray<unsigned int> FrsHitData_fUniqueID = {fReader, "FrsHitData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsHitData_fBits = {fReader, "FrsHitData.fBits"};
   TTreeReaderArray<ULong_t> FrsHitData_fwr_t = {fReader, "FrsHitData.fwr_t"};
   TTreeReaderArray<unsigned short> FrsHitData_ftpat = {fReader, "FrsHitData.ftpat"};
   TTreeReaderArray<ULong_t> FrsHitData_fwr_travmus = {fReader, "FrsHitData.fwr_travmus"};
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
   TTreeReaderArray<unsigned int> FrsHitData_ftime_in_ms = {fReader, "FrsHitData.ftime_in_ms"};
   TTreeReaderArray<unsigned int> FrsHitData_fibin_for_s = {fReader, "FrsHitData.fibin_for_s"};
   TTreeReaderArray<unsigned int> FrsHitData_fibin_for_100ms = {fReader, "FrsHitData.fibin_for_100ms"};
   TTreeReaderArray<unsigned int> FrsHitData_fibin_for_spill = {fReader, "FrsHitData.fibin_for_spill"};
   TTreeReaderArray<unsigned int> FrsHitData_fincrease_sc_temp2 = {fReader, "FrsHitData.fincrease_sc_temp2"};
   TTreeReaderArray<unsigned int> FrsHitData_fincrease_sc_temp3 = {fReader, "FrsHitData.fincrease_sc_temp3"};
   TTreeReaderArray<unsigned int> FrsHitData_fextraction_time_ms = {fReader, "FrsHitData.fextraction_time_ms"};
   TTreeReaderArray<unsigned int> FrsHitData_fibin_clean_for_s = {fReader, "FrsHitData.fibin_clean_for_s"};
   TTreeReaderArray<unsigned int> FrsHitData_fibin_clean_for_100ms = {fReader, "FrsHitData.fibin_clean_for_100ms"};
   TTreeReaderArray<unsigned int> FrsHitData_fibin_clean_for_spill = {fReader, "FrsHitData.fibin_clean_for_spill"};
   TTreeReaderArray<unsigned int> FrsMainCalMusicData_fUniqueID = {fReader, "FrsMainCalMusicData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMainCalMusicData_fBits = {fReader, "FrsMainCalMusicData.fBits"};
   TTreeReaderArray<unsigned int> FrsMainCalScalerData_fUniqueID = {fReader, "FrsMainCalScalerData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMainCalScalerData_fBits = {fReader, "FrsMainCalScalerData.fBits"};
   TTreeReaderArray<unsigned int> FrsMainCalScalerData_index = {fReader, "FrsMainCalScalerData.index"};
   TTreeReaderArray<unsigned int> FrsMainCalScalerData_scaler = {fReader, "FrsMainCalScalerData.scaler"};
   TTreeReaderArray<unsigned int> FrsMainCalSciData_fUniqueID = {fReader, "FrsMainCalSciData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMainCalSciData_fBits = {fReader, "FrsMainCalSciData.fBits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc21l_hits = {fReader, "FrsMainCalSciData.mhtdc_sc21l_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc21r_hits = {fReader, "FrsMainCalSciData.mhtdc_sc21r_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc22l_hits = {fReader, "FrsMainCalSciData.mhtdc_sc22l_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc22r_hits = {fReader, "FrsMainCalSciData.mhtdc_sc22r_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc41l_hits = {fReader, "FrsMainCalSciData.mhtdc_sc41l_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc41r_hits = {fReader, "FrsMainCalSciData.mhtdc_sc41r_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc42l_hits = {fReader, "FrsMainCalSciData.mhtdc_sc42l_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc42r_hits = {fReader, "FrsMainCalSciData.mhtdc_sc42r_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc43l_hits = {fReader, "FrsMainCalSciData.mhtdc_sc43l_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc43r_hits = {fReader, "FrsMainCalSciData.mhtdc_sc43r_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc81l_hits = {fReader, "FrsMainCalSciData.mhtdc_sc81l_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc81r_hits = {fReader, "FrsMainCalSciData.mhtdc_sc81r_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc31l_hits = {fReader, "FrsMainCalSciData.mhtdc_sc31l_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc31r_hits = {fReader, "FrsMainCalSciData.mhtdc_sc31r_hits"};
   TTreeReaderArray<Int_t> FrsMainCalSciData_mhtdc_sc11_hits = {fReader, "FrsMainCalSciData.mhtdc_sc11_hits"};
   TTreeReaderArray<unsigned int> FrsMainV1290Data_fUniqueID = {fReader, "FrsMainV1290Data.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMainV1290Data_fBits = {fReader, "FrsMainV1290Data.fBits"};
   TTreeReaderArray<unsigned int> FrsMainV1290Data_channel = {fReader, "FrsMainV1290Data.channel"};
   TTreeReaderArray<unsigned int> FrsMainV1290Data_v1290_data = {fReader, "FrsMainV1290Data.v1290_data"};
   TTreeReaderArray<unsigned int> FrsMainV1290Data_leadOrTrail = {fReader, "FrsMainV1290Data.leadOrTrail"};
   TTreeReaderArray<unsigned int> FrsMainV792Data_fUniqueID = {fReader, "FrsMainV792Data.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMainV792Data_fBits = {fReader, "FrsMainV792Data.fBits"};
   TTreeReaderArray<unsigned int> FrsMainV792Data_channel = {fReader, "FrsMainV792Data.channel"};
   TTreeReaderArray<unsigned int> FrsMainV792Data_v792_data = {fReader, "FrsMainV792Data.v792_data"};
   TTreeReaderArray<unsigned int> FrsMainV792Data_geo = {fReader, "FrsMainV792Data.geo"};
   TTreeReaderArray<unsigned int> FrsMainV830Data_fUniqueID = {fReader, "FrsMainV830Data.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMainV830Data_fBits = {fReader, "FrsMainV830Data.fBits"};
   TTreeReaderArray<unsigned int> FrsMainV830Data_index = {fReader, "FrsMainV830Data.index"};
   TTreeReaderArray<unsigned int> FrsMainV830Data_scaler = {fReader, "FrsMainV830Data.scaler"};
   TTreeReaderArray<unsigned int> FrsMultiHitData_fUniqueID = {fReader, "FrsMultiHitData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMultiHitData_fBits = {fReader, "FrsMultiHitData.fBits"};
   TTreeReaderArray<ULong_t> FrsMultiHitData_fwr_t = {fReader, "FrsMultiHitData.fwr_t"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_s2x_mhtdc = {fReader, "FrsMultiHitData.fID_s2x_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_s4x_mhtdc = {fReader, "FrsMultiHitData.fID_s4x_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_s2a_mhtdc = {fReader, "FrsMultiHitData.fID_s2a_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_s4a_mhtdc = {fReader, "FrsMultiHitData.fID_s4a_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_tof_mhtdc = {fReader, "FrsMultiHitData.fID_tof_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_beta_mhtdc = {fReader, "FrsMultiHitData.fID_beta_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_AoQ_mhtdc = {fReader, "FrsMultiHitData.fID_AoQ_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_AoQ_corr_mhtdc = {fReader, "FrsMultiHitData.fID_AoQ_corr_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_z_mhtdc = {fReader, "FrsMultiHitData.fID_z_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_z2_mhtdc = {fReader, "FrsMultiHitData.fID_z2_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_z_travmus_mhtdc = {fReader, "FrsMultiHitData.fID_z_travmus_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_dEdeg_mhtdc = {fReader, "FrsMultiHitData.fID_dEdeg_mhtdc"};
   TTreeReaderArray<Float_t> FrsMultiHitData_fID_dEdegoQ_mhtdc = {fReader, "FrsMultiHitData.fID_dEdegoQ_mhtdc"};
   TTreeReaderArray<unsigned int> FrsTPCCalData_fUniqueID = {fReader, "FrsTPCCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsTPCCalData_fBits = {fReader, "FrsTPCCalData.fBits"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_x_s2_foc_21_22 = {fReader, "FrsTPCCalData.ftpc_angle_x_s2_foc_21_22"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_y_s2_foc_21_22 = {fReader, "FrsTPCCalData.ftpc_angle_y_s2_foc_21_22"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_x_s2_foc_21_22 = {fReader, "FrsTPCCalData.ftpc_x_s2_foc_21_22"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_y_s2_foc_21_22 = {fReader, "FrsTPCCalData.ftpc_y_s2_foc_21_22"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc21_22_sc21_x = {fReader, "FrsTPCCalData.ftpc21_22_sc21_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc21_22_sc22_x = {fReader, "FrsTPCCalData.ftpc21_22_sc22_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_x_s2_foc_23_24 = {fReader, "FrsTPCCalData.ftpc_angle_x_s2_foc_23_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_y_s2_foc_23_24 = {fReader, "FrsTPCCalData.ftpc_angle_y_s2_foc_23_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_x_s2_foc_23_24 = {fReader, "FrsTPCCalData.ftpc_x_s2_foc_23_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_y_s2_foc_23_24 = {fReader, "FrsTPCCalData.ftpc_y_s2_foc_23_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc23_24_sc21_x = {fReader, "FrsTPCCalData.ftpc23_24_sc21_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc23_24_sc21_y = {fReader, "FrsTPCCalData.ftpc23_24_sc21_y"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc23_24_sc22_x = {fReader, "FrsTPCCalData.ftpc23_24_sc22_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc23_24_sc22_y = {fReader, "FrsTPCCalData.ftpc23_24_sc22_y"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_x_s2_foc_22_24 = {fReader, "FrsTPCCalData.ftpc_angle_x_s2_foc_22_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_y_s2_foc_22_24 = {fReader, "FrsTPCCalData.ftpc_angle_y_s2_foc_22_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_x_s2_foc_22_24 = {fReader, "FrsTPCCalData.ftpc_x_s2_foc_22_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_y_s2_foc_22_24 = {fReader, "FrsTPCCalData.ftpc_y_s2_foc_22_24"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_x_s4 = {fReader, "FrsTPCCalData.ftpc_angle_x_s4"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_angle_y_s4 = {fReader, "FrsTPCCalData.ftpc_angle_y_s4"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_x_s4 = {fReader, "FrsTPCCalData.ftpc_x_s4"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_y_s4 = {fReader, "FrsTPCCalData.ftpc_y_s4"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_sc41_x = {fReader, "FrsTPCCalData.ftpc_sc41_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_sc41_y = {fReader, "FrsTPCCalData.ftpc_sc41_y"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_sc42_x = {fReader, "FrsTPCCalData.ftpc_sc42_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_sc42_y = {fReader, "FrsTPCCalData.ftpc_sc42_y"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_sc43_x = {fReader, "FrsTPCCalData.ftpc_sc43_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_music41_x = {fReader, "FrsTPCCalData.ftpc_music41_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_music42_x = {fReader, "FrsTPCCalData.ftpc_music42_x"};
   TTreeReaderArray<Float_t> FrsTPCCalData_ftpc_music43_x = {fReader, "FrsTPCCalData.ftpc_music43_x"};
   TTreeReaderArray<unsigned int> FrsTPCV1190Data_fUniqueID = {fReader, "FrsTPCV1190Data.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsTPCV1190Data_fBits = {fReader, "FrsTPCV1190Data.fBits"};
   TTreeReaderArray<unsigned int> FrsTPCV1190Data_channel = {fReader, "FrsTPCV1190Data.channel"};
   TTreeReaderArray<unsigned int> FrsTPCV1190Data_v1190_data = {fReader, "FrsTPCV1190Data.v1190_data"};
   TTreeReaderArray<unsigned int> FrsTPCV1190Data_leadOrTrail = {fReader, "FrsTPCV1190Data.leadOrTrail"};
   TTreeReaderArray<unsigned int> FrsTPCV7X5Data_fUniqueID = {fReader, "FrsTPCV7X5Data.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsTPCV7X5Data_fBits = {fReader, "FrsTPCV7X5Data.fBits"};
   TTreeReaderArray<unsigned int> FrsTPCV7X5Data_geo = {fReader, "FrsTPCV7X5Data.geo"};
   TTreeReaderArray<unsigned int> FrsTPCV7X5Data_v7x5_data = {fReader, "FrsTPCV7X5Data.v7x5_data"};
   TTreeReaderArray<unsigned int> FrsTPCV7X5Data_channel = {fReader, "FrsTPCV7X5Data.channel"};
   TTreeReaderArray<unsigned int> FrsTpatData_fUniqueID = {fReader, "FrsTpatData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsTpatData_fBits = {fReader, "FrsTpatData.fBits"};
   TTreeReaderArray<ULong_t> FrsTpatData_wr_t = {fReader, "FrsTpatData.wr_t"};
   TTreeReaderArray<unsigned short> FrsTpatData_tpat = {fReader, "FrsTpatData.tpat"};
   TTreeReaderArray<unsigned int> FrsUserCalMusicData_fUniqueID = {fReader, "FrsUserCalMusicData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsUserCalMusicData_fBits = {fReader, "FrsUserCalMusicData.fBits"};
   TTreeReaderArray<unsigned int> FrsUserCalScalerData_fUniqueID = {fReader, "FrsUserCalScalerData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsUserCalScalerData_fBits = {fReader, "FrsUserCalScalerData.fBits"};
   TTreeReaderArray<unsigned int> FrsUserCalScalerData_index = {fReader, "FrsUserCalScalerData.index"};
   TTreeReaderArray<unsigned int> FrsUserCalScalerData_scaler = {fReader, "FrsUserCalScalerData.scaler"};
   TTreeReaderArray<unsigned int> FrsUserCalSciData_fUniqueID = {fReader, "FrsUserCalSciData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsUserCalSciData_fBits = {fReader, "FrsUserCalSciData.fBits"};
   TTreeReaderArray<unsigned int> FrsUserV7X5Data_fUniqueID = {fReader, "FrsUserV7X5Data.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsUserV7X5Data_fBits = {fReader, "FrsUserV7X5Data.fBits"};
   TTreeReaderArray<unsigned int> FrsUserV7X5Data_geo = {fReader, "FrsUserV7X5Data.geo"};
   TTreeReaderArray<unsigned int> FrsUserV7X5Data_channel = {fReader, "FrsUserV7X5Data.channel"};
   TTreeReaderArray<unsigned int> FrsUserV7X5Data_v7x5_data = {fReader, "FrsUserV7X5Data.v7x5_data"};
   TTreeReaderArray<unsigned int> FrsUserV830Data_fUniqueID = {fReader, "FrsUserV830Data.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsUserV830Data_fBits = {fReader, "FrsUserV830Data.fBits"};
   TTreeReaderArray<unsigned int> FrsUserV830Data_scaler = {fReader, "FrsUserV830Data.scaler"};
   TTreeReaderArray<unsigned int> FrsUserV830Data_index = {fReader, "FrsUserV830Data.index"};


   aida_new(TTree * /*tree*/ =0) { }
   virtual ~aida_new() { }
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

   ClassDef(aida_new,0);

};

#endif

#ifdef aida_new_cxx
void aida_new::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t aida_new::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef aida_new_cxx
