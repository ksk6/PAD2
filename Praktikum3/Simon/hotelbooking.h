#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <booking.h>

class HotelBooking : public Booking
{
public:
    HotelBooking();
    HotelBooking(long id, double price, string fromDate, string toDate, long travelid, string hotel, string town, bool smoke);
    HotelBooking(double price);
private:
    string hotel, town;
    bool smoke;
};

#endif // HOTELBOOKING_H
