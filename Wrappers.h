#pragma once

#include <memory>

struct HarmonicSetWrapper
{
    HarmonicSetWrapper(HarmonicSet* hs);
    ~HarmonicSetWrapper();
    HarmonicSet* hsPtr = nullptr;
};

struct DistortionWrapper
{
    DistortionWrapper(Distortion* d);
    ~DistortionWrapper();
    Distortion* dPtr = nullptr;
};

struct PatternGeneratorWrapper
{
    PatternGeneratorWrapper(PatternGenerator* pg);
    ~PatternGeneratorWrapper();
    PatternGenerator* pgPtr = nullptr;
};

struct PatternPlayerWrapper
{
    PatternPlayerWrapper(PatternPlayer* pp);
    ~PatternPlayerWrapper();
    PatternPlayer* ppPtr = nullptr;
};

struct NoiseMakerWrapper
{
    NoiseMakerWrapper(NoiseMaker* nm);
    ~NoiseMakerWrapper();
    NoiseMaker* nmPtr = nullptr;
};
