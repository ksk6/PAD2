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

    // Getter
    long getId() const;
    long getCustomerID() const;
    vector<Booking *> getTravelBookings() const;

    // Setter
    void setCustomerID(long value);
    void setId(long value);
    void setTravelBookings(const vector<Booking *> &value);

private:
    long id, customerID;
    vector<Booking*> travelBookings;
};

#endif // TRAVEL_H
