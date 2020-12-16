#pragma once

#include <memory>

struct HarmonicSet;

struct HarmonicSetWrapper
{
    HarmonicSetWrapper(HarmonicSet* hs) : hsPtr(hs) { }
    ~HarmonicSetWrapper() { delete hsPtr; }
    HarmonicSet* hsPtr = nullptr;
};

struct Distortion;

struct DistortionWrapper
{
    DistortionWrapper(Distortion* d) : dPtr(d) { }
    ~DistortionWrapper()
    {
        delete dPtr;
    }
    Distortion* dPtr = nullptr;
};

struct PatternGenerator;

struct PatternGeneratorWrapper
{
    PatternGeneratorWrapper(PatternGenerator* pg) : pgPtr(pg) { }
    ~PatternGeneratorWrapper() { delete pgPtr; }
    PatternGenerator* pgPtr = nullptr;
};

struct PatternPlayer;

struct PatternPlayerWrapper
{
    PatternPlayerWrapper(PatternPlayer* pp) : ppPtr(pp) { }
    ~PatternPlayerWrapper() { delete ppPtr; }
    PatternPlayer* ppPtr = nullptr;
};

struct NoiseMaker;

struct NoiseMakerWrapper
{
    NoiseMakerWrapper(NoiseMaker* nm) : nmPtr(nm) { }
    ~NoiseMakerWrapper() { delete nmPtr; }
    NoiseMaker* nmPtr = nullptr;
};
