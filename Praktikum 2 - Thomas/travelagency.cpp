#include "travelagency.h"

TravelAgency::TravelAgency()
{

}

///
/// \brief Generiert eine neue ID
/// \return
///
int TravelAgency::GenerateNewID(){
    int newID = 0;
    for(Booking *b : this->allBooking){
        if(b->getId() > newID)
            newID = b->getId();
    }
    newID++;
    return newID;
}


// ---------- Getter ---------- //
double TravelAgency::getTotalPrice() const { return totalPrice; }

int TravelAgency::getNumberOfHotelBookings() const { return numberOfHotelBookings; }

int TravelAgency::getNumberOfRentalCarReservation() const { return numberOfRentalCarReservation; }

int TravelAgency::getNumberOfFlights() const { return numberOfFlights; }



bool TravelAgency::idExists(long travelID){
    for(Travel *t : this->allTravels)
    {
        if(t->getId() == travelID) { return true; }
    }
    return false;
}

int TravelAgency::createBooking(char type, double price, string start, string end,
                                long travelID, vector<string> bookingDetails){
    if(idExists(travelID) == false)
    {
        return -1;
    }
    else
    {
        int id = GenerateNewID();
        this->totalPrice += price;

        if(type == 'f')
        {
            this->allBooking.push_back(new FlightBooking(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2)));
            this->numberOfFlights++;
        }
        else if(type == 'h')
        {
            this->allBooking.push_back(new HotelBooking(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1)));
            this->numberOfHotelBookings++;
        }
        else if(type == 'r')
        {
            this->allBooking.push_back(new RentalCarReservation(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2)));
            this->numberOfRentalCarReservation++;
        }
        else
        {
            // Fehlermeldung
            return -1;
        }
        return id;
    }
}


void TravelAgency::readFile()
{
    ifstream quelle;
    string path = "booking.txt";

    quelle.open(path.c_str(), ios::in);

    if(!quelle)
    {
        cerr << "Die Datei " << path << " konnte nicht geöffnet werden";
        exit(-1);
    }
    else
    {
        Customer customer;
        Travel travel;
        string line, linepart;
        //int counter;

        // Daten einlesen
        while(getline(quelle, line, '\n')){
            stringstream lineSS(line);

            vector<string> linedata;
            while(getline(lineSS, linepart, '|')){
                linedata.push_back(linepart);
            }

            //
            if(line.at(0) == 'F')
            {
                //FlightBooking fb(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9), linedata.at(10));
                //maxFlightbookingValue += fb.getPrice();
                numberOfFlights++;
                this->allBooking.push_back(new FlightBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9), linedata.at(10)));
            }
            else if(line.at(0) == 'R')
            {
                //RentalCarReservation RcR(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9), linedata.at(10));
                //maxRentalCarReservationValue += RcR.getPrice();
                numberOfRentalCarReservation++;
                this->allBooking.push_back(new RentalCarReservation(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9), linedata.at(10)));
            }
            else if(line.at(0) == 'H')
            {
                //HotelBooking hb(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9));
                //maxHotelBookingsValue += hb.getPrice();
                numberOfHotelBookings++;
                this->allBooking.push_back(new HotelBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9)));
            }

            //Überprüfe, ob Customer vorhanden ist
            bool customerExists = false;
            for(Customer *c : this->allCustomers)
            {
                if(c->getId() == stol(linedata.at(6)))
                {
                    customer = *c;
                    customerExists = true;
                }
            }

            // Falls der Customer nicht vorhanden ist, neuen anlegen
            if(customerExists == false){
                this->allCustomers.push_back(new Customer(stol(linedata.at(6)), linedata.at(7)));
            }

            //Überprüfe ob Travel vorhanden
            bool travelExists = false;
            for(Travel *t : this->allTravels)
            {
                if(t->getId() == stol(linedata.at(5)))
                {
                    travel = *t;
                    travelExists = true;
                }
            }

            // Falls der Travel nicht vorhanden ist, neuen anlegen
            if(travelExists == false){
                this->allTravels.push_back(new Travel(stol(linedata.at(5)), stol(linedata.at(6))));
                travel = *this->allTravels.at(this->allTravels.size()-1);
            }
        }

        // Zum Testen
        unsigned int testTravel = 17;
        unsigned int testCustomer = 1;
        unsigned int numberOfBookingsOfTestTravel = 0;
        unsigned int numberOfTravelsOfTestCustomer = 0;

        //Ordne allen Travels ihre Bookings zu
        //Gesamtpreisberechnen
        for(Travel *t : this->allTravels)
        {
            for(Booking *b : this->allBooking)
            {
                totalPrice += b->getPrice();
                if(b->getTravelId() == t->getId())
                    t->addBooking(b);
            }
        }

        //Loop durch customers für jeden Customer suche Travel
        for(Customer *c : this->allCustomers)
        {
            for(Travel *t : this->allTravels)
            {
                if(t->getCustomerID() == c->getId())
                    c->addTravel(t);
            }
        }

        for(Customer *c : this->allCustomers)
        {
            if(c->getId() == testCustomer) { numberOfTravelsOfTestCustomer = c->getTravelList().size(); }
        }

        for(Travel *t : this->allTravels)
        {
            if(t->getId() == testTravel) { numberOfBookingsOfTestTravel = t->getTravelBookings().size(); }
        }

        // Informationsausgabe
        cout << "Es wurden " << numberOfFlights << " Flugbuchungen, " << numberOfRentalCarReservation << " Mietwagenbuchungen und " << numberOfHotelBookings << " Hotelbuchungen mit einem Gesamtwert von " << long(totalPrice)<< " Euro erfasst\n";
        cout << "----------------------------------- Alle Reisen -----------------------------" << endl;
        for(Travel *t : this->allTravels)
        {
            cout << "Reisenr.: " << t->getId() << " vom Kunden mit der ID " << t->getCustomerID() << " beinhaltet " << t->getTravelBookings().size() << " Buchungen" << endl;
        }

        cout << "----------------------------------- Alle Kunden -----------------------------" << endl;
        for(Customer *c : this->allCustomers)
        {
            cout << c->getName() << " hat die ID " << c->getId() << " und hat " << c->getTravelList().size() << " Reisen gebucht " << endl;
        }
        cout << "Der Kunde mit der ID " << testCustomer << " hat " << numberOfTravelsOfTestCustomer << " Reisen gebucht" << endl;
        cout << "Die Reise mit der ID " << testTravel << " hat " << numberOfBookingsOfTestTravel << " Buchungen" << endl;
    }

    quelle.close();
}
