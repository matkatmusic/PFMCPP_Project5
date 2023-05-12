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
*/
/*
===============================================================     
{
    If you completed Project 3:
     
     1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
        Choose the classes that contained nested classes.  Include the nested classes when you copy them over.
    
     2) move all of your implementations of all functions to OUTSIDE of the class.
    
     3) add destructors
            make the destructors do something like print out the name of the class.
}
*/
/*
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
*/
/*
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

struct MassageChair
{
    int numOfVibrationControls {9};
    int appliedPressure {10}; //measured in PSI
    float backrestReclineAngle = 34.6f;
    double massageDuration;
    float footrestInclineAngle;

    MassageChair();

    void giveMassage(bool startMassage);
    void playBackgroundSound(); 
    int displayTimer(int msgDuration); // displays how much time is left on massage.
    void printMassageChairVars();
    bool startVibration(bool startMassage)
    {
        startMassage == false ? std::cout << "would you like to start a massage?\n" : std::cout <<  "starting\n";
        while(startMassage == true)
        {
            --massageDuration;
            massageDuration < 0.1 ? startMassage = false : startMassage = true;
        }
        return startMassage;
    }  
};


MassageChair::MassageChair() :
massageDuration(30.00),
footrestInclineAngle(90.f)
{
    std::cout << "MassageChair is being constructed!" << std::endl;
}

void MassageChair::giveMassage(bool startMassage)
{
    if(startMassage == true)
    {
        std::cout << "Please remove shoes, and relax!!\n";
    }
    else
    {
        std::cout << "No Massage For You!\n";
    }
}

void MassageChair::playBackgroundSound()
{
    std::cout << "Now playing! \n";
}

int MassageChair::displayTimer(int msgDuration)
{
    std::cout << "now counting down from " << msgDuration << "minuntes\n";
    int secs = 60, mins = msgDuration;
    
    while(mins >= 0)
    {
        --secs;
        
        if(mins > 0 && secs == 0)
        {
            --mins;
            secs += 60;
            
            while(mins == 0 && secs > 0)
            {
                --secs;
            }
        }
        else if(mins == 0 && secs < 0)
        {
            std::cout << "Massage Complete\n";
            break;
        }
        std::cout << mins << " : " << secs << "\n";
    }
    return msgDuration;
}

void MassageChair::printMassageChairVars()
{
    std::cout << "numOfVibrationControls: " << numOfVibrationControls << " \n";
    std::cout << "appliedPressure: " << appliedPressure << " \n";
    std::cout << "backrestReclineAngle: " << backrestReclineAngle << "\n";
    std::cout << "massageDuration:  " << massageDuration << "\n";
    std::cout << "footrestInclineAngle: " << footrestInclineAngle << "\n\n";
}

/*
 copied UDT 2:
 */

struct PetCat
{
    int numOfEyes {2};
    double legnthOfTail {10.35};
    std::string furColor = "Grey & White";
    int ageOfCat;
    std::string nameOfPetCat;
    bool maleGender;
    bool catHungry = true;

    struct CatCollar
    {
        std::string materialOfCollar {"Nylon"};
        float collarMeasurement {10.2f};
        bool isWaterProof = true;
        bool hasCollarBuckle;
        int numOfHolesForBuckle;
        int leashLength;

        CatCollar();

        void repelFleas(int repellantStrength, std::string repellantExpiration);
        void attachLeash();
        int tightenCollar(int bucklePosition);
        void printCatCollarVars();
        int leashExtend(int desiredLength)
        {
            if(desiredLength > leashLength)
            {
                std::cout << "leash isn't that long!\n";
            }
            else
            {
                for(int i = 0; i < desiredLength; ++i)
                {
                    std::cout << "extending to " << i << " \n";
                }
            }
            return desiredLength;
        }
    };

    PetCat();

