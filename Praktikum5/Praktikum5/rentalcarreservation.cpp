#include "rentalcarreservation.h"



// --------------------------------- CONSTRUCTORS ---------------------------------



RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::~RentalCarReservation()
{

}



// --------------------------------- FUNCTIONS ---------------------------------



string RentalCarReservation::showDetails() const
{
    return getInsuranceType();
}



// --------------------------------- GETTER/SETTER ---------------------------------



string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

void RentalCarReservation::setPickupLocation(const string &value)
{
    pickupLocation = value;
}

string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

void RentalCarReservation::setReturnLocation(const string &value)
{
    returnLocation = value;
}

string RentalCarReservation::getCompany() const
{
    return company;
}

void RentalCarReservation::setCompany(const string &value)
{
    company = value;
}

string RentalCarReservation::getInsuranceType() const
{
    return insuranceType;
}

void RentalCarReservation::setInsuranceType(const string &value)
{
    insuranceType = value;
}

QString RentalCarReservation::getQPickupLocation() const
{
    return QString::fromStdString(pickupLocation);
}

QString RentalCarReservation::getQReturnLocation() const
{
    return QString::fromStdString(returnLocation);
}

QString RentalCarReservation::getQCompany() const
{
    return QString::fromStdString(company);
}

QString RentalCarReservation::getQInsuranceType() const
{
    return QString::fromStdString(insuranceType);
}

