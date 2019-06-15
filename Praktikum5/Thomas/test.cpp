#include "test.h"
#include "travelagency.h"

void Test::testAvis(){
    TravelAgency t;
    t.readFile();
    int counter = 0;
    for(unsigned int i=0; i<=t.getAllBooking().Size()-1; i++){
        if(t.getAllBooking()[i]->getType() == 'R')
        {
            RentalCarReservation* r = dynamic_cast<RentalCarReservation*>(t.getAllBooking()[i]);
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
    for(unsigned int i=0; i<=t.getAllBooking().Size()-1; i++){
        if(t.getAllBooking()[i]->getType() == 'F')
        {
            FlightBooking* f = dynamic_cast<FlightBooking*>(t.getAllBooking()[i]);
            if(f->getAirline() == "United Airlines")
                counter++;
        }
    }
    QCOMPARE(counter, 3);
}
void Test::testValue(){
    TravelAgency t;
    t.readFile();
    int counter = 0;

    QCOMPARE(t.getAllBooking().Size(), 31);
    QVERIFY(t.getTotalPrice() > 1000 );
}
