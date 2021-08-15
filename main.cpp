/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
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
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


#include <iostream>

/*
 copied UDT 1:
 */

struct Dishwasher
{
    Dishwasher();
    ~Dishwasher();

    int capacityPlates { 15 };
    int capacityCupsGlasses { 18 };
    int capacityCutlery, timePerRun;
    double waterConsumption;

    struct Dishes
    {
        Dishes();
        ~Dishes();

        float oiliness;
        int soupBowls { 4 };
        int regularPlates { 12 };
        int cups, glasses;
        void clogDrain(std::string residues = "too much");
        void tarnish(bool isSensitive = false);
        void shatter(bool isPiledBadly = false);

        int puttingInGlasses(int toClean = 5, int room = 18);

        void soupBowlCounter();
    };

    void cleanDishes(Dishes dishes);
    void dryDishes(bool shouldDryDishes = true, int temp = 55);
    void selfClean(int afterRun = 45);

    int alarm(int remainingTime = 100);

    Dishes dishes;
    void updateOiliness(float oiliness);

    void cutleryCounter();
};

Dishwasher::Dishwasher() :
capacityCutlery(30),
timePerRun(135),
waterConsumption(30.5)
{}

Dishwasher::~Dishwasher()
{
    std::cout << "Dishwasher destroyed" << std::endl;
}

Dishwasher::Dishes::Dishes() :
oiliness(25.76f),
cups(8),
glasses(5)
{}

Dishwasher::Dishes::~Dishes()
{
    std::cout << "Dishes destroyed" << std::endl;
}

void Dishwasher::updateOiliness(float oiliness)
{
    dishes.oiliness = oiliness;
}

void Dishwasher::cutleryCounter()
{
    std::cout << "room for " << this->capacityCutlery << " pieces of cutlery" << std::endl;
}

void Dishwasher::Dishes::clogDrain(std::string residues)
{
    if(residues == "too much")
    {
        std::cout << "clogged" << std::endl;
    }
}

void Dishwasher::Dishes::tarnish(bool isSensitive)
{
    if(isSensitive)
    {
        std::cout << "cutlery successfully tarnished" << std::endl;
    }
}

void Dishwasher::Dishes::shatter(bool isPiledBadly)
{
    if(isPiledBadly)
    {
        std::cout << "let's break some stuff, e.g. " << cups << " cups" << std::endl;
    }
}

int Dishwasher::Dishes::puttingInGlasses(int toClean, int room)
{
    int spaceLeft = room - glasses - cups;
    std::cout << "glass(es) to put away: " << toClean << std::endl;
    while(spaceLeft > 0 && toClean > 0)
    {
        --toClean;
        ++glasses;
        --spaceLeft;
    }
    std::cout << "any glasses left?" << std::endl;
    toClean == 0 ? std::cout << "all in there" << std::endl : std::cout << "yeah, " << toClean << ", but there's no more room..." << std::endl;
    return spaceLeft;
}

void Dishwasher::Dishes::soupBowlCounter()
{
    std::cout << "here's " << this->soupBowls << " soupbowls" << std::endl;
}

void Dishwasher::cleanDishes(Dishwasher::Dishes newDishes)
{
    if(newDishes.oiliness > 0)
    {
        std::cout << "dishes are dirty, oiliness: " << newDishes.oiliness << std::endl;
        std::cout << "cleaning dishes, this will take " << timePerRun << " minutes" << std::endl;
        newDishes.oiliness = 0.f;
        dishes.oiliness = newDishes.oiliness;
        dishes.soupBowls = newDishes.soupBowls;
        dishes.regularPlates = newDishes.regularPlates;
        dishes.cups = newDishes.cups;
        dishes.glasses = newDishes.glasses;
        std::cout << "dishes cleaned, oiliness: " << dishes.oiliness << std::endl;
    }
    else
    {
        std::cout << "dishes are not dirty, oiliness: " << dishes.oiliness << std::endl;
    }
}

void Dishwasher::dryDishes(bool shouldDryDishes, int temp)
{
    if(shouldDryDishes)
    {
        if(temp < 55)
        {
            std::cout << "raising temperature to 55" << std::endl;
        }
    }
}

void Dishwasher::selfClean(int afterRun)
{
    if(afterRun >= 45)
    {
        std::cout << "let's clean" << std::endl;
    }
    else
    {
        std::cout << "not yet" << std::endl;
    }
}

int Dishwasher::alarm(int remainingTime)
{
    remainingTime = timePerRun;
    while(remainingTime > 0)
    {
        --remainingTime;
        if(remainingTime == 0)
        {
            std::cout << std::endl << "beep beep beep" << std::endl;
        }
        else
        {
            std::cout << "M";
        }
    }
    return remainingTime;
}


/*
 copied UDT 2:
 */

struct Oven
{
    Oven();
    ~Oven();

    int numberBakingSheets, numberPrograms;
    int highestTemp { 300 };
    int currentTemp { 220 };
    std::string currentProgram;

