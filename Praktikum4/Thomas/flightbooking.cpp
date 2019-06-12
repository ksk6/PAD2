#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}
FlightBooking::FlightBooking(long id, double price, string fromDate, string toDate, long travelID, string fromDest, string toDest, string airline, char seatPref){
    this->type = 'F';
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->travelId = travelID;
    this->fromDest = fromDest;
    this->toDest = toDest;
    this->airline = airline;
    this->seatPref = seatPref;
}

FlightBooking::~FlightBooking()
{

}

FlightBooking::FlightBooking(double price) { this->price = price; }


// Getter
string FlightBooking::getFromDest() const { return fromDest; }
string FlightBooking::getToDest() const { return toDest; }
string FlightBooking::getAirline() const { return airline; }
char FlightBooking::getSeatPref() const { return seatPref; }


string FlightBooking::showDetails()
{
    if(this->seatPref == 'W')
        return "Fensterplatz";
    else
        return "Gangplatz";
}
