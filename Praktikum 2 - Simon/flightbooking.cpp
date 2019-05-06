#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}
FlightBooking::FlightBooking(long id, double price, string fromDate, string toDate, long travelID, string fromDest, string toDest, string airline){
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->travelId = travelID;
    this->fromDest = fromDest;
    this->toDest = toDest;
    this->airline = airline;
}

FlightBooking::FlightBooking(double price){
    this->price = price;
}


