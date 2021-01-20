#include "Wrappers.h"

#include "HarmonicSet.h"
#include "Distortion.h"
#include "PatternPlayer.h"
#include "PatternGenerator.h"
#include "NoiseMaker.h"

HarmonicSetWrapper::HarmonicSetWrapper(HarmonicSet* hs) : hsPtr(hs) { } 
HarmonicSetWrapper::~HarmonicSetWrapper() { delete hsPtr; }
   
DistortionWrapper::DistortionWrapper(Distortion* d) : dPtr(d) { }
DistortionWrapper::~DistortionWrapper() { delete dPtr; }

PatternGeneratorWrapper::PatternGeneratorWrapper(PatternGenerator* pg) : pgPtr(pg) { }
PatternGeneratorWrapper::~PatternGeneratorWrapper() { delete pgPtr; }

PatternPlayerWrapper::PatternPlayerWrapper(PatternPlayer* pp) : ppPtr(pp) { }
PatternPlayerWrapper::~PatternPlayerWrapper() { delete ppPtr; }

NoiseMakerWrapper::NoiseMakerWrapper(NoiseMaker* nm) : nmPtr(nm) { }
NoiseMakerWrapper::~NoiseMakerWrapper() { delete nmPtr; }