#include "travel.h"

Travel::Travel()
{

}

Travel::Travel(long tid, long cid)
{
    this->id = tid;
    this->customerID = cid;
}


void Travel::addBooking(Booking* booking) { this->travelBookings.push_back(booking); }

// ---------- Getter ---------- //
long Travel::getId() const { return id; }

long Travel::getCustomerID() const { return customerID; }

vector<Booking *> Travel::getTravelBookings() const { return travelBookings; }

// ---------- Setter ---------- //
void Travel::setCustomerID(long value) { customerID = value; }

void Travel::setId(long value) { id = value; }

void Travel::setTravelBookings(const vector<Booking *> &value) { travelBookings = value; }
