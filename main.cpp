/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.

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


 */
#include <iostream>
/*
 copied UDT 1:
 */
struct CoffeeShop
{
    CoffeeShop();
    ~CoffeeShop();
    int numBaristas, numCoffeeMachines, numRegisters, numCustomers, numTables;
    float balance;
    std::string brewMethod;

    struct Coffee
    {
        Coffee();
        ~Coffee();
        std::string type, roast;
        int coarseness;
    };
    Coffee standardBrew;

    struct Customer
    {
        Customer();
        ~Customer();
        int customerID;
        bool rewardsMember;
        float customerPhoneNumber, rewardsBalance;
        std::string name;

        bool useRewardsPoints(float rewardsPoints);
        void newMemberPromotion(float incentiveAmount);
        bool contactCustomer(std::string msg);
    };

    Coffee brewCoffee( std::string customerName, Coffee coffeeType, int size, std::string brewType, bool cream, bool sugar);
    bool grindCoffee(Coffee coffeeType, int coarseness, Customer customerA);
    void renameCustomer(Customer& customerA, std::string newName); // changed to a reference to fix, IDK
    void pourCoffee(Coffee coffee, int size);
};

CoffeeShop::CoffeeShop() :
numBaristas(2),
numCoffeeMachines(4),
numRegisters(2),
numCustomers(0),
numTables(12),
balance(0.0f),
brewMethod("pour over")
{
    std::cout << "\n+ CoffeeShop constructed!" << std::endl;  
}

CoffeeShop::~CoffeeShop()
{
    std::cout << "\n- CoffeeShop destructed!" << std::endl;
}

CoffeeShop::Coffee::Coffee() :
type("columbian"),
roast("dark"),
coarseness(1)
{
    std::cout << "\n+ CoffeeShop::Coffee constructed!" << std::endl;  
}

CoffeeShop::Coffee::~Coffee()
{
    std::cout << "\n- CoffeeShop::Coffee destructed!" << std::endl;  
}

CoffeeShop::Customer::Customer() :
customerID(1),
rewardsMember(false),
customerPhoneNumber(0.0f),
rewardsBalance(0.0f),
name("New Customer")
{
    std::cout << "\n+ CoffeeShop::Customer constructed!" << std::endl;  

}

CoffeeShop::Customer::~Customer()
{
    std::cout << "\n- CoffeeShop::Customer destructed!" << std::endl;  

}

bool CoffeeShop::Customer::contactCustomer(std::string msg = "Your order is ready.")
{
    if( customerPhoneNumber > 0 )
    {
        if( msg.length() > 1 )
        {
            std::cout << "Texting " << name << ": \"" << msg << "\"" << std::endl;
            return true;
        }
        else std::cout << "Message is too short.\n";

    }
    else std::cout << name << " doesn't have a phone number saved.\n";

    return false;
}

bool CoffeeShop::Customer::useRewardsPoints(float rewardsPoints)
{
    if( rewardsMember == true )
    {
        if( rewardsBalance > rewardsPoints )
        {
            rewardsBalance -= rewardsPoints;
            std::cout << name << " used " << rewardsPoints << " points, leaving a balance of " << rewardsBalance << "\n";
            return true;
        }
        else std::cout << name << " doesn't have enough points.\n";

    }
    else std::cout << name << " is not a rewards member!\n";

    return false;
}

void CoffeeShop::Customer::newMemberPromotion(float incentiveAmount)
{
    rewardsBalance += incentiveAmount;
    rewardsMember = true;
    contactCustomer("Welcome to the coffee club!");
}

CoffeeShop::Coffee CoffeeShop::brewCoffee(std::string customerName, Coffee coffeeType, int size, std::string brewType, bool cream = false, bool sugar = false)
{
    std::cout << "New order for " << customerName << ": size " << size << ", " << brewType << ", " << coffeeType.type << ", " << coffeeType.roast;
    if( cream)
    {
        std::cout << ", with cream";
    }

    if( sugar)
    {
        std::cout << ", with sugar";
    }
    
    std::cout << std::endl;

    CoffeeShop::Coffee newCoffee;

    return newCoffee;
}

bool CoffeeShop::grindCoffee(Coffee coffeeType, int coarseness, Customer customerA)
{
    for( int i = coffeeType.coarseness; i < coarseness; ++i)
    {
        std::cout << "... grinding coffee to coarseness " << i << std::endl;
    }
    std::cout << "Ground coffee to coarseness " << coarseness << ", " << coffeeType.type << ", " << coffeeType.roast << " for: " << customerA.name << "\n";
    return true;
}

