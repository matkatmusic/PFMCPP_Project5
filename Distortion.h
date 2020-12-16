#pragma once

#include "LeakedObjectDetector.h"

struct Distortion
{
    Distortion();
    ~Distortion();

    float brightness;
    int numEchoes;
    float roughness;
    int vinylTap;

    void processInput();

    float calculateBrightness(float roomSize, float hiPass, float loPass);

    bool toggleBypass(bool bypass = false);

    void printCalculateBrightness(float first, float second, float third);

    JUCE_LEAK_DETECTOR(Distortion)
};
