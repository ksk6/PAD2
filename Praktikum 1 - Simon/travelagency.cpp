#include "travelagency.h"
#include <sstream>

TravelAgency::TravelAgency()
{

}

void TravelAgency::readFile()
{
    ifstream quelle;
    string path = "bookings.txt";
    double maxFlightbookingValue = 0, maxRentalCarReservationValue = 0, maxHotelBookingsValue = 0;
    int numberOfFlights = 0, numberOfRentalCarReservation = 0, numberOfHotelBookings = 0;
    quelle.open(path.c_str(), ios::in);

    if(!quelle){
        cerr << "Die Datei " << path << " konnte nicht geöffnet werden";
        exit(-1);
    }else
    {
        string s,s2;
        //int counter;
        while(getline(quelle, s, '\n')){
            stringstream ss(s);
            if(s.at(0) == 'F')
            {
                vector <string> fbdata;
                while(getline(ss, s2, '|')){
                    fbdata.push_back(s2);
                }
                FlightBooking fb(stol(fbdata.at(1).c_str()), stod(fbdata.at(2).c_str()), fbdata.at(3), fbdata.at(4), fbdata.at(5), fbdata.at(6), fbdata.at(7));
                maxFlightbookingValue += fb.getPrice();
                numberOfFlights++;
                this->flightBookings.push_back(fb);
            }
            else if(s.at(0) == 'R')
            {
                vector <string> rcrdata;
                while(getline(ss, s2, '|')){
                    rcrdata.push_back(s2);
                }
                RentalCarReservation RcR(stol(rcrdata.at(1).c_str()), stod(rcrdata.at(2).c_str()), rcrdata.at(3), rcrdata.at(4), rcrdata.at(5), rcrdata.at(6), rcrdata.at(7));
                maxRentalCarReservationValue += RcR.getPrice();
                numberOfRentalCarReservation++;
                this->rentalCarReservations.push_back(RcR);
            }else if(s.at(0) == 'H')
            {
                vector <string> hbdata;
                while(getline(ss, s2, '|')){
                    hbdata.push_back(s2);
                }
                HotelBooking hb(stol(hbdata.at(1).c_str()), stod(hbdata.at(2).c_str()), hbdata.at(3), hbdata.at(4), hbdata.at(5), hbdata.at(6));
                maxHotelBookingsValue += hb.getPrice();
                numberOfHotelBookings++;
                this->hotelBookings.push_back(&hb);
            }
        }


        cout << "Es wurden " << numberOfFlights << " Flugbuchungen mit einem Gesamtwert von " << maxFlightbookingValue << " Euro erfasst\n"
             << "Es wurden " << numberOfRentalCarReservation << " Mietwagenbuchungen mit einem Gesamtwert von " << maxRentalCarReservationValue<< " Euro erfasst\n"
             << "Es wurden " << numberOfHotelBookings << " Hotelbuchungen mit einem Gesamtwert von " << maxHotelBookingsValue << " Euro erfasst\n";
    }
    quelle.close();
}

char* Substr(char* arr, int begin, int len)
{
    char* res = new char[len];
    for (int i = 0; i < len; i++)
        res[i] = *(arr + begin + i);
    res[len] = 0;
    return res;
}

