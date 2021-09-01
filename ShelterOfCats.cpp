#include "ShelterOfCats.h"

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
