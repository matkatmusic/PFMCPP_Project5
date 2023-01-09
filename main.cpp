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
};

Cat::Cat() :
numLimbs(3),
numTails(1),
ageYears(3.6f),
colour("orange"),
weightKg(4.1f),
cutenessLevel(50),
maxCroquettes(7)
{
    std::cout << "Cat is born" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Cat is gone to cat heaven" << std::endl;
}


void Cat::meow(int loudnessDB)
{
    std::cout << "Meow!!!" << std::endl;
    std::cout << "My current cuteness level is " << cutenessLevel << std::endl;
    if (loudnessDB < 30)
    {
        cutenessLevel += 10;
    }
    else
    {
        cutenessLevel -= loudnessDB;        
    }
   
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

    void domintateWorld(int numDays);

    void createEvilMachine(int numWings, int numTentacles);
};

/*
 new UDT 5:
 with 2 member functions
*/

struct SelfSufficientCat
{
    Cat cat;
    VendingMachine vendingMachine;

    SelfSufficientCat();
    ~SelfSufficientCat();

    void selfAdministerCroquettes(int numCroquettes);

    void upgradeCroquettes(std::string newBrand, std::string newFlavour);
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
    Cat cat;
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << cat.numLimbs << " limb(s) and " << cat.numTails << " tail(s). It is " << cat.ageYears << " year(s) old. Its colour is " << cat.colour << ". And its cuteness level is " << cat.cutenessLevel << ".\n"
        << "Cat weight: " << cat.weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << cat.maxCroquettes << "\n"
        << "--- ";
    cat.meow(42);
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
    std::cout << "good to go!" << std::endl;
}
