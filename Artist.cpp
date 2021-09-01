void Artist::printQAboutf()
{
    std::cout << "Is ladygaga's member var 'f' equal to 6? " << (this->f == 6 ? "Yes" : "No") << "\n";
}

void Artist::Group::printNumberOfMembers()
{
    std::cout << "loveGaga.members: " << this->numberOfMembers << std::endl << std::endl;
}

void Artist::printNumberOfFollowers()
{
    std::cout << "ladygaga.followers: " << this->numberOfFollowers << std::endl << std::endl;
}


Artist::~Artist()
{
    std::cout<< "Artist is being deleted" << std::endl;
}

void Artist::abbreOfNumber(int fiveThousands, int followers)
{
    std::string fiveThou = "5k";
    while(followers < fiveThousands)
    {
        followers += 100;
        std::cout << "This artist has " << followers << " followers" << std::endl;
        if(followers >= fiveThousands)
        {
            numberOfFollowers = followers;
            std::cout << "This artist has " << fiveThou << " followers" << std::endl;
        }
    }
}

int Artist::Group::groupMembers(int capacity, int members)
{
    while(members < capacity)
    {
        ++members;
        std::cout << "The group has" << members << "members" << std::endl;
        if(members >= capacity)
        {
            std::cout<< "There is no capacity for new members." << std::endl;
            numberOfMembers = members;
            return members;
        }
    }
    return -1;
}
Artist::Artist() : f(6){}

void Artist::printThing()
{
    std::cout << "Artist::printThing() f: " << f << " fb:" << fb << std::endl; 
}

void Artist::Group::addAdministrators(std::string nickname)
{
    std::cout << " New Administrator:" << nickname << std::endl;
}

void Artist::Group::confirmNotice(std::string notice1 = "Monday" )
{
    std::cout << " Confirmed" << notice1 << std::endl;
}

void Artist::Group::changeNickname(std::string newNickname)
{
    std::cout << " New Nickname" << newNickname << std::endl;
}

std::string Artist::followAArtist(std::string nameOfArtist)
{
    return nameOfArtist;
}

void Artist::enterTheGroupOfAArtist(Group group)
{
    std::cout << " Successful enter into" << group.numberOfMembers << std::endl;
}

void Artist::checkTheHottestSongOfArtist(int rankingOfASong)
{
    std::cout << "The ranking: " << rankingOfASong << std::endl;
}