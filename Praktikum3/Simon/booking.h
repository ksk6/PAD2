#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
using namespace std;

class Booking
{
public:
    Booking();
    double getPrice() const;

    long getId() const;

    long getTravelId() const;

    string getFromDate();

    string getToDate();

protected:
    long id, travelId;
    double price;
    string fromDate, toDate;
};

#endif // BOOKING_H
