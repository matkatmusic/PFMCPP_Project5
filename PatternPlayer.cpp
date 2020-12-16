
#include "PatternPlayer.h"


PatternPlayer::PatternPlayer() 
{
    std::cout << "PatternPlayer default constructor: " << std::endl;
    printDescription();
}

PatternPlayer::PatternPlayer(float bass, float gen)
{
    std::cout << "PatternPlayer constructor with bass " << bass << " and gen " << gen << std::endl;
    harmonicSet.bassFrequency = bass;
    harmonicSet.genFrequency = gen;
    harmonicSet.reset();
    printDescription();
}

PatternPlayer::~PatternPlayer() 
{
    std::cout << "Pattern Player switched off" << std::endl;

}

void PatternPlayer::printDescription () 
{
    std::cout << "Harmonic set: " << harmonicSet.bassFrequency << " and " << harmonicSet.genFrequency << std::endl;
}

void PatternPlayer::matchNote(int i) 
{
    if (i < currentNote) 
    {
        harmonicSet.prev();
        currentNote -= 1;
        // std::cout << "matchNote rewind to " << currentNote << std::endl;
        matchNote(i);
    }
    else if (i > currentNote) 
    {
        harmonicSet.next();
        currentNote += 1;
        // std::cout << "matchNote forward to " << currentNote << std::endl;
        matchNote(i);
    }
}

void PatternPlayer::play() 
{

    pattern.printName();

    matchNote(pattern.startingNote);
    int endingNote = pattern.startingNote + pattern.numberOfNotes;

    for (int i = pattern.startingNote; i < endingNote; i++) 
    {
        std::cout << harmonicSet.next() << " ";
        currentNote += 1;
        for (int j = 0; j < distortion.numEchoes; j++)
        {
            std::cout << "*";
        }
    }

    if (pattern.repeat)
    {
        std::cout << std::endl;
        std::cout << pattern.startingNote << " and " << currentNote << std::endl;
        matchNote(pattern.startingNote);

        for (int i = pattern.startingNote; i < endingNote; i++) 
        {
            std::cout << harmonicSet.next() << " ";
            currentNote += 1;
            for (int j = 0; j < distortion.numEchoes; j++)
            {
                std::cout << "#";
            }
        }
    }

    std::cout << std::endl;
    
}

