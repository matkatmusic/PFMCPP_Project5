#include <iostream>
#include "LeakedObjectDetector.h"
#pragma once

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
