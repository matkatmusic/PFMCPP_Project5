/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>

/*
 copied UDT 1:
 */

struct HarmonicSet
{
    HarmonicSet(float bass, float gen);
    HarmonicSet();
    ~HarmonicSet();

    float bassFrequency, genFrequency;

    void playSet(float minFrequency, float maxFrequency);

    float calculateHarmonicity();

    void playFiltered(float minFrequency, float maxFrequency, int genRule);
};

HarmonicSet::HarmonicSet(float bass, float gen)
{
    bassFrequency = bass;
    genFrequency = gen;
}

HarmonicSet::HarmonicSet()
{
    bassFrequency = 110;
    genFrequency = 220;
}

HarmonicSet::~HarmonicSet()
{
    std::cout << "Destructor of Harmonic Set with bass " << bassFrequency << " and gen " << genFrequency << std::endl;
}

void HarmonicSet::playSet(float minFrequency, float maxFrequency)
{
    std::cout << "Harmonic set of bass " << bassFrequency << " and generator " << genFrequency << std::endl;
    float outputNote = (bassFrequency + genFrequency);
    float previous = genFrequency;
    while (outputNote < maxFrequency) 
    {
        if (minFrequency < outputNote)
        {
            std::cout << outputNote << " ";
        }
        float current = outputNote;
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


/*
 copied UDT 2:
 */

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
};

Distortion::Distortion()
{
    brightness = 0.5f;
    numEchoes = 3;
    roughness = 0.8f;
    vinylTap = 11;
}

Distortion::~Distortion()
{
    std::cout << "Distortion switched off" << std::endl;
    for (float shriek = brightness; shriek > 0.01f; shriek *= 0.75f)
    {
        for (int i = int(shriek * 30); i > 0; i -= 1)
        {
            std::cout << "+-";
        }
        std::cout << std::endl;
    }
}

void Distortion::processInput()
{
    std::cout << "DISTORRTIIOOOOON"<< std::endl;
    for (int n = numEchoes; n > 0; n -= 1)
    {
        std::cout << "DISTORRTI";
        for (int m = n; m > 0; m -= 1)
        {
            std::cout << "O";
        }
        std::cout << "N" << std::endl;
    }
}

float Distortion::calculateBrightness(float roomSize, float hiPass, float loPass)
{
    if (roomSize < loPass)
    {
        return loPass;
    }
    if (roomSize > hiPass)
    {
        return hiPass;
    }
    return roomSize;
}

bool Distortion::toggleBypass(bool bypass)
{
    return !bypass;
}

/*
 copied UDT 3:
 */

struct PatternGenerator
{
    PatternGenerator();
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
        int startingMIDI;  
        bool isArpeggio;    
        std::string patternName;

        void play();
        void reverse();
        void stop();
    };

    // void getRhythm(RhythmicRules rhythms); 
    void calculateNote(HarmonicSet harmonies);
    Pattern generatePattern();
};

PatternGenerator::PatternGenerator()
{
    rootedness = 1.0f;
    repetitionPercentage = 0.15f;
    stepSize = 2;
    variability = 1.0f;
    fractalDimension = 1.618f;
}

PatternGenerator::Pattern::Pattern()
{
    repeat = false; 
    numberOfNotes = 5;  
    startingMIDI = 69;  
    isArpeggio = true;    
    patternName = "triads";
}

// void PatternGenerator::getRhythm(RhythmicRules rhythms)
// {
//     RhythmicRules::Meter meter;
//     rhythms.outputRhythm(meter);
// }

void PatternGenerator::calculateNote(HarmonicSet harmonies)
{
    harmonies.calculateHarmonicity();
}
    
PatternGenerator::Pattern PatternGenerator::generatePattern()
{
    PatternGenerator::Pattern newPattern;
    std::cout << "new pattern: 12345" << std::endl;
    return newPattern;
}

void PatternGenerator::Pattern::play()
{
    std::cout << patternName << std::endl;
}

void PatternGenerator::Pattern::reverse()
{

}

void PatternGenerator::Pattern::stop()
{

}


/*
 new UDT 4:
 */

/*
 new UDT 5:
 */

#include <iostream>
int main()
{
    Distortion distorition;
    std::cout << "good to go!" << std::endl;
}
