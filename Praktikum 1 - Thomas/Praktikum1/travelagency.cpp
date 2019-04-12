#include "travelagency.h"

enum BuchungsTyp{
    FLIGHT = 'F',
    HOTEL = 'H',
    RENTAL_CAR = 'R'
};

enum MaxLengths{
    FROM_DATE_MAX = 8,
    TO_DATE_MAX = 8,
    FROM_DEST_MAX = 3,
    TO_DEST_MAX = 3,
    COMPANY_MAX = 15,
    HOTEL_MAX = 15,
    TOWN_MAX = 15,
    PICKUP_LOCATION_MAX = 15,
    RETURN_LOCATION_MAX = 15,
    TYP_MAX = 1
};

TravelAgency::TravelAgency()
{

}



void TravelAgency::readFile()
{    
    char buchungsTyp = NULL;
    vector<string> buchungsData;
    string path = "bookings.txt",
           line = "",
           buchungsDataEntry = "";
    ifstream quelle;
    stringstream ss;
    double maxFlightbookingValue = 0, maxRentalCarReservationValue = 0, maxHotelBookingsValue = 0;
    int numberOfFlights = 0, numberOfRentalCarReservation = 0, numberOfHotelBookings = 0;

    quelle.open(path.c_str(), ios::in);

    if(!quelle){
        cerr << path << " konnte nicht geoeffnet werden";
        exit(-1);
    }

    while(getline(quelle, line, '\n')){
        buchungsTyp = line[0];
        ss = stringstream(line);

        while(getline(ss , buchungsDataEntry, '|')){
            buchungsData.push_back(buchungsDataEntry);
        }

        if(buchungsTyp == FLIGHT){
            FlightBooking fb(
                    stol(buchungsData[1].c_str()),
                    stod(buchungsData[2].c_str()),
                    buchungsData[3],
                    buchungsData[4],
                    buchungsData[5],
                    buchungsData[6],
                    buchungsData[7]
            );
            this->flightBookings.push_back(fb);
            numberOfFlights++;
            maxFlightbookingValue += fb.getPrice();
        }else if(buchungsTyp == HOTEL){
            HotelBooking hb(
                    stol(buchungsData[1].c_str()),
                    stod(buchungsData[2].c_str()),
                    buchungsData[3],
                    buchungsData[4],
                    buchungsData[5],
                    buchungsData[6]
            );
            this->hotelBookings.push_back(hb);
            numberOfHotelBookings++;
            maxHotelBookingsValue += hb.getPrice();
        }else if(buchungsTyp == RENTAL_CAR){
            RentalCarReservation cr(
                    stol(buchungsData[1].c_str()),
                    stod(buchungsData[2].c_str()),
                    buchungsData[3],
                    buchungsData[4],
                    buchungsData[5],
                    buchungsData[6],
                    buchungsData[7]
            );
            this->rentalCarReservations.push_back(cr);
            numberOfRentalCarReservation++;
            maxRentalCarReservationValue += cr.getPrice();
        }else{
            cerr << "Unbekannter Buchungstyp: " << buchungsTyp << endl;
            exit(-1);
        }

    }

    quelle.close();

    cout << "Es wurden " << numberOfFlights << " Flugbuchungen mit einem Gesamtwert von " << maxFlightbookingValue << " Euro erfasst.\n"
         << "Es wurden " << numberOfRentalCarReservation << " Mietwagenbuchungen mit einem Gesamtwert von " << maxRentalCarReservationValue<< " Euro erfasst.\n"
         << "Es wurden " << numberOfHotelBookings << " Hotelbuchungen mit einem Gesamtwert von " << maxHotelBookingsValue << " Euro erfasst.\n";
}


char* Substr(char* arr, int begin, int len)
{
    char* res = new char[len];
    for (int i = 0; i < len; i++)
        res[i] = *(arr + begin + i);
    res[len] = 0;
    return res;
}


