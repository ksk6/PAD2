#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include <travel.h>
using namespace std;

class Customer
{
public:
    Customer();
    Customer(long id, string name);
    void addTravel(Travel* travel);

    long getId() const;
    vector<Travel *> getTravelList() const;

    void setName(const string &value);
    void setId(long value);

    string getName() const;

private:
    long id;
    string name;
    vector<Travel*> travelList;
};

#endif // CUSTOMER_H
