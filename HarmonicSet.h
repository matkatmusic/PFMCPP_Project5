#pragma once

#include "LeakedObjectDetector.h"

struct HarmonicSet
{
    HarmonicSet(float bass = 110.f, float gen = 220.f);
    ~HarmonicSet();

    float bassFrequency, genFrequency;
    float current, previous;

    void playSet(float minFrequency, float maxFrequency);

    float calculateHarmonicity();
    float next();
    float prev();
    void reset();

    void playFiltered(float minFrequency, float maxFrequency, int genRule);

    void printNext();
    
    void printPrev();

    void printBassFrequency();
    
    void printGenFrequency();

    void printCurrent();

    void printPrevious();

    void printCalculateHarmonicity();

    JUCE_LEAK_DETECTOR(HarmonicSet)
};
