#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H



#include <booking.h>

#include <string>



using namespace std;



class RentalCarReservation : public Booking
{

public:

    // constructor
    RentalCarReservation();
    RentalCarReservation(long bid, long tid, double price, string dateFrom, string dateTo, vector<string> arcs,
                         string pickupLocation, string returnLocation, string company, string insuranceType)
        : Booking(bid, tid, price, dateFrom, dateTo, arcs), pickupLocation(pickupLocation), returnLocation(returnLocation), company(company), insuranceType(insuranceType)
    {
        bookingType = "RentalCarReservation";
    }
    virtual ~RentalCarReservation();

    // functions
    virtual string showDetails() const;

    // getter/setter
    string getPickupLocation() const;
    void setPickupLocation(const string &value);
    string getReturnLocation() const;
    void setReturnLocation(const string &value);
    string getCompany() const;
    void setCompany(const string &value);
    string getInsuranceType() const;
    void setInsuranceType(const string &value);

    QString getQPickupLocation() const;
    QString getQReturnLocation() const;
    QString getQCompany() const;
    QString getQInsuranceType() const;

private:

    // var
    string
    pickupLocation,
    returnLocation,
    company,
    insuranceType;

};



#endif
