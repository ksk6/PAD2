#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <booking.h>

class FlightBooking : public Booking
{
public:
    FlightBooking();
    FlightBooking(long id, double price, string fromDate, string toDate, long travelID, string fromDest,
                  string toDest, string airline, char seatPref, vector<int> vorherigeBuchungen);
    FlightBooking(double price);
    virtual ~FlightBooking();
    string showDetails();

    // Getter
    string getFromDest() const;
    string getToDest() const;
    string getAirline() const;
    char getSeatPref() const;

private:
    string fromDest, toDest, airline;
    char seatPref;
};

#endif // FLIGHTBOOKING_H
