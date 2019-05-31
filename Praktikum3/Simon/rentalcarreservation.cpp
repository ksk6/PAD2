#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::RentalCarReservation(long id, double price, string fromDate, string toDate, long travelid,
                                           string pickupLocation, string returnLocation, string company, string insuranceType)
{
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->travelId = travelid;
    this->pickupLocation = pickupLocation;
    this->returnLocation = returnLocation;
    this->company = company;
    this->insuranceType = insuranceType;
}
RentalCarReservation::RentalCarReservation(double price){
    this->price = price;
}


