#include "travelagency.h"
#include "graph.h"
#include "list.h"
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
    for(unsigned int i=0; i<= this->allBooking.Size()-1; i++){
        if(this->allBooking[i]->getId() > newID)
            newID = this->allBooking[i]->getId();
    }
    newID++;
    return newID;
}


// Getter
double TravelAgency::getTotalPrice() const { return totalPrice; }
List<Booking*> TravelAgency::getAllBooking() const { return allBooking; }
vector<Customer *> TravelAgency::getAllCustomers() const { return allCustomers; }
vector<Travel *> TravelAgency::getAllTravels() const { return allTravels; }
int TravelAgency::getNumberOfHotelBookings() const { return numberOfHotelBookings; }
int TravelAgency::getNumberOfRentalCarReservation() const { return numberOfRentalCarReservation; }
int TravelAgency::getNumberOfFlights() const { return numberOfFlights; }


// Setter
void TravelAgency::setAllCustomers(const vector<Customer *> &value) { allCustomers = value; }


// Finders
Booking* TravelAgency::findBooking(long id){
    for(unsigned int i=0; i<= this->allBooking.Size()-1; i++)
    {
        if(this->allBooking[i]->getId() == id)
            return this->allBooking[i];
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


int TravelAgency::createBooking( char type, double price, string start, string end, long travelID, vector<string> bookingDetails){
    bool travelExists = false, smoke = false;
    if(this->findTravel(travelID) != nullptr)
        travelExists = true;

    if(travelExists == false)
    {
        return -1;
    }else{
        vector<int> vorherigeBuchungen = {}; // TODO: Per GUI erfragen
        this->totalPrice += price;
        int id = GenerateNewID();
        if(type == 'F')
        {
            this->allBooking.InsertNode(new FlightBooking(id, price, start, end, travelID,
                                                          bookingDetails.at(0), bookingDetails.at(1),
                                                          bookingDetails.at(2), bookingDetails.at(3).at(0),
                                                          vorherigeBuchungen));
            this->numberOfFlights++;
        }else if(type == 'H'){
            if(bookingDetails.at(2) == "true")
                smoke = true;
            else
                smoke = false;
            this->allBooking.InsertNode(new HotelBooking(id, price, start, end, travelID,
                                                         bookingDetails.at(0), bookingDetails.at(1),
                                                         smoke, vorherigeBuchungen));
            this->numberOfHotelBookings++;
        }else if(type == 'R'){
            this->allBooking.InsertNode(new RentalCarReservation(id, price, start, end, travelID,
                                                                 bookingDetails.at(0), bookingDetails.at(1),
                                                                 bookingDetails.at(2), bookingDetails.at(3),
                                                                 vorherigeBuchungen));
            this->numberOfRentalCarReservation++;
        }
        return id;
    }
}

bool TravelAgency::readFile()
{
    ifstream quelle;
    string path = "C:/Users/thomas.trautwein/Desktop/PAD2-master/Praktikum5/Thomas/bookings_praktikum5.txt";
    //string path = "C:/Users/thomas.trautwein/Desktop/PAD2-master/Praktikum4/Thomas/bookings_praktikum4.txt";

    quelle.open(path.c_str(), ios::in);

    if(!quelle){
        cerr << "Die Datei " << path << " konnte nicht geöffnet werden";
        exit(-1);
    }else{
        string s,s2;
        int counter = 1;

        while(getline(quelle, s, '\n')){
            stringstream ss(s);

            vector<int> vorherigeBuchungen = {};
            unsigned int numNormalAttrs;
            switch (s.at(0)) {
                case 'F': numNormalAttrs = 12; break;
                case 'R': numNormalAttrs = 12; break;
                case 'H': numNormalAttrs = 11; break;
                default: throw runtime_error("Buchungsart ist nicht definiert");
            }

            try{
                vector<string> linedata;
                while(getline(ss, s2, '|')){

                    // Normale Attribute hinzufügen
                    if(linedata.size() < numNormalAttrs && s2 != ""){ linedata.push_back(s2); }

                    // Vorgaenger Buchungen hinzufügen
                    else if(linedata.size() >= numNormalAttrs && s2 != ""){ vorherigeBuchungen.push_back(stoi(s2)); }

                    // Wenn ein normales Attribut leer ist
                    else{ throw runtime_error("Ein Attribut ist leer"); }
                }

                DataConverter* ddata;
                int dataID;
                if(s.at(0) == 'F')
                {
                    numberOfFlights++;
                    FlightBooking* data = new FlightBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()),
                                                        linedata.at(3), linedata.at(4), stol(linedata.at(5)), linedata.at(8),
                                                        linedata.at(9), linedata.at(10), linedata.at(11).at(0), vorherigeBuchungen);
                    this->allBooking.InsertNode(data);
                    dataID = data->getId();
                    ddata = new DataConverter(data);
                }
                else if(s.at(0) == 'R')
                {
                    numberOfRentalCarReservation++;
                    RentalCarReservation* data = new RentalCarReservation(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()),
                                                                       linedata.at(3), linedata.at(4), stol(linedata.at(5)),
                                                                       linedata.at(8), linedata.at(9), linedata.at(10), linedata.at(11),
                                                                       vorherigeBuchungen);
                    this->allBooking.InsertNode(data);
                    dataID = data->getId();
                    ddata = new DataConverter(data);
                }
                else
                {
                    numberOfHotelBookings++;
                    HotelBooking* data = new HotelBooking(stol(linedata.at(1).c_str()), stod(linedata.at(2).c_str()),
                                                          linedata.at(3), linedata.at(4), stol(linedata.at(5)),
                                                          linedata.at(8), linedata.at(9), stoi(linedata.at(10)),
                                                          vorherigeBuchungen);
                    this->allBooking.InsertNode(data);
                    dataID = data->getId();
                    ddata = new DataConverter(data);
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

                //Überprüfe ob Travel vorhanden
                Travel trav;
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

                trav.addKnoten(dataID, ddata, vorherigeBuchungen);

            } catch(const std::exception& e){
                for(unsigned int i = 0; i<this->allBooking.Size()-1; i++)
                {
                    // Muss jeder Knoten mittels der Funktion gelöscht werden,
                    // da sonst leere Container noch verknüpft sind?
                    allBooking.DeleteNode();
                }

                QMessageBox msgBox;
                msgBox.setWindowTitle("Fehler");
                QString errorMessage = "Es ist ein Fehler aufgetreten. Fehlendes Attribut in Zeile " + QString::number(counter);
                msgBox.setText(errorMessage);
                msgBox.exec();
                return false;
            }
        }
        //Ordne allen Travels ihre Bookings zu Gesamtpreisberechnen
        for(Travel *t : this->allTravels)
        {
            t->topologischSortieren();

            for(unsigned int i=0; i<=this->allBooking.Size()-1;i++)
            {
                if(this->allBooking[i]->getTravelId() == t->getId()){
                    totalPrice += this->allBooking[i]->getPrice();
                    t->addBooking(this->allBooking[i]);
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
    QFile targetFile(targetName);

    if (!targetFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        cerr << "Die Datei " << &targetName << " konnte nicht erstellt werden";
        exit(-1);
    }else
    {
        QTextStream data(&targetFile);
        string line;
        Booking* b;
        for(unsigned int i=0; i<= this->allBooking.Size(); i++)
        {
            b = this->allBooking[i];

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
        }
    }
    targetFile.close();
}
