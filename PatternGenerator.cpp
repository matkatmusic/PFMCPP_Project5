#include "PatternGenerator.h"
#include "HarmonicSet.h"

PatternGenerator::PatternGenerator()
{
    rootedness = 1.0f;
    repetitionPercentage = 0.15f;
    stepSize = 2;
    variability = 1.0f;
    fractalDimension = 1.618f;
}

PatternGenerator::~PatternGenerator()
{
    std::cout << "pattern generator destructor" << std::endl;
}

PatternGenerator::Pattern::Pattern()
{
    repeat = true; 
    numberOfNotes = 5;  
    startingNote = 1;  
    isArpeggio = true;    
    patternName = "spectra";
}

void PatternGenerator::calculateNote(HarmonicSet& harmonies)
{
    harmonies.calculateHarmonicity();
}
    
PatternGenerator::Pattern PatternGenerator::generatePattern()
{
    PatternGenerator::Pattern newPattern;
    return newPattern;
}

void PatternGenerator::Pattern::printName()
{
    std::cout << "PATTERN'S NAME: " << this->patternName << std::endl;
}

void PatternGenerator::Pattern::reverse()
{

}

void PatternGenerator::Pattern::stop()
{

}
