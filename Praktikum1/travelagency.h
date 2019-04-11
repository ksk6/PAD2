#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <rentalcarreservation.h>
#include <vector>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <fstream>

class TravelAgency
{
public:
    TravelAgency();
    void readFile();
    void readBinaryFile();
private:
    vector<RentalCarReservation> rentalCarReservations;
    vector<HotelBooking*> hotelBookings;
    vector<FlightBooking> flightBookings;
};

#endif // TRAVELAGENCY_H
