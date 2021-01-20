
#include "Distortion.h"
#include <iostream>

Distortion::Distortion()
{
    brightness = 0.5f;
    numEchoes = 3;
    roughness = 0.8f;
    vinylTap = 11;
}

Distortion::~Distortion()
{
    std::cout << "Distortion switched off" << std::endl;
}

void Distortion::printCalculateBrightness(float first, float second, float third)
{
    std::cout << "BRIGHTNESS: " << this->calculateBrightness(first, second, third) << std::endl;
}

void Distortion::processInput()
{
    std::cout << "DISTORRTIIOOOOON"<< std::endl;
}

float Distortion::calculateBrightness(float roomSize, float hiPass, float loPass)
{
    if (roomSize < loPass)
    {
        return loPass;
    }
    if (roomSize > hiPass)
    {
        return hiPass;
    }
    return roomSize;
}

bool Distortion::toggleBypass(bool bypass)
{
    return !bypass;
}
