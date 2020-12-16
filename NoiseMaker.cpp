#include "NoiseMaker.h"

NoiseMaker::NoiseMaker() 
{
    distortion.brightness = 1.0f;
    distortion.roughness = 0.5f;
    distortion.numEchoes = 6;
}

NoiseMaker::~NoiseMaker() 
{
    std::cout << "Shutting off NoiseMaker" << std::endl;
}

void NoiseMaker::makeSomeNoise() 
{
    distortion.processInput();
}

