#include <iostream>
#include "LeakedObjectDetector.h"
#include "ShelterOfCats.h"
#include "Safeway.h"
#pragma once

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