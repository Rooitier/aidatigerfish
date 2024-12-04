//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul 19 09:05:03 2024 by ROOT version 6.26/10
// from TTree evt//cbmout_0
// found on file: 162Eu_new_0034_0028.root
//////////////////////////////////////////////////////////

#ifndef evt_h
#define evt_h

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



class evt : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   // TTreeReaderValue<unsigned int> EventHeader = {fReader, "EventHeader"};
   // TTreeReaderValue<un> EventHeader = {fReader, "EventHeader"};
   TTreeReaderValue<uint64_t> EventHeader_fEventno = {fReader, "EventHeader.fEventno"};
   TTreeReaderValue<int> EventHeader_fTrigger = {fReader, "EventHeader.fTrigger"};
   TTreeReaderValue<uint64_t> EventHeader_fTimeStamp = {fReader, "EventHeader.fTimeStamp"};
   TTreeReaderValue<bool> EventHeader_fSpillFlag = {fReader, "EventHeader.fSpillFlag"};
   TTreeReaderArray<unsigned int> FatimaTwinpeaksCalData_fUniqueID = {fReader, "FatimaTwinpeaksCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> FatimaTwinpeaksCalData_fBits = {fReader, "FatimaTwinpeaksCalData.fBits"};
   TTreeReaderArray<UChar_t> FatimaTwinpeaksCalData_ftrig = {fReader, "FatimaTwinpeaksCalData.ftrig"};
   TTreeReaderArray<unsigned short> FatimaTwinpeaksCalData_fboard_id = {fReader, "FatimaTwinpeaksCalData.fboard_id"};
   TTreeReaderArray<unsigned short> FatimaTwinpeaksCalData_fch_ID = {fReader, "FatimaTwinpeaksCalData.fch_ID"};
   TTreeReaderArray<unsigned short> FatimaTwinpeaksCalData_fdetector_id = {fReader, "FatimaTwinpeaksCalData.fdetector_id"};
   TTreeReaderArray<Double_t> FatimaTwinpeaksCalData_fslow_lead_time = {fReader, "FatimaTwinpeaksCalData.fslow_lead_time"};
   TTreeReaderArray<Double_t> FatimaTwinpeaksCalData_fslow_trail_time = {fReader, "FatimaTwinpeaksCalData.fslow_trail_time"};
   TTreeReaderArray<Double_t> FatimaTwinpeaksCalData_ffast_lead_time = {fReader, "FatimaTwinpeaksCalData.ffast_lead_time"};
   TTreeReaderArray<Double_t> FatimaTwinpeaksCalData_ffast_trail_time = {fReader, "FatimaTwinpeaksCalData.ffast_trail_time"};
   TTreeReaderArray<Double_t> FatimaTwinpeaksCalData_ffast_ToT = {fReader, "FatimaTwinpeaksCalData.ffast_ToT"};
   TTreeReaderArray<Double_t> FatimaTwinpeaksCalData_fslow_ToT = {fReader, "FatimaTwinpeaksCalData.fslow_ToT"};
   TTreeReaderArray<Double_t> FatimaTwinpeaksCalData_fenergy = {fReader, "FatimaTwinpeaksCalData.fenergy"};
   TTreeReaderArray<unsigned short> FatimaTwinpeaksCalData_fwr_subsystem_id = {fReader, "FatimaTwinpeaksCalData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> FatimaTwinpeaksCalData_fwr_t = {fReader, "FatimaTwinpeaksCalData.fwr_t"};
   TTreeReaderArray<Long_t> FatimaTwinpeaksCalData_fabsolute_event_time = {fReader, "FatimaTwinpeaksCalData.fabsolute_event_time"};
   TTreeReaderArray<unsigned int> FatimaTimeMachineData_fUniqueID = {fReader, "FatimaTimeMachineData.fUniqueID"};
   TTreeReaderArray<unsigned int> FatimaTimeMachineData_fBits = {fReader, "FatimaTimeMachineData.fBits"};
   TTreeReaderArray<Double_t> FatimaTimeMachineData_fundelayed_time = {fReader, "FatimaTimeMachineData.fundelayed_time"};
   TTreeReaderArray<Double_t> FatimaTimeMachineData_fdelayed_time = {fReader, "FatimaTimeMachineData.fdelayed_time"};
   TTreeReaderArray<unsigned int> FatimaTimeMachineData_fwr_subsystem_id = {fReader, "FatimaTimeMachineData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> FatimaTimeMachineData_fwr_t = {fReader, "FatimaTimeMachineData.fwr_t"};
   TTreeReaderArray<unsigned int> FatimaVmeCalData_fUniqueID = {fReader, "FatimaVmeCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> FatimaVmeCalData_fBits = {fReader, "FatimaVmeCalData.fBits"};
   TTreeReaderArray<ULong_t> FatimaVmeCalData_fwr_t = {fReader, "FatimaVmeCalData.fwr_t"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsingles_e = {fReader, "FatimaVmeCalData.fsingles_e"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsingles_e_raw = {fReader, "FatimaVmeCalData.fsingles_e_raw"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsingles_qdc_id = {fReader, "FatimaVmeCalData.fsingles_qdc_id"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsingles_coarse_time = {fReader, "FatimaVmeCalData.fsingles_coarse_time"};
   TTreeReaderArray<vector<unsigned long>> FatimaVmeCalData_fsingles_fine_time = {fReader, "FatimaVmeCalData.fsingles_fine_time"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsingles_tdc_timestamp = {fReader, "FatimaVmeCalData.fsingles_tdc_timestamp"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsingles_tdc_timestamp_raw = {fReader, "FatimaVmeCalData.fsingles_tdc_timestamp_raw"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsingles_tdc_id = {fReader, "FatimaVmeCalData.fsingles_tdc_id"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsc41l_hits = {fReader, "FatimaVmeCalData.fsc41l_hits"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsc41r_hits = {fReader, "FatimaVmeCalData.fsc41r_hits"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_ftm_undelayed_hits = {fReader, "FatimaVmeCalData.ftm_undelayed_hits"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_ftm_delayed_hits = {fReader, "FatimaVmeCalData.ftm_delayed_hits"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsc41l_e_hits = {fReader, "FatimaVmeCalData.fsc41l_e_hits"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fsc41r_e_hits = {fReader, "FatimaVmeCalData.fsc41r_e_hits"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_ftm_undelayed_e_hits = {fReader, "FatimaVmeCalData.ftm_undelayed_e_hits"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_ftm_delayed_e_hits = {fReader, "FatimaVmeCalData.ftm_delayed_e_hits"};
   TTreeReaderArray<Int_t> FatimaVmeCalData_ffatvme_mult = {fReader, "FatimaVmeCalData.ffatvme_mult"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fqdc_id = {fReader, "FatimaVmeCalData.fqdc_id"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fqdc_e = {fReader, "FatimaVmeCalData.fqdc_e"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fqdc_e_raw = {fReader, "FatimaVmeCalData.fqdc_e_raw"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_fqdc_t_coarse = {fReader, "FatimaVmeCalData.fqdc_t_coarse"};
   TTreeReaderArray<vector<unsigned long>> FatimaVmeCalData_fqdc_t_fine = {fReader, "FatimaVmeCalData.fqdc_t_fine"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_ftdc_id = {fReader, "FatimaVmeCalData.ftdc_id"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_ftdc_time = {fReader, "FatimaVmeCalData.ftdc_time"};
   TTreeReaderArray<vector<unsigned int>> FatimaVmeCalData_ftdc_time_raw = {fReader, "FatimaVmeCalData.ftdc_time_raw"};
   TTreeReaderArray<unsigned int> FatimaVmeTimeMachineData_fUniqueID = {fReader, "FatimaVmeTimeMachineData.fUniqueID"};
   TTreeReaderArray<unsigned int> FatimaVmeTimeMachineData_fBits = {fReader, "FatimaVmeTimeMachineData.fBits"};
   TTreeReaderArray<Double_t> FatimaVmeTimeMachineData_fundelayed_time = {fReader, "FatimaVmeTimeMachineData.fundelayed_time"};
   TTreeReaderArray<Double_t> FatimaVmeTimeMachineData_fdelayed_time = {fReader, "FatimaVmeTimeMachineData.fdelayed_time"};
   TTreeReaderArray<unsigned int> FatimaVmeTimeMachineData_fwr_subsystem_id = {fReader, "FatimaVmeTimeMachineData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> FatimaVmeTimeMachineData_fwr_t = {fReader, "FatimaVmeTimeMachineData.fwr_t"};
   TTreeReaderArray<unsigned int> GermaniumCalData_fUniqueID = {fReader, "GermaniumCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> GermaniumCalData_fBits = {fReader, "GermaniumCalData.fBits"};
   TTreeReaderArray<UChar_t> GermaniumCalData_ftrig = {fReader, "GermaniumCalData.ftrig"};
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
   TTreeReaderArray<unsigned int> bPlastTwinpeaksCalData_fUniqueID = {fReader, "bPlastTwinpeaksCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksCalData_fBits = {fReader, "bPlastTwinpeaksCalData.fBits"};
   TTreeReaderArray<unsigned int> bPlastTwinpeaksCalData_ftrig = {fReader, "bPlastTwinpeaksCalData.ftrig"};
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
   TTreeReaderArray<unsigned int> bPlastTimeMachineData_fUniqueID = {fReader, "bPlastTimeMachineData.fUniqueID"};
   TTreeReaderArray<unsigned int> bPlastTimeMachineData_fBits = {fReader, "bPlastTimeMachineData.fBits"};
   TTreeReaderArray<Double_t> bPlastTimeMachineData_fundelayed_time = {fReader, "bPlastTimeMachineData.fundelayed_time"};
   TTreeReaderArray<Double_t> bPlastTimeMachineData_fdelayed_time = {fReader, "bPlastTimeMachineData.fdelayed_time"};
   TTreeReaderArray<unsigned int> bPlastTimeMachineData_fwr_subsystem_id = {fReader, "bPlastTimeMachineData.fwr_subsystem_id"};
   TTreeReaderArray<ULong_t> bPlastTimeMachineData_fwr_t = {fReader, "bPlastTimeMachineData.fwr_t"};
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
   TTreeReaderArray<unsigned int> FatimaVmeQDCCalData_fUniqueID = {fReader, "FatimaVmeQDCCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> FatimaVmeQDCCalData_fBits = {fReader, "FatimaVmeQDCCalData.fBits"};
   TTreeReaderArray<ULong_t> FatimaVmeQDCCalData_wr_t = {fReader, "FatimaVmeQDCCalData.wr_t"};
   TTreeReaderArray<Double_t> FatimaVmeQDCCalData_coarse_time = {fReader, "FatimaVmeQDCCalData.coarse_time"};
   TTreeReaderArray<Double_t> FatimaVmeQDCCalData_fine_time = {fReader, "FatimaVmeQDCCalData.fine_time"};
   TTreeReaderArray<unsigned int> FatimaVmeQDCCalData_qlong = {fReader, "FatimaVmeQDCCalData.qlong"};
   TTreeReaderArray<unsigned int> FatimaVmeQDCCalData_qlong_raw = {fReader, "FatimaVmeQDCCalData.qlong_raw"};
   TTreeReaderArray<unsigned int> FatimaVmeQDCCalData_qshort_raw = {fReader, "FatimaVmeQDCCalData.qshort_raw"};
   TTreeReaderArray<Int_t> FatimaVmeQDCCalData_detector = {fReader, "FatimaVmeQDCCalData.detector"};
   TTreeReaderArray<unsigned int> FatimaVmeResiduals_fUniqueID = {fReader, "FatimaVmeResiduals.fUniqueID"};
   TTreeReaderArray<unsigned int> FatimaVmeResiduals_fBits = {fReader, "FatimaVmeResiduals.fBits"};
   TTreeReaderArray<Double_t> FatimaVmeResiduals_sc41l = {fReader, "FatimaVmeResiduals.sc41l"};
   TTreeReaderArray<Double_t> FatimaVmeResiduals_sc41r = {fReader, "FatimaVmeResiduals.sc41r"};
   TTreeReaderArray<Double_t> FatimaVmeResiduals_tm_delayed = {fReader, "FatimaVmeResiduals.tm_delayed"};
   TTreeReaderArray<Double_t> FatimaVmeResiduals_tm_undelayed = {fReader, "FatimaVmeResiduals.tm_undelayed"};
   TTreeReaderArray<unsigned int> FatimaVmeTDCCalData_fUniqueID = {fReader, "FatimaVmeTDCCalData.fUniqueID"};
   TTreeReaderArray<unsigned int> FatimaVmeTDCCalData_fBits = {fReader, "FatimaVmeTDCCalData.fBits"};
   TTreeReaderArray<ULong_t> FatimaVmeTDCCalData_wr_t = {fReader, "FatimaVmeTDCCalData.wr_t"};
   TTreeReaderArray<Double_t> FatimaVmeTDCCalData_timestamp = {fReader, "FatimaVmeTDCCalData.timestamp"};
   TTreeReaderArray<unsigned int> FatimaVmeTDCCalData_timestamp_raw = {fReader, "FatimaVmeTDCCalData.timestamp_raw"};
   TTreeReaderArray<Int_t> FatimaVmeTDCCalData_detector = {fReader, "FatimaVmeTDCCalData.detector"};
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
   TTreeReaderArray<unsigned int> FrsMultiHitData_fUniqueID = {fReader, "FrsMultiHitData.fUniqueID"};
   TTreeReaderArray<unsigned int> FrsMultiHitData_fBits = {fReader, "FrsMultiHitData.fBits"};
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


   evt(TTree * /*tree*/ =0) { }
   virtual ~evt() { }
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

   ClassDef(evt,0);

};

#endif

#ifdef evt_cxx
void evt::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t evt::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef evt_cxx
