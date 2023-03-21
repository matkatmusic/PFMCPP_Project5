/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */
#include <iostream>

struct Headphones
{
    Headphones();
    ~Headphones();

    struct Microphone
    {
        Microphone();
        ~Microphone();

        float inputGain = 0.25f;
        bool flexibleConstruction { false };
        bool EnablementState = true;
        bool currentState;

        void setState(bool state);
        bool getState(bool toggleStateOnRequest = false);
        float trackInputLevel(bool useGainToDecibelsTransformation = false, bool strobeLedOnClipping = false);
        void displayInitState();
    };

    int impedance = 250;
    float spectrumDistribution { 3.3f };
    char wireLength;
    bool isClosed;
    std::string manufacturer = " ";

    void startPlayingSound(float gainCompensation = 1.0f);
    float changeEarcupPosition(char position); // returns a dimension from top to the earcup
    void imitateSurround(bool isSurround = false);

    void changeMicrophoneInputGain(Microphone connectedMicrophone, float targetGain);
    void decreaseInputSensitivityOnClipping(Microphone connectedMicrophone);
    std::string getConnectedMicrophoneID(Microphone connectedMicrophone, bool withHeadphonesIDAppended = false);
    void displayInitState();

    Microphone mike;
};
// ================================================================================
Headphones::Headphones() : wireLength('3'), isClosed(false)
{
    std::cout << "Headphones constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

Headphones::~Headphones()
{
    std::cout << "Headphones destructor launched" << std::endl;    
}

Headphones::Microphone::Microphone() : currentState(false)
{
    std::cout << "Headphones::Microphone constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

Headphones::Microphone::~Microphone()
{
    std::cout << "Headphones::Microphone destructor launched" << std::endl;    
}
// ================================================================================
void Headphones::Microphone::setState(bool state)
{
    std::cout << "Microphone state changed to " << state << std::endl;
}

bool Headphones::Microphone::getState(bool toggleStateOnRequest)
{
    if (toggleStateOnRequest)
    {
        currentState = !currentState;
        std::cout << "Mike's state has been changed on state request\n";        
    }
    else
        std::cout << "Mike's state stayed the same\n";  
    return currentState;
}

float Headphones::Microphone::trackInputLevel(bool useGainToDecibelsTransformation, bool strobeLedOnClipping)
{
    float inputLevel = -4.3f; // arbitralily taken value supposed to be recieved from input gain controller state
    if (useGainToDecibelsTransformation)
        std::cout << "Gain to Decibels transformation applied\nInput level is " << inputLevel << std::endl;
    if (strobeLedOnClipping)
        std::cout << "Signal has been sent to LED\n";
    return inputLevel;
}

void Headphones::startPlayingSound(float gainCompensation)
{
    float inputLevel = -4.3f * gainCompensation;
    std::cout << "Playback started with level: " << inputLevel << std::endl;
}

float Headphones::changeEarcupPosition(char position)
{
    std::cout << "New earcup position has been set";
    return position;
}

void Headphones::imitateSurround(bool isSurround)
{
    if (isSurround)
        std::cout << "Surround imitation enabled\n";
    else
        std::cout << "Surround imitation disabled\n";

    std::cout << "Warning. Surround imitation might have a malfunction with " << impedance << " Ohm\n";
}

void Headphones::displayInitState()
{
    std::cout << "Impedance = " << impedance << std::endl
              << "Spectrum distribution = " << spectrumDistribution << std::endl
              << "Wire length = " << wireLength << std::endl
              << "Is closed = " << isClosed << std::endl
              << "Manufacturer: " << manufacturer << std::endl;
}

void Headphones::Microphone::displayInitState()
{
    std::cout << "Input gain = " << inputGain << std::endl
              << "Flexible construction = " << flexibleConstruction << std::endl
              << "Enablement state = " << EnablementState << std::endl
              << "Current state = " << currentState << std::endl;
}
/*
 copied UDT 2:
 */
struct OscillatorSection
{
    OscillatorSection();
    OscillatorSection(std::string);
    ~OscillatorSection();

    struct Waveform
    {
        Waveform();
        ~Waveform();

        std::string waveformName = "sine";
        bool keyTrack;
        int initialPhase { 180 };

        void invertPhase(int initialPhase);
        void useFadeIn(float fadeInDuration = 0.01f);
        void fillEntireWaveTable(char transformationTypeIndex = 0);
        void displayInitState();
    };
    std::string oscName = "Basic oscillator";
    char waveformIndex;
    float unisonSpread = 0.5f;
    float level = 0.67f;
    float pan { 0.0f };
    short amountOfVoices;

    std::string getWaveformName(Waveform requestedWaveform); // returns waveform's name
    bool getKeyTrackState(Waveform requestedWaveform); // returns key tracking state
    void trackPhase(Waveform targetWaveform);
    void setName(std::string newOscName);
    void displayInitState();

    Waveform sine;
};
// ================================================================================
OscillatorSection::OscillatorSection() : waveformIndex('0'), amountOfVoices(1)
{
    std::cout << "OscillatorSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::OscillatorSection(std::string explicitOscName) : waveformIndex('0'), amountOfVoices(1) // overloaded constructor
{
    oscName = explicitOscName;
    std::cout << "OscillatorSection OVERLOADED constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::~OscillatorSection()
{
    std::cout << "OscillatorSection destructor launched" << std::endl;
}

OscillatorSection::Waveform::Waveform() : keyTrack(false)
{
    std::cout << "OscillatorSection::Waveform constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::Waveform::~Waveform()
{
    std::cout << "OscillatorSection::Waveform destructor launched" << std::endl;
}
// ================================================================================
void OscillatorSection::Waveform::invertPhase(int phase)
{
    int tempPhase = phase;
    if (phase < 0) phase += 180;
    else phase -= 180;
    std::cout << "Phase inverted";
    std::cout << "Previous phase " << tempPhase << " has been inverted to " << phase << std::endl;
}

void OscillatorSection::Waveform::useFadeIn(float fadeInDuration)
{
    std::cout << "Applied Fade In: " << fadeInDuration << std::endl;
}

void OscillatorSection::Waveform::fillEntireWaveTable(char transformationTypeIndex)
{
    std::cout << "Wavetable filled with transformation algorithm No: " << transformationTypeIndex << std::endl;
}

std::string OscillatorSection::getWaveformName(Waveform requestedWaveform)
{
    return requestedWaveform.waveformName;
}

bool OscillatorSection::getKeyTrackState(Waveform requestedWaveform)
{
    return requestedWaveform.keyTrack;
}

void OscillatorSection::trackPhase(Waveform targetWaveform)
{
    bool isPlaying = false; // checks if the midi-key is pushed
    int phase = 181; // supposed to be refreshed every sync time tick
    int currentPhase = !isPlaying ? targetWaveform.initialPhase : phase;
    std::cout << "Phase is being tracked now\nCurrent phase is " << currentPhase << std::endl;
}

void OscillatorSection::setName(std::string newOscName)
{
    std::string tempOscName = oscName;
    oscName = newOscName;
    std::cout << "Previous oscillator name " << tempOscName << " has been changed to " << oscName << std::endl;
}

void OscillatorSection::displayInitState()
{
    std::cout << "Oscillator name: " << oscName << std::endl
              << "Waveform index = " << waveformIndex << std::endl
              << "Unison spread = " << unisonSpread << std::endl
              << "Level = " << level << std::endl
              << "Amount of voices = " << amountOfVoices << std::endl;
}

void OscillatorSection::Waveform::displayInitState()
{
    std::cout << "Waveform Name: " << waveformName << std::endl
              << "Key track = " << keyTrack << std::endl
              << "initial phase = " << initialPhase << std::endl;
}
/*
 copied UDT 3:
 */
struct FilterSection
{
    FilterSection();
    ~FilterSection();

    std::string filterName = "Basic Filter";
    float cutFrequency = 15000.0f;
    float qualityFactor = 1.0f;
    float gain;
    float mix;
    char combPatternIndex { '0' };

    std::string getFilteringAlgorithm(bool considerMixAmount = false); // returns algorithm of filtering
    void setParametricQuality(float coefficientOfQualityAndGainInteraction);
    void flipHorizontally(float pivotFrequencyOffset);
    void displayInitState();
};
// ================================================================================
FilterSection::FilterSection() : gain(0.0f), mix(1.0f)
{
    std::cout << "FilterSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

FilterSection::~FilterSection()
{
    std::cout << "FilterSection destructor launched" << std::endl;
}
// ================================================================================
std::string FilterSection::getFilteringAlgorithm(bool considerMixAmount)
{
    std::string algorithmLine = "Filter Algorithm is normal";
    std::string considerationLine = (considerMixAmount ? " with mix amount considered\n" : "\n");
    std::cout << algorithmLine + considerationLine << std::endl;
    return algorithmLine + considerationLine;
}

void FilterSection::setParametricQuality(float coefficientOfQualityAndGainInteraction)
{
    std::cout << "Quality is now bound to Gain with " << coefficientOfQualityAndGainInteraction << std::endl;
    std::cout << "Quality factor is " << qualityFactor << " combined with " << gain << " gain\n";
}

void FilterSection::flipHorizontally(float pivotFrequencyOffset)
{
    std::cout << "Filter pattern flipped with " << pivotFrequencyOffset << " horizontal offset\n";
}

void FilterSection::displayInitState()
{
    std::cout << "Filter name: " << filterName << std::endl
              << "Cut frequency = " << cutFrequency << std::endl
              << "Quality factor = " << qualityFactor << std::endl
              << "Gain = " << gain << std::endl
              << "Mix = " << mix << std::endl
              << "Comb pattern index = " << combPatternIndex << std::endl;
}
/*
 new UDT 4:
 with 2 member functions
 */
struct Headset
{
    Headset();
    ~Headset();

    bool checkConnection(Headphones headphones, Headphones::Microphone mike);
    void replaceMikeWithExternal(Headphones headphones, Headphones::Microphone mike);

    Headphones BeyerdynamicsDT1990;
    Headphones::Microphone ShureSM7B;
};
// ================================================================================
Headset::Headset()
{
    std::cout << "Headset constructor launched" << std::endl;
    BeyerdynamicsDT1990.startPlayingSound(0.99f);
}

Headset::~Headset()
{
    std::cout << "Headset destructor launched" << std::endl;
    ShureSM7B.setState(false);
}
// ================================================================================
bool Headset::checkConnection(Headphones headphones, Headphones::Microphone mike)
{
    if (headphones.manufacturer != " " && mike.inputGain != 0.0f)
    {
        std::cout << "Connection checked. Headset is available to use" << std::endl;
        return true;
    }
    std::cout << "Connection checked. Headset is unavailable to use" << std::endl;
    return false;
}

void Headset::replaceMikeWithExternal(Headphones headphones, Headphones::Microphone mike)
{
    headphones.mike = mike;
    std::cout << "Headphones internal microphone replaced by external one" << std::endl;
}
/*
 new UDT 5:
 with 2 member functions
 */
struct GeneratorChain
{
    GeneratorChain();
    ~GeneratorChain();

    float calculateTotalLevel(OscillatorSection osc, FilterSection filter);
    void fadeInFilterMix(FilterSection filter);

    OscillatorSection osc1 { "SawOsc" };
    FilterSection FormantAOUI;
};
// ================================================================================
GeneratorChain::GeneratorChain()
{
    std::cout << "GeneratorChain constructor launched" << std::endl;
    FormantAOUI.getFilteringAlgorithm(true);
}

GeneratorChain::~GeneratorChain()
{
    std::cout << "GeneratorChain destructor launched" << std::endl;
    std::cout << "Last filter used: " << FormantAOUI.filterName << std::endl;
}
// ================================================================================

float GeneratorChain::calculateTotalLevel(OscillatorSection osc, FilterSection filter)
{
    std::cout << "Calculating total level..." << std::endl;
    return osc.level * filter.gain;
}

void GeneratorChain::fadeInFilterMix(FilterSection filter)
{
    if (filter.mix != 0.0f)
    {
        float temp = filter.mix;
        filter.mix = 0.0f;
        // for (int i = 0; i <= (int) (temp * 10); i++)
        //     {
        //         filter.mix += 0.1f;
        //         std::cout << filter.mix << std::endl;
        //     }
        for (float i = 0.0f; i <= temp + 0.1f; i += 0.1f)    // not really a common usage of an iterator but it works :)
        {
            filter.mix = i;
            std::cout << "Current filter mix amount: " << filter.mix << std::endl;            
        }
    }
    else std::cout << "Error. Mix amount is 0.0f" << std::endl;
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    std::cout << "\n";

    Headphones sennheiserHDxxx;
    Headphones::Microphone neumannRandomMike;
    OscillatorSection sineOsc("Sine Osc"), trisineOsc("trisine Osc");
    OscillatorSection::Waveform saw, square;
    FilterSection negativeComb;
    GeneratorChain chain1;
    Headset customSet;
    std::cout << "\n";

    sennheiserHDxxx.changeEarcupPosition(2);
    sennheiserHDxxx.imitateSurround(true);
    sennheiserHDxxx.startPlayingSound(0.69f);
    std::cout << "\n";

    neumannRandomMike.getState(true);
    neumannRandomMike.setState(true);
    neumannRandomMike.trackInputLevel(false, true);
    std::cout << "\n";

    sineOsc.getKeyTrackState(saw);
    sineOsc.getWaveformName(saw);
    sineOsc.setName("Hypersaw");
    sineOsc.trackPhase(saw);
    std::cout << "\n";

    saw.fillEntireWaveTable(1);
    square.useFadeIn(0.11f);
    saw.invertPhase(-60);
    std::cout << "\n";

    negativeComb.flipHorizontally(-0.2f);
    negativeComb.getFilteringAlgorithm(/*false*/);
    negativeComb.setParametricQuality(0.88f);
    std::cout << "\n";

    customSet.checkConnection(sennheiserHDxxx, neumannRandomMike);
    customSet.replaceMikeWithExternal(sennheiserHDxxx, neumannRandomMike);
    std::cout << "\n";

    chain1.calculateTotalLevel(trisineOsc, negativeComb);
    chain1.fadeInFilterMix(negativeComb);
    std::cout << "\n";
    
    std::cout << "good to go!" << std::endl;
}
