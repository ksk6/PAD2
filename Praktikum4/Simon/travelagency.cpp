#include "travelagency.h"
#include <sstream>
#include <booking.h>
#include <flightbooking.h>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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
    bool travelExists = false, smoke = false;
    if(this->findTravel(travelID) != nullptr)
        travelExists = true;

    if(travelExists == false)
    {
        return -1;
    }else{
        this->totalPrice += price;
        int id = GenerateNewID();
        if(type == 'F')
        {
            this->allBooking.push_back(new FlightBooking(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2), bookingDetails.at(3).at(0)));
            this->numberOfFlights++;
        }else if(type == 'H'){
            if(bookingDetails.at(2) == "true")
                smoke = true;
            else
                smoke = false;
            this->allBooking.push_back(new HotelBooking(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1), smoke));
            this->numberOfHotelBookings++;
        }else if(type == 'R'){
            this->allBooking.push_back(new RentalCarReservation(id, price, start, end, travelID, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2), bookingDetails.at(3)));
            this->numberOfRentalCarReservation++;
        }
        return id;
    }
}

bool TravelAgency::readFile()
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
        int counter = 1;
        while(getline(quelle, s, '\n')){
            stringstream ss(s);
            try{
                vector<string> linedata;
                while(getline(ss, s2, '|')){
                    if(s2 == "")
                    {
                        throw runtime_error("Ein Attribut ist leer");
                    }
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
                counter++;
            } catch(const std::exception& e){
                for(Booking *b : this->allBooking){
                    delete b;
                }

                QMessageBox msgBox;
                msgBox.setWindowTitle("Fehler");
                QString errorMessage = "Es ist ein Fehler aufgetreten. Fehlendes Attribut in Zeile " + QString::number(counter);
                msgBox.setText(errorMessage);
                msgBox.exec();
                return false;
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
    return true;
}

void TravelAgency::writeFile(QString targetName){
    /*ofstream targetFile;
    targetFile.open(targetName.c_str());
    */
    //QString filename = QFileDialog::getSaveFileName(this, "Buchungen speichern", "", ".txt");
    QFile targetFile(targetName);

    if (!targetFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        cerr << "Die Datei " << &targetName << " konnte nicht erstellt werden";
        exit(-1);
    }else
    {
        QTextStream data(&targetFile);
        string line;
        for(Booking* b : this->allBooking)
        {
            Travel *t = this->findTravel(b->getTravelId());
            Customer *c = this->findCustomer(t->getCustomerID());
            if(b->getType() == 'F'){
                FlightBooking* f = dynamic_cast<FlightBooking*>(b);
                line = "F|" + to_string(f->getId()) + "|" + to_string(f->getPrice())
                        + "|" + f->getFromDate() + "|" + f->getToDate() + "|" + to_string(f->getTravelId()) + "|" +
                        to_string(c->getId()) + "|" + c->getName() + "|" + f->getFromDest() + "|" + f->getToDest()
                        + "|" + f->getAirline() + "|" + to_string(f->getSeatPref()) + "\n";
            }else if(b->getType() == 'R'){
                RentalCarReservation* r = dynamic_cast<RentalCarReservation*>(b);
                line = "R|" + to_string(r->getId()) + "|" + to_string(r->getPrice())
                        + "|" + r->getFromDate() + "|" + r->getToDate() + "|" + to_string(r->getTravelId()) + "|" +
                        to_string(c->getId()) + "|" + c->getName() + "|" + r->getPickupLocation() + "|" + r->getReturnLocation()
                        + "|" + r->getCompany() + "|" + r->getInsuranceType() + "\n";
            }else if(b->getType() == 'H'){
                HotelBooking* h = dynamic_cast<HotelBooking*>(b);
                line = "H|" + to_string(h->getId()) + "|" + to_string(h->getPrice())
                        + "|" + h->getFromDate() + "|" + h->getToDate() + "|" + to_string(h->getTravelId()) + "|" +
                        to_string(c->getId()) + "|" + c->getName() + "|" + h->getHotel() + "|" + h->getTown()
                        + "|" + to_string(h->getSmoke()) + "\n";
            }
            data << QString::fromStdString(line);
            //delete t;
            //delete c;
        }
    }
    targetFile.close();
}