    void takeOffCollar(CatCollar newCollar);
    void knockOverObjects();
    void scratchVisitors();
    CatCollar replacementCollar;
    void printPetCatVars();
    void catEatFood()
    {
        int nomNomNom = 0;
        
        if(catHungry == true)
        {
            while(catHungry == true && nomNomNom <= 3)
            {
                ++nomNomNom;
                std::cout << "nom nom nom... im still hungry!\n";
                
                if(nomNomNom > 3)
                {
                    std::cout << "Meow... I'm Full now.\n";
                    catHungry = false;
                }   
            }
        }
    }
};

PetCat::CatCollar::CatCollar() :
hasCollarBuckle(true),
numOfHolesForBuckle(4),
leashLength(10)
{
    std::cout << "CatCollar is being constructed!" << std::endl; 
}

void PetCat::CatCollar::repelFleas(int repellantStrength, std::string repellantExpiration)
{
    std::cout << repellantStrength << "is the repellant strength of this collar\n"; 
    std::cout << repellantExpiration << "is the expiration date\n";
}

void PetCat::CatCollar::attachLeash()
{
    std::cout << "Now attaching leash...\n";
    
    if(isWaterProof == true)
    {
        std::cout << "don't be afraid to get a little wet\n";  
    }
}

int PetCat::CatCollar::tightenCollar(int bucklePosition)
{ 
    if(hasCollarBuckle == true && bucklePosition <= numOfHolesForBuckle)
    {
        --bucklePosition;
        std::cout << "collar has been tightened\n";
    }
    else
    {
        std::cout << "This collar only has " << numOfHolesForBuckle << " please inut a whole number smaller or equal to that\n";
    }
    return bucklePosition;
}

void PetCat::CatCollar::printCatCollarVars()
{
    std::cout << "materialOfCollar: " << materialOfCollar << " \n";
    std::cout << "collarMeasurement: " << collarMeasurement << " \n";
    std::cout << "isWaterProof: " << isWaterProof << "\n";
    std::cout << "hasCollarBuckle:  " << hasCollarBuckle << "\n";
    std::cout << "numOfHolesForBuckle: " << numOfHolesForBuckle << "\n\n";  
}

PetCat::PetCat() :
ageOfCat(3),
nameOfPetCat("Doris"),
maleGender(false)
{
    std::cout << "PetCat is being constructed!" << std::endl;
}

void PetCat::takeOffCollar(CatCollar newCollar)
{
    std::cout << nameOfPetCat << " has removed her collar please replace it\n"; 
    replacementCollar = newCollar;
}

void PetCat::knockOverObjects()
{
    std::cout << nameOfPetCat << " has knock over an Object\n";
}

void PetCat::scratchVisitors()
{
    std::cout << nameOfPetCat << " has scratched a visitor\n";
}

void PetCat::printPetCatVars()
{
    std::cout << "numOfEyes: " << numOfEyes << " \n";
    std::cout << "legnthOfTail: " << legnthOfTail << " \n";
    std::cout << "furColor: " << furColor << "\n";
    std::cout << "ageOfCat:  " << ageOfCat << "\n";
    std::cout << "maleGender:  " << maleGender << "\n";    
    std::cout << "nameOfPetCat: " << nameOfPetCat << "\n\n"; 
}

/*
 copied UDT 3:
 */

struct Human
{
    int ageInYears {33};
    std::string nameOfHuman {"First Last"};
    std::string ethnicity = "Black/African American";
    int dateOfBirth;
    std::string bloodType;
    int amountOfBlood;
    bool isAngry = false;

    struct HealthStatus
    {
        int numOfHealthComplications {0};
        bool chronicDiseasesPresent {false};
        bool goToAppointment = false;
        std::string dateOfLastCheckup = "23 Feburary 2022";
        float bodyMassIndex;
        std::string bloodPressureLevel;

        HealthStatus();

        void contractSTD(std::string whichSTD, std::string dateContracted);
        void developeHealthCondition(bool isHereditary, std::string knownSymptoms, std::string conditionName);
        void scheduleCheckUp(std::string returnDate, bool sameDoctor);
        void printHealthStatusVars();
        int countdownNextVisit(int daysSinceLastVisit)
        {
            int daysLeft = 365 - daysSinceLastVisit;
            
            for(int i = daysLeft; i > 0; --i)
            {
                std::cout << i << " days left until next visit\n";
            }
            goToAppointment = true;
            return daysLeft;
        }
    };

