#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}
HotelBooking::HotelBooking(long id, double price, string fromDate, string toDate, long travelid, string hotel, string town, bool smoke, vector<int> vorherigeBuchungen)
{
    this->type = 'H';
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->travelId = travelid;
    this->hotel = hotel;
    this->town = town;
    this->smoke = smoke;
    this->vorherigeBuchungen = vorherigeBuchungen;
}

HotelBooking::HotelBooking(double price)
{
    this->price = price;
}

HotelBooking::~HotelBooking()
{

}


// Getter
string HotelBooking::getHotel() const { return hotel; }
string HotelBooking::getTown() const { return town; }
bool HotelBooking::getSmoke() const { return smoke; }


string HotelBooking::showDetails()
{
    if(this->smoke == true)
        return "Raucherzimmer";
    else
        return "Nichtraucherzimmer";
}
