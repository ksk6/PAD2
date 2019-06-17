#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
#include <vector>
using namespace std;

class Booking
{
public:
    Booking();
    virtual ~Booking();

    virtual string showDetails() = 0;

    // Getter
    double getPrice() const;
    long getId() const;
    long getTravelId() const;
    string getFromDate();
    string getToDate();
    char getType() const;

protected:
    long id, travelId;
    char type;
    double price;
    string fromDate, toDate;
    vector<int> vorherigeBuchungen;
};

#endif // BOOKING_H
