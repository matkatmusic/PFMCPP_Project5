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

 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */





#include<iostream>
#include "LeakedObjectDetector.h"

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

    JUCE_LEAK_DETECTOR(Safeway)
};

struct CustomerWrapper
{
    CustomerWrapper( Safeway::Customer *ptr) : pointerToCustomer(ptr){}
    ~CustomerWrapper()
    {
        delete pointerToCustomer;
    }
    Safeway::Customer *pointerToCustomer = nullptr;
};

struct SafewayWrapper
{
    SafewayWrapper( Safeway *ptr) : pointerToSafeway(ptr) {}
    ~SafewayWrapper()
    {
        delete pointerToSafeway;
    }
    Safeway *pointerToSafeway = nullptr;
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

    JUCE_LEAK_DETECTOR(Artist)
};

struct GroupWrapper
{
    GroupWrapper(Artist::Group *ptr) : pointerToGroup(ptr) {}
    ~GroupWrapper()
    {
        delete pointerToGroup;
    }
    Artist::Group *pointerToGroup = nullptr;
};

struct ArtistWrapper
{
    ArtistWrapper(Artist *ptr) : pointerToArtist(ptr) {}
    ~ArtistWrapper()
    {
        delete pointerToArtist;
    }
    Artist *pointerToArtist = nullptr;
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

    JUCE_LEAK_DETECTOR(ShelterOfCats)
};

struct ShelterOfCatsWrapper
{
    ShelterOfCatsWrapper( ShelterOfCats *ptr) : pointerToShelterOfCats(ptr) {}
    ~ShelterOfCatsWrapper()
    {
        delete pointerToShelterOfCats;
    }
    ShelterOfCats *pointerToShelterOfCats = nullptr;
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

    JUCE_LEAK_DETECTOR(Map)
};

struct MapWrapper
{
    MapWrapper( Map *ptr) : pointerToMap(ptr) {}
    ~MapWrapper()
    {
        delete pointerToMap;
    }
    Map *pointerToMap = nullptr;
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
    JUCE_LEAK_DETECTOR(CommerceBureau)
};

struct CommerceBureauWrapper
{
    CommerceBureauWrapper( CommerceBureau *ptr) : pointerToCommerceBureau(ptr) {}
    ~CommerceBureauWrapper()
    {
        delete pointerToCommerceBureau;
    }
    CommerceBureau *pointerToCommerceBureau = nullptr;
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
    //Safeway northblock;//2
    SafewayWrapper northblock( new Safeway());
    //SafewayWrapper patrick( new Safeway::Customer());
    northblock.pointerToSafeway->printThing();
    //ShelterOfCats oreo;//3
    ShelterOfCatsWrapper oreo( new ShelterOfCats());
    oreo.pointerToShelterOfCats->printThing();
    //Artist ladygaga;//6
    ArtistWrapper ladygaga( new Artist());
    ladygaga.pointerToArtist->printThing();
    CustomerWrapper patrick( new Safeway::Customer());
    GroupWrapper loveGaga (new Artist::Group());


    std::cout << "" << std::endl; 
//=========Part2
    northblock.pointerToSafeway->limitOfCoupons(5, 3);
    std::cout << "northblock.coupons: " << northblock.pointerToSafeway->coupons << std::endl;
    northblock.pointerToSafeway->printCoupons();
    
    patrick.pointerToCustomer->alarmForMembership(10, 13);
    std::cout << "patrick.membership: " << patrick.pointerToCustomer->membership << std::endl;
    patrick.pointerToCustomer->printMembership();

    oreo.pointerToShelterOfCats->preparationBeforeAdopt(3, 1);
    std::cout << "oreo.getVaccined: " << oreo.pointerToShelterOfCats->getVaccined << std::endl;
    oreo.pointerToShelterOfCats->printGetVaccined();

    std::cout << "ladygaga.followers: " << ladygaga.pointerToArtist->numberOfFollowers << std::endl;
    ladygaga.pointerToArtist->printNumberOfFollowers();

    std::cout << "loveGaga.members: " << loveGaga.pointerToGroup->numberOfMembers << std::endl;
    loveGaga.pointerToGroup->printNumberOfMembers();

    std::cout << "" << std::endl;
    northblock.pointerToSafeway->printQAboutb();
    std::cout << "Is northblock's member var 'b' equal to 2? " << (northblock.pointerToSafeway->b == 2 ? "Yes" : "No") << "\n";
    northblock.pointerToSafeway->printQAboutb();
    
    std::cout << "Is oreo's member var 'c' equal to 3? " << (oreo.pointerToShelterOfCats->c == 3 ? "Yes" : "No") << "\n";
    oreo.pointerToShelterOfCats->printQAboutc();

    std::cout << "Is ladygaga's member var 'f' equal to 6? " << (ladygaga.pointerToArtist->f == 6 ? "Yes" : "No") << "\n";
    ladygaga.pointerToArtist->printQAboutf();
//Part 2 =========End

    std::cout << "" << std::endl; 
    Safeway::Customer mary;
    northblock.pointerToSafeway->orderGroceryOnline(mary);
    oreo.pointerToShelterOfCats->donateMoney(4.88);
    oreo.pointerToShelterOfCats->adoptACat(23);
    ladygaga.pointerToArtist->checkTheHottestSongOfArtist(23);
    ladygaga.pointerToArtist->followAArtist("ladygaga");

    std::cout << "" << std::endl; 

    MapWrapper mapleStreet( new Map());
    mapleStreet.pointerToMap->parkSpaceFinder(0);
    std::cout << "" << std::endl; 
    mapleStreet.pointerToMap->turnROrNot(13, 7, 12);
    std::cout << "" << std::endl; 
    CommerceBureauWrapper market (new CommerceBureau());
    market.pointerToCommerceBureau->permissionUpdate(7, 6);
    market.pointerToCommerceBureau->taxPaidRequirment(1, 0.15);

    std::cout << "" << std::endl; 
    
    std::cout << "good to go!" << std::endl;
}
