struct CustomerWrapper
{
    CustomerWrapper( Safeway::Customer *ptr);
    ~CustomerWrapper();
    Safeway::Customer *pointerToCustomer = nullptr;
};

struct SafewayWrapper
{
    SafewayWrapper( Safeway *ptr);
    ~SafewayWrapper();
    Safeway *pointerToSafeway = nullptr;
};

struct GroupWrapper
{
    GroupWrapper(Artist::Group *ptr);
    ~GroupWrapper();
    Artist::Group *pointerToGroup = nullptr;
};

struct ArtistWrapper
{
    ArtistWrapper(Artist *ptr);
    ~ArtistWrapper();
    Artist *pointerToArtist = nullptr;
};

struct ShelterOfCatsWrapper
{
    ShelterOfCatsWrapper( ShelterOfCats *ptr);
    ~ShelterOfCatsWrapper();
    ShelterOfCats *pointerToShelterOfCats = nullptr;
};

struct MapWrapper
{
    MapWrapper( Map *ptr);
    ~MapWrapper();
    Map *pointerToMap = nullptr;
};

struct CommerceBureauWrapper
{
    CommerceBureauWrapper( CommerceBureau *ptr);
    ~CommerceBureauWrapper();
    CommerceBureau *pointerToCommerceBureau = nullptr;
};