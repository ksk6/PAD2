#include "dataconverter.h"


DataConverter::DataConverter(FlightBooking* data){
    this->bookingArt = BookingArt::FLIGHT;

    this->fData = data;
}

DataConverter::DataConverter(HotelBooking* data){
    this->bookingArt = BookingArt::HOTEL;

    this->hData = data;
}

DataConverter::DataConverter(RentalCarReservation* data){
    this->bookingArt = BookingArt::CAR;

    this->rData = data;
}
