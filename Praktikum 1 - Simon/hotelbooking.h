#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <iostream>
using namespace std;

class HotelBooking
{
public:
    HotelBooking();
    HotelBooking(long id, double price, string fromDate, string toDate, string hotel, string town);
    HotelBooking(double price);
    //Getter functions
    double getPrice() const;
    long getId() const;
    string getFromDate() const;
    string getToDate() const;
    string getHotel() const;
    string getTown() const;

private:
    long id;
    double price;
    string fromDate, toDate, hotel, town;
};

#endif // HOTELBOOKING_H