void TravelAgency::readBinaryFile()
{
    ifstream quelle;
    string path = "bookingsBinary.bin";
    FlightBooking maxFB(0);
    HotelBooking maxHB(0);
    RentalCarReservation maxRCR(0);
    double maxFlightbookingValue = 0, maxRentalCarReservationValue = 0, maxHotelBookingsValue = 0;

    quelle.open(path.c_str(), ios::in | ios::binary);

    if(!quelle)
        cout << "Die Datei " << path << " konnte nicht geöffnet werden";

    long id;
    double price;
    char fromDest[3];
    char toDest[3];
    char hotel[15], town [15], pickupLocation [15], returnLocation [15], company [15];
    char typ[1];
    char fromDate[8], toDate[8];

    while (!quelle.eof()) {
        //quelle.read((char *) &zahl1, sizeof (zahl1));
        quelle.read(reinterpret_cast<char *>(&typ), sizeof (char[1]));
        quelle.read(reinterpret_cast<char *>(&id), sizeof (long));
        quelle.read(reinterpret_cast<char *>(&price), sizeof (double));
        quelle.read(reinterpret_cast<char *>(&fromDate), sizeof (char[8]));
        quelle.read(reinterpret_cast<char *>(&toDate), sizeof (char[8]));
        if(typ[0] == 'F'){

            quelle.read(reinterpret_cast<char *>(&fromDest), sizeof (char[3]));
            quelle.read(reinterpret_cast<char *>(&toDest), sizeof (char[3]));
            quelle.read(reinterpret_cast<char *>(&company), sizeof (char[15]));

            //FlightBooking FB(id, price, fromDate, toDate, fromDest, test, company);
            FlightBooking FB(
                    id,
                    price,
                    Substr(fromDate, 0, 8),
                    Substr(toDate, 0, 8),
                    Substr(fromDest, 0, 3),
                    Substr(toDest, 0, 3),
                    Substr(company, 0, 15)
            );

            this->flightBookings.push_back(FB);
            maxFlightbookingValue += FB.getPrice();

            if(maxFB.getPrice() < FB.getPrice())
                maxFB = FB;

        }else if(typ[0] == 'R'){

            quelle.read(reinterpret_cast<char *>(&pickupLocation), sizeof (char[15]));
            quelle.read(reinterpret_cast<char *>(&returnLocation), sizeof (char[15]));
            quelle.read(reinterpret_cast<char *>(&company), sizeof (char[15]));

            RentalCarReservation RCR(
                    id,
                    price,
                    Substr(fromDate, 0, 8),
                    Substr(toDate, 0, 8),
                    Substr(pickupLocation, 0, 15),
                    Substr(returnLocation, 0, 15),
                    Substr(company, 0, 15));

            //RentalCarReservation RCR(id, price, fromDate, toDate, pickupLocation, returnLocation, company); OLD Version
            this->rentalCarReservations.push_back(RCR);
            maxRentalCarReservationValue += RCR.getPrice();

            if(maxRCR.getPrice() < RCR.getPrice())
                maxRCR = RCR;

        }else if(typ[0] == 'H'){

            quelle.read(reinterpret_cast<char *>(&hotel), sizeof (char[15]));
            quelle.read(reinterpret_cast<char *>(&town), sizeof (char[15]));
            //HotelBooking hb(id, price, fromDate, toDate, hotel, town);
            HotelBooking hb(
                    id,
                    price,
                    Substr(fromDate, 0, 8),
                    Substr(toDate, 0, 8),
                    Substr(hotel, 0, 15),
                    Substr(town, 0, 15)
            );
            maxHotelBookingsValue += hb.getPrice();
            this->hotelBookings.push_back(&hb);

            if(maxHB.getPrice() < hb.getPrice())
                maxHB = hb;
        }
    }
    quelle.close();
    cout << "Es wurden " << this->flightBookings.size() << " Flugbuchungen mit einem Gesamtwert von " << maxFlightbookingValue <<  " Euro erfasst\n"
         << "Es wurden " << this->rentalCarReservations.size() << " Mietwagenbuchungen mit einem Gesamtwert von " << maxRentalCarReservationValue << " Euro erfasst\n"
         << "Es wurden " << this->hotelBookings.size() << " Hotelbuchungen mit einem Gesamtwert von " << maxHotelBookingsValue <<" Euro erfasst\n";

    cout << "\nTeuerste Flugbuchung (Id " << maxFB.getId() << "): Vom " << maxFB.getFromDate() << " bis " << maxFB.getToDate() << " von " << maxFB.getFromDest() <<
            " nach " << maxFB.getToDest() << " mit " << maxFB.getAirline() << " zum Preis von " << maxFB.getPrice() << " Euro.\n" << endl <<
            "Teuerste Mietwagenbuchung (Id " << maxRCR.getId() << "): Vom " << maxRCR.getFromDate() << " bis " << maxRCR.getToDate() << " von " << maxRCR.getPickupLocation() <<
            " nach " << maxRCR.getReturnLocation() << " mit " << maxRCR.getCompany() << " zum Preis von " << maxRCR.getPrice() << " Euro.\n" << endl <<
            "Teuerste Hotelbuchung (Id " << maxHB.getId() << "): Vom " << maxHB.getFromDate() << " bis " << maxHB.getToDate() << " im " << maxHB.getHotel() <<
            " in " << maxHB.getTown() << " zum Preis von " << maxHB.getPrice() << " Euro.\n";

}