void TravelAgency::readBinaryFile(){
    string path = "bookingsBinary.bin";
    ifstream quelle;
    long id;
    double price;
    char fromDest[FROM_DEST_MAX],
         toDest[TO_DEST_MAX],
         hotel[HOTEL_MAX],
         town[TOWN_MAX],
         pickupLocation[PICKUP_LOCATION_MAX],
         returnLocation[RETURN_LOCATION_MAX],
         company[COMPANY_MAX],
         typ[TYP_MAX],
         fromDate[FROM_DATE_MAX],
         toDate[TO_DATE_MAX];
    FlightBooking maxFB;
    HotelBooking maxHB;
    RentalCarReservation maxRC;
    double maxFlightbookingValue = 0, maxRentalCarReservationValue = 0, maxHotelBookingsValue = 0;


    quelle.open(path.c_str(), ios::in);

    if(!quelle){
        cerr << path << " konnte nicht geoeffnet werden";
        exit(-1);
    }

    while (!quelle.eof()){
        quelle.read(reinterpret_cast<char *>(&typ), sizeof (typ));
        quelle.read(reinterpret_cast<char *>(&id), sizeof (id));
        quelle.read(reinterpret_cast<char *>(&price), sizeof (price));
        quelle.read(reinterpret_cast<char *>(&fromDate), sizeof (fromDate));
        quelle.read(reinterpret_cast<char *>(&toDate), sizeof (toDate));

        if(typ[0] == FLIGHT){
            quelle.read(reinterpret_cast<char *>(&fromDest), sizeof (fromDest));
            quelle.read(reinterpret_cast<char *>(&toDest), sizeof (toDest));
            quelle.read(reinterpret_cast<char *>(&company), sizeof (company));

            FlightBooking fb(
                    id,
                    price,
                    Substr(fromDate, 0, FROM_DATE_MAX),
                    Substr(toDate, 0, TO_DATE_MAX),
                    Substr(fromDest, 0, FROM_DEST_MAX),
                    Substr(toDest, 0, TO_DEST_MAX),
                    Substr(company, 0, COMPANY_MAX)
            );
            this->flightBookings.push_back(fb);
            maxFlightbookingValue += fb.getPrice();

            if(maxFB.getPrice() < fb.getPrice()){ maxFB = fb; }
        }
        else if(typ[0] == HOTEL){
            quelle.read(reinterpret_cast<char *>(&hotel), sizeof (hotel));
            quelle.read(reinterpret_cast<char *>(&town), sizeof (town));

            HotelBooking hb(
                    id,
                    price,
                    Substr(fromDate, 0, FROM_DATE_MAX),
                    Substr(toDate, 0, TO_DATE_MAX),
                    Substr(hotel, 0, HOTEL_MAX),
                    Substr(town, 0, TOWN_MAX)
            );
            maxHotelBookingsValue += hb.getPrice();
            this->hotelBookings.push_back(hb);

            if(maxHB.getPrice() < hb.getPrice()){ maxHB = hb; }
        }
        if(typ[0] == RENTAL_CAR){
            quelle.read(reinterpret_cast<char *>(&pickupLocation), sizeof (pickupLocation));
            quelle.read(reinterpret_cast<char *>(&returnLocation), sizeof (returnLocation));
            quelle.read(reinterpret_cast<char *>(&company), sizeof (company));

            RentalCarReservation cr(
                    id,
                    price,
                    Substr(fromDate, 0, FROM_DATE_MAX),
                    Substr(toDate, 0, TO_DATE_MAX),
                    Substr(pickupLocation, 0, PICKUP_LOCATION_MAX),
                    Substr(returnLocation, 0, RETURN_LOCATION_MAX),
                    Substr(company, 0, COMPANY_MAX)
            );
            this->rentalCarReservations.push_back(cr);
            maxRentalCarReservationValue += cr.getPrice();

            if(maxRC.getPrice() < cr.getPrice()){ maxRC = cr; }
        }
    }

    quelle.close();

    cout << "Es wurden " << this->flightBookings.size() << " Flugbuchungen mit einem Gesamtwert von " << maxFlightbookingValue <<  " Euro erfasst\n"
         << "Es wurden " << this->rentalCarReservations.size() << " Mietwagenbuchungen mit einem Gesamtwert von " << maxRentalCarReservationValue << " Euro erfasst\n"
         << "Es wurden " << this->hotelBookings.size() << " Hotelbuchungen mit einem Gesamtwert von " << maxHotelBookingsValue <<" Euro erfasst\n";

    cout << "Teuerste Flugbuchung (Id " << maxFB.getId() << "): Vom " << maxFB.getFromDate() << " bis " << maxFB.getToDate() << " von " << maxFB.getFromDest() <<
            " nach " << maxFB.getToDest() << " mit " << maxFB.getAirline() << " zum Preis von " << maxFB.getPrice() << " Euro.\n" <<
            "Teuerste Mietwagenbuchung (Id " << maxRC.getId() << "): Vom " << maxRC.getFromDate() << " bis " << maxRC.getToDate() << " von " << maxRC.getPickupLocation() <<
            " nach " << maxRC.getReturnLocation() << " mit " << maxRC.getCompany() << " zum Preis von " << maxRC.getPrice() << " Euro.\n" <<
            "Teuerste Hotelbuchung (Id " << maxHB.getId() << "): Vom " << maxHB.getFromDate() << " bis " << maxHB.getToDate() << " im " << maxHB.getHotel() <<
            " in " << maxHB.getTown() << " zum Preis von " << maxHB.getPrice() << " Euro.\n";
}
