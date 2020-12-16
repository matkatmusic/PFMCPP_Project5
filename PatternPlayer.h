#pragma once

#include "LeakedObjectDetector.h"

#include "PatternGenerator.h"


struct PatternPlayer 
{
    PatternPlayer();
    PatternPlayer(float bass, float gen);
    ~PatternPlayer();

    PatternGenerator patternGenerator;
    PatternGenerator::Pattern pattern = patternGenerator.generatePattern();
    HarmonicSet harmonicSet;
    Distortion distortion;

    int currentNote = 1;

    void printDescription();
    void matchNote(int i);
    void play();

    JUCE_LEAK_DETECTOR(PatternPlayer)
};
