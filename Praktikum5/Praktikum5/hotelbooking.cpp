#include "hotelbooking.h"



// --------------------------------- CONSTRUCTORS/DESTRCUTORS ---------------------------------



HotelBooking::HotelBooking()
{

}

HotelBooking::~HotelBooking()
{

}



// --------------------------------- FUNCTIONS ---------------------------------



string HotelBooking::showDetails() const
{
    if(getSmoke()) {
        return "Ja";
    } else {
        return "Nein";
    }
}



// --------------------------------- GETTER/SETTER ---------------------------------



string HotelBooking::getHotel() const
{
    return hotel;
}

void HotelBooking::setHotel(const string &value)
{
    hotel = value;
}

string HotelBooking::getTown() const
{
    return town;
}

void HotelBooking::setTown(const string &value)
{
    town = value;
}

bool HotelBooking::getSmoke() const
{
    return smoke;
}

void HotelBooking::setSmoke(bool value)
{
    smoke = value;
}

void HotelBooking::setSmoke(int value)
{
    switch(value) {
        case 0:
            smoke = false;
            break;
        case 1:
            smoke = true;
            break;
    }
}

void HotelBooking::setSmoke(const string &value)
{
    setSmoke(stoi(value));
}

QString HotelBooking::getQHotel() const
{
    return QString::fromStdString(hotel);
}

QString HotelBooking::getQTown() const
{
    return QString::fromStdString(town);
}
