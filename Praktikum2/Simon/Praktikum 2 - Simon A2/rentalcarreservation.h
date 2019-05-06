#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <booking.h>

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation();
    RentalCarReservation(long id, double price, string fromDate, string toDate, long travelid,
                         string pickupLocation, string returnLocation, string company);
    RentalCarReservation(double price);

private:
    string pickupLocation, returnLocation, company;
};

#endif // RENTALCARRESERVATION_H
