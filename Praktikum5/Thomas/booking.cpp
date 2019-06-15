#include "booking.h"

Booking::Booking()
{

}

Booking::~Booking()
{

}

// Getter
double Booking::getPrice() const { return price; }
long Booking::getId() const { return id; }
long Booking::getTravelId() const { return travelId; }
char Booking::getType() const { return type; }
string Booking::getFromDate() { return this->fromDate; }
string Booking::getToDate() { return this->toDate; }
