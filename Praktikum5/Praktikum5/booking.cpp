#include "booking.h"



// --------------------------------- CONSTRUCTORS/DESTRCUTORS ---------------------------------



Booking::Booking()
{

}
Booking::~Booking()
{

}



// --------------------------------- GETTER/SETTER ---------------------------------



long Booking::getBid() const
{
    return bid;
}

void Booking::setBid(long value)
{
    bid = value;
}

//long Booking::getTid()
//{
//    return tid;
//}

void Booking::setTid(long value)
{
    tid = value;
}

double Booking::getPrice() const
{
    return price;
}

void Booking::setPrice(double value)
{
    price = value;
}

string Booking::getFromDate() const
{
    return dateFrom;
}

void Booking::setFromDate(const string &value)
{
    dateFrom = value;
}

string Booking::getToDate() const
{
    return dateTo;
}

void Booking::setToDate(const string &value)
{
    dateTo = value;
}

QDate Booking::getQDateFrom() const
{
    QDate date = QDate::fromString(QString::fromStdString(this->getFromDate()), "yyyyMMdd");
    return date;
}

QDate Booking::getQDateTo() const
{
    QDate date = QDate::fromString(QString::fromStdString(this->getToDate()), "yyyyMMdd");
    return date;
}

long Booking::getArc1() const
{
    return arc1;
}

void Booking::setArc1(long value)
{
    arc1 = value;
}

long Booking::getArc2() const
{
    return arc2;
}

void Booking::setArc2(long value)
{
    arc2 = value;
}

string Booking::getBookingType() const
{
    return bookingType;
}

void Booking::setBookingType(const string &value)
{
    bookingType = value;
}
