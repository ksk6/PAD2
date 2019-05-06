#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}
HotelBooking::HotelBooking(long id, double price, string fromDate, string toDate, long travelid, string hotel, string town)
{
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->travelId = travelid;
    this->hotel = hotel;
    this->town = town;
}

HotelBooking::HotelBooking(double price)
{
    this->price = price;
}


