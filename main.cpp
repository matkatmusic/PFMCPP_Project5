/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
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

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */





#include <iostream>
#include <iomanip>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */
struct Cat
{
    Cat();
    ~Cat();
    int numLimbs;
    int numTails;
    float ageYears;
    std::string colour;
    float weightKg;
    int cutenessLevel;
    int maxCroquettes;

    void meow(int loudnessDB);

    bool catchAnimal(std::string animalSpecies); 

    float throwUpFurBall(); 

    int eatCroquettes(int croquettesNum, float croquetteWeight);

    JUCE_LEAK_DETECTOR(Cat)
};

Cat::Cat() :
numLimbs(3),
numTails(1),
ageYears(3.6f),
colour("grey"),
weightKg(4.1f),
cutenessLevel(50),
maxCroquettes(7)
{
    std::cout << "Cat is born" << std::endl;
}

Cat::~Cat() 
{
    if (cutenessLevel < 0)
    {
        std::cout << "Cat is gone to cat hell" << std::endl;
    }
    else
    {
        std::cout << "Cat is gone to cat heaven" << std::endl;
    }
}


void Cat::meow(int loudnessDB)
{
    std::cout << "Meow!!! " << loudnessDB << " dB" << std::endl;
    if (loudnessDB < 30)
    {
        cutenessLevel += 10;
    }
    else
    {
        cutenessLevel -= loudnessDB;        
    }
    std::cout << "My current cuteness level is " << cutenessLevel << std::endl;
}

bool Cat::catchAnimal(std::string animalSpecies)
{
    if (animalSpecies == "Fly")
    {
        cutenessLevel += 10;
        return true;
    }
    cutenessLevel -= 10;
    return false;
}

float Cat::throwUpFurBall()
{
    cutenessLevel -= 50;
    return weightKg * 11;
}

int Cat::eatCroquettes(int croquettesNum, float croquetteWeightG)
{
    int i = 0;
    while (i < croquettesNum)
    {
        ++i;
        weightKg += croquetteWeightG * 0.001f;
        std::cout << "Eating a croquette... yum!\n";
        if (i >= maxCroquettes) 
        {
            std::cout << "I had enough.\n";
            return croquettesNum - i;
        }
    }
    return 0;
}

struct CatWrapper
{
    Cat* catPtr = nullptr;
    CatWrapper(Cat* ptrToCat) : catPtr(ptrToCat) 
    { 
        std::cout << "+++ CatWrapper +++" << std::endl;
    }
    ~CatWrapper()
    {
        delete catPtr;
        std::cout << "/// CatWrapper ///" << std::endl;
    }
};

/*
 copied UDT 2:
 */
struct VendingMachine
{
    VendingMachine();
    ~VendingMachine();
    bool isOn = true;
    float interiorTemperatureCelsius = 10.2f;
    float targetTemperatureCelsius = 8.5f;
    float cashCollectedEuros = 123.54f;
    int itemSelected = 13;

    struct ItemDispenser
    {
        ItemDispenser();
        ~ItemDispenser();
        std::string name = "KitKat";
        std::string flavour = "Original";
        int inventory = 5;
        float priceEuros = 2.5f;
        int itemNumber = 13;
        bool isDisabled = false;

        bool distributeItems(int numberOfItems); 

        void stockUp(int itemsAdded); 

        void disable(std::string cause); 
    };

    ItemDispenser kitkatDispenser;

    float chargeCustomerEuros(const ItemDispenser& item, int numberOfItems) const; 

    bool dispenseKitkat(int numberOfItems); 

    void refrigerate() const;

    JUCE_LEAK_DETECTOR(VendingMachine)
};

VendingMachine::VendingMachine()
{
    std::cout << "VendingMachine being constructed" << std::endl;
}

VendingMachine::~VendingMachine()
{
    std::cout << "VendingMachine being destructed" << std::endl;
}

VendingMachine::ItemDispenser::ItemDispenser() :
name("KitKat"),
flavour("Original"),
inventory(5),
priceEuros(2.5f),
itemNumber(13),
isDisabled(false)
{
    std::cout << "VendingMachine::ItemDispenser being constructed" << std::endl;
}

VendingMachine::ItemDispenser::~ItemDispenser()
{
    std::cout << "VendingMachine::ItemDispenser being destructed" << std::endl;
}

