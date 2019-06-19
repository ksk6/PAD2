#ifndef CUSTOMER_H
#define CUSTOMER_H



#include <travel.h>

#include <string>
#include <vector>



using namespace std;




class Customer
{

public:

    // constructors
    Customer();
    Customer(long cid, string name)
        : cid(cid), name(name)
    {}

    // functions
    bool findTravel(long tid) const;
    void addTravel(Travel* travel);
    int getTravelCount() const;

    // getter/setter
    long getCid() const;
    void setCid(long value);
    string getName() const;
    QString getQName() const;
    void setName(const string &value);

private:

    // var
    long cid;
    string name;

    // lists
    vector<Travel*> travelList;

};



#endif
