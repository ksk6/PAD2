#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::RentalCarReservation(long id, double price, string fromDate, string toDate, long travelid,
                                           string pickupLocation, string returnLocation, string company, string insuranceType)
{
    this->type = 'R';
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

RentalCarReservation::~RentalCarReservation()
{

}


// Getter
string RentalCarReservation::getPickupLocation() const { return pickupLocation; }
string RentalCarReservation::getReturnLocation() const { return returnLocation; }
string RentalCarReservation::getCompany() const { return company; }
string RentalCarReservation::getInsuranceType() const { return insuranceType; }


string RentalCarReservation::showDetails(){
    return this->insuranceType;
}
