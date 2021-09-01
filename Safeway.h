#include <iostream>
#include "LeakedObjectDetector.h"

struct Safeway
{
    int b;
    float bb{2.2f};
    Safeway();
    ~Safeway();
    float openTime = 9.f;
    float discount = 0.7f;
    int customerPoints = 234;
    int permissionYear = 2021;
    int coupons = 34;
    
    struct Customer
    {
        int accountnumber = 133423;
        int membership = 37;
        bool relatedCreditCard = 0;
        float amountOfLastOrder = 67.59f;
        int registrationDays = 133;
        void redeemGiftCard(int codeOfGiftcard = 133278645);
        bool redeemProduct(int pointsOfProduct = 700);
        void changeProfile(int dateOfBirthday = 13);
        int alarmForMembership(int threshold, int currentDays);
        void printMembership();
    };
    void printCoupons();
    void printQAboutb();
    void orderGroceryOnline(Customer customer);
    double refund(int productNumber);
    void collectCoupons(Customer customer);
    void printThing();
    int limitOfCoupons(int threshold, int couponsInUse);

    JUCE_LEAK_DETECTOR(Safeway)
};