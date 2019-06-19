#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H



#include "booking.h"
#include "customer.h"
#include "travel.h"

#include "list.h"

#include <QMessageBox>

#include <string>
#include <vector>



using namespace std;



class TravelAgency
{

public:

    // constructor
    TravelAgency(string name);

    // destructor
    ~TravelAgency();

    // load file
    void readFile(const string &path);
    void extractBooking(string line);
    vector<string> parser(string line);

    // functions
    void createBooking(double price, long travelId, QDate start, QDate end,
                       QString departure, QString arrival, QString airline, char seatPref, vector<string> arcs);
    void createBooking(double price, long travelId, QDate start, QDate end,
                       QString hotel, QString town, bool smoke, vector<string> arcs);
    void createBooking(double price, long travelId, QDate start, QDate end,
                       QString pickupLocation, QString returnLocation, QString company, QString insuranceType, vector<string> arcs);

    void clearData();
    QString getConcatenatedData(Booking *b);
    QString getConcMainData(const char &type, Booking *b);

    // find
    Booking* findBooking(long bid);
    Travel* findTravel(long tid);
    Customer* findCustomer(long cid) const;

    long getNextBookingId();

    // info functions
    void countPriceTotal();
    void countBookings();
    void countTravels();
    void countCustomer();

    // print functions
    void printBookingsInfo() const;
    void printTravelCustomerInfo() const;
    void printCustomerTravelsCount(long cid) const;
    void printTravelBookingsCount(long tid);

    // lists
    //vector<Booking*> allBookings;
    List<Booking*> allBookings;
    vector<Customer*> allCustomers;
    List<Travel*> allTravels;

    // unit tests
    long countRentalCarReservationsOfCompany(const QString &value);
    long countFlightBookingsOfAirline(const QString &value);
    long countBookingsMinPrice(const double &value);

    // getter/setter
    string getName() const;
    long getId() const;
    long getFlightbookingCount() const;
    void setFlightbookingCount(long value);
    long getHotelbookingCount() const;
    void setHotelbookingCount(long value);
    long getRentalcarresCount() const;
    void setRentalcarresCount(long value);
    long getBookingsCount() const;
    void setBookingsCount(long value);
    double getPriceTotal() const;
    void setPriceTotal(double value);
    long getTravelCount() const;
    void setTravelCount(long value);
    long getCustomerCount() const;
    void setCustomerCount(long value);
    Travel* getTravel(Booking* b);
    Customer* getCustomer(Booking* b);
    long getLastImportBookingCount() const;
    void setLastImportBookingCount(long value);
    long getLastImportTravelCount() const;
    void setLastImportTravelCount(long value);
    long getLastImportCustomerCount() const;
    void setLastImportCustomerCount(long value);
    double getLastImportPriceTotal() const;
    void setLastImportPriceTotal(double value);


private:

    // var
    const string name;

    long lastImportBookingCount;
    long lastImportTravelCount;
    long lastImportCustomerCount;
    double lastImportPriceTotal;

    long bookingsCount;
    long flightbookingCount;
    long hotelbookingCount;
    long rentalcarresCount;
    long travelCount;
    long customerCount;
    double priceTotal;

    long (*getTid)();
    long (*getCid)();
    long (*getBid)();
};



#endif
