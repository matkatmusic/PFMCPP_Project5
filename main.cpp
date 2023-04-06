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

/*
 copied UDT 2:
 */

/*
 copied UDT 3:
 */

/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
#include <iostream>
// Copied UDT #1

struct Guitar
{
    int numStrings = 6;
    int numFrets = 22;
    int volumeLevel = 40;
    std::string brand = "Gibson";
    std::string material = "Spruce Wood";
    bool inTune;

    struct Strings
    {
        float lowEStringGauge = .040f; 
        float dStringGauge = .010f;
        std::string brand = "Ernie Ball";
        std::string sku = "2229";
        std::string material ="Nickel";
        int currentPitchST;

        Strings();
        ~Strings();
        
        void bend(std::string whichString, bool bendUp);
        void slide(std::string currentNote, std::string targetNote);
        bool snap();
    };

    Guitar();
    ~Guitar();

    bool playNote(std::string whichNote);
    void tune(float CurrentCent);
    bool makePercussiveNoise();
    void increaseVolume(int targetVolume);
    
};

Guitar::Guitar() :
inTune(false)
{
    std::cout << "Guitar being constructed!" << std::endl;
}

Guitar::~Guitar()
{
    std::cout << "Guitar being deconstructed" << std::endl;
}

Guitar::Strings::Strings() :
currentPitchST(2)
{
    std::cout << "Strings being constructed!" << std::endl;
}

Guitar::Strings::~Strings()
{
    std::cout << "Strings being deconstructed" << std::endl;
}



void Guitar::Strings::bend(std::string whichString, bool bendUp)
{
    if(whichString == "Low E")
    {
        bendUp = false;
    }
    if(whichString == "A")
    {
        currentPitchST += 2;
        std::cout << "Bending note up to: " << currentPitchST << std::endl;
    }
}
void Guitar::Strings::slide(std::string currentNote, std::string targetNote)
{
    if(targetNote == "A")
    {
        if(currentNote == "G")
        {
            currentPitchST += 2;
            std::cout << "Sliding up to: " << currentPitchST << std::endl;
        }
    }
}
bool Guitar::Strings::snap()
{
    return true;
}

bool Guitar::playNote(std::string whichNote)
{
    if(whichNote == "F")
    {
        std::cout << "Now playing " << whichNote << " ." << std::endl;
        return true;
    }
    
    return false;
}

void Guitar::tune(float currentCent)
{
    if(currentCent == .00f)
    {
        inTune = true;
    }
    else
    {
        inTune = false;
        currentCent = 0;
        std::cout << "Current tuning is: " << currentCent << std::endl;
    }  
}
bool Guitar::makePercussiveNoise()
{
    std::cout << "tap tap tap" << std::endl;
    return true;
}

void Guitar::increaseVolume(int targetVolume)
{
    while (volumeLevel < targetVolume)
    {
        ++volumeLevel;
        std::cout << "Increasing volume to " << volumeLevel << std::endl; 
        if (volumeLevel == targetVolume)
        {
            std::cout << "At desired volume" << std::endl;
        }    
    }
}

// Copied UDT 2

struct Engines 
{
    int numEngines = 2;
    float powerOutput;
    float fuelEfficiency = 10.f;
    float emissions = 20.f;
    int size = 20;
    int engineSpeed = 0;

    struct Turbines
    {
        int lowPressureLenth = 84; 
        int highPressureWidth = 93;
        int fuelReleased = 0;
        std::string brand = "GE";
        std::string model = "CF3942";
        std::string material ="Titanium";
        int currentSpeed;
        int thrustLevel;
        float currentPressure;

        Turbines();
        ~Turbines();

        void increaseThrustLevel(int targetLevel);
        void increaseSpeed(int targetSpeed);
        void increasePressure(int targetPressure);
        void releaseFuel(int amount);
    };

    Engines();
    ~Engines();

    bool engageThrust(Turbines thrust,bool turbinesEngaged);
    void increasePower(int amountOfIncrease);
    void controlSpeed();
};

Engines::Engines() :
powerOutput{.30f}
{
    std::cout << "Engines being constructed!" << std::endl;
}

Engines::~Engines()
{
    std::cout << "Engines being deconstructed" << std::endl;
}

Engines::Turbines::Turbines() :
currentSpeed(0),
thrustLevel(0),
currentPressure{.00f}
{
    std::cout << "Turbines being constructed!" << std::endl;
}

Engines::Turbines::~Turbines()
{
    std::cout << "Turbines being deconstructed" << std::endl;
}

void Engines::Turbines::increaseThrustLevel(int targetLevel)
{
    if(targetLevel == 20)
    {
        thrustLevel += 20;
        std::cout << "Thrust level increased to " << thrustLevel << std::endl;
    }
}
void Engines::Turbines::increaseSpeed(int targetSpeed)
{
    if(targetSpeed == 20)
    {
        currentSpeed += 20;
        std::cout << "Speed increased to " << currentSpeed << std::endl;
    }
}
void Engines::Turbines::increasePressure(int targetPressure)
{
    if(targetPressure == 40)
    {
        currentPressure += 40;
        std::cout << "Pressure increased to " << currentPressure << std::endl;
    }
}

