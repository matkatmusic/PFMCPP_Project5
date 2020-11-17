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
    float current, previous;

    void playSet(float minFrequency, float maxFrequency);

    float calculateHarmonicity();
    float next();
    float prev();
    void reset();

    void playFiltered(float minFrequency, float maxFrequency, int genRule);
};

HarmonicSet::HarmonicSet(float bass, float gen)
{
    bassFrequency = bass;
    genFrequency = gen;
    current = gen;
    previous = bass;
}

HarmonicSet::HarmonicSet()
{
    bassFrequency = 110.f;
    genFrequency = 220.f;
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
    for (float shriek = brightness; shriek > 0.03f; shriek *= 0.75f)
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
            if (rand() < roughness * RAND_MAX)
            {
                std::cout << "O";
            }
            else
            {
                std::cout << "o";
            }
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
};

PatternPlayer::PatternPlayer() {
    std::cout << "PatternPlayer default constructor: " << std::endl;
    printDescription();
}

PatternPlayer::PatternPlayer(float bass, float gen){
    std::cout << "PatternPlayer constructor with bass " << bass << " and gen " << gen << std::endl;
    harmonicSet.bassFrequency = bass;
    harmonicSet.genFrequency = gen;
    harmonicSet.reset();
    printDescription();
}

PatternPlayer::~PatternPlayer() {
    std::cout << "Pattern Player switched off" << std::endl;

}

void PatternPlayer::printDescription () 
{
    std::cout << "Harmonic set: " << harmonicSet.bassFrequency << " and " << harmonicSet.genFrequency << std::endl;
}

void PatternPlayer::matchNote(int i) {
    if (i < currentNote) 
    {
        harmonicSet.prev();
        currentNote -= 1;
        std::cout << "matchNote rewind to " << currentNote << std::endl;
        matchNote(i);
    }
    else if (i > currentNote) 
    {
        harmonicSet.next();
        currentNote += 1;
        std::cout << "matchNote forward to " << currentNote << std::endl;
        matchNote(i);
    }
}

void PatternPlayer::play() {

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

struct NoiseMaker {
    NoiseMaker();
    ~NoiseMaker();

    Distortion distortion;

    void makeSomeNoise();
};

NoiseMaker::NoiseMaker() {
    distortion.brightness = 1.0f;
    distortion.roughness = 0.5f;
    distortion.numEchoes = 6;
}

NoiseMaker::~NoiseMaker() 
{
    std::cout << "Shutting off NoiseMaker" << std::endl;
}

void NoiseMaker::makeSomeNoise() {
    distortion.processInput();
}



#include <iostream>
int main()
{

    HarmonicSet hs;
    std::cout << hs.bassFrequency << std::endl;
    std::cout << hs.genFrequency << std::endl;
    std::cout << hs.next() << " ^";
    std::cout << hs.next() << " ^";
    std::cout << hs.next() << " ^";
    std::cout << hs.next() << " v";
    std::cout << hs.prev() << " ^";
    std::cout << hs.next() << " v";
    std::cout << hs.prev() << " v";
    std::cout << hs.prev() << std::endl;

    std::cout << "current: " << hs.current << std::endl;
    std::cout << "previous: " << hs.previous << std::endl;

    HarmonicSet hs2(130.f, 450.f);
    std::cout << hs2.bassFrequency << std::endl;
    std::cout << hs2.genFrequency << std::endl;
    std::cout << hs2.next() << " ^";
    std::cout << hs2.next() << " ^";
    std::cout << hs2.next() << " ^";
    std::cout << hs2.next() << " v";
    std::cout << hs2.prev() << " ^";
    std::cout << hs2.next() << " v";
    std::cout << hs2.prev() << " v";
    std::cout << hs2.prev() << std::endl;

    std::cout << "current: " << hs2.current << std::endl;
    std::cout << "previous: " << hs2.previous << std::endl;

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

    HarmonicSet harmonicSet = HarmonicSet(220.0f, 440.0f);
    harmonicSet.playSet(220.0f, 22000.0f);
    HarmonicSet harmonicSetTwo(100.0f, 360.0f);
    harmonicSetTwo.playSet(10.f, 22000.0f);
    std::cout << "Sum of bass and generator is " << harmonicSetTwo.calculateHarmonicity() << std::endl;

    Distortion ds2;
    ds2.processInput();

    ds2.numEchoes = 15;
    ds2.processInput();


    std::cout << "good to go!" << std::endl;
}
