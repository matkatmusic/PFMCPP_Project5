#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"


struct Artist
{
    double fb{6.6};
    Artist();
    ~Artist();
    int f;
    int age = 23;
    int numberOfSocialUpdates = 14;
    int numberOfFollowers = 1002;
    int numberOfAlbums = 3;
    int numberOfAwards = 5;
    void printThing();
    struct Group
    {
        int numberOfMembers = 233;
        std::string administrator = "sodabuddy";
        std::string notice = " New album will be released in few weeks";
        int limitOfMembers = 500;
        int unreadMessages = 82;
        void printNumberOfMembers();
        void addAdministrators(std::string nickname = "Tulips");
        void confirmNotice(std::string notice1);
        void changeNickname(std::string newNickname = "Cornish");
        int groupMembers(int capacity, int members = 0);
    };
    std::string followAArtist(std::string nameOfArtist);
    void enterTheGroupOfAArtist(Group group);
    void checkTheHottestSongOfArtist(int rankingOfASong);
    void abbreOfNumber(int fiveThousands, int followers = 0);
    void printNumberOfFollowers();
    void printQAboutf();

    JUCE_LEAK_DETECTOR(Artist)
};
