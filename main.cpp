/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */





#include <iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

struct HarmonicSet
{
    HarmonicSet(float bass = 110.f, float gen = 220.f) : 
        bassFrequency(bass), 
        genFrequency(gen), 
        current(gen), 
        previous(bass)
    {
        reset();
    }
    ~HarmonicSet();

    float bassFrequency, genFrequency;
    float current, previous;

    void playSet(float minFrequency, float maxFrequency);

    float calculateHarmonicity();
    float next();
    float prev();
    void reset();

    void playFiltered(float minFrequency, float maxFrequency, int genRule);

    void printNext()
    {
        std::cout << " ^" << this->next();
    }
    
    void printPrev()
    {
        std::cout << " v" << this->prev();
    }
    
    void printBassFrequency()
    {
        std::cout << this->bassFrequency << std::endl;
    }
    
    void printGenFrequency()
    {
        std::cout << this->genFrequency << std::endl;
    }

    void printCurrent()
    {
        std::cout << "Current: " << this->current << std::endl;
    }

    void printPrevious()
    {
        std::cout << "Previous: " << this->previous << std::endl;
    }

    void printCalculateHarmonicity()
    {
        std::cout << "SUM OF BASS AND GENERATOR IS " << this->calculateHarmonicity() << std::endl;
    }

    JUCE_LEAK_DETECTOR(HarmonicSet)
};

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

struct HarmonicSetWrapper
{
    HarmonicSetWrapper(HarmonicSet* hs) : hsPtr(hs) { }
    ~HarmonicSetWrapper() { delete hsPtr; }
    HarmonicSet* hsPtr = nullptr;
};


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

    void printCalculateBrightness(float first, float second, float third)
    {
        std::cout << "BRIGHTNESS: " << this->calculateBrightness(first, second, third) << std::endl;
    }

    JUCE_LEAK_DETECTOR(Distortion)
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
    // for (float shriek = brightness; shriek > 0.03f; shriek *= 0.75f)
    // {
    //     for (int i = int(shriek * 30); i > 0; i -= 1)
    //     {
    //         std::cout << "+-";
    //     }
    //     std::cout << std::endl;
    // }
}

void Distortion::processInput()
{
    std::cout << "DISTORRTIIOOOOON"<< std::endl;
    // for (int n = numEchoes; n > 0; n -= 1)
    // {
    //     std::cout << "DISTORRTI";
    //     for (int m = n; m > 0; m -= 1)
    //     {
    //         if (rand() < roughness * RAND_MAX)
    //         {
    //             std::cout << "O";
    //         }
    //         else
    //         {
    //             std::cout << "o";
    //         }
    //     }
    //     std::cout << "N" << std::endl;
    // }
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

    void calculateNote(HarmonicSet harmonies);
    Pattern generatePattern();

    JUCE_LEAK_DETECTOR(PatternGenerator)
};

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

void PatternGenerator::calculateNote(HarmonicSet harmonies)
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


/*
 new UDT 4:
 */

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

PatternPlayer::PatternPlayer() 
{
    std::cout << "PatternPlayer default constructor: " << std::endl;
    printDescription();
}

PatternPlayer::PatternPlayer(float bass, float gen)
{
    std::cout << "PatternPlayer constructor with bass " << bass << " and gen " << gen << std::endl;
    harmonicSet.bassFrequency = bass;
    harmonicSet.genFrequency = gen;
    harmonicSet.reset();
    printDescription();
}

PatternPlayer::~PatternPlayer() 
{
    std::cout << "Pattern Player switched off" << std::endl;

}

void PatternPlayer::printDescription () 
{
    std::cout << "Harmonic set: " << harmonicSet.bassFrequency << " and " << harmonicSet.genFrequency << std::endl;
}

void PatternPlayer::matchNote(int i) 
{
    if (i < currentNote) 
    {
        harmonicSet.prev();
        currentNote -= 1;
        // std::cout << "matchNote rewind to " << currentNote << std::endl;
        matchNote(i);
    }
    else if (i > currentNote) 
    {
        harmonicSet.next();
        currentNote += 1;
        // std::cout << "matchNote forward to " << currentNote << std::endl;
        matchNote(i);
    }
}

