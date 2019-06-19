#ifndef TEST_H
#define TEST_H



#include <QObject>
#include <QtTest/QTest>

#include <sstream>

#include "travelagency.h"
#include "booking.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"



using namespace std;



class Test : public QObject
{
    Q_OBJECT

    public:

        explicit Test(QObject *parent = nullptr);

    private slots:

        void initTestCase();

        void test_CountRentalCarReservationsOfCompany(); //const QString &value, const long &expected
        void test_CountFlightBookingsOfAirline(); //const QString &value, const long &expected
        void test_CountBookingsMinPrice(); //const double &value, const long &expected

        void cleanupTestCase();

    private:

        TravelAgency *ta;

};



#endif // TEST_H
