#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <iostream>
using namespace std;

class FlightBooking
{
public:
    FlightBooking();
    FlightBooking(long id, double price, string fromDate, string toDate, string fromDest, string toDest, string airline);
    FlightBooking(double price);
    //Getter functions
    double getPrice() const;
    long getId() const;
    string getFromDate() const;
    string getToDate() const;
    string getToDest() const;
    string getAirline() const;
    string getFromDest() const;

private:
    long id;
    double price;
    string fromDate, toDate, fromDest, toDest, airline;
};

#endif // FLIGHTBOOKING_H
