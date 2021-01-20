

#include "HarmonicSet.h"
#include <iostream>

HarmonicSet::HarmonicSet(float bass, float gen) : 
    bassFrequency(bass), 
    genFrequency(gen), 
    current(gen), 
    previous(bass)
{
    reset();
}

HarmonicSet::~HarmonicSet()
{
    std::cout << "Destructor of Harmonic Set with bass " << bassFrequency << " and gen " << genFrequency << std::endl;
}

float HarmonicSet::next() 
{
    float temp = current;
    current = previous + current;
    previous = temp;
    return current;
}

float HarmonicSet::prev() 
{
    float temp = previous;
    previous = current - previous;
    current = temp; 
    return current;
}

void HarmonicSet::reset() 
{
    current = genFrequency;
    previous = bassFrequency;
}


void HarmonicSet::playSet(float minFrequency, float maxFrequency)
{
    std::cout << "Harmonic set of bass " << bassFrequency << " and generator " << genFrequency << std::endl;
    float outputNote = (bassFrequency + genFrequency);
    previous = genFrequency;
    while (outputNote < maxFrequency) 
    {
        if (minFrequency < outputNote)
        {
            std::cout << outputNote << " ";
        }
        current = outputNote;
        outputNote += previous;
        previous = current;
    }
    std::cout << std::endl;
}

float HarmonicSet::calculateHarmonicity()
{
    return bassFrequency + genFrequency;
}

void HarmonicSet::playFiltered(float minFrequency, float maxFrequency, int genRule)
{
    float outputNote = (bassFrequency + genFrequency); 
    genRule += 1; 
    if (minFrequency < outputNote)
    {
        if (maxFrequency > outputNote)
        {
            std::cout << outputNote << std::endl;
        }
    }
}

void HarmonicSet::printNext()
{
    std::cout << " ^" << this->next();
}
    
void HarmonicSet::printPrev()
{
    std::cout << " v" << this->prev();
}
    
void HarmonicSet::printBassFrequency()
{
    std::cout << this->bassFrequency << std::endl;
}
    
void HarmonicSet::printGenFrequency()
{
    std::cout << this->genFrequency << std::endl;
}

void HarmonicSet::printCurrent()
{
    std::cout << "Current: " << this->current << std::endl;
}

void HarmonicSet::printPrevious()
{
    std::cout << "Previous: " << this->previous << std::endl;
}

void HarmonicSet::printCalculateHarmonicity()
{
    std::cout << "SUM OF BASS AND GENERATOR IS " << this->calculateHarmonicity() << std::endl;
}
