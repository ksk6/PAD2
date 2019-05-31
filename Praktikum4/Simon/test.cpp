#include "test.h"
#include "travelagency.h"

void Test::testAvis(){
    TravelAgency t;
    t.readFile();
    int counter = 0;
    for(Booking *b : t.getAllBooking()){
        if(b->getType() == 'R')
        {
            RentalCarReservation* r = dynamic_cast<RentalCarReservation*>(b);
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
    for(Booking *b : t.getAllBooking()){
        if(b->getType() == 'F')
        {
            FlightBooking* f = dynamic_cast<FlightBooking*>(b);
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

    QCOMPARE(t.getAllBooking().size(), 31);
    QVERIFY(t.getTotalPrice() > 1000 );
}

