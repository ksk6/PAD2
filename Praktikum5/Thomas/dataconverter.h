#ifndef DATACONVERTER_H
#define DATACONVERTER_H
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

enum BookingArt{
    FLIGHT, HOTEL, CAR
};

class DataConverter
{
public:
    DataConverter(FlightBooking* data);
    DataConverter(HotelBooking* data);
    DataConverter(RentalCarReservation* data);

    int bookingArt;
    FlightBooking* fData;
    HotelBooking* hData;
    RentalCarReservation* rData;
};

#endif // DATACONVERTER_H
