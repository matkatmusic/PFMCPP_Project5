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


#include<iostream>

/*
 copied UDT 1:====================================
 */
struct Safeway
{
    int b;
    float bb{2.2f};
    Safeway();
    ~Safeway();
    float openTime = 9.f;
    float discount = 0.7f;
    int customerPoints = 234;
    int permissionYear = 2021;
    int coupons = 34;
    
    struct Customer
    {
        int accountnumber = 133423;
        int membership = 37;
        bool relatedCreditCard = 0;
        float amountOfLastOrder = 67.59f;
        int registrationDays = 133;
        void redeemGiftCard(int codeOfGiftcard = 133278645);
        bool redeemProduct(int pointsOfProduct = 700);
        void changeProfile(int dateOfBirthday = 13);
        int alarmForMembership(int threshold, int currentDays);
        void printMembership();
    };
    void printCoupons();
    void printQAboutb();
    void orderGroceryOnline(Customer customer);
    double refund(int productNumber);
    void collectCoupons(Customer customer);
    void printThing();
    int limitOfCoupons(int threshold, int couponsInUse);
};

void Safeway::printQAboutb()
{
    std::cout << "Is northblock's member var 'b' equal to 2? " << (this->b == 2 ? "Yes" : "No") << "\n";
}

void Safeway::printCoupons()
{
    std::cout << "northblock.coupons: " << this->coupons << std::endl << std::endl;
}
void Safeway::Customer::printMembership()
{
    std::cout << "patrick.membership: " << this->membership << std::endl << std::endl;
}

Safeway::~Safeway()
{
    std::cout<< "Artist is being deleted" << std::endl;
}

int Safeway::Customer::alarmForMembership(int threshold, int currentDays = 0)
{  
    while(currentDays >  threshold)
    {
        --currentDays;
        std::cout << "left days: " << currentDays << std::endl;
        if(currentDays <= threshold)
        {
            std::cout<< "It's time to refresh your membership." << std::endl;
            membership = currentDays;
            return currentDays;
        }
    }
    return -1;
}

int Safeway::limitOfCoupons(int threshold, int couponsInUse = 0)//P5
{
    while(couponsInUse < threshold)
    {
        ++couponsInUse;
        std::cout << "coupons in use : " << couponsInUse << std::endl;
        if(couponsInUse >= threshold)
        {
            std::cout << "In one order, you could only use 5 promocode." << std::endl;
            coupons  = couponsInUse;
            return couponsInUse;
        }
    }
    return -1;
}

Safeway::Safeway() : b(2)
{
}


void Safeway::printThing()
{
    std::cout << "Safeway::printThing() b: " << b << " bb:"<< bb << std::endl; 
}

void Safeway::orderGroceryOnline(Customer customer)
{
    std::cout << "Customer's profile: " << customer.accountnumber << std::endl;
}

double Safeway::refund(int productNumber)
{
    std::cout << "Product Number: " << productNumber << std::endl;
    std::cout << "Product Value: 1" << std::endl;
    return 0.1;
}

void Safeway::collectCoupons(Customer customer)
{
    std::cout << "Coupons " << customer.membership << std::endl;
}

void Safeway::Customer::redeemGiftCard(int codeOfGiftcard)
{
    std::cout << "submit " << codeOfGiftcard << std::endl;
}

bool Safeway::Customer::redeemProduct(int pointsOfProduct)
{
    return !(pointsOfProduct > 700);
}

void Safeway::Customer::changeProfile(int dateOfBirthday)
{
    std::cout << " Current Date Of Birthday" << dateOfBirthday << std::endl;
}
/*
 copied UDT 2:====================================
 */
struct Artist
{
    double fb{6.6};
    Artist();
    ~Artist();
    int f;
    int age = 23;
    int numberOfSocialUpdates = 14;
    int numberOfFollowers = 1002;
    int numberOfAlbums = 3;
    int numberOfAwards = 5;
    void printThing();
    struct Group
    {
        int numberOfMembers = 233;
        std::string administrator = "sodabuddy";
        std::string notice = " New album will be released in few weeks";
        int limitOfMembers = 500;
        int unreadMessages = 82;
        void printNumberOfMembers();
        void addAdministrators(std::string nickname = "Tulips");
        void confirmNotice(std::string notice1);
        void changeNickname(std::string newNickname = "Cornish");
        int groupMembers(int capacity, int members = 0);
    };
    std::string followAArtist(std::string nameOfArtist);
    void enterTheGroupOfAArtist(Group group);
    void checkTheHottestSongOfArtist(int rankingOfASong);
    void abbreOfNumber(int fiveThousands, int followers = 0);
    void printNumberOfFollowers();
    void printQAboutf();
};

void Artist::printQAboutf()
{
    std::cout << "Is ladygaga's member var 'f' equal to 6? " << (this->f == 6 ? "Yes" : "No") << "\n";
}