void CoffeeShop::renameCustomer(Customer& customerA, std::string newName)
{
    if( newName.length() > 1)
    {
        std::cout << customerA.name;
        customerA.name = newName;
        std::cout << "'s name changed to: " << customerA.name << "\n";
    }
    else
    {
        std::cout << "New name too short.\n";
    }
}

void CoffeeShop::pourCoffee(Coffee coffee, int size)
{
    std::cout << "Pouring coffee...\n";
    for( int i = 1; i < size; ++i)
    {
        if( i == size)
        {
            std::cout << "FULL!\n";
            return;
        }

        std::cout << "Volume at " << i << ", keep pouring... " << std::endl;
    }

    std::cout << "Size " << size << " " << coffee.roast << " " << coffee.type << " coffee poured.\n";
}

/*
 copied UDT 2:
 */
 struct InvoiceManager
{
    InvoiceManager();
    ~InvoiceManager();
    int numInvoices, numClients, numTemplates;
    float outBalance;
    std::string workType;

    struct Invoice
    {
        Invoice(std::string name);
        ~Invoice();
        std::string clientName, workType;
        int invoiceNumber;
        float workTime, totalBalance, dueDate;
        bool overdue;

        void download(std::string format);
        void markAsPaid(Invoice& invoiceA);
        void duplicate(Invoice& invoiceA);
    };


    Invoice createInvoice(std::string clientName, float dueDate, std::string workType, float workTime);
    bool checkOverdue(Invoice invoice);
    float checkBalance(Invoice invoice);
    void printHolidyCards();
};

InvoiceManager::InvoiceManager() :
numInvoices(234),
numClients(32),
numTemplates(4),
outBalance(10345.24f),
workType("mastering")
{
    std::cout << "\n+ InvoiceManager constructed!" << std::endl; 
}

InvoiceManager::~InvoiceManager()
{
    std::cout << "\n- InvoiceManager destructed!" << std::endl;
}

InvoiceManager::Invoice::Invoice(std::string name) :
clientName("unknown"),
workType("post"),
workTime(0.0f),
totalBalance(0.0f),
overdue(false)
{
    std::cout << "\n+ InvoiceManager::Invoice constructed:" << std::endl;
    std::cout << "Client name: " << (clientName = name) << std::endl;
    std::cout << "workType: " << workType << std::endl;
    std::cout << "workTime: " << workTime << std::endl;
    std::cout << "totalBalance: $" << totalBalance << std::endl;
    std::cout << "overdue: false\n";
    std::cout << "+++++++++++++++++\n";
    
}

InvoiceManager::Invoice::~Invoice()
{
    std::cout << "\n- InvoiceManager::Invoice destructed:" << std::endl;
    overdue ? std::cout << "overdue! guess you didn't need the $" << totalBalance << std::endl : std::cout << "not overdue!\n";
    std::cout << "-----------------\n";
}

void InvoiceManager::Invoice::download(std::string format = "pdf")
{
    std::cout << "https:\\\\my.freshbooks.com\\invoice." << format << "\n";
}

void InvoiceManager::Invoice::markAsPaid(Invoice& invoiceA)
{
    invoiceA.totalBalance = 0.0f;
    invoiceA.overdue = false;
}

void InvoiceManager::Invoice::duplicate(Invoice& invoiceA)
{
    Invoice invoiceB = invoiceA;    // I would not really do this
    ++invoiceB.invoiceNumber;
    std::cout << "Duplicated invoice " << invoiceA.invoiceNumber << " as " << invoiceB.invoiceNumber << std::endl;
}

InvoiceManager::Invoice InvoiceManager::createInvoice(std::string name, float date, std::string type = "post", float time = 0.0f)
{
    Invoice newInvoice(name);
    ++numInvoices;
    newInvoice.invoiceNumber = numInvoices;
    newInvoice.dueDate = date;
    newInvoice.workType = type;
    newInvoice.workTime = time;

    return newInvoice;
}

bool InvoiceManager::checkOverdue(Invoice invoiceA)
{
    std::cout << "Invoice " << invoiceA.invoiceNumber << " is ";
    if( invoiceA.overdue == false)
    {
        std::cout <<  "not ";
    }
    std::cout << "overdue.\n";

    return invoiceA.overdue;
}

float InvoiceManager::checkBalance(Invoice invoiceA)
{
    std::cout << invoiceA.invoiceNumber << " balance is: " << invoiceA.totalBalance << std::endl;

    return invoiceA.totalBalance;
}

