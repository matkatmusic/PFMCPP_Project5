#pragma once

#include "LeakedObjectDetector.h"

#include "Distortion.h"

struct NoiseMaker 
{
    NoiseMaker();
    ~NoiseMaker();

    Distortion distortion;

    void makeSomeNoise();

    JUCE_LEAK_DETECTOR(NoiseMaker)
};