    void bakeCake(std::string typeOfCake = "apple", int preHeat = 180);
    void bakePizza(std::string typeOfPizza = "margherita", int preHeat = 220);
    void makeRoast(std::string typeOfRoast = "beef", int setTemp = 230);

    int adjustTemp(int targetTemp = 200, int current = 25);

    void printMaxTemp();
};

Oven::Oven() :
numberBakingSheets(3),
numberPrograms(5),
currentProgram("top heat")
{}

Oven::~Oven()
{
    std::cout << "Oven destroyed" << std::endl;
}

void Oven::bakeCake(std::string typeOfCake, int preHeat)
{
    std::cout << "baking an " << typeOfCake << " pie, preheating to " << preHeat << std::endl;
}

void Oven::bakePizza(std::string typeOfPizza, int preHeat)
{
    std::cout << "baking a pizza " << typeOfPizza << ", preheating to " << preHeat << " although we can try " << highestTemp << " some time" << std::endl;
}

void Oven::makeRoast(std::string typeOfRoast, int setTemp)
{
    std::cout << "making a " << typeOfRoast << " roast, setting Temperature to " << setTemp << std::endl;
}

int Oven::adjustTemp(int targetTemp, int current)
{
    current = currentTemp;
    std::cout << "current: " << currentTemp << ", target is: " << targetTemp << std::endl;
    int dir = (current < targetTemp ? 1 : -1);
    while(current > targetTemp)
    {
        current += dir;
        currentTemp = current;
    }
    std::cout << "current: " << currentTemp << ", reached target of: " << targetTemp << std::endl;
    return current;
}

void Oven::printMaxTemp()
{
    std::cout << "It goes up to " << this->highestTemp << " degrees Celsius" << std::endl;
}


/*
 copied UDT 3:
 */

struct Stove
{
    Stove();
    ~Stove();
    
    std::string typeStove;
    int numberHotplates { 4 };
    int hotplatesInUse { 1 };
    double largestDiam, smallestDiam;

    void boilWater(int setLevel = 9);
    void frySteaks(int setLevel = 7);
    void makeSoup(int setLevel = 5);

    int cookBigMeal(int numPotsNeeded = 5, int inUse = 0);

    void potSizePossibilities();
};

Stove::Stove() :
    typeStove("induction"),
    largestDiam(28.5),
    smallestDiam(14.5)
{}

Stove::~Stove()
{
    std::cout << "Oven destroyed" << std::endl;
}

void Stove::boilWater(int setLevel)
{
    std::cout << "boiling water, setting level to " << setLevel << " on 1 of " << numberHotplates << " hotplates" << std::endl;
}

void Stove::frySteaks(int setLevel)
{
    std::cout << "frying steaks, setting level to " << setLevel << std::endl;
}

void Stove::makeSoup(int setLevel)
{
    std::cout << "making soup, setting level to " << setLevel << std::endl;
}

int Stove::cookBigMeal(int numPotsNeeded, int inUse)
{
    hotplatesInUse = inUse;
    while(hotplatesInUse < numberHotplates && numPotsNeeded > 0)
    {
        --numPotsNeeded;
        ++hotplatesInUse;
        if(hotplatesInUse == numberHotplates) 
        {
            std::cout << "no more room" << std::endl;
        }
        
        std::cout << (numPotsNeeded == 0 ? 
                        "all pots on the stove" : 
                        std::string("still ") + std::to_string(numPotsNeeded) + " pot(s) more needed") 
                    << std::endl;
    }
    return numPotsNeeded;
}

void Stove::potSizePossibilities()
{
    std::cout << "You can use pots with a diameter between " << this->smallestDiam << " and " << this->largestDiam << " centimeters" << std::endl;
}


/*
 new UDT 4:
 with 2 member functions
 */

struct KitchenCatalog
{
    KitchenCatalog();
    ~KitchenCatalog();

    Dishwasher myDishwasher;
    Oven myOven;
    Stove myStove;
    
    void displayPage(int pageNumber);
    double shippingCost(int numDshwsh, int numOvn, int numStv);
    void shippingForAnOven();
};

KitchenCatalog::KitchenCatalog()
{
    std::cout << "KitchenCatalog constructed" << std::endl;
}

KitchenCatalog::~KitchenCatalog()
{
    std::cout << "KitchenCatalog destroyed" << std::endl;
}

void KitchenCatalog::displayPage(int pageNumber)
{
    if (pageNumber == 1)
    {
        std::cout << "look at this dishwasher, up to " << myDishwasher.capacityCupsGlasses << " cups or glasses will fit in!" << std::endl;
    }
    else if (pageNumber == 2)
    {
        std::cout << "look at this oven, it can go up to " << myOven.highestTemp << " degrees Celsius!" << std::endl;
    }
    else if (pageNumber == 3)
    {
        std::cout << "look at this stove, it's hotplates go from " << myStove.smallestDiam << " cm to " << myStove.largestDiam << " cm in diameter!" << std::endl;
    }
    else 
    {
        std::cout << "there's no page " << pageNumber << ", try 1, 2, or 3" << std::endl;
    }
}

