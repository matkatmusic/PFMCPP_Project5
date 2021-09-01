struct CustomerWrapper
{
    CustomerWrapper( Safeway::Customer *ptr) : pointerToCustomer(ptr){}
    ~CustomerWrapper()
    {
        delete pointerToCustomer;
    }
    Safeway::Customer *pointerToCustomer = nullptr;
};

struct SafewayWrapper
{
    SafewayWrapper( Safeway *ptr) : pointerToSafeway(ptr) {}
    ~SafewayWrapper()
    {
        delete pointerToSafeway;
    }
    Safeway *pointerToSafeway = nullptr;
};

struct GroupWrapper
{
    GroupWrapper(Artist::Group *ptr) : pointerToGroup(ptr) {}
    ~GroupWrapper()
    {
        delete pointerToGroup;
    }
    Artist::Group *pointerToGroup = nullptr;
};

struct ArtistWrapper
{
    ArtistWrapper(Artist *ptr) : pointerToArtist(ptr) {}
    ~ArtistWrapper()
    {
        delete pointerToArtist;
    }
    Artist *pointerToArtist = nullptr;
};

struct ShelterOfCatsWrapper
{
    ShelterOfCatsWrapper( ShelterOfCats *ptr) : pointerToShelterOfCats(ptr) {}
    ~ShelterOfCatsWrapper()
    {
        delete pointerToShelterOfCats;
    }
    ShelterOfCats *pointerToShelterOfCats = nullptr;
};

struct MapWrapper
{
    MapWrapper( Map *ptr) : pointerToMap(ptr) {}
    ~MapWrapper()
    {
        delete pointerToMap;
    }
    Map *pointerToMap = nullptr;
};

struct CommerceBureauWrapper
{
    CommerceBureauWrapper( CommerceBureau *ptr) : pointerToCommerceBureau(ptr) {}
    ~CommerceBureauWrapper()
    {
        delete pointerToCommerceBureau;
    }
    CommerceBureau *pointerToCommerceBureau = nullptr;
};