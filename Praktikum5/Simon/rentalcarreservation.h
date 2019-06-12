#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <booking.h>

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation();
    RentalCarReservation(long id, double price, string fromDate, string toDate, long travelid,
                         string pickupLocation, string returnLocation, string company, string insuranceType);
    RentalCarReservation(double price);
    ~RentalCarReservation();
    string showDetails();
    string getPickupLocation() const;

    string getReturnLocation() const;

    string getCompany() const;

    string getInsuranceType() const;

private:
    string pickupLocation, returnLocation, company, insuranceType;
};

#endif // RENTALCARRESERVATION_H
