#ifndef TRAVEL_H
#define TRAVEL_H



#include "booking.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

#include <vector>

#include "algorithmen.cpp"


using namespace std;



class Travel
{

public:

    // constructors
    Travel();
    Travel(long tid, long cid)
        : tid(tid), cid(cid)
    {
        dependencies = new Graph<Booking*, 1000>();
    }
    ~Travel() {
        delete dependencies;
    }

    // functions
    bool findBooking(long bid) const;
    void addBooking(Booking* booking);
    int getBookingsCount() const;

    // graph
    Graph<Booking*, 1000> *dependencies;
    void buildGraph();

    // checks
    bool checkRoundtrip();
    bool checkMissingHotel();
    bool checkNeedlessHotel();
    bool checkNeedlessRentalCar();

    // structs
    struct node{
        Booking* booking;
        unsigned long end;
    };

    // getter/setter
    long getTid() const;
    void setTid(long value);
    long getCid() const;
    void setCid(long value);


private:

    // var
    long tid, cid;

    // lists
    vector<Booking*> travelBookings;

};



#endif // TRAVEL_H
