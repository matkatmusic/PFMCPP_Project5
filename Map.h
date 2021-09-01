#include <iostream>
#include "LeakedObjectDetector.h"
#include "ShelterOfCats.h"
#include "Safeway.h"

struct Map
{
    ShelterOfCats kittenMeet;
    Safeway oDistrict;
    void parkSpaceFinder(int parkingLot);
    void turnROrNot(double currentT, double openT, double closeT);
    Map();
    ~Map();

    JUCE_LEAK_DETECTOR(Map)
};