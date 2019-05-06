#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <booking.h>

class FlightBooking : public Booking
{
public:
    FlightBooking();
    FlightBooking(long id, double price, string fromDate, string toDate, long travelID, string fromDest, string toDest, string airline);
    FlightBooking(double price);


private:
    string fromDest, toDest, airline;
};

#endif // FLIGHTBOOKING_H
