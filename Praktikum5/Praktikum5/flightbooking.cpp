#include "flightbooking.h"



// --------------------------------- CONSTRUCTORS/DESTRCUTORS ---------------------------------



FlightBooking::FlightBooking()
{

}

FlightBooking::~FlightBooking()
{

}



// --------------------------------- FUNCTIONS ---------------------------------



string FlightBooking::showDetails() const
{
    string var = "empty";

    switch(getSeatPref()) {
        case 'A':
            var = "Gang";
            break;
        case 'W':
            var = "Fenster";
            break;
    }

    return var;
}



// --------------------------------- GETTER/SETTER ---------------------------------



string FlightBooking::getFromDest() const
{
    return fromDest;
}

void FlightBooking::setFromDest(const string &value)
{
    fromDest = value;
}

string FlightBooking::getToDest() const
{
    return toDest;
}

void FlightBooking::setToDest(const string &value)
{
    toDest = value;
}

string FlightBooking::getAirline() const
{
    return airline;
}

void FlightBooking::setAirline(const string &value)
{
    airline = value;
}

char FlightBooking::getSeatPref() const
{
    return seatPref;
}

void FlightBooking::setSeatPref(char value)
{
    seatPref = value;
}

void FlightBooking::setSeatPref(const string &value)
{
    seatPref = value[0];
}

QString FlightBooking::getQFromDest() const
{
    return QString::fromStdString(fromDest);
}

QString FlightBooking::getQToDest() const
{
    return QString::fromStdString(toDest);
}

QString FlightBooking::getQAirline() const
{
    return QString::fromStdString(airline);
}

QString FlightBooking::getQSeatPref() const
{
    return QChar(seatPref);
}
