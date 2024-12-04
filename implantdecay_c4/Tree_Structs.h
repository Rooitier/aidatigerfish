#ifndef ImplantDecay_h
#define ImplantDecay_h

#include <stdint.h>
#include <TObject.h>

#if defined (__MAKECINT__)
#pragma link C++ class FrsData+;
#pragma link C++ class PlasticHit+;
#pragma link C++ class vector<PlasticHit>+;
#pragma link C++ class PlasticData+;
#pragma link C++ class GammaData+;
#pragma link C++ class ImplantEntry+;
#pragma link C++ class vector<ImplantEntry>+;
#pragma link C++ class DecayEntry+;
#pragma link C++ class PlasticDecayEntry+;
#endif

#include <AidaData.h>
#include <AidaHitData.h>
#include <AidaCalData.h>

// FRS struct
struct FrsData : public TObject
{
  uint64_t WR;
  float AoQ;
  float Z;
  float Z2;
  float Sci41_E;
  float Sci42_E;
  float dE_S2;
  float dE_S4;
  float beta;
  float x2;
  float a2;
  float x4;
  float a4;

  ClassDefNV(FrsData, 2);
};

struct PlasticHit : public TObject
{
  int Detector;
  int XChan;
  int YChannel;
  double ToT;
  double LeadT;
  double T0LeadT;

  ClassDefNV(PlasticHit, 2);
};

struct PlasticData : public TObject
{
  int Detectors;
  std::vector<PlasticHit> Hits;

  ClassDefNV(PlasticData, 2);
};

struct GammaData : public TObject
{
  double Energy;

  ClassDefNV(GammaData, 2);
};

struct ImplantEntry : public TObject
{
  AidaHit Aida;
  FrsData Frs;
  PlasticData Plastic;
  double DecayTime;
  double DecayTimeFine;

  ClassDefNV(ImplantEntry, 2);
};

struct DecayEntry : public TObject
{
  AidaHit Aida;
  PlasticData Plastic;
  std::vector<GammaData> Fatima;
  std::vector<GammaData> HPGe;
  bool OnSpill;

  std::vector<ImplantEntry> Implants;
  Long64_t LastFrsTime;

  ClassDefNV(DecayEntry, 2);
};

struct PlasticDecayEntry : public TObject
{
  PlasticData Plastic;
  std::vector<ImplantEntry> Implants;
  bool OnSpill;

  ClassDefNV(PlasticDecayEntry, 2);
};

#endif