void Engines::Turbines::releaseFuel(int amount)
{
    while (fuelReleased < amount)
    {
        fuelReleased += 2;
        std::cout << "Releasing fuel... " << fuelReleased << " liters released so far." << std::endl;
    }
}

bool Engines::engageThrust(Turbines thrust, bool turbinesEngaged)
{
    if(turbinesEngaged == true)
    {
        int targetLevel = 20;
        thrust.increaseThrustLevel(targetLevel);
        return true;
    }
    
    return false;
}
void Engines::increasePower(int amountOfIncrease)
{
    if(amountOfIncrease == 40)
    {
        powerOutput += 40;
        std::cout << "Power output increased to " << powerOutput << std::endl;
    }
}
void Engines::controlSpeed()
{
    if(engineSpeed == 0)
    {
        engineSpeed += 10;
        std::cout << "Speed controlled to " << engineSpeed << std::endl;
    }
}

// Copied UDT 3
struct Fuselage
{
    int length; int width; int capacity;
    float height = 19.f;
    float drag = 32.2f;

    Fuselage();
    ~Fuselage();

    void encloseCabin();
    void supportWingsAndTail();
    void maintainInternalPressure();
    void receivePassengers(int passengerCount);
};

Fuselage::Fuselage() :
length(40),
width(60),
capacity(10)
{
    std::cout << "Fuselage being constructed!" << std::endl;
}

Fuselage::~Fuselage()
{
    std::cout << "Fuselage being deconstructed" << std::endl;
}

void Fuselage::encloseCabin()
{
    std::cout << "Cabin enclosed." << std::endl;
}
void Fuselage::supportWingsAndTail()
{
    std::cout << "Supporting wings and tail." << std::endl;
}
void Fuselage::maintainInternalPressure()
{
    if(capacity >= 50)
    {
        std::cout << "Maintaining internal pressure at a capacity of: "<< capacity << std::endl;
    }
    else
    {
        std::cout << "Cannot maintain internal pressure. Increase capacity." << std::endl;
    }
}

void Fuselage::receivePassengers(int passengerCount)
{
    int availableCap = capacity;
    for (int i = 0; i < passengerCount; ++i)
    {
        if (availableCap > 0)
        {
            --availableCap;
            std::cout << "Passenger " << i + 1 << " has boarded. " << availableCap <<" more passengers can fit." << std::endl;
        }
        else
        {
            std::cout << "Fuselage is at full capacity. Cannot board any more passengers." << std::endl;
        }
    }
}

// New UDT 4

struct GuitarCollector
{
    Guitar gib;
    Guitar lp;
    
    void raiseMultipleVolumes();
    void tuneAll();
    GuitarCollector();
    ~GuitarCollector();
};

GuitarCollector::GuitarCollector()
{
    std::cout << "GuitarCollector being constructed" << std::endl;
}

GuitarCollector::~GuitarCollector()
{
    std::cout << "GuitarCollector being deconstructed" << std::endl;
}

void GuitarCollector::raiseMultipleVolumes()
{
    gib.increaseVolume(70);
    lp.increaseVolume(50);
}

void GuitarCollector::tuneAll()
{
    gib.tune(.03f);
    lp.tune(.04f);
}

// New UDT 5

struct CoreOfPlane
{
    Engines eg;
    Engines::Turbines tb;
    Fuselage fs;

    void adjustPressures();
    void startUp();
    CoreOfPlane();
    ~CoreOfPlane();
    
};

CoreOfPlane::CoreOfPlane()
{
    std::cout << "CoreOfPlane being constructed" << std::endl;
}

CoreOfPlane::~CoreOfPlane()
{
    std::cout << "CoreOfPlane being deconstructed" << std::endl;
}

void CoreOfPlane::adjustPressures()
{
    tb.increasePressure(50);
    fs.maintainInternalPressure();
}

void CoreOfPlane::startUp()
{
    eg.engageThrust(tb, true);
    fs.encloseCabin();
    fs.supportWingsAndTail();
}


int main()
{
    Guitar gib;
    Guitar::Strings eball;
    gib.playNote("F");
    gib.tune(.04f);
    gib.makePercussiveNoise();
    gib.increaseVolume(50);
    eball.bend("Low E", false);
    eball.slide("A", "G");
    eball.snap();

    Engines engines;
    Engines::Turbines turbines;
    engines.engageThrust(turbines, true);
    engines.increasePower(40);
    engines.controlSpeed();
    turbines.increaseThrustLevel(20);
    turbines.increaseSpeed(20);
    turbines.increasePressure(40);
    turbines.releaseFuel(10);

    Fuselage fuselage;
    fuselage.encloseCabin();
    fuselage.supportWingsAndTail();
    fuselage.maintainInternalPressure();
    fuselage.receivePassengers(10);

    GuitarCollector gc;
    gc.raiseMultipleVolumes();
    gc.tuneAll();
    
    CoreOfPlane cop;
    cop.adjustPressures();
    cop.startUp();
    
    
    std::cout << "good to go!" << std::endl;
}
