#include "booking.h"

Booking::Booking()
{

}


// ---------- Getter ---------- //
double Booking::getPrice() const { return price; }

long Booking::getId() const { return id; }

long Booking::getTravelId() const { return travelId; }
