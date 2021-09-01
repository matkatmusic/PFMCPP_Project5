void Safeway::printQAboutb()
{
    std::cout << "Is northblock's member var 'b' equal to 2? " << (this->b == 2 ? "Yes" : "No") << "\n";
}

void Safeway::printCoupons()
{
    std::cout << "northblock.coupons: " << this->coupons << std::endl << std::endl;
}
void Safeway::Customer::printMembership()
{
    std::cout << "patrick.membership: " << this->membership << std::endl << std::endl;
}

Safeway::~Safeway()
{
    std::cout<< "Artist is being deleted" << std::endl;
}

int Safeway::Customer::alarmForMembership(int threshold, int currentDays = 0)
{  
    while(currentDays >  threshold)
    {
        --currentDays;
        std::cout << "left days: " << currentDays << std::endl;
        if(currentDays <= threshold)
        {
            std::cout<< "It's time to refresh your membership." << std::endl;
            membership = currentDays;
            return currentDays;
        }
    }
    return -1;
}

int Safeway::limitOfCoupons(int threshold, int couponsInUse = 0)//P5
{
    while(couponsInUse < threshold)
    {
        ++couponsInUse;
        std::cout << "coupons in use : " << couponsInUse << std::endl;
        if(couponsInUse >= threshold)
        {
            std::cout << "In one order, you could only use 5 promocode." << std::endl;
            coupons  = couponsInUse;
            return couponsInUse;
        }
    }
    return -1;
}

Safeway::Safeway() : b(2)
{
}


void Safeway::printThing()
{
    std::cout << "Safeway::printThing() b: " << b << " bb:"<< bb << std::endl; 
}

void Safeway::orderGroceryOnline(Customer customer)
{
    std::cout << "Customer's profile: " << customer.accountnumber << std::endl;
}

double Safeway::refund(int productNumber)
{
    std::cout << "Product Number: " << productNumber << std::endl;
    std::cout << "Product Value: 1" << std::endl;
    return 0.1;
}

void Safeway::collectCoupons(Customer customer)
{
    std::cout << "Coupons " << customer.membership << std::endl;
}

void Safeway::Customer::redeemGiftCard(int codeOfGiftcard)
{
    std::cout << "submit " << codeOfGiftcard << std::endl;
}

bool Safeway::Customer::redeemProduct(int pointsOfProduct)
{
    return !(pointsOfProduct > 700);
}

void Safeway::Customer::changeProfile(int dateOfBirthday)
{
    std::cout << " Current Date Of Birthday" << dateOfBirthday << std::endl;
}