double KitchenCatalog::shippingCost(int numDshwsh, int numOvn, int numStv)
{
    double totalPrice;
    totalPrice = numDshwsh * 599.99 + numOvn * 499.99 + numStv * 449.99;
    double shipping = (totalPrice > 1000. || totalPrice == 0.) ? 0. : 24.99;
    std::cout << "Shipping will cost " << shipping << " Euro for your order with a total of " << totalPrice << " Euro" << std::endl;
    return shipping;
}

void KitchenCatalog::shippingForAnOven()
{
    std::cout << "The shipping for an oven is " << this->shippingCost(0, 1, 0) << " Euro" << std::endl;
}

/*
 new UDT 5:
 with 2 member functions
 */

struct KitchenStuff
{
    KitchenStuff();
    ~KitchenStuff();

    Dishwasher myDishwasher;
    Dishwasher::Dishes myDishes;
    Oven myOven;
    Stove myStove;

    void usingOven(std::string myDish);
    void usingStove(std::string myDish);

    void dishwasherTime();
};

KitchenStuff::KitchenStuff()
{
    std::cout << "KitchenStuff constructed" << std::endl;
}

KitchenStuff::~KitchenStuff()
{
    std::cout << "Kitchenstuff destroyed" << std::endl;
}

void KitchenStuff::usingOven(std::string myDish)
{
    if (myDish == "cake")
    {
        myOven.bakeCake();
        myDishes.oiliness = 10.f;
        myDishwasher.cleanDishes(myDishes);
    }
    else if (myDish == "pizza")
    {
        myOven.bakePizza();
        myDishes.oiliness = 25.f;
        myDishwasher.cleanDishes(myDishes);
    }
    else if (myDish == "roast")
    {
        myOven.makeRoast();
        myDishes.oiliness = 25.f;
        myDishwasher.cleanDishes(myDishes);
    }
}

void KitchenStuff::usingStove(std::string myDish)
{
    if (myDish == "water")
    {
        myStove.boilWater();
        myDishes.oiliness = 0.f;
        myDishwasher.cleanDishes(myDishes);
        std::cout << "It's only water, just let it dry" << std::endl;
    }
    else if (myDish == "steak")
    {
        myStove.frySteaks();
        myDishes.oiliness = 22.5f;
        myDishwasher.cleanDishes(myDishes);
    }
    else if (myDish == "soup")
    {
        myStove.makeSoup();
        myDishes.oiliness = 7.5f;
        myDishwasher.cleanDishes(myDishes);
    }
}

void KitchenStuff::dishwasherTime()
{
    std::cout << "A run takes " << this->myDishwasher.timePerRun << " minutes" << std::endl;
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
    Dishwasher::Dishes myDishes;
    myDishes.oiliness = 9001.f;
    Dishwasher dishwasher;
    dishwasher.cleanDishes(myDishes);

    dishwasher.updateOiliness(123.45f);
    dishwasher.dryDishes();
    dishwasher.alarm();

    dishwasher.dishes.tarnish(true);

    dishwasher.dishes.shatter(true);
    dishwasher.dishes.puttingInGlasses(2,18);
    dishwasher.dishes.puttingInGlasses(9,18);

    std::cout << "room for " << dishwasher.capacityCutlery << " pieces of cutlery" << std::endl;
    dishwasher.cutleryCounter();
    std::cout << "here's " << myDishes.soupBowls << " soupbowls" << std::endl;
    myDishes.soupBowlCounter();

    Oven oven;
    oven.bakePizza();
    oven.adjustTemp();
    std::cout << "How high does it go?" << std::endl;
    std::cout << "It goes up to " << oven.highestTemp << " degrees Celsius" << std::endl;
    oven.printMaxTemp();

    Stove stove;
    stove.boilWater();
    stove.cookBigMeal();
    std::cout << "You can use pots with a diameter between " << stove.smallestDiam << " and " << stove.largestDiam << " centimeters" << std::endl;
    stove.potSizePossibilities();

    KitchenCatalog kitchenCatalog;
    kitchenCatalog.displayPage(2);
    kitchenCatalog.displayPage(5);
    kitchenCatalog.shippingCost(1, 3, 5);
    kitchenCatalog.shippingCost(0, 0, 2);
    std::cout << "The shipping for an oven is " << kitchenCatalog.shippingCost(0, 1, 0) << " Euro" << std::endl;
    kitchenCatalog.shippingForAnOven();

    KitchenStuff kitchenStuff;
    kitchenStuff.usingOven("pizza");
    kitchenStuff.usingStove("water");
    std::cout << "A run takes " << kitchenStuff.myDishwasher.timePerRun << " minutes" << std::endl;
    kitchenStuff.dishwasherTime();

    std::cout << "good to go!" << std::endl;
}
