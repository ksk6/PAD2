#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <iostream>
using namespace std;

class RentalCarReservation
{
public:
    RentalCarReservation();
    RentalCarReservation(long id, double price, string fromDate, string toDate,
                         string pickupLocation, string returnLocation, string company);
    RentalCarReservation(double price);

    //Getter functions
    double getPrice() const;
    long getId() const;
    string getFromDate() const;
    string getToDate() const;
    string getPickupLocation() const;
    string getReturnLocation() const;
    string getCompany() const;

private:
    long id;
    double price;
    string fromDate, toDate, pickupLocation, returnLocation, company;
};

#endif // RENTALCARRESERVATION_H