bool VendingMachine::ItemDispenser::distributeItems(int numberOfItems)
{
    for (int i = 0; i < numberOfItems; ++i)
    {
        std::cout << "Distributing item\n";
        --inventory;
        if (inventory == 0) 
        {
            disable("Empty");
            ++i;
            return (i == numberOfItems);
        }
    }
    return true;
}

void VendingMachine::ItemDispenser::stockUp(int itemsAdded)
{
    inventory += itemsAdded;
    isDisabled = false;
}

void VendingMachine::ItemDispenser::disable(std::string cause)
{
    if (cause == "Empty") 
    {
        std::cout << "Please restock " << name << " - " << flavour << std::endl;
    }
    isDisabled = true;
}

float VendingMachine::chargeCustomerEuros(const ItemDispenser& item, int numberOfItems) const
{
    float priceCharged = 0.0f;
    for (int i = 0; i < numberOfItems; i++)
    {
        priceCharged += item.priceEuros;        
    }
    return priceCharged;
}

bool VendingMachine::dispenseKitkat(int numberOfItems)
{
    std::cout << "Attempt at dispensing " << numberOfItems << " items\n";
    return kitkatDispenser.distributeItems(numberOfItems);
}

void VendingMachine::refrigerate() const
{
    std::cout << (interiorTemperatureCelsius > targetTemperatureCelsius ? "Refrigeration in progress..." : "No refrigeration needed") << std::endl;
}

struct VendingMachineWrapper
{
    VendingMachine* vendingMachinePtr;
    VendingMachineWrapper(VendingMachine* ptrToVendingMachine) : vendingMachinePtr(ptrToVendingMachine)
    {
        std::cout << "+++ VendingMachineWrapper +++" << std::endl;
    }
    ~VendingMachineWrapper()
    {
        delete vendingMachinePtr;
        std::cout << "/// VendingMachineWrapper ///" << std::endl;
    }
};

/*
 copied UDT 3:
 */
struct Computer
{
    Computer();
    ~Computer();
    int numCPUCores = 6;
    float CPUFrequencyGHz = 3.4f;
    int memoryMB = 32;
    int powerNeededW = 430;
    std::string operatingSystem = "Solaris";

    struct Drive 
    {
        Drive();
        ~Drive();
        std::string brand = "Seagate";
        float capacityGB = 2000.0f;
        int standardRpm = 7200;
        float readSpeedMBs = 101.1f;
        float writeSpeedMs = 74.2f;

        int readData(int address) const; 
        
        bool writeData(int address, int data) const; 

        void parkHeads() const; 
    };

    Drive cDrive;

    bool bootUp(const Drive& systemDrive) const; 

    bool runProgram(const Drive& programDrive, std::string path) const; 

    bool crash() const;

    JUCE_LEAK_DETECTOR(Computer)
};

Computer::Computer()
{
    std::cout << "Computer being constructed" << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer being destructed" << std::endl;
}

Computer::Drive::Drive()
{
    std::cout << "Computer::Drive being constructed" << std::endl;
}

Computer::Drive::~Drive()
{
    std::cout << "Computer::Drive being destructed" << std::endl;
}

int Computer::Drive::readData(int address) const
{
    return address * rand();
}

bool Computer::Drive::writeData(int address, int data) const
{
    return ((rand() * address * data) % 1000000) != 0; // Very bad harddrive!
}

void Computer::Drive::parkHeads() const
{
    std::cout << ((rand() % 1000000) != 0 ? "Heads parked" : "Failed to park heads!") << std::endl;
}

bool Computer::bootUp(const Drive& systemDrive) const
{
    return systemDrive.readData(rand()) != 0;
}

bool Computer::runProgram(const Drive& programDrive, std::string path) const
{
    std::cout << "Running " << path << " on " << programDrive.brand << std::endl;
    return true;
}

bool Computer::crash() const
{
    if (operatingSystem == "Solaris") 
    {
        return false;
    }
    return (rand() % 1000000) == 0;
}

struct ComputerWrapper
{
    Computer* computerPtr;
    ComputerWrapper(Computer* ptrToComputer) : computerPtr(ptrToComputer)
    {
        std::cout << "+++ ComputerWrapper +++" << std::endl;
    }
    ~ComputerWrapper()
    {
        delete computerPtr;
        std::cout << "/// ComputerWrapper ///" << std::endl;
    }
};

