#include "booking.h"

Booking::Booking()
{

}

double Booking::getPrice() const
{
    return price;
}

long Booking::getId() const
{
    return id;
}

long Booking::getTravelId() const
{
    return travelId;
}

string Booking::getFromDate()
{
    return this->fromDate;
}

string Booking::getToDate()
{
    return this->toDate;
}


