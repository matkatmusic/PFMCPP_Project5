#pragma once

#include "LeakedObjectDetector.h"

struct HarmonicSet;

struct PatternGenerator
{
    PatternGenerator();
    ~PatternGenerator();
    float rootedness;
    float repetitionPercentage;
    int stepSize;
    float variability;
    float fractalDimension;

    struct Pattern
    {
        Pattern();
        bool repeat; 
        int numberOfNotes;  
        int startingNote;  
        bool isArpeggio;    
        std::string patternName;

        void printName();
        void reverse();
        void stop();
    };

    void calculateNote(HarmonicSet& harmonies);
    Pattern generatePattern();

    JUCE_LEAK_DETECTOR(PatternGenerator)
};
