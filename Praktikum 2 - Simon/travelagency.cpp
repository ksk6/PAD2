#include "travelagency.h"
#include <sstream>
#include <booking.h>
#include <flightbooking.h>
#include <iomanip>

TravelAgency::TravelAgency()
{

}

int TravelAgency::GenerateNewID(){
    int newID = 0;
    for(Booking *b : this->allBooking){
        if(b->getId() > newID)
            newID = b->getId();
    }
    newID++;
    return newID;
}

double TravelAgency::getTotalPrice() const
{
    return totalPrice;
}

int TravelAgency::getNumberOfHotelBookings() const
{
    return numberOfHotelBookings;
}

int TravelAgency::getNumberOfRentalCarReservation() const
{
    return numberOfRentalCarReservation;
}

int TravelAgency::getNumberOfFlights() const
{
    return numberOfFlights;
}

int TravelAgency::createBooking( char type, double price, string start, string end, long travelID, vector<string> bookingDetails){
    bool travelExists = false;
    for(Travel *t : this->allTravels)
    {
        if(t->getId() == travelID)
        {
            travelExists = true;
            break;
        }
    }

    if(travelExists == false)
    {
        return -1;
    }else{
        this->totalPrice += price;
        int id = GenerateNewID();
        if(type == 'f')
        {
            this->allBooking.push_back(new FlightBooking(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2)));
            this->numberOfFlights++;
        }else if(type == 'h'){
            this->allBooking.push_back(new HotelBooking(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1)));
            this->numberOfHotelBookings++;
        }else if(type == 'r'){
            this->allBooking.push_back(new RentalCarReservation(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2)));
            this->numberOfRentalCarReservation++;
        }
        return id;
    }
}

void TravelAgency::readFile()
{
    ifstream quelle;
    string path = "booking.txt";

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

            vector<string> linedata;
            while(getline(ss, s2, '|')){
                linedata.push_back(s2);
            }


            if(s.at(0) == 'F')
            {
                numberOfFlights++;
                this->allBooking.push_back(new FlightBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9), linedata.at(10)));
            }
            else if(s.at(0) == 'R')
            {
                numberOfRentalCarReservation++;
                this->allBooking.push_back(new RentalCarReservation(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9), linedata.at(10)));
            }else if(s.at(0) == 'H')
            {
                numberOfHotelBookings++;
                this->allBooking.push_back(new HotelBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()), linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8), linedata.at(9)));
            }
            Customer cus;
            //Überprüfe ob Customer vorhanden
            bool cusExists = false;
            for(Customer *c : this->allCustomers)
            {
                if(c->getId() == stol(linedata.at(6)))
                {
                    cus = *c;
                    cusExists = true;
                }
            }

            if(cusExists == false){
                this->allCustomers.push_back(new Customer(stol(linedata.at(6)), linedata.at(7)));
            }


            Travel trav;
            //Überprüfe ob Customer vorhanden
            bool travelExists = false;
            for(Travel *t : this->allTravels)
            {
                if(t->getId() == stol(linedata.at(5)))
                {
                    trav = *t;
                    travelExists = true;
                }
            }

            if(travelExists == false){
                this->allTravels.push_back(new Travel(stol(linedata.at(5)), stol(linedata.at(6))));
                trav = *this->allTravels.at(this->allTravels.size()-1);
            }
        }
        //Ordne allen Travels ihre Bookings zu
        //Gesamtpreisberechnen
        unsigned int numberOfBookingsOfTrav17 = 0;
        totalPrice = 0.0;
        for(Travel *t : this->allTravels)
        {
            for(Booking *b : this->allBooking)
            {
                if(b->getTravelId() == t->getId())
                {
                    t->addBooking(b);
                    totalPrice += b->getPrice();
                }
            }
        }

        unsigned int numberOfTravelsOfCus1 = 0;
        //Loop durch cus für jeden Cus suche Travel
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
            if(c->getId() == 1)
                numberOfTravelsOfCus1 = c->getTravelList().size();
        }

        for(Travel *t : this->allTravels)
        {
            if(t->getId() == 17)
                numberOfBookingsOfTrav17 = t->getTravelBookings().size();
        }
        //totalPrice = CalculateTotal();
        cout << "Es wurden " << numberOfFlights << " Flugbuchungen, " << numberOfRentalCarReservation << " Mietwagenbuchungen und " << numberOfHotelBookings << " Hotelbuchungen mit einem Gesamtwert von " << totalPrice << " Euro erfasst\n";
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

        cout << "----------------------------------- Kunden mit der ID 1 -----------------------------" << endl;
        cout << "Der Kunde mit der ID 1 hat " << numberOfTravelsOfCus1 << " Reisen gebucht" << endl;
        cout << "----------------------------------- Reise mit der ID 17 -----------------------------" << endl;
        cout << "Die Reise mit der ID 17 hat " << numberOfBookingsOfTrav17 << " Buchungen" << endl;

    }
    quelle.close();
}


