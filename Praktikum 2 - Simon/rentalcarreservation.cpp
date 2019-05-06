#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::RentalCarReservation(long id, double price, string fromDate, string toDate, long travelid,
                                           string pickupLocation, string returnLocation, string company)
{
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->travelId = travelid;
    this->pickupLocation = pickupLocation;
    this->returnLocation = returnLocation;
    this->company = company;
}
RentalCarReservation::RentalCarReservation(double price){
    this->price = price;
}


