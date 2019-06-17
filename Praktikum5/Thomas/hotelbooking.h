#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <booking.h>

class HotelBooking : public Booking
{
public:
    HotelBooking();
    HotelBooking(long id, double price, string fromDate, string toDate,
                 long travelid, string hotel, string town, bool smoke,
                 vector<int> vorherigeBuchungen);
    HotelBooking(double price);
    ~HotelBooking();
    string showDetails();

    // Getter
    string getHotel() const;
    string getTown() const;
    bool getSmoke() const;

private:
    string hotel, town;
    bool smoke;
};

#endif // HOTELBOOKING_H
