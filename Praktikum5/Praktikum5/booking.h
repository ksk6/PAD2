#ifndef BOOKING_H
#define BOOKING_H



#include <string>
#include <QDate>
#include <vector>



using namespace std;



class Booking
{ 

public:

    // constructors
    explicit Booking();
    Booking(long bid, long tid, double price, string dateFrom, string dateTo, vector<string> arcs)
        : bid(bid), tid(tid), price(price), dateFrom(dateFrom), dateTo(dateTo)
    {
        // default ( keine Abhängigkeit )
        setArc1(-1);
        setArc2(-1);

        if(arcs.size() == 1) {
            setArc1(stol(arcs.at(0)));
        } else if(arcs.size() == 2) {
            setArc1(stol(arcs.at(0)));
            setArc2(stol(arcs.at(1)));
        }
    }
    virtual ~Booking();

    // functions
    virtual string showDetails() const = 0;

    // getter/setter
    virtual long getBid() const;
    void setBid(long value);

    virtual long getTid() {
        return tid;
    }

    void setTid(long value);

    typedef long (*compareFunction)();

    //compareFunction getCompareFunction() {
    //    long (*fptr)() = getTid;
    //}

    virtual double getPrice() const;
    void setPrice(double value);
    virtual string getFromDate() const;
    void setFromDate(const string &value);
    virtual string getToDate() const;
    void setToDate(const string &value);
    QDate getQDateFrom() const;
    QDate getQDateTo() const;
    long getArc1() const;
    void setArc1(long value);
    long getArc2() const;
    void setArc2(long value);
    string getBookingType() const;
    void setBookingType(const string &value);


protected:

    // var
    long bid, tid;
    double price;

    string
    dateFrom, dateTo,
    bookingType;

    // abhängigkeiten
    long arc1, arc2;

};



#endif // BOOKING_H