void Artist::Group::printNumberOfMembers()
{
    std::cout << "loveGaga.members: " << this->numberOfMembers << std::endl << std::endl;
}

void Artist::printNumberOfFollowers()
{
    std::cout << "ladygaga.followers: " << this->numberOfFollowers << std::endl << std::endl;
}


Artist::~Artist()
{
    std::cout<< "Artist is being deleted" << std::endl;
}

void Artist::abbreOfNumber(int fiveThousands, int followers)
{
    std::string fiveThou = "5k";
    while(followers < fiveThousands)
    {
        followers += 100;
        std::cout << "This artist has " << followers << " followers" << std::endl;
        if(followers >= fiveThousands)
        {
            numberOfFollowers = followers;
            std::cout << "This artist has " << fiveThou << " followers" << std::endl;
        }
    }
}

int Artist::Group::groupMembers(int capacity, int members)
{
    while(members < capacity)
    {
        ++members;
        std::cout << "The group has" << members << "members" << std::endl;
        if(members >= capacity)
        {
            std::cout<< "There is no capacity for new members." << std::endl;
            numberOfMembers = members;
            return members;
        }
    }
    return -1;
}
Artist::Artist() : f(6){}

void Artist::printThing()
{
    std::cout << "Artist::printThing() f: " << f << " fb:" << fb << std::endl; 
}

void Artist::Group::addAdministrators(std::string nickname)
{
    std::cout << " New Administrator:" << nickname << std::endl;
}

void Artist::Group::confirmNotice(std::string notice1 = "Monday" )
{
    std::cout << " Confirmed" << notice1 << std::endl;
}

void Artist::Group::changeNickname(std::string newNickname)
{
    std::cout << " New Nickname" << newNickname << std::endl;
}

std::string Artist::followAArtist(std::string nameOfArtist)
{
    return nameOfArtist;
}

void Artist::enterTheGroupOfAArtist(Group group)
{
    std::cout << " Successful enter into" << group.numberOfMembers << std::endl;
}

void Artist::checkTheHottestSongOfArtist(int rankingOfASong)
{
    std::cout << "The ranking: " << rankingOfASong << std::endl;
}

/*
 copied UDT 3:====================================
 */
struct ShelterOfCats
{
    float cb{3.3f};
    ShelterOfCats();
    ~ShelterOfCats();
    int c;
    int numberOfCats = 5;
    float distance = 1.2f;
    int amountOfMoneyToAdoptACat = 80;
    float ageOfACat = 0.5f;
    int getVaccined = 3;
    void adoptACat(int numberOfCat);
    double donateMoney(double donation);
    void visitTheShelterOnSite(std::string address);
    void printThing();
    int preparationBeforeAdopt(int preparationNumber, int vaccineNumber = 0);
    void printGetVaccined();
    void printQAboutc();
};

void ShelterOfCats::printQAboutc()
{
     std::cout << "Is oreo's member var 'c' equal to 3? " << (this->c == 3 ? "Yes" : "No") << "\n";
}

void ShelterOfCats::printGetVaccined()
{
    std::cout << "oreo.getVaccined: " << this->getVaccined << std::endl << std::endl;
}

ShelterOfCats::~ShelterOfCats()
{
    std::cout<< "ShelterOfCats is being deleted" << std::endl;
}

int ShelterOfCats::preparationBeforeAdopt(int preparationNumber, int vaccineNumber)
{
    for(int i = vaccineNumber; i <= preparationNumber; ++i)
    {
        std::cout << "Already get vaccined: " << i << std::endl;
        if(i >= preparationNumber)
        {
            std::cout << "This kitten is all set."<< std::endl;
            getVaccined = i;
            return i;
        }
    }
    return -1;
}


ShelterOfCats::ShelterOfCats() : c(3)
{
}


void ShelterOfCats::printThing()
{
    std::cout << "ShelterOfCats::printThing() c: " << c << " cb:" << cb << std::endl; 
}

void ShelterOfCats::adoptACat(int numberOfCat)
{
    std::cout << "Current number of cat: " << numberOfCat << std::endl;
}

double ShelterOfCats::donateMoney(double donation)
{
    donation += donation;
    return 4.90;
}

void ShelterOfCats::visitTheShelterOnSite(std::string address)
{
    std::cout << "The address:" << address << std::endl;
}

/*
 new UDT 4:====================================
 with 2 member functions
 */
struct Map
{
    ShelterOfCats kittenMeet;
    Safeway oDistrict;
    Safeway::Customer mary;
    void parkSpaceFinder(int parkingLot);
    void turnROrNot(double currentT, double openT, double closeT);
    Map();
    ~Map();

};



Map::Map()
{
    std::cout << "Welcome!" << std::endl;
}

Map::~Map()
{
    std::cout << "See you!" << std::endl;
}


