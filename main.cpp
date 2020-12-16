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


#include <iostream>
#include "LeakedObjectDetector.h"


/*
 copied UDT 1:
 */


#include "HarmonicSet.h"



/*
 copied UDT 2:
 */

#include "Distortion.h"


/*
 copied UDT 3:
 */


#include "PatternGenerator.h"



/*
 new UDT 4:
 */

#include "PatternPlayer.h"


/*
 new UDT 5:
 */

#include "NoiseMaker.h"

#include "Wrappers.h"


#include <iostream>
int main()
{

    HarmonicSetWrapper hs ( new HarmonicSet );
    std::cout << hs.hsPtr->bassFrequency << std::endl;
    std::cout << hs.hsPtr->genFrequency << std::endl;
    std::cout << " ^" << hs.hsPtr->next();
    std::cout << " ^" << hs.hsPtr->next();
    std::cout << " ^" << hs.hsPtr->next();
    std::cout << " ^" << hs.hsPtr->next();
    std::cout << " v" << hs.hsPtr->prev();
    std::cout << " ^" << hs.hsPtr->next();
    std::cout << " v" << hs.hsPtr->prev();
    std::cout << " v" << hs.hsPtr->prev();
    std::cout << std::endl;

    std::cout << "current: " << hs.hsPtr->current << std::endl;
    std::cout << "previous: " << hs.hsPtr->previous << std::endl;

    // here I've just changed the second HarmonicSet to use member functions
    HarmonicSetWrapper hs2( new HarmonicSet(15.f, 40.f) );
    hs2.hsPtr->printBassFrequency();
    hs2.hsPtr->printGenFrequency();
    hs2.hsPtr->printNext();
    hs2.hsPtr->printNext();
    hs2.hsPtr->printNext();
    hs2.hsPtr->printNext();
    hs2.hsPtr->printPrev();
    hs2.hsPtr->printNext();
    hs2.hsPtr->printPrev();
    hs2.hsPtr->printPrev();
    std::cout << std::endl;

    std::cout << "current: " << hs2.hsPtr->current << std::endl;
    hs2.hsPtr->printCurrent();
    std::cout << "previous: " << hs2.hsPtr->previous << std::endl;
    hs2.hsPtr->printPrevious();

    DistortionWrapper distorition( new Distortion );

    PatternPlayerWrapper pp( new PatternPlayer );
    pp.ppPtr->play();

    PatternPlayerWrapper pp2(new PatternPlayer(440.f, 442.f));
    pp2.ppPtr->distortion.numEchoes = 5;
    pp2.ppPtr->pattern.patternName = "pattern 2";
    pp2.ppPtr->pattern.startingNote = 6;
    pp2.ppPtr->pattern.numberOfNotes = 7;
    pp2.ppPtr->play();

    NoiseMakerWrapper nm ( new NoiseMaker );
    nm.nmPtr->makeSomeNoise();

    std::cout << "*=-=*=-=*=-=*=-=*=-=* old stuff *=-=*=-=*=-=*=-=*=-=*" << std::endl;

    PatternGenerator::Pattern pattern;
    std::cout << "pattern's name: " << pattern.patternName << std::endl;
    pattern.printName(); // prints the same name

    PatternGeneratorWrapper pg ( new PatternGenerator );
    pg.pgPtr->generatePattern(); // prints "new pattern: 12345"

    DistortionWrapper ds ( new Distortion );
    ds.dPtr->processInput();
    std::cout << "brightness: " << ds.dPtr->calculateBrightness(250.f, 300.f, 100.f) << std::endl;
    std::cout << "brightness: " << ds.dPtr->calculateBrightness(350.f, 300.f, 200.f) << std::endl;
    ds.dPtr->printCalculateBrightness(250.f, 300.f, 100.f);
    ds.dPtr->printCalculateBrightness(350.f, 300.f, 200.f);

    HarmonicSetWrapper harmonicSet ( new HarmonicSet(220.0f, 440.0f));
    harmonicSet.hsPtr->playSet(220.0f, 22000.0f);
    HarmonicSetWrapper harmonicSetTwo ( new HarmonicSet(100.0f, 360.0f));
    harmonicSetTwo.hsPtr->playSet(10.f, 22000.0f);
    std::cout << "Sum of bass and generator is " << harmonicSetTwo.hsPtr->calculateHarmonicity() << std::endl;
    harmonicSetTwo.hsPtr->printCalculateHarmonicity();

    DistortionWrapper ds2 ( new Distortion );
    ds2.dPtr->processInput();

    ds2.dPtr->numEchoes = 15;
    ds2.dPtr->processInput();


    std::cout << "good to go!" << std::endl;
}
