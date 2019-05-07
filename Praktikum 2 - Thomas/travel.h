#ifndef TRAVEL_H
#define TRAVEL_H
#include <booking.h>
#include <vector>


class Travel
{
public:
    Travel();
    Travel(long tid, long cid);

    void addBooking(Booking* booking);

    long getCustomerID() const;
    long getId() const;
    vector<Booking *> getTravelBookings() const;

    void setCustomerID(long value);
    void setId(long value);
    void setTravelBookings(const vector<Booking *> &value);

private:
    long id,
         customerID;
    vector<Booking*> travelBookings;
};

#endif // TRAVEL_H
