#include "customer.h"



// --------------------------------- FUNCTIONS ---------------------------------



bool Customer::findTravel(long tid) const
{
    for(Travel* t : travelList) {
        if(t->getTid() == tid) return true;
    } return false;
}



void Customer::addTravel(Travel *travel)
{
    if(!findTravel(travel->getTid())) travelList.push_back(travel);
}

int Customer::getTravelCount() const
{
    return static_cast<int>(travelList.size());
}



// --------------------------------- GETTER/SETTER ---------------------------------



long Customer::getCid() const
{
    return cid;
}

void Customer::setCid(long value)
{
    cid = value;
}

string Customer::getName() const
{
    return name;
}

QString Customer::getQName() const
{
    return QString::fromStdString(name);
}

void Customer::setName(const string &value)
{
    name = value;
}
