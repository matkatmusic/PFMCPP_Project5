/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 6) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */
#include <iostream>
/*
 copied UDT 1:
 */

struct Animal
{
    Animal();
    ~Animal();
    void howManyToes();
    void setNumLegs(int numLegs);
    void setNumToesOnFoot(int numToesOnFoot);

private:
    int totalToes;
    int numLegs; 
    int numToesOnFoot;
    bool isItAPobble = false;
};

/*
 copied UDT 2:
 */

struct Car
{
    Car();
    ~Car();
    void distanceTraveled();
    void setDriving(bool driving);
    void setPetrol(float petrol);

private:
    bool driving;
    float petrol;
    int miles;
};


/*
 copied UDT 3:
 */

struct Multiply
{
    Multiply();
    ~Multiply();
    void multipleOf(int num);
    void setMaxMultiple(int maxMultiple);

private:
    int maxMultiple;
    int result;
};

/*
 new UDT 4:
 */

struct MyLife
{
    MyLife();
    ~MyLife();
private:
    Animal pet;
    Car ford;
    Multiply homeWork;
};

/*
 new UDT 5:
 */

struct YourLife
{
    YourLife();
    ~YourLife();
private:
    Animal pet;
    Car ford;
    Multiply homeWork;
};


///////////////////////////////////////////////////////////
Animal::Animal():totalToes(0), numLegs(0), numToesOnFoot(0), isItAPobble(false)
{

}

Animal::~Animal()
{
    std::cout << "Destroy Animal" << std::endl;
}

void Animal::howManyToes()
{
    for(int i = 1; i<=numLegs;i++)
    {
        totalToes = i*numToesOnFoot;
        std::cout << "foot: " << i << " Toe count: " << totalToes << std::endl; 
    }

    if(totalToes==0)
    {
        std::cout << "The pobble who had no Toes!" << std::endl;
        isItAPobble = true;
    }
}

void Animal::setNumLegs(int numLegs)
{
    this->numLegs = numLegs;
}

void Animal::setNumToesOnFoot(int numToesOnFoot)
{
    this->numToesOnFoot = numToesOnFoot; 
}

///////////////////////////////////////////////////////////

Car::Car():driving(false), petrol(8.0f), miles(0)
{

}

Car::~Car()
{
    std::cout << "Destroy Car" << std::endl;
}

void Car::distanceTraveled()
{
    while (driving)
    {
        std::cout << "miles travelled: " << miles << " petrol left: " << petrol << std::endl;
        miles++;
        petrol -= 0.5f;
        if(petrol <= 0.0f)
        {
            break;
        }
    }

}

void Car::setDriving(bool driving)
{
    this->driving = driving;
}

void Car::setPetrol(float petrol)
{
    this->petrol = petrol;
}

///////////////////////////////////////////////////////////

Multiply::Multiply(): maxMultiple(12), result(0) 
{

}

Multiply::~Multiply()
{
    std::cout << "Destroy Multiply" << std::endl;
}

void Multiply::multipleOf(int num)
{
    for(int i = 0; i<=maxMultiple;i++)
    {
    result = num * i;
    std::cout<< num << " times " << i << " equals " << result << std::endl; 
    }

}

void Multiply::setMaxMultiple(int maxMultiple)
{
    this->maxMultiple = maxMultiple;
}

///////////////////////////////////////////////////////////

MyLife::MyLife()
{

}

MyLife::~MyLife()
{
    pet.howManyToes();
}

///////////////////////////////////////////////////////////

YourLife::YourLife()
{

}

YourLife::~YourLife()
{
    pet.setNumLegs(4);
    pet.setNumToesOnFoot(5);
    pet.howManyToes();
}


int main()
{
    // Animal a;
    // a.setNumLegs(8);
    // a.setNumToesOnFoot(4);
    // a.howManyToes();

    // Car c;
    // c.setPetrol(10.5f);
    // c.setDriving(true);
    // c.distanceTraveled();
    // std::cout << "good to go!" << std::endl;

    // Multiply m;
    // m.setMaxMultiple(20);
    // m.multipleOf(8);

    MyLife me;
    YourLife you;
}
