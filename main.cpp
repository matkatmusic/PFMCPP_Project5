/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only
what you need to new projects you will learn how to write code that doesn't leak
as well as how to refactor.

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================
 If you completed Project 3:

 1) Copy 3 of your user-defined types (the ones with constructors and
for()/while() loops from Project 3) here Choose the classes that contained
nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have:
        5 member variables
            the member variable names and types should be relevant to the work
the UDT will perform. pick properties that can be represented with 'int float
double bool char std::string' 3 member functions with an arbitrary number of
parameters give some of those parameters default values. constructors that
initialize some of these member variables the remaining member variables should
be initialized in-class for() or while() loops that modify member variables 1) 2
of your 3 UDTs need to have a nested UDT. this nested UDT should fulfill the
same requirements as above: 5 member variables 3 member functions constructors
and loops.

 2) Define your implementations of all functions OUTSIDE of the class.
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new
UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.
        maybe print out the name of the class being destructed, or call a member
function of one of the members.  be creative

 7) copy over your main() from the end of Project3
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.

 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.

 9) After you finish, click the [run] button.  Clear up any errors or warnings
as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list
of compiler arguments in the .replit file. all of the "-Wno" in that file are
compiler arguments. You can resolve any [-Wpadded] warnings by adding
-Wno-padded to the list of compiler arguments in the .replit file. all of the
"-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */

/*
 copied UDT 2:
 */

/*
 copied UDT 3:
 */

/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left,
 entering a message, and click [Commit and push].

 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single
 message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
#include <stdlib.h>

// UDT 1:
struct Student 
{
    int grade;
    std::string name;
    int courseID = 0;
    int age;
    int studentID;

    Student(std::string);
    ~Student();

    void printStudentID();
    void printStudentName();
    void printStudentGrade();
};

Student::Student(std::string givenName)
{
    grade = 50;
    name = givenName;
    age = 18;
    studentID = 123456;
}

Student::~Student() {}

void Student::printStudentID() 
{
    std::cout << "Student ID: " << studentID << std::endl;
}

void Student::printStudentName() 
{
    std::cout << "Student Name: " << name << std::endl;
}

void Student::printStudentGrade() 
{
    for(int i = 0; i < 4; i++)
    {
        grade += 10; 
    }
    std::cout << "Student Grade: " << grade << std::endl;
}

// UDT 2:
struct Guitarist
{
    int age;
    std::string favoriteStyle;
    std::string name;
    std::string favoriteGuitarBrand;
    float height;

    Guitarist();
    ~Guitarist();

    struct Guitar
    {
        std::string brand;
        std::string model;
        int numberOfStrings;
        float volume;
        bool isConnected;

        Guitar();
        ~Guitar();

        void volumeUp(float);
        void volumeDown(float);
        void connect();
        void disconnect();
    };

    Guitar myGuitar;

    void connectGuitar();
    void disconnectGuitar();
    void turnVolumeUp(float);
    void turnVolumeDown(float);
};

Guitarist::Guitarist()
{
    age = 35;
    favoriteStyle = "Metal";
    name = "John";
    favoriteGuitarBrand = "Schecter";
    height = 6.2f;
}

Guitarist::~Guitarist() {}

Guitarist::Guitar::Guitar()
{
    brand = "Fender";
    model = "Stratocaster";
    numberOfStrings = 6;
    volume = 5.0f;
    isConnected = false;
}

Guitarist::Guitar::~Guitar() {}

void Guitarist::Guitar::volumeUp(float value)
{
    volume += value;
}

void Guitarist::Guitar::volumeDown(float value)
{
    volume -= value;
}

void Guitarist::Guitar::connect()
{
    isConnected = true;
}

void Guitarist::Guitar::disconnect()
{
    isConnected = false;
}

void Guitarist::connectGuitar()
{
    myGuitar.connect();
}

void Guitarist::disconnectGuitar()
{
    myGuitar.disconnect();
}

void Guitarist::turnVolumeUp(float value = 0.1f)
{
    myGuitar.volumeUp(value);
}

void Guitarist::turnVolumeDown(float value = 0.1f)
{
    myGuitar.volumeDown(value);
}

// UDT 3:
struct Bassist
{
    int age;
    std::string favoriteStyle = "Jazz";
    std::string name;
    std::string favoriteBassBrand;
    float height;

    Bassist(int, float);
    ~Bassist();

    struct Bass
    {
        std::string brand;
        std::string model;
        int numberOfStrings;
        float volume;
        bool isConnected;

        Bass(int, std::string, std::string, bool);
        ~Bass();

        void volumeUp(float);
        void volumeDown(float);
        void connect();
        void disconnect();
    };

    Bass myBass = Bass(5, "Fender", "Player", true);

    void turnVolumeUp(float);
    void turnVolumeDown(float);
    void slapTheBass();
};

Bassist::Bassist(int givenAge, float givenHeight)
{
    age = givenAge;
    height = givenHeight;
    name = "Carol";
    favoriteBassBrand = "Fender";
}

Bassist::~Bassist() {}

Bassist::Bass::Bass(int givenNumberOfStrings, std::string givenBrand, std::string givenModel, bool givenIsConnected)
{
    numberOfStrings = givenNumberOfStrings;
    brand = givenBrand;
    model = givenModel;
    isConnected = givenIsConnected;
    volume = 0.0f;
}

Bassist::Bass::~Bass() {}

void Bassist::Bass::volumeUp(float value)
{
    while (volume < 50.0f)
    {
        volume += value;
    }
}

void Bassist::Bass::volumeDown(float value)
{
    volume -= value;
}

void Bassist::Bass::connect()
{
    isConnected = true;
}

void Bassist::Bass::disconnect()
{
    isConnected = false;
}

void Bassist::turnVolumeUp(float value)
{
    myBass.volumeUp(value);
}

void Bassist::turnVolumeDown(float value)
{
    myBass.volumeDown(value);
}

void Bassist::slapTheBass()
{
    std::cout << "Slapping the bass!" << std::endl;
}

int main() {
  Student mario = Student("Mario");
  mario.printStudentName();
  mario.printStudentID();
  mario.printStudentGrade();

  std::cout << "good to go!" << std::endl;
}
