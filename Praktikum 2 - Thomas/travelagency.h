#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <fstream>

#include <customer.h>
#include <flightbooking.h>
#include <rentalcarreservation.h>
#include <hotelbooking.h>
#include <sstream>
#include <booking.h>
#include <flightbooking.h>


class TravelAgency
{
public:
    TravelAgency();

    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
    bool idExists(long id);
    int createBooking( char type, double price, string start, string end, long travelID, vector<string> bookingDetails);

    int getNumberOfFlights() const;
    int getNumberOfRentalCarReservation() const;
    int getNumberOfHotelBookings() const;
    double getTotalPrice() const;

private:
    vector<Booking*> allBooking;
    vector<Customer*> allCustomers;
    vector<Travel*> allTravels;
    int GenerateNewID();
    double totalPrice = 0;
    int numberOfFlights = 0, numberOfRentalCarReservation = 0, numberOfHotelBookings = 0;
    //Customer GenerateCustomer(vector<string>* linedata);
    //Travel GenerateTravel(vector<string>* linedata);
};

#endif // TRAVELAGENCY_H
