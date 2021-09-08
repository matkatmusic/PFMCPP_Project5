/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */








#include<iostream>

#include "Wrappers.h"
#include "Safeway.h"
#include "ShelterOfCats.h"
#include "Artist.h"
#include "CommerceBureau.h"
#include "Map.h"





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