/*
 new UDT 4:
 with 2 member functions
 */
struct CatCyberOverlord 
{
    Cat cat;
    Computer computer;

    CatCyberOverlord();
    ~CatCyberOverlord();

    void dominateWorld(int numHours);

    void createEvilMachine(int numWings, int numTentacles);

    JUCE_LEAK_DETECTOR(CatCyberOverlord)
};

CatCyberOverlord::CatCyberOverlord()
{
    std::cout << "Aliens irradiate a cat sleeping in a discarded compter - A CatCyberOverlord is born!" << std::endl;
    cat.cutenessLevel = -1000;
    computer.powerNeededW = 0;
    cat.meow(70);
}

CatCyberOverlord::~CatCyberOverlord()
{
    std::cout << "Superdog destructed the CatCyberOverlord! Hurray for Superdog!" << std::endl;
}

void CatCyberOverlord::dominateWorld(int numHours)
{
    std::cout << "Attempting to dominate the world for " << numHours << " hours\n";
    cat.cutenessLevel -= numHours;
    if (numHours > 3)
    {
        std::cout << "Failure: The cat cyberoverlord decides to take a nap instead" << std::endl;
    }
    else
    {
        std::cout << "After " << numHours << " hours of world domination, the cat cyberoverlord goes back to chasing flies and slightly redeems itself." << std::endl;
        cat.catchAnimal("Fly");
    }
}

void CatCyberOverlord::createEvilMachine(int numWings, int numTentacles)
{
    std::cout << "Attempting to build an evil machine with " << numWings << " wings and " << numTentacles << " tentacles driven by a computer with " << computer.numCPUCores << " cores\n";
    if ((numWings + numTentacles) > computer.numCPUCores)
    {
        std::cout << "The cat cyberoverlord overestimated its computer. The evil machine crashes." << std::endl;       
    }
    else
    {
        std::cout << "The cat cyberoverlord uses its evil machine to eat croquettes more efficiently." << std::endl;
        cat.maxCroquettes *= 10;
        cat.eatCroquettes(20, 1.0f);
    }   
}

struct CatCyberOverlordWrapper 
{
    CatCyberOverlord* catCyberOverlordPtr;
    CatCyberOverlordWrapper(CatCyberOverlord* ptrToCatCyberOverlord) : catCyberOverlordPtr(ptrToCatCyberOverlord)
    {
        std::cout << "+++ CatCyberOverlordWrapper +++" << std::endl;    
    }
    ~CatCyberOverlordWrapper()
    {
        delete catCyberOverlordPtr;
        std::cout << "/// CatCyberOverlordWrapper ///" << std::endl;
    }
};

/*
 new UDT 5:
 with 2 member functions
*/

struct CatRentalMachine
{
    Cat cat;
    VendingMachine vendingMachine;

    CatRentalMachine(Cat& rentalCat);
    ~CatRentalMachine();

    Cat distributeCat() const;
    void returnCat(const Cat& returnedCat) const;

    JUCE_LEAK_DETECTOR(CatRentalMachine)
};

CatRentalMachine::CatRentalMachine(Cat& rentalCat):
cat(rentalCat)
{
    std::cout << "Genius idea! CatRentalMachine constructed" << std::endl;
    std::cout << "Repurposing the Kitkat dispenser should be straightforward.\n";
    vendingMachine.interiorTemperatureCelsius = 25.0f;
    vendingMachine.targetTemperatureCelsius = 25.0f;
    vendingMachine.kitkatDispenser.name = "Garfield";
    vendingMachine.kitkatDispenser.flavour = cat.colour;
    vendingMachine.kitkatDispenser.inventory = 1;
    vendingMachine.kitkatDispenser.priceEuros = 50.0f;
    std::cout 
        << "New parameters: \n"
        << std::setprecision(1)
        << "Temperature: " << vendingMachine.interiorTemperatureCelsius << "\n"
        << "Product name: " << vendingMachine.kitkatDispenser.name << "\n"
        << "Product flavour: " << vendingMachine.kitkatDispenser.flavour << "\n"
        << std::setprecision(2)
        << "Product price: " <<     vendingMachine.kitkatDispenser.priceEuros << std::endl;
}

