
#include "CommerceBureau.h"

void CommerceBureau::memberG()
{
    std::cout << "CommerceBureau permissionUpdate: " << this->permissionUpdate(2019,2021) << " and CommerceBureau taxPaidRequirment : " << this->taxPaidRequirment(0, 1245566.23) << std::endl;
}

CommerceBureau::CommerceBureau()
{
   std::cout << "Entering the internal system..." << std::endl;
}

CommerceBureau::~CommerceBureau()
{
    std::cout << "Leaving the internal system..." << std::endl;
}

bool CommerceBureau::permissionUpdate(int currentMonth, int permissionMonth)
{
    if (permissionMonth < currentMonth)
    {
        std::cout << "Time to update your business permission." << std::endl;
        return false; 
    }

    return true;
}

double CommerceBureau::taxPaidRequirment(bool forProfit, double tax = 0)
{
    if (forProfit == true)
    {
        std::cout << "need to pay " << tax << " profit as tax." <<std::endl;
        return tax;
    }
    std::cout << "This is a non-profit organization." << std::endl;
    return 0;
}
