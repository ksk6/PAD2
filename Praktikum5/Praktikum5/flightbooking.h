#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H



#include <booking.h>

#include <string>



using namespace std;



class FlightBooking : public Booking
{

public:

    // constructors
    FlightBooking();
    FlightBooking(long bid, long tid, double price, string dateFrom, string dateTo, vector<string> arcs,
                  string fromDest, string toDest, string airline, string seatPref)
        : Booking(bid, tid, price, dateFrom, dateTo, arcs), fromDest(fromDest), toDest(toDest), airline(airline)
    {
        setSeatPref(seatPref);
        bookingType = "FlightBooking";
    }
    virtual ~FlightBooking();

    // functions
    virtual string showDetails() const;

    // getter/setter
    string getFromDest() const;
    void setFromDest(const string &value);
    string getToDest() const;
    void setToDest(const string &value);
    string getAirline() const;
    void setAirline(const string &value);
    char getSeatPref() const;   
    void setSeatPref(char value);
    void setSeatPref(const string &value);

    QString getQFromDest() const;
    QString getQToDest() const;
    QString getQAirline() const;
    QString getQSeatPref() const;

private:

    string
    fromDest,
    toDest,
    airline;

    char seatPref;

};



#endif
