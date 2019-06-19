#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H



#include <booking.h>

#include <string>



using namespace std;



class HotelBooking : public Booking
{

public:

    // constructors
    HotelBooking();
    HotelBooking(long bid, long tid, double price, string dateFrom, string dateTo, vector<string> arcs,
                 string hotel, string town, string smoke)
        : Booking(bid, tid, price, dateFrom, dateTo, arcs), hotel(hotel), town(town)
    {
        setSmoke(smoke);
        bookingType = "HotelBooking";
    }
    virtual ~HotelBooking();

    // functions
    virtual string showDetails() const;

    // getter/setter
    string getHotel() const;
    void setHotel(const string &value);
    string getTown() const;
    void setTown(const string &value);
    bool getSmoke() const;
    void setSmoke(bool value);
    void setSmoke(int value);
    void setSmoke(const string &value);

    QString getQHotel() const;
    QString getQTown() const;

private:

    // var
    string
    hotel,
    town;

    bool smoke;

};



#endif
