/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/


#include <iostream>
#include <iomanip>

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

    void printCatDetailsAndMeow();
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

void Cat::printCatDetailsAndMeow()
{
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << this->numLimbs << " limb(s) and " << this->numTails << " tail(s). It is " << this->ageYears << " year(s) old. Its colour is " << this->colour << ". And its cuteness level is " << this->cutenessLevel << ".\n"
        << "Cat weight: " << this->weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << this->maxCroquettes << std::endl;
    std::cout  << "--- ";
    this->meow(25);
}

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

    float chargeCustomerEuros(ItemDispenser item, int numberOfItems); 

    bool dispenseKitkat(int numberOfItems); 

    void refrigerate();

    void stockUpAndDispense();
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

float VendingMachine::chargeCustomerEuros(ItemDispenser item, int numberOfItems)
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

void VendingMachine::refrigerate()
{
    std::cout << (interiorTemperatureCelsius > targetTemperatureCelsius ? "Refrigeration in progress..." : "No refrigeration needed") << std::endl;
}

void VendingMachine::stockUpAndDispense()
{
        this->kitkatDispenser.stockUp(3);
    std::cout 
        << "--- "
        << "New item dispenser inventory: " << this->kitkatDispenser.inventory << "\n"
        << "New item dispenser state: " << (this->kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n"
        << "--- "
        << (this->dispenseKitkat(2) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser inventory: " << this->kitkatDispenser.inventory << "\n";
}

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

        int readData(int address); 
        
        bool writeData(int address, int data); 

        void parkHeads(); 
    };

    Drive cDrive;

    bool bootUp(Drive systemDrive); 

    bool runProgram(Drive programDrive, std::string path); 

    bool crash();    
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

int Computer::Drive::readData(int address)
{
    return address * rand();
}

bool Computer::Drive::writeData(int address, int data)
{
    return ((rand() * address * data) % 1000000) != 0; // Very bad harddrive!
}

void Computer::Drive::parkHeads()
{
    std::cout << ((rand() % 1000000) != 0 ? "Heads parked" : "Failed to park heads!") << std::endl;
}

bool Computer::bootUp(Drive systemDrive)
{
    return systemDrive.readData(rand()) != 0;
}

bool Computer::runProgram(Drive programDrive, std::string path)
{
    std::cout << "Running " << path << " on " << programDrive.brand << std::endl;
    return true;
}

bool Computer::crash()
{
    if (operatingSystem == "Solaris") 
    {
        return false;
    }
    return (rand() % 1000000) == 0;
}


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

/*
 new UDT 5:
 with 2 member functions
*/

struct CatRentalMachine
{
    Cat cat;
    VendingMachine vendingMachine;

    CatRentalMachine(Cat rentalCat);
    ~CatRentalMachine();

    Cat distributeCat();
    void returnCat(Cat returnedCat);
};

CatRentalMachine::CatRentalMachine(Cat rentalCat):
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

Cat CatRentalMachine::distributeCat()
{
    std::cout << "Distributing a cat for rental\n";
    std::cout << "His name is " << vendingMachine.kitkatDispenser.name << "\n";
    return cat;
}

void CatRentalMachine::returnCat(Cat returnedCat)
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
    Cat cat;
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << cat.numLimbs << " limb(s) and " << cat.numTails << " tail(s). It is " << cat.ageYears << " year(s) old. Its colour is " << cat.colour << ". And its cuteness level is " << cat.cutenessLevel << ".\n"
        << "Cat weight: " << cat.weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << cat.maxCroquettes << "\n";
    std::cout  << "--- ";
    cat.meow(25);
    std::cout << "*** Repeat with this->\n";
    cat.printCatDetailsAndMeow();
    std::cout << "***\n";
    
    std::cout
        << "--- "
        << "Did the cat catch a fly? " << (cat.catchAnimal("Fly") ? "Yes!" : "No :(") << "\n"
        << "--- "
        << "Size of the furball: " << cat.throwUpFurBall() << "mm\n"
        << "--- Attempting to eat 11 croquettes in bowl\n"
        << cat.eatCroquettes(11, 1) << " croquette(s) left in bowl\n"
        << std::setprecision(3)
        << "Cat new weight: " << cat.weightKg << "\n"
        << std::endl;
    
    VendingMachine vendingMachine;
    std::cout 
        << std::setprecision(1)
        << "Vending machine on: " << (vendingMachine.isOn ? "Yes" : "No") << "\n"
        << "Interior temperature: " << vendingMachine.interiorTemperatureCelsius << "°C" << "\n"
        << "Target temperature: " << vendingMachine.targetTemperatureCelsius << "°C" << "\n"
        << "--- ";
    vendingMachine.refrigerate();
    std::cout << std::setprecision(2) 
        << "Cash collected: " << vendingMachine.cashCollectedEuros << "€\n" 
        << "Item selected: " << vendingMachine.itemSelected << "\n"
        << "--- "
        << "Charging customer for 5 items: " << vendingMachine.chargeCustomerEuros(vendingMachine.kitkatDispenser, 5) << "€\n"
        << "*** Dispenser number: " << vendingMachine.kitkatDispenser.itemNumber << "\n"
        << "*** "
        << (vendingMachine.kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n"
        << "*** Product: " << vendingMachine.kitkatDispenser.name << "\n"
        << "*** Flavour: " << vendingMachine.kitkatDispenser.flavour << "\n"
        << "*** Inventory: " << vendingMachine.kitkatDispenser.inventory << "\n"
        << "*** Price: " << vendingMachine.kitkatDispenser.priceEuros << "€\n"
        << "--- "
        << (vendingMachine.dispenseKitkat(6) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser state: " << (vendingMachine.kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n";
    
    vendingMachine.kitkatDispenser.stockUp(3);
    std::cout 
        << "--- "
        << "New item dispenser inventory: " << vendingMachine.kitkatDispenser.inventory << "\n"
        << "New item dispenser state: " << (vendingMachine.kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n"
        << "--- "
        << (vendingMachine.dispenseKitkat(2) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser inventory: " << vendingMachine.kitkatDispenser.inventory << "\n";
    std::cout << "*** Repeat with this->\n";
    vendingMachine.stockUpAndDispense();
    std::cout << "***\n";
    
    std::cout << std::endl;
    Computer computer;
    std::cout 
        << "--- "
        << "Computer booted: " << (computer.bootUp(computer.cDrive) ? "Yes" : "No") << "\n"
        << "Number of cores: " << computer.numCPUCores << "\n"
        << "CPU Frequency: " << computer.CPUFrequencyGHz << "GHz\n"
        << "RAM: " << computer.memoryMB << "MB\n"
        << "Power needed: " << computer.powerNeededW << "W\n"
        << "Operating system: " << computer.operatingSystem << "\n"
        << "*** Drive brand: " << computer.cDrive.brand << "\n"
        << "*** Drive capacity: " << computer.cDrive.capacityGB << "GB\n"
        << "*** Drive RPM: " << computer.cDrive.standardRpm << "\n"
        << "*** Drive read speed: " << computer.cDrive.readSpeedMBs << "MB/s\n"
        << "--- "
        << "*** Data read at address 123: " << computer.cDrive.readData(123) << "\n"
        << "--- "
        << "*** Writing data 456 at address 678 successful?: " << (computer.cDrive.writeData(678, 456) ? "Yes" : "No") << "\n"
        << "--- ";
    computer.runProgram(computer.cDrive, "/usr/local/games/pacman/pacman");
    std::cout 
        << "--- "
        << "Computer crashed: " << (computer.crash() ? "Yes :(" : "No") << "\n"
        << "--- ";
    computer.cDrive.parkHeads();
    std::cout << std::endl;

    
    CatCyberOverlord catCyberOverlord;
    catCyberOverlord.dominateWorld(5);
    std::cout << "New cuteness level: " << catCyberOverlord.cat.cutenessLevel << std::endl;
    catCyberOverlord.dominateWorld(2);
    std::cout << "New cuteness level: " << catCyberOverlord.cat.cutenessLevel << std::endl;
    catCyberOverlord.createEvilMachine(2, 6);
    std::cout << "Who needs wings? 6 tentacles will do!\n";
    catCyberOverlord.createEvilMachine(0, 6);
    std::cout << std::endl;
    
    Cat rentalCat;
    rentalCat.numLimbs = 4;
    rentalCat.cutenessLevel = 150;
    rentalCat.maxCroquettes = 12345;
    rentalCat.colour = "orange";
    CatRentalMachine catRentalMachine(rentalCat);
    Cat myRentalCat = catRentalMachine.distributeCat();
    std::cout << "What a beautiful cat!\n";
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << myRentalCat.numLimbs << " limb(s) and " << myRentalCat.numTails << " tail(s). It is " << myRentalCat.ageYears << " year(s) old. Its colour is " << myRentalCat.colour << ". And its cuteness level is " << myRentalCat.cutenessLevel << ".\n"
        << "Cat weight: " << myRentalCat.weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << myRentalCat.maxCroquettes << "\n"
        << "This cat is too cute, I'll return a grey cat instead....\n";
    catRentalMachine.returnCat(cat);
    
    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}
