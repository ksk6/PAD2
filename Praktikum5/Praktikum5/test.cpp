#include "test.h"



// --------------------------------------------------------------------------------



    Test::Test(QObject *parent)
    {

    }



// --------------------------------------------------------------------------------



    void Test::initTestCase()
    {
        ta = new TravelAgency("TravelAgency-TEST");
        ta->readFile("./bookings_praktikum4.txt");
    }



// --------------------------------------------------------------------------------



    void Test::test_CountRentalCarReservationsOfCompany()
    {
        QString company = "Avis";
        long value = ta->countRentalCarReservationsOfCompany(company);

        QCOMPARE(value, 5);

        QString msg = "Eingelesen wurden " + QString::number(value) + " Mietwagenbuchungen der Firma " + company + ".";
        qDebug(msg.toLatin1());
    }


    void Test::test_CountFlightBookingsOfAirline()
    {
        QString airline = "United Airlines";
        long value = ta->countFlightBookingsOfAirline(airline);

        QCOMPARE(value, 3);

        QString msg = "Eingelesen wurden " + QString::number(value) + " Flugbuchungen mit der Fluglinie " + airline + ".";
        qDebug(msg.toLatin1());
    }


    void Test::test_CountBookingsMinPrice()
    {
        double minPrice = 1000.0;
        long value = ta->countBookingsMinPrice(minPrice);

        QCOMPARE(value, 31);

        QString msg = "Eingelesen wurden " + QString::number(value) + " Buchungen mit einem Wert von mindestens " + QString::number(minPrice) + " EURO.";
        qDebug(msg.toLatin1());
    }



// --------------------------------------------------------------------------------



    void Test::cleanupTestCase()
    {
        delete ta;
    }