void Map::parkSpaceFinder(int parkingLot)
{
    if (parkingLot > 1)
    {
        std::cout << "Has " << parkingLot << "parking spaces. " << std::endl;
    }
    else if(parkingLot== 1)
    {
        std::cout << "Has " << parkingLot << "parking space. " << std::endl;
    }
    else if(parkingLot==0)
    {
        std::cout << "Has " << parkingLot << " parking space. " << std::endl;
        oDistrict.orderGroceryOnline(mary);
        std::cout << "Would you like to order online? " << std::endl;
    } 
}

void Map::turnROrNot(double currentT, double openT, double closeT)
{
    if(openT <= currentT && closeT > currentT)
    {
        std::cout << "It's open until " << closeT << "." << std::endl;
    }
    else
    {
        std::cout << "It will open at " << openT << " tommorow." << std::endl;
    }
}



/*
 new UDT 5:====================================
 with 2 member functions
 */
struct CommerceBureau
{
    ShelterOfCats kittenMeet;
    Safeway oDistrict;
    CommerceBureau();
    ~CommerceBureau();
    bool permissionUpdate(int currentYear, int permissionYear);
    double taxPaidRequirment(bool forProfit, double tax);
    void memberG();
};

void CommerceBureau::memberG()
{
    std::cout << "CommerceBureau permissionUpdate: " << this->permissionUpdate(2019,2021) << " and CommerceBureau taxPaidRequirment : " << this->taxPaidRequirment(0, 1245566.23) << std::endl;
}

CommerceBureau::CommerceBureau()
{
   std::cout << "Entering the internal system..." << std::endl;
}

CommerceBureau::~CommerceBureau()
{
    std::cout << "Leaving the internal system..." << std::endl;
}

bool CommerceBureau::permissionUpdate(int currentMonth, int permissionMonth)
{
    if (permissionMonth < currentMonth)
    {
        std::cout << "Time to update your business permission." << std::endl;
        return false; 
    }

    return true;
}

double CommerceBureau::taxPaidRequirment(bool forProfit, double tax = 0)
{
    if (forProfit == true)
    {
        std::cout << "need to pay " << tax << " profit as tax." <<std::endl;
        return tax;
    }
    std::cout << "This is a non-profit organization." << std::endl;
    return 0;
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

    std::cout << "" << std::endl; 
    Safeway northblock;//2
    northblock.printThing();
    ShelterOfCats oreo;//3
    oreo.printThing();
    Artist ladygaga;//6
    ladygaga.printThing();
    Safeway::Customer patrick;
    Artist::Group loveGaga;

    std::cout << "" << std::endl; 
//=========Part2
    northblock.limitOfCoupons(5, 3);
    std::cout << "northblock.coupons: " << northblock.coupons << std::endl;
    northblock.printCoupons();
    
    patrick.alarmForMembership(10, 13);
    std::cout << "patrick.membership: " << patrick.membership << std::endl;
    patrick.printMembership();

    oreo.preparationBeforeAdopt(3, 1);
    std::cout << "oreo.getVaccined: " << oreo.getVaccined << std::endl;
    oreo.printGetVaccined();

    std::cout << "ladygaga.followers: " << ladygaga.numberOfFollowers << std::endl;
    ladygaga.printNumberOfFollowers();

    std::cout << "loveGaga.members: " << loveGaga.numberOfMembers << std::endl;
    loveGaga.printNumberOfMembers();

    std::cout << "" << std::endl;
    northblock.printQAboutb();
    std::cout << "Is northblock's member var 'b' equal to 2? " << (northblock.b == 2 ? "Yes" : "No") << "\n";
    northblock.printQAboutb();
    
    std::cout << "Is oreo's member var 'c' equal to 3? " << (oreo.c == 3 ? "Yes" : "No") << "\n";
    oreo.printQAboutc();

    std::cout << "Is ladygaga's member var 'f' equal to 6? " << (ladygaga.f == 6 ? "Yes" : "No") << "\n";
    ladygaga.printQAboutf();
//Part 2 =========End

    std::cout << "" << std::endl; 
    Safeway::Customer mary;
    northblock.orderGroceryOnline(mary);
    oreo.donateMoney(4.88);
    oreo.adoptACat(23);
    ladygaga.checkTheHottestSongOfArtist(23);
    ladygaga.followAArtist("ladygaga");

    std::cout << "" << std::endl; 

    Map mapleStreet;
    mapleStreet.parkSpaceFinder(0);
    std::cout << "" << std::endl; 
    mapleStreet.turnROrNot(13, 7, 12);
    std::cout << "" << std::endl; 
    CommerceBureau market;
    market.permissionUpdate(7, 6);
    market.taxPaidRequirment(1, 0.15);

    std::cout << "" << std::endl; 
    
    std::cout << "good to go!" << std::endl;
}
