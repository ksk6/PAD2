#include "travelagency.h"
#include <sstream>
#include <booking.h>
#include <flightbooking.h>

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

Booking* TravelAgency::findBooking(long id){
    for(Booking *b : this->allBooking)
    {
        if(b->getId() == id)
            return b;
    }
    return nullptr;
}

Travel* TravelAgency::findTravel(long id){
    for(Travel *t : this->allTravels)
    {
        if(t->getId() == id)
            return t;
    }
    return nullptr;
}

Customer* TravelAgency::findCustomer(long id){
    for(Customer *c : this->allCustomers)
    {
        if(c->getId() == id)
            return c;
    }
    return nullptr;
}
double TravelAgency::getTotalPrice() const
{
    return totalPrice;
}

vector<Booking *> TravelAgency::getAllBooking() const
{
    return allBooking;
}

void TravelAgency::setAllCustomers(const vector<Customer *> &value)
{
    allCustomers = value;
}

vector<Customer *> TravelAgency::getAllCustomers() const
{
    return allCustomers;
}

vector<Travel *> TravelAgency::getAllTravels() const
{
    return allTravels;
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
                //FlightBooking::FlightBooking(long id, double price, string fromDate, string toDate, long travelID, string fromDest, string toDest, string airline, char seatPref){
                this->allBooking.push_back(new FlightBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()),
                                                             linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8),
                                                             linedata.at(9), linedata.at(10), linedata.at(11).at(0)));
            }
            else if(s.at(0) == 'R')
            {
                numberOfRentalCarReservation++;
                this->allBooking.push_back(new RentalCarReservation(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()),
                                                                    linedata.at(3), linedata.at(4), stol(linedata.at(5)),
                                                                    linedata.at(8), linedata.at(9), linedata.at(10), linedata.at(11)));
            }else if(s.at(0) == 'H')
            {
                numberOfHotelBookings++;
                this->allBooking.push_back(new HotelBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()),
                                                            linedata.at(3), linedata.at(4), stol(linedata.at(5)),
                                                            linedata.at(8), linedata.at(9), stoi(linedata.at(10))));
            }
            //Überprüfe ob Customer vorhanden
            Customer cus;
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
        for(Travel *t : this->allTravels)
        {
            for(Booking *b : this->allBooking)
            {
                if(b->getTravelId() == t->getId()){
                    totalPrice += b->getPrice();
                    t->addBooking(b);
                }
            }
        }

        //Loop durch cus für jeden Cus suche Travel
        for(Customer *c : this->allCustomers)
        {
            for(Travel *t : this->allTravels)
            {
                if(t->getCustomerID() == c->getId())
                    c->addTravel(t);
            }
        }
    }
    quelle.close();
}