void InvoiceManager::printHolidyCards()
{
    std::cout << "Printing holiday cards for all " << numClients << " clients...\n";
    int i = 0;
    while( i < numClients )
    {
        ++i;
        std::cout << "Printing card # " << i << std::endl;
    }

}

/*
 copied UDT 3:
 */
struct ScooterRental
{
    ScooterRental();
    ~ScooterRental();
    int distanceTraveled, speed, latitude, longitude;
    float rentalTime, balance, voltage;

    void accelerate(float throttle);
    void brake(float brake);
    float lock();
    void cruiseControl(int targetSpeed);
};

ScooterRental::ScooterRental() :
distanceTraveled(0),
speed(0),
latitude(3),
longitude(-11),
rentalTime(0.0f),
balance(1.0f),
voltage(100.0f)
{
    std::cout << "\n+ ScooterRental constructed!" << std::endl; 
}

ScooterRental::~ScooterRental()
{
    std::cout << "\n- ScooterRental destructed!" << std::endl; 
}

void ScooterRental::accelerate(float throttle = 0.0f)
{
    voltage = voltage * throttle;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

void ScooterRental::brake(float brake = 0.0f)
{
    voltage -= brake;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

float ScooterRental::lock()
{
    voltage = 0.0f;
    std::cout << "The scooter voltage is " << voltage << std::endl;
    
    return balance;
}

void ScooterRental::cruiseControl(int targetSpeed)
{
    std::cout << "Engaging cruise control at speed " << targetSpeed << std::endl;
    for( ; speed < targetSpeed; ++speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    for( ; speed > targetSpeed; --speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    if( speed == targetSpeed) std::cout << "Cruisin' at " << speed << "\n";
}


/*
 new UDT 4:
 with 2 member functions
 */
struct Town         
{
    Town();
    ~Town();
    CoffeeShop coffeeShop;
    ScooterRental scooterRental;
    float totalTaxes;

    float collectTaxes();
    void quarantine();
};

Town::Town()
{
    std::cout << "\n+ Building Town with coffeeShop and a scooter rental!\n";
}

Town::~Town()
{
    std::cout << "\n- Demolishing Town with coffeShop and a scooter rental which earned " << totalTaxes << "!\n";
}

float Town::collectTaxes()
{
float taxes = 0.0f;

std::cout << "Taxing:\n";
std::cout << "coffeeShop with balance of $" << coffeeShop.balance << " for $"<< coffeeShop.balance * 0.3f << std::endl;
std::cout << "scooterRental with balance of $" << scooterRental.balance << " for $" << scooterRental.balance * 0.3f << std::endl;

taxes += coffeeShop.balance * 0.3f + scooterRental.balance * 0.3f;
totalTaxes += taxes;

std::cout << "for a total haul of $" << taxes << (taxes < 1 ? "?" : "!") << std::endl;

coffeeShop.balance *= 0.7f;
scooterRental.balance *= 0.7f;

return taxes;
}

void Town::quarantine()
{
    std::cout << "! Quarantine in effect ! Stay home !\n";
    coffeeShop.numBaristas = 0;
    coffeeShop.numCustomers = 0;
    std::cout << "! Public transportation is free if you need to use it !\n";
    scooterRental.balance = 999999999.0f;
}


/*
 new UDT 5:
 with 2 member functions
 */
struct Studio
{
    Studio();
    ~Studio();
    int numInterns, numAssistants;
    float balance;
    CoffeeShop theKitchen;
    ScooterRental scooterA, scooterB;
    InvoiceManager invoices;

    void orderRun(std::string runner, InvoiceManager::Invoice invoice, ScooterRental scooter, int latCoord, int longCoord, std::string order);
    void prepareCoffee(std::string runner, std::string clientName, CoffeeShop::Coffee coffeeType, int size, std::string brewType, bool cream, bool sugar);
};

Studio::Studio() :
numInterns(4),
numAssistants(3),
balance(10000.0f)
{
    std::cout << "\n+ Constructed Studio!\n";
}

Studio::~Studio()
{
    std::cout << "\n- Destructing Studio!\n";
}

void Studio::orderRun(std::string runner, InvoiceManager::Invoice invoice, ScooterRental scooter, int latCoord, int longCoord, std::string order)
{
    std::cout << "Hey " << runner << " you need to go to grab " << order << " for " << invoice.clientName << ".\n";
    std::cout << "Here's a map, X marks the spot U need to go to:\n";
    int longRectified = longCoord + 18;
    int latRectified = latCoord + 18;
    int scooterLongRectified = scooter.longitude + 18;
    int scooterLatRectified = scooter.latitude + 18;
    
    for(int x = 1; x <= 37; ++x)
    {
        std::cout << "==";
    }
    std::cout << std::endl;

    for(int y = 1; y <= 36; ++y)
    {
        std::cout << "||";
        for(int x = 1; x <= 36; ++x)
        {
            if(x == longRectified && y == latRectified) std::cout << "X ";
            else if(x == scooterLongRectified && y == scooterLatRectified) std::cout << "U ";
            else if(x == 36) std::cout << "||";
            else std::cout << "  ";
        }
        
        std::cout << std::endl;
    }
    for(int x = 1; x <= 37; ++x)
    {
        std::cout << "==";
    }

    std::cout << std::endl;
 
    balance += scooter.balance;
   
}

void Studio::prepareCoffee(std::string runner, std::string clientName, CoffeeShop::Coffee coffeeType, int size, std::string brewType, bool cream = false, bool sugar = false)
{
    std::cout << "Hey " << runner << ", you need to make a " << brewType << " size " << size << " " << coffeeType.type << " coffee" << (cream && sugar ? " with cream and sugar" : (cream ? " with cream " : (sugar ? " with sugar" : ""))) << " for " << clientName << std::endl;
    theKitchen.brewCoffee(clientName, coffeeType, size, brewType, cream, sugar);
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
    std::cout << "good to go!" << std::endl;

    std::cout << std::endl; // new UDT

    CoffeeShop broBucks;
    CoffeeShop::Customer tobyMason;

    broBucks.renameCustomer(tobyMason, "Toby Mason");
    broBucks.grindCoffee(broBucks.standardBrew, 10, tobyMason);
    broBucks.brewCoffee("Toby Mason", broBucks.standardBrew, 2, "cold brew", true, false);
    broBucks.pourCoffee(broBucks.standardBrew, 3);

    std::cout << std::endl; // new UDT

    tobyMason.useRewardsPoints( 130.0f);
    tobyMason.newMemberPromotion( 3.0f);
    std::cout << "Toby's rewards's balance is now: " << tobyMason.rewardsBalance << std::endl;
    tobyMason.useRewardsPoints( 12.0f);
    tobyMason.useRewardsPoints( 2.0f);
    tobyMason.contactCustomer();
    tobyMason.customerPhoneNumber = 3233933291;
    tobyMason.contactCustomer("k");
    tobyMason.contactCustomer();

    std::cout << std::endl; // new UDT

    InvoiceManager tobyInvoices;
    InvoiceManager::Invoice testInvoice("test");
    
    tobyInvoices.createInvoice("test invoice 2", 346255342.0f);
    testInvoice.invoiceNumber = 5;
    tobyInvoices.checkOverdue(testInvoice);
    testInvoice.totalBalance = 543.21f;
    testInvoice.overdue = true;
    tobyInvoices.checkBalance(testInvoice);
    tobyInvoices.printHolidyCards();
    testInvoice.download();
    testInvoice.markAsPaid(testInvoice);
    std::cout << "Invoice " << testInvoice.invoiceNumber << " remaining balance: " << testInvoice.totalBalance << std::endl;
    testInvoice.duplicate(testInvoice);

    std::cout << std::endl; // new UDT
    
    ScooterRental tobysScooter;

    tobysScooter.accelerate( 1.5f);
    tobysScooter.brake(100.0f);
    tobysScooter.cruiseControl(10);
    tobysScooter.cruiseControl(4);
    tobysScooter.lock();

    std::cout << std::endl; // new UDT

    Town weHo;
    weHo.collectTaxes();
    weHo.quarantine();

    std::cout << std::endl; // new UDT

    Studio conway;
    InvoiceManager::Invoice kiss = conway.invoices.createInvoice("Kiss", 999999.9f, "tracking");
    conway.orderRun("Toby", kiss, conway.scooterA, -5, 9, "a burger from Le Petite Trois");
    conway.prepareCoffee("Toby","Gene", conway.theKitchen.standardBrew, 2, "hot");
    conway.prepareCoffee("Seth","Paul", conway.theKitchen.standardBrew, 3, "cold", true, true);
    conway.prepareCoffee("Seth","Eric", conway.theKitchen.standardBrew, 3, "hot", false, true);


    std::cout << "\n\n# This is the end of main()\n\n";

}
