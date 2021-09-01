
CustomerWrapper::CustomerWrapper( Safeway::Customer *ptr) : pointerToCustomer(ptr){}

CustomerWrapper::~CustomerWrapper()
{
    delete pointerToCustomer;
}


SafewayWrapper::SafewayWrapper(Safeway *ptr) : pointerToSafeway(ptr) {}

SafewayWrapper:: ~SafewayWrapper()
{
    delete pointerToSafeway;
}

GroupWrapper::GroupWrapper(Artist::Group *ptr) : pointerToGroup(ptr) {}

GroupWrapper::~GroupWrapper()
{
    delete pointerToGroup;
}


ArtistWrapper::ArtistWrapper(Artist *ptr) : pointerToArtist(ptr) {}

ArtistWrapper::~ArtistWrapper()
{
    delete pointerToArtist;
}

ShelterOfCatsWrapper::ShelterOfCatsWrapper( ShelterOfCats *ptr) : pointerToShelterOfCats(ptr) {}

ShelterOfCatsWrapper::~ShelterOfCatsWrapper()
{
    delete pointerToShelterOfCats;
}

MapWrapper::MapWrapper( Map *ptr) : pointerToMap(ptr) {}

MapWrapper::~MapWrapper()
{
    delete pointerToMap;
}


CommerceBureauWrapper::CommerceBureauWrapper( CommerceBureau *ptr) : pointerToCommerceBureau(ptr) {}

CommerceBureauWrapper::~CommerceBureauWrapper()
{
    delete pointerToCommerceBureau;
}