void PatternPlayer::play() 
{

    pattern.printName();

    matchNote(pattern.startingNote);
    int endingNote = pattern.startingNote + pattern.numberOfNotes;

    for (int i = pattern.startingNote; i < endingNote; i++) 
    {
        std::cout << harmonicSet.next() << " ";
        currentNote += 1;
        for (int j = 0; j < distortion.numEchoes; j++)
        {
            std::cout << "*";
        }
    }

    if (pattern.repeat)
    {
        std::cout << std::endl;
        std::cout << pattern.startingNote << " and " << currentNote << std::endl;
        matchNote(pattern.startingNote);

        for (int i = pattern.startingNote; i < endingNote; i++) 
        {
            std::cout << harmonicSet.next() << " ";
            currentNote += 1;
            for (int j = 0; j < distortion.numEchoes; j++)
            {
                std::cout << "#";
            }
        }
    }

    std::cout << std::endl;
    
}

/*
 new UDT 5:
 */

struct NoiseMaker 
{
    NoiseMaker();
    ~NoiseMaker();

    Distortion distortion;

    void makeSomeNoise();

    JUCE_LEAK_DETECTOR(NoiseMaker)
};

NoiseMaker::NoiseMaker() 
{
    distortion.brightness = 1.0f;
    distortion.roughness = 0.5f;
    distortion.numEchoes = 6;
}

NoiseMaker::~NoiseMaker() 
{
    std::cout << "Shutting off NoiseMaker" << std::endl;
}

void NoiseMaker::makeSomeNoise() 
{
    distortion.processInput();
}



#include <iostream>
int main()
{

    HarmonicSet hs;
    std::cout << hs.bassFrequency << std::endl;
    std::cout << hs.genFrequency << std::endl;
    std::cout << " ^" << hs.next();
    std::cout << " ^" << hs.next();
    std::cout << " ^" << hs.next();
    std::cout << " ^" << hs.next();
    std::cout << " v" << hs.prev();
    std::cout << " ^" << hs.next();
    std::cout << " v" << hs.prev();
    std::cout << " v" << hs.prev();
    std::cout << std::endl;

    std::cout << "current: " << hs.current << std::endl;
    std::cout << "previous: " << hs.previous << std::endl;

    // here I've just changed the second HarmonicSet to use member functions
    HarmonicSet hs2(15.f, 40.f);
    hs2.printBassFrequency();
    hs2.printGenFrequency();
    hs2.printNext();
    hs2.printNext();
    hs2.printNext();
    hs2.printNext();
    hs2.printPrev();
    hs2.printNext();
    hs2.printPrev();
    hs2.printPrev();
    std::cout << std::endl;

    std::cout << "current: " << hs2.current << std::endl;
    hs2.printCurrent();
    std::cout << "previous: " << hs2.previous << std::endl;
    hs2.printPrevious();

    Distortion distorition;

    PatternPlayer pp;
    pp.play();

    PatternPlayer pp2(440.f, 442.f);
    pp2.distortion.numEchoes = 5;
    pp2.pattern.patternName = "pattern 2";
    pp2.pattern.startingNote = 6;
    pp2.pattern.numberOfNotes = 7;
    pp2.play();

    NoiseMaker nm;
    nm.makeSomeNoise();

    std::cout << "*=-=*=-=*=-=*=-=*=-=* old stuff *=-=*=-=*=-=*=-=*=-=*" << std::endl;

    PatternGenerator::Pattern pattern;
    std::cout << "pattern's name: " << pattern.patternName << std::endl;
    pattern.printName(); // prints the same name

    PatternGenerator pg;
    pg.generatePattern(); // prints "new pattern: 12345"

    Distortion ds;
    ds.processInput();
    std::cout << "brightness: " << ds.calculateBrightness(250.f, 300.f, 100.f) << std::endl;
    std::cout << "brightness: " << ds.calculateBrightness(350.f, 300.f, 200.f) << std::endl;
    ds.printCalculateBrightness(250.f, 300.f, 100.f);
    ds.printCalculateBrightness(350.f, 300.f, 200.f);

    HarmonicSet harmonicSet = HarmonicSet(220.0f, 440.0f);
    harmonicSet.playSet(220.0f, 22000.0f);
    HarmonicSet harmonicSetTwo(100.0f, 360.0f);
    harmonicSetTwo.playSet(10.f, 22000.0f);
    std::cout << "Sum of bass and generator is " << harmonicSetTwo.calculateHarmonicity() << std::endl;
    harmonicSetTwo.printCalculateHarmonicity();

    Distortion ds2;
    ds2.processInput();

    ds2.numEchoes = 15;
    ds2.processInput();


    std::cout << "good to go!" << std::endl;
}
