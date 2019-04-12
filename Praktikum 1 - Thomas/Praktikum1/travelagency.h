#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <fstream>
#include <sstream>
#include <vector>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <rentalcarreservation.h>
using namespace std;

class TravelAgency
{

public:
    TravelAgency();
    void readFile();
    void readBinaryFile();

private:
    vector<RentalCarReservation> rentalCarReservations;
    vector<HotelBooking> hotelBookings;
    vector<FlightBooking> flightBookings;
};

#endif // TRAVELAGENCY_H
