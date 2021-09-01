Map::Map()
{
    std::cout << "Welcome!" << std::endl;
}

Map::~Map()
{
    std::cout << "See you!" << std::endl;
}


void Map::parkSpaceFinder(int parkingLot)
{
    if (parkingLot > 1)
    {
        std::cout << "Has " << parkingLot << "parking spaces. " << std::endl;
    }
    else if(parkingLot== 1)
    {
        std::cout << "Has " << parkingLot << "parking space. " << std::endl;
    }
    else if(parkingLot==0)
    {
        std::cout << "Has " << parkingLot << " parking space. " << std::endl;
        oDistrict.orderGroceryOnline(mary);
        std::cout << "Would you like to order online? " << std::endl;
    } 
}

void Map::turnROrNot(double currentT, double openT, double closeT)
{
    if(openT <= currentT && closeT > currentT)
    {
        std::cout << "It's open until " << closeT << "." << std::endl;
    }
    else
    {
        std::cout << "It will open at " << openT << " tommorow." << std::endl;
    }
}