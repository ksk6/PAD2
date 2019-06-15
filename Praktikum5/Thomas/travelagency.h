#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <fstream>

#include <customer.h>
#include <flightbooking.h>
#include <rentalcarreservation.h>
#include <hotelbooking.h>
#include <QString>
#include <list.h>

class TravelAgency
{
public:
    TravelAgency();
    bool readFile();
    int createBooking( char type, double price, string start, string end, long travelID, vector<string> bookingDetails);
    void writeFile(QString targetName);

    // Getter
    int getNumberOfFlights() const;
    int getNumberOfRentalCarReservation() const;
    int getNumberOfHotelBookings() const;
    double getTotalPrice() const;
    //vector<Booking *> getAllBooking() const;
    List<Booking*> getAllBooking() const;
    vector<Customer *> getAllCustomers() const;
    vector<Travel *> getAllTravels() const;

    // Setter
    void setAllCustomers(const vector<Customer *> &value);

    // Finder
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);

private:
    //vector<Booking*> allBooking;
    List<Booking*> allBooking;
    vector<Customer*> allCustomers;
    vector<Travel*> allTravels;
    int GenerateNewID();
    double totalPrice = 0;
    int numberOfFlights = 0, numberOfRentalCarReservation = 0, numberOfHotelBookings = 0;
    //Customer GenerateCustomer(vector<string>* linedata);
    //Travel GenerateTravel(vector<string>* linedata);
};

#endif // TRAVELAGENCY_H
