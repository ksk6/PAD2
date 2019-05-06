#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <fstream>

#include <customer.h>
#include <flightbooking.h>
#include <rentalcarreservation.h>
#include <hotelbooking.h>

class TravelAgency
{
public:
    TravelAgency();
    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
private:
    vector<Booking*> allBooking;
    vector<Customer*> allCustomers;
    vector<Travel*> allTravels;
    Customer GenerateCustomer(vector<string>* linedata);
    Travel GenerateTravel(vector<string>* linedata);
};

#endif // TRAVELAGENCY_H