    Human();

    void visitDoctor(HealthStatus updateHealthStatus);
    void goToSleep(int howLong);
    void donateBlood(Human girlfriend, bool giveLeftArm);
    HealthStatus healthStatus;
    void printHumanVars();
};

Human::HealthStatus::HealthStatus() :
bodyMassIndex(23.8f),
bloodPressureLevel("120/83 mmHg")
{
    std::cout << "HealthStatus is being constructed!" << std::endl;
}

Human::Human() :
dateOfBirth(12181989),
bloodType("O Negative"),
amountOfBlood(5000) //mL
{
    std::cout << "Human being constructed!" << std::endl;
}

void Human::HealthStatus::contractSTD(std::string whichSTD, std::string dateContracted)
{
    std::cout << "Your tested positive for the folling STD " << whichSTD << " which was contracted on" << dateContracted <<" \n";
}

void Human::HealthStatus::developeHealthCondition(bool isHereditary, std::string knownSymptoms, std::string conditionName)
{
    std::cout << "You have noticed having" << knownSymptoms << " \n";
    std::cout << "which are symptoms of " << conditionName << " \n";
    
    if(isHereditary == true) std::cout << "this condition is hereditary";
}

void Human::HealthStatus::scheduleCheckUp(std::string returnDate, bool sameDoctor)
{
    returnDate = "Day/Month/Year";
    sameDoctor = true;
}

void Human::HealthStatus::printHealthStatusVars()
{
    std::cout << "numOfHealthComplications: " << numOfHealthComplications << " \n";
    std::cout << "chronicDiseasesPresent: " << chronicDiseasesPresent << " \n";
    std::cout << "dateOfLastCheckup: " << dateOfLastCheckup << "\n";
    std::cout << "bodyMassIndex:  " << bodyMassIndex << "\n";
    std::cout << "bloodPressureLevel: " << bloodPressureLevel << "\n\n"; 
}

void Human::visitDoctor(HealthStatus updateHealthStatus)
{
    //I would ideally update all the member variables of HealthStatus here with std::cin's.
    std::cout << "Blood Pressure: " << updateHealthStatus.bloodPressureLevel << " \n";
    std::cout << "Body Mass Index: " << updateHealthStatus.bodyMassIndex << " \n";
    std::cout << "Chronic Diseases Present: " << updateHealthStatus.chronicDiseasesPresent << " \n";
    std::cout << "Date Of Last Check-Up: " << updateHealthStatus.dateOfLastCheckup << " \n";
    std::cout << "Number of Complications: " << updateHealthStatus.numOfHealthComplications << " \n";
    //here I would replace dateOfLastCheckup with todays date.
    updateHealthStatus.goToAppointment = false;
}

void Human::goToSleep(int howLong)
{
    std::cout << nameOfHuman << " is going to get " << howLong << " hours of sleep!\n";
}

void Human::donateBlood(Human girlfriend, bool giveLeftArm)
{
    if(giveLeftArm == true)
    {
         std::cout << "you have decided to donate from your left arm\n";
    }
    else
    {
        std::cout << "you have decided to donate from your right arm\n";
    }
    int bloodDonated = 0;
    
    while(bloodDonated < 500 || girlfriend.amountOfBlood < 4000)
    {
        bloodDonated += 100;
        girlfriend.amountOfBlood -= 100;
        std::cout << "still donating: " << bloodDonated << "/500... hang in there.\n";
    }
    std::cout << "all done, go home\n";
}

void Human::printHumanVars()
{
    std::cout << "ageInYears: " << ageInYears << " \n";
    std::cout << "nameOfHuman: " << nameOfHuman << " \n";
    std::cout << "ethnicity: " << ethnicity << "\n";
    std::cout << "dateOfBirth:  " << dateOfBirth << "\n";
    std::cout << "bloodType: " << bloodType << "\n\n"; 
}



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
int main()
{
    std::cout << "good to go!" << std::endl;
}