CatRentalMachine::~CatRentalMachine()
{
    std::cout << "The authorities get wind of this lucrative business. CatRentalMachine destructed" << std::endl;
}

Cat CatRentalMachine::distributeCat() const
{
    std::cout << "Distributing a cat for rental\n";
    std::cout << "His name is " << vendingMachine.kitkatDispenser.name << "\n";
    return cat;
}

void CatRentalMachine::returnCat(const Cat& returnedCat) const
{
    if (returnedCat.colour != cat.colour)
    {
        std::cout << "You are trying to return the wrong cat!" << std::endl;
    }
    else
    {
        std::cout << "Cat safely returned! Thanks for using our services!" << std::endl;
    }
}

struct CatRentalMachineWrapper
{
    CatRentalMachine* catRentalMachinePtr;
    CatRentalMachineWrapper(CatRentalMachine* ptrToCatRentalMachine) : catRentalMachinePtr(ptrToCatRentalMachine)
    {
        std::cout << "+++ CatRentalMachineWrapper +++" << std::endl;
    }
    ~CatRentalMachineWrapper()
    {
        delete catRentalMachinePtr;
        std::cout << "/// CatRentalMachineWrapper ///" << std::endl;
    }
};

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
int main()
{
    CatWrapper catWrapper( new Cat() );
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << catWrapper.catPtr->numLimbs << " limb(s) and " << catWrapper.catPtr->numTails << " tail(s). It is " << catWrapper.catPtr->ageYears << " year(s) old. Its colour is " << catWrapper.catPtr->colour << ". And its cuteness level is " << catWrapper.catPtr->cutenessLevel << ".\n"
        << "Cat weight: " << catWrapper.catPtr->weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << catWrapper.catPtr->maxCroquettes << "\n";
    std::cout  << "--- ";
    catWrapper.catPtr->meow(25);
    
    std::cout
        << "--- "
        << "Did the cat catch a fly? " << (catWrapper.catPtr->catchAnimal("Fly") ? "Yes!" : "No :(") << "\n"
        << "--- "
        << "Size of the furball: " << catWrapper.catPtr->throwUpFurBall() << "mm\n"
        << "--- Attempting to eat 11 croquettes in bowl\n"
        << catWrapper.catPtr->eatCroquettes(11, 1) << " croquette(s) left in bowl\n"
        << std::setprecision(3)
        << "Cat new weight: " << catWrapper.catPtr->weightKg << "\n"
        << std::endl;
    
    VendingMachineWrapper vendingMachineWrapper( new VendingMachine() );
    std::cout 
        << std::setprecision(1)
        << "Vending machine on: " << (vendingMachineWrapper.vendingMachinePtr->isOn ? "Yes" : "No") << "\n"
        << "Interior temperature: " << vendingMachineWrapper.vendingMachinePtr->interiorTemperatureCelsius << "°C" << "\n"
        << "Target temperature: " << vendingMachineWrapper.vendingMachinePtr->targetTemperatureCelsius << "°C" << "\n"
        << "--- ";
    vendingMachineWrapper.vendingMachinePtr->refrigerate();
    std::cout << std::setprecision(2) 
        << "Cash collected: " << vendingMachineWrapper.vendingMachinePtr->cashCollectedEuros << "€\n" 
        << "Item selected: " << vendingMachineWrapper.vendingMachinePtr->itemSelected << "\n"
        << "--- "
        << "Charging customer for 5 items: " << vendingMachineWrapper.vendingMachinePtr->chargeCustomerEuros(vendingMachineWrapper.vendingMachinePtr->kitkatDispenser, 5) << "€\n"
        << "*** Dispenser number: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.itemNumber << "\n"
        << "*** "
        << (vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n"
        << "*** Product: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.name << "\n"
        << "*** Flavour: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.flavour << "\n"
        << "*** Inventory: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.inventory << "\n"
        << "*** Price: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.priceEuros << "€\n"
        << "--- "
        << (vendingMachineWrapper.vendingMachinePtr->dispenseKitkat(6) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser state: " << (vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n";
    
    vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.stockUp(3);
    std::cout 
        << "--- "
        << "New item dispenser inventory: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.inventory << "\n"
        << "New item dispenser state: " << (vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n"
        << "--- "
        << (vendingMachineWrapper.vendingMachinePtr->dispenseKitkat(2) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser inventory: " << vendingMachineWrapper.vendingMachinePtr->kitkatDispenser.inventory << "\n";
    
    std::cout << std::endl;
    ComputerWrapper computerWrapper( new Computer() );
    std::cout 
        << "--- "
        << "Computer booted: " << (computerWrapper.computerPtr->bootUp(computerWrapper.computerPtr->cDrive) ? "Yes" : "No") << "\n"
        << "Number of cores: " << computerWrapper.computerPtr->numCPUCores << "\n"
        << "CPU Frequency: " << computerWrapper.computerPtr->CPUFrequencyGHz << "GHz\n"
        << "RAM: " << computerWrapper.computerPtr->memoryMB << "MB\n"
        << "Power needed: " << computerWrapper.computerPtr->powerNeededW << "W\n"
        << "Operating system: " << computerWrapper.computerPtr->operatingSystem << "\n"
        << "*** Drive brand: " << computerWrapper.computerPtr->cDrive.brand << "\n"
        << "*** Drive capacity: " << computerWrapper.computerPtr->cDrive.capacityGB << "GB\n"
        << "*** Drive RPM: " << computerWrapper.computerPtr->cDrive.standardRpm << "\n"
        << "*** Drive read speed: " << computerWrapper.computerPtr->cDrive.readSpeedMBs << "MB/s\n"
        << "--- "
        << "*** Data read at address 123: " << computerWrapper.computerPtr->cDrive.readData(123) << "\n"
        << "--- "
        << "*** Writing data 456 at address 678 successful?: " << (computerWrapper.computerPtr->cDrive.writeData(678, 456) ? "Yes" : "No") << "\n"
        << "--- ";
    computerWrapper.computerPtr->runProgram(computerWrapper.computerPtr->cDrive, "/usr/local/games/pacman/pacman");
    std::cout 
        << "--- "
        << "Computer crashed: " << (computerWrapper.computerPtr->crash() ? "Yes :(" : "No") << "\n"
        << "--- ";
    computerWrapper.computerPtr->cDrive.parkHeads();
    std::cout << std::endl;
    
    CatCyberOverlordWrapper catCyberOverlordWrapper( new CatCyberOverlord() );
    catCyberOverlordWrapper.catCyberOverlordPtr->dominateWorld(5);
    std::cout << "New cuteness level: " << catCyberOverlordWrapper.catCyberOverlordPtr->cat.cutenessLevel << std::endl;
    catCyberOverlordWrapper.catCyberOverlordPtr->dominateWorld(2);
    std::cout << "New cuteness level: " << catCyberOverlordWrapper.catCyberOverlordPtr->cat.cutenessLevel << std::endl;
    catCyberOverlordWrapper.catCyberOverlordPtr->createEvilMachine(2, 6);
    std::cout << "Who needs wings? 6 tentacles will do!\n";
    catCyberOverlordWrapper.catCyberOverlordPtr->createEvilMachine(0, 6);
    std::cout << std::endl;
    
    CatWrapper rentalCatWrapper( new Cat() );
    rentalCatWrapper.catPtr->numLimbs = 4;
    rentalCatWrapper.catPtr->cutenessLevel = 150;
    rentalCatWrapper.catPtr->maxCroquettes = 12345;
    rentalCatWrapper.catPtr->colour = "orange";
    CatRentalMachineWrapper catRentalMachineWrapper( new CatRentalMachine(*rentalCatWrapper.catPtr) );
    Cat myRentalCat = catRentalMachineWrapper.catRentalMachinePtr->distributeCat();
    std::cout << "What a beautiful cat!\n";
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << myRentalCat.numLimbs << " limb(s) and " << myRentalCat.numTails << " tail(s). It is " << myRentalCat.ageYears << " year(s) old. Its colour is " << myRentalCat.colour << ". And its cuteness level is " << myRentalCat.cutenessLevel << ".\n"
        << "Cat weight: " << myRentalCat.weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << myRentalCat.maxCroquettes << "\n"
        << "This cat is too cute, I'll return a grey cat instead....\n";
    CatWrapper randomCatWrapper( new Cat() );
    catRentalMachineWrapper.catRentalMachinePtr->returnCat(*randomCatWrapper.catPtr);
    
    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}
