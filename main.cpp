/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) For any std::cout statements you had in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
 
 2) if you didn't have any std::cout statements in main() that accessed member variables:
         write some.
         then do 1a) & 1b)
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        void memberFunc() { std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; }  //3)
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    int main()
    {
        MyFoo mf;
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;  //3)
        mf.memberFunc();
        return 0;
    }
}



/*
 copied UDT 1:
 */
#include <iostream>
#include <vector>

struct Pet 
{
    bool isCat, isDog, isPetHappy, isPetHungry;
    int age;
    double foodLevel;
    std::string name;

    Pet(std::string petType, std::string petName) : isCat(false), isDog(false), isPetHappy(false), isPetHungry(false), age(0), foodLevel(10.0), name(petName)
    { 
        std::cout << "A " << petType << " named " << petName << " is born!" << std::endl;

        if(petType == "cat")
        {
            std::cout << "meow" << std::endl;
            isCat = true;
        }
        else if (petType == "dog")
        {
            std::cout << "woof" << std::endl;
            isDog = false;
        }
        else {
            //handle other pet types
        }
    }

    ~Pet()
    {
        std::cout << "A pet is destroyed, RIP " << name << std::endl;
    }

    void feed()
    {
        std::cout << "nom" << std::endl;
        isPetHungry = false;
        isPetHappy = true;
    }

    void walk(int howLong)
    {   
        if(isPetHungry == false)
        {
            std::cout << "walking " << name << " for " << howLong << " minutes " << std::endl;
            while(howLong > 0)
            {
                std::cout << ".";
                howLong --;
                foodLevel = foodLevel - 0.25;

                if(foodLevel < 5 and foodLevel > 1)
                {
                    std::cout << name << " is getting hungry!!" << std::endl;
                }

                if(foodLevel < 1)
                {
                    std::cout << name << " is too hungry to walk, time to eat!" << std::endl;
                    howLong = 0;
                    isPetHungry = true;
                }
            }
            std::cout << std::endl;
        }
        else 
        {
            std::cout << name << " is hungry, let's eat first! " << std::endl;
        }
        
        std::cout << "Done walking " << name << std::endl;
        isPetHappy = true;
    }

    void status()
    {
        std::cout << name;
        isPetHungry ?  std::cout << " is" : std::cout << " is not";
        std::cout << " hungry" << std::endl;
        
        std::cout << "food level: " << foodLevel << std::endl;

        std::cout << name;
        isPetHappy ?  std::cout << " is" : std::cout << " is not";
        std::cout << " happy" << std::endl;
    }
};

/*
 copied UDT 2:
 */

struct Human
{
    int numberOfViolations, numberOfCars, numberOfPets;
    std::string name;
    bool licenseIsValid, hasBike;
    std::vector<Pet> pets;

    Human(std::string humanName) : numberOfViolations(0), numberOfCars(0), numberOfPets(0), name(humanName), licenseIsValid(false), hasBike(false), pets({})
    { 
        std::cout << "A human is created, hello " << name << std::endl;
    }

    ~Human()
    {
        std::cout << "A human is destroyed, RIP " << name << std::endl;
    }

    void adoptPet(Pet pet)
    {
        numberOfPets ++;
        pets.push_back(pet);
        std::cout << name << " has adopted " << pet.name << std::endl;
    }

    bool isDriverAllowedToDrive();
    std::string isPetHungry(Pet ourPet)
    {
        if(ourPet.isPetHungry)
        {
            return "Pet is hungry!";
        }
        else 
        {
            return "Pet is not hungry";
        }
    }
};

/*
 copied UDT 3:
 */

struct Synthesizer 
{
    unsigned int polyphony, notesOn;
    std::string synthName;
    Synthesizer(std::string name) : polyphony(16), notesOn(0), synthName(name) {
        std::cout << "A synthesizer is created " << synthName << std::endl;
    }
    ~Synthesizer()
    {
        std::cout << "A synthesizer is destroyed " <<
        synthName << std::endl;
    }
    void noteOn()
    {
        if(notesOn < polyphony) 
        {
            std::cout << " -note on- ";
            ++ notesOn;
        }
    }
    void noteOff()
    {
        std::cout << " -note off- ";
        -- notesOn;
    }
};

struct Sequencer
{
    bool isPlaying, playForward, playReverse;
    std::vector<int> notes;
    std::string name;

    Sequencer(std::string seqName) : isPlaying(0), playForward(true), playReverse(false), notes({}), name(seqName)
    {}

    void recordNote(int note)
    {
        notes.push_back(note);
    }

    void playBack(Synthesizer synth)
    {
        if(playForward)
        {
            std::cout << "playing forward:: ";
            for(auto& n : notes)
            {   
                std::cout << n << " "; 
                synth.noteOn();
                synth.noteOff();
            }
        }

        if(playReverse)
        {
            std::cout << "playing reverse:: ";
            for(auto n = notes.rbegin(); n != notes.rend(); ++n)
            {   
                std::cout << *n << " "; 
                synth.noteOn();
                synth.noteOff();
            }
        }
        std::cout << std::endl;
    }

    void setForwardPlayback()
    {
        playForward = true;
        playReverse = false;
    }

    void setReversePlayback()
    {
        playForward = false;
        playReverse = true;
    }
};

/*
 new UDT 4:
 */

struct Composition
{
    std::vector<Synthesizer> synths;
    std::vector<Sequencer> seqs;

    Composition(std::vector<Synthesizer> synthesizers, std::vector<Sequencer> sequencers) : synths(synthesizers), seqs(sequencers)
    {
        std::cout << "A composition is created featuring:" << std::endl;
        for(auto& synthesizer : synthesizers)
        {   
            std::cout << synthesizer.synthName << std::endl; 
        }
    }

    void addCommand(std::string synth, std::string command, std::string sequencer)
    {
        for(auto& seq : seqs)
        {
            if(seq.name == sequencer)
            {
                for(auto& s : synths)
                {   
                    if(s.synthName == synth)
                    {
                        std::cout << seq.name << " " <<command << " " << s.synthName << std::endl;
                        seq.playBack(s);
                    }
                }
            }
        }
    }

    ~Composition()
    {
        std::cout << "A composition is destroyed." << std::endl;
    }
};


/*
 new UDT 5:
 */

struct Adoption
{
    Human adopter;
    Pet adoptee;

    Adoption(Human human, Pet pet) : adopter(human), adoptee(pet) {
        adopter.adoptPet(pet);
    }

    ~Adoption()
    {
        std::cout << "Adoption is complete." << std::endl;
    }

};

#include <iostream>
int main()
{
    Example::main();
    Pet zuul("cat", "Zuul");
    Human jason("Jason");
    std::cout << "---" << std::endl;
    Synthesizer moog("Mother32"), korg("Sigma");
    Sequencer mc202("MC202"), msq8("SQD-1");
    mc202.recordNote(99);
    mc202.recordNote(24);
    mc202.recordNote(77);
    Composition newSong({moog, korg}, {mc202});
    newSong.addCommand("Mother32", "plays", "MC202");
    std::cout << "---" << std::endl;
    Adoption adoptionEvent(jason, zuul);
}
