#ifndef RENTALCARRESERATION_H
#define RENTALCARRESERATION_H
#include <booking.h>


class RentalCarReservation : public Booking
{
public:
    RentalCarReservation();
    RentalCarReservation(long id, double price, string fromDate, string toDate, long travelid,
                         string pickupLocation, string returnLocation, string company);
    RentalCarReservation(double price);

protected:
    string pickupLocation,
           returnLocation,
           company;
};

#endif // RENTALCARRESERATION_H
