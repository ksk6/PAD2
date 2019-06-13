#include "test.h"
#include "travelagency.h"

void Test::testAvis(){
    TravelAgency t;
    t.readFile();
    int counter = 0;
    for(unsigned int i=0; i<=t.getAllBooking().size(); i++){
        if(t.getAllBooking().at(i)->getType() == 'R')
        {
            RentalCarReservation* r = dynamic_cast<RentalCarReservation*>(t.getAllBooking().at(i));
            if(r->getCompany() == "Avis")
                counter++;
        }
    }
    QCOMPARE(counter, 5);
}
void Test::testUnitedAirlines(){
    TravelAgency t;
    t.readFile();
    int counter = 0;
    for(unsigned int i=0; i<=t.getAllBooking().size(); i++){
        if(t.getAllBooking().at(i)->getType() == 'F')
        {
            FlightBooking* f = dynamic_cast<FlightBooking*>(t.getAllBooking().at(i));
            if(f->getAirline() == "United Airlines")
                counter++;
        }
    }
    QCOMPARE(counter, 3);
}
void Test::testValue(){
    TravelAgency t;
    t.readFile();
    double price = 0;
    for(unsigned int i=0; i<= 30; i++)
    {
        price = t.getAllBooking().at(i)->getPrice();
    }
    QVERIFY(price > 1000 );
}

