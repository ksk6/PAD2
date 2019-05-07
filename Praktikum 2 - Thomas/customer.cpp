#include "customer.h"

Customer::Customer()
{

}

Customer::Customer(long id, string name){
    this->id = id;
    this->name = name;
}


void Customer::addTravel(Travel* travel){ this->travelList.push_back(travel); }

// ---------- Getter ---------- //
long Customer::getId() const { return id; }

string Customer::getName() const { return name; }

vector<Travel *> Customer::getTravelList() const { return travelList; }


// ---------- Setter ---------- //
void Customer::setName(const string &value) { name = value; }

void Customer::setId(long value) { id = value; }

