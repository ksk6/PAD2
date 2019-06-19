#include "travelagency.h"

#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

#include <iostream>
#include <iomanip>
#include <fstream>



using namespace std;



// ========================================================== CONSTRUCTORS ==========================================================



TravelAgency::TravelAgency(string name)
    : name(name)
{
}

TravelAgency::~TravelAgency()
{
    for(unsigned long long i = 0; i < allBookings.size(); i++) { // delete all bookings
        allBookings.deleteNode();
    }

    for(unsigned long long i = 0; i < allTravels.size(); i++) { // delete all travels
        allTravels.deleteNode();
    }
    allTravels.clear(); // clear travels vector

    for(Customer* c : allCustomers) { // delete all customer
        delete c;
    }
    allCustomers.clear(); // clear customer vector
}



// ========================================================== FIND BOOKING/TRAVEL/CUSTOMER ==========================================================



Booking* TravelAgency::findBooking(long bid)
{
    for(unsigned long long i = 0; i < allBookings.size(); i++) {
        if(allBookings[i]->getBid() == bid) return allBookings[i];
    }
    return nullptr;
}



Travel* TravelAgency::findTravel(long tid)
{
    for(unsigned long long i = 0; i < allTravels.size(); i++) {
        if(allTravels[i]->getTid() == tid) return allTravels[i];
    } return nullptr;
}



Customer* TravelAgency::findCustomer(long cid) const
{
    for(Customer* c : allCustomers) {
        if(c->getCid() == cid) return c;
    } return nullptr;
}



long TravelAgency::getNextBookingId()
{
    long x = 0;
    for(unsigned long long i = 0; i < allBookings.size(); i++) {
        if(allBookings[i]->getBid() > x) x = allBookings[i]->getBid();
    } return ++x;
}



// ========================================================== READ FILE ==========================================================



//READFILE Textdatei auslesen

void TravelAgency::readFile(const string &path)
{
    // Reset Counter
    setLastImportBookingCount(0);
    setLastImportCustomerCount(0);
    setLastImportTravelCount(0);
    setLastImportPriceTotal(0.0);

    // Einlesen
    ifstream bookings;
    bookings.open(path); // Fileinputstream öffnen

    if(bookings) { // Datei offen?

        string line;

        long rowcount = 0;

        while(getline(bookings, line)) { // einzelne Zeilen auslesen

            rowcount++;

            try {

                extractBooking(line);

            } catch(const char* msg) {

                QString err_msg = "[ERROR] ";
                err_msg.append(msg);
                err_msg.append(" in Zeile ");
                err_msg.append(QString::number(rowcount));
                err_msg.append("!");

                cout << err_msg.toStdString() << endl;

                QMessageBox errorBox;
                errorBox.critical(nullptr, "Fehler beim Importieren", err_msg);

                clearData();

                break;
            }

        }

    } else {
        cout << "[ERROR] File can not be opened or read!" << endl;
        return;
    }

    if(bookings.is_open()) bookings.close(); // schließen des Fileinputstreams

    countBookings(); countCustomer(); countTravels(); countPriceTotal();


    for(unsigned long long i = 0; i < allTravels.size(); i++) {
        //allTravels[i]->dependencies->deleteGraph();
        allTravels[i]->buildGraph();
    }

    // Test-Ausgabe
//    for(unsigned long long i = 0; i < allBookings.size(); i++) {
//        cout << allBookings[i]->getTid() << "||" << allBookings[i]->getBid() << endl;
//    }

    return;
}



// EXTRACT BOOKING

void TravelAgency::extractBooking(string line)
{
    vector<string> values = parser(line); // trennen der einzelnen strings

    // Prüfe Buchungstyp
    if(values.at(0) != "F" && values.at(0) != "H" && values.at(0) != "R") {
        throw("Unbekannter Buchungstyp");
    }

    // Setzen des Buchungstyps
    char type = values.at(0)[0];

    // Prüfe Anzahl der Attribute (bei unkorrekter Anzahl wird ein Fehler geworfen)
    switch(values.at(0)[0]) {
        case 'F': {
            if(values.size() < 12 || values.size() > 14)
                throw("Fehlendes Attribut");
            break;
        }
        case 'H': {
            if(values.size() < 11 || values.size() > 13)
                throw("Fehlendes Attribut");
            break;
        }
        case 'R': {
            if(values.size() < 12 || values.size() > 14)
                throw("Fehlendes Attribut");
            break;
        }
    }

    // Deklarieren & Initialisieren der allgemeinen Buchungs- und Kundendaten
    int     bid = stoi( values.at(1) ),
            tid = stoi( values.at(5) ),
            cid = stoi( values.at(6) );

    // Überspringen, wenn schon vorhanden
    if(findBooking(bid)) return;
    this->lastImportBookingCount++;

    double  price = stod( values.at(2) );
    this->lastImportPriceTotal = this->lastImportPriceTotal + price;

    string  name = values.at(7),
            dateFrom = values.at(3),
            dateTo = values.at(4),
            var1, var2, var3, var4,
            arc1, arc2;
    vector<string> arcs;

    // Zeiger auf Booking, Travel, Kunde
    Booking* booking = nullptr;
    Travel* travel;
    Customer* customer;

    // suchen
    customer = findCustomer(cid);
    travel = findTravel(tid);

    // falls nicht vorhanden, dann erstellen
    if(!customer) {
        this->lastImportCustomerCount++;
        allCustomers.push_back(
            customer = new Customer(cid, name)
        );
    }
    if(!travel) {
        this->lastImportTravelCount++;
        allTravels.insert(
            travel = new Travel(tid, cid)
        );
    }

    // Reise-Kunde Zuweisung
    customer->addTravel(travel); // Logik zum Vermeiden von Duplikaten in Customer::addTravel()


    // initialisieren der buchungsspezifischen Daten
    if(type == 'H') {
        var1 = values.at(8);
        var2 = values.at(9);
        var3 = values.at(10);
    } else {
        var1 = values.at(8);
        var2 = values.at(9);
        var3 = values.at(10);
        var4 = values.at(11);
    }

    // abhängigkeiten einfügen
    if(type == 'H' && values.size() > 11) {
        arc1 = values.at(11);
        arcs.push_back(arc1);
        if(values.size() == 13) {
            arc2 = values.at(12);
            arcs.push_back(arc2);
        }
    } else if(values.size() > 12) {
        arc1 = values.at(12);
        arcs.push_back(arc1);
        if(values.size() == 14) {
            arc2 = values.at(13);
            arcs.push_back(arc2);
        }
    }


    // Erstellen der Booking
    switch(type) {
    case 'F':
        allBookings.insert(
            booking = new FlightBooking(bid, tid, price, dateFrom, dateTo, arcs, var1, var2, var3, var4)
        ); break;
    case 'H':
        allBookings.insert(
            booking = new HotelBooking(bid, tid, price, dateFrom, dateTo, arcs, var1, var2, var3)
        ); break;
    case 'R':
        allBookings.insert(
            booking = new RentalCarReservation(bid, tid, price, dateFrom, dateTo, arcs, var1, var2, var3, var4)
        ); break;
    }

    // Buchung zur Reise hinzufügen
    travel->addBooking(booking);

}



// LINE PARSER zum Trennen der Werte anhand |



vector<string> TravelAgency::parser(string line)
{
    vector<string> values;
    string delimiter = "|", value;
    size_t pos = 0;
    while ((pos = line.find(delimiter)) != string::npos) {
        value = line.substr(0, pos);
        values.push_back(value);
        line.erase(0, pos + delimiter.length());
    }
    values.push_back(line);
    return values;
}



// ========================================================== FUNCTIONS ==========================================================



//int TravelAgency::createBooking(char type, double price, string start, string end, long travelId, vector<string> bookingDetails)
//{
//    // Prüfen ob Travel existiert
//    Travel* travel = findTravel(travelId);

//    if(!travel) {
//        cout << "Die Reise mit der ID " << travelId << " konnte nicht gefunden werden!" << endl;
//        return -1;
//    }

//    // Setze nächste BookingID
//    long bid = getNextBookingId();

//    Booking* booking;

//    // Erstellen der Buchung
//    switch(type) {
//    case 'F':
//        cout << "Creating Flightbooking..." << endl;
//        allBookings.push_back(
//            booking = new FlightBooking(bid, travelId, price, start, end, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2), bookingDetails.at(3))
//        ); break;
//    case 'H':
//        cout << "Creating Hotelbooking..." << endl;
//        allBookings.push_back(
//            booking = new HotelBooking(bid, travelId, price, start, end, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2))
//        ); break;
//    case 'R':
//        cout << "Creating Rentalcar Reservation..." << endl;
//        allBookings.push_back(
//            booking = new RentalCarReservation(bid, travelId, price, start, end, bookingDetails.at(0), bookingDetails.at(1), bookingDetails.at(2), bookingDetails.at(3))
//        ); break;
//    default:
//        cout << "[ERROR] (extractBooking) Unbekannter Booking-Type!" << endl;
//        return -1;
//    }

//    // Hinzufügen der Buchung
//    travel->addBooking(booking);

//    countBookings();
//    countPriceTotal();

//    return bid;
//}



void TravelAgency::createBooking(double price, long travelId, QDate start, QDate end,
                                 QString departure, QString arrival, QString airline, char seatPref, vector<string> arcs)
{
    // Prüfen ob Travel existiert
    Travel* travel = findTravel(travelId);

    if(!travel) {
        cout << "[ERROR] Die Reise mit der ID " << travelId << " konnte nicht gefunden werden!" << endl;
        QMessageBox::critical(nullptr, "Fehler beim hinzufügen der Buchung", "Die Reise mit der ID " + QString::number(travelId) + " konnte nicht gefunden werden!");
        return;
    }

    // Setze nächste BookingID
    long bid = getNextBookingId();

    string seatPrefStr(1, seatPref);

    Booking *booking = new FlightBooking(bid, travelId, price, start.toString("yyyyMMdd").toStdString(), end.toString("yyyyMMdd").toStdString(), arcs,
                                         departure.toStdString(), arrival.toStdString(), airline.toStdString(), seatPrefStr);

    cout << "SeatP: " << seatPrefStr << endl;
    cout << "SeatP: " << dynamic_cast<FlightBooking*>(booking)->getSeatPref() << endl;


    // Hinzufügen der Buchung
    allBookings.insert(booking);
    travel->addBooking(booking);

    // Graph neu erstellen
    travel->dependencies->deleteGraph();
    travel->buildGraph();

    countBookings();
    countPriceTotal();
}



void TravelAgency::createBooking(double price, long travelId, QDate start, QDate end,
                                 QString hotel, QString town, bool smoke, vector<string> arcs)
{
    // Prüfen ob Travel existiert
    Travel* travel = findTravel(travelId);

    if(!travel) {
        cout << "[ERROR] Die Reise mit der ID " << travelId << " konnte nicht gefunden werden!" << endl;
        QMessageBox::critical(nullptr, "Fehler beim hinzufügen der Buchung", "Die Reise mit der ID " + QString::number(travelId) + " konnte nicht gefunden werden!");
        return;
    }

    // Setze nächste BookingID
    long bid = getNextBookingId();

    // Variable 'smoke' in string umwandeln
    string smokeStr;
    if(smoke)
        smokeStr = "1";
    else
        smokeStr = "0";

    Booking *booking = new HotelBooking(bid, travelId, price, start.toString("yyyyMMdd").toStdString(), end.toString("yyyyMMdd").toStdString(), arcs,
                                         hotel.toStdString(), town.toStdString(), smokeStr);

    // Hinzufügen der Buchung
    allBookings.insert(booking);
    travel->addBooking(booking);

    // Graph neu erstellen
    travel->dependencies->deleteGraph();
    travel->buildGraph();

    countBookings();
    countPriceTotal();
}



void TravelAgency::createBooking(double price, long travelId, QDate start, QDate end,
                                 QString pickupLocation, QString returnLocation, QString company, QString insuranceType, vector<string> arcs)
{
    // Prüfen ob Travel existiert
    Travel* travel = findTravel(travelId);

    if(!travel) {
        cout << "[ERROR] Die Reise mit der ID " << travelId << " konnte nicht gefunden werden!" << endl;
        QMessageBox::critical(nullptr, "Fehler beim hinzufügen der Buchung", "Die Reise mit der ID " + QString::number(travelId) + " konnte nicht gefunden werden!");
        return;
    }

    // Setze nächste BookingID
    long bid = getNextBookingId();

    Booking *booking = new RentalCarReservation(bid, travelId, price, start.toString("yyyyMMdd").toStdString(), end.toString("yyyyMMdd").toStdString(), arcs,
                                         company.toStdString(), pickupLocation.toStdString(), returnLocation.toStdString(), insuranceType.toStdString());

    // Hinzufügen der Buchung
    allBookings.insert(booking);
    travel->addBooking(booking);

    // Graph neu erstellen
    travel->dependencies->deleteGraph();
    travel->buildGraph();

    countBookings();
    countPriceTotal();
}



void TravelAgency::clearData()
{
    setLastImportBookingCount(0);
    setLastImportCustomerCount(0);
    setLastImportTravelCount(0);
    setLastImportPriceTotal(0.0);

    allBookings.clear();
    allCustomers.clear();
    allTravels.clear();
}



QString TravelAgency::getConcatenatedData(Booking *b)
{
    QString data;

    if(FlightBooking* fb = dynamic_cast<FlightBooking*>(b)) {

        data = getConcMainData('F', b);
        data += fb->getQFromDest() + "|"
                + fb->getQToDest() + "|"
                + fb->getQAirline() + "|"
                + fb->getQSeatPref();

    } else if (HotelBooking* hb = dynamic_cast<HotelBooking*>(b)) {

        unsigned int smoke;
        if(hb->getSmoke())
            smoke = 1;
        else
            smoke = 0;

        data = getConcMainData('H', b);
        data += hb->getQHotel() + "|"
                + hb->getQTown() + "|"
                + QString::number(smoke);

    } else if (RentalCarReservation* rcr = dynamic_cast<RentalCarReservation*>(b)) {

        data = getConcMainData('R', b);
        data += rcr->getQPickupLocation() + "|"
                + rcr->getQReturnLocation() + "|"
                + rcr->getQCompany() + "|"
                + rcr->getQInsuranceType();

    }

    return data;
}



QString TravelAgency::getConcMainData(const char &type, Booking *b)
{
    QString data;

    data = QString(QChar(type)) + "|"
           + QString::number(b->getBid()) + "|"
           + QString::number(b->getPrice()) + "|"
           + b->getQDateFrom().toString("yyyyMMdd") + "|"
           + b->getQDateTo().toString("yyyyMMdd") + "|"
           + QString::number(b->getTid()) + "|"
           + QString::number(findTravel(b->getTid())->getCid()) + "|"
           + findCustomer(findTravel(b->getTid())->getCid())->getQName() + "|";

    return data;
}



// ========================================================== EVALUATION ==========================================================



// Anzahl Bookings

void TravelAgency::countBookings()
{
    long bCount = static_cast<long>(allBookings.size());
    long fCount = 0, hCount = 0, rCount = 0;

    for(unsigned long long i = 0; i < allBookings.size(); i++) {
        if(dynamic_cast<FlightBooking*>(allBookings[i]))
            fCount++;

        if(dynamic_cast<HotelBooking*>(allBookings[i]))
            hCount++;

        if(dynamic_cast<RentalCarReservation*>(allBookings[i]))
            rCount++;
    }

    setBookingsCount(bCount);
    setFlightbookingCount(fCount);
    setHotelbookingCount(hCount);
    setRentalcarresCount(rCount);
}

// Gesamtpreis aller Buchungen
void TravelAgency::countPriceTotal()
{
    double total = 0.0;

    for(unsigned long long i = 0; i < allBookings.size(); i++) {
        total += allBookings[i]->getPrice();
    }

    setPriceTotal(total);
}

// Anzahl Reisen
void TravelAgency::countTravels()
{
    setTravelCount(static_cast<long>(allTravels.size()));
}

// Anzahl Kunden
void TravelAgency::countCustomer()
{
    setCustomerCount(static_cast<long>(allCustomers.size()));
}



// ========================================================== PRINTS ==========================================================



void TravelAgency::printBookingsInfo() const
{
    cout << "Es wurden " <<
            this->getFlightbookingCount() << " Flugbuchungen, " <<
            this->getHotelbookingCount() << " Hotebuchungen und " <<
            this->getRentalcarresCount() << " Mietwagenreservierungen " <<
            "im Gesamtwert von " << getPriceTotal() << " EURO eingelesen." <<
            endl;
}

void TravelAgency::printTravelCustomerInfo() const
{
    cout << "Es wurden " << getTravelCount() << " Reisen und " << getCustomerCount() << " Kunden angelegt." << endl;
}

void TravelAgency::printCustomerTravelsCount(long cid) const
{
    for(Customer* c : allCustomers) {
        if(c->getCid() == cid) {
            cout << "Der Kunde mit der ID " << cid << " hat " << c->getTravelCount() << " Reisen gebucht." << endl;
            return;
        }
    }
    cout << "Der Kunde mit der ID " << cid << " existiert nicht!" << endl;
}

void TravelAgency::printTravelBookingsCount(long tid)
{
    for(unsigned long long i = 0; i < allTravels.size(); i++) {
        if(allTravels[i]->getTid() == tid) {
            cout << "Zur Reise mit der ID " << tid << " gehoeren " << allTravels[i]->getBookingsCount() << " Buchungen." << endl;
            return;
        }
    }
    cout << "Die Reise mit der ID " << tid << " existiert nicht!" << endl;
}



// ========================================================== UNIT TESTS ==========================================================



long TravelAgency::countRentalCarReservationsOfCompany(const QString &value)
{
    long count = 0;

    for(unsigned long long i = 0; i < allBookings.size(); i++) {

        if(RentalCarReservation* rcr = dynamic_cast<RentalCarReservation*>(allBookings[i]))
            if(rcr->getQCompany() == value)
                count++;

    }

    return count;
}



long TravelAgency::countFlightBookingsOfAirline(const QString &value)
{
    long count = 0;

    for(unsigned long long i = 0; i < allBookings.size(); i++) {

        if(FlightBooking* fb = dynamic_cast<FlightBooking*>(allBookings[i]))
            if(fb->getQAirline() == value)
                count++;

    }

    return count;
}



long TravelAgency::countBookingsMinPrice(const double &value)
{
    long count = 0;

    for(unsigned long long i = 0; i < allBookings.size(); i++) {

        if(allBookings[i]->getPrice() >= value)
            count++;

    }

    return count;
}



// ========================================================== GETTER/SETTER ==========================================================



string TravelAgency::getName() const
{
    return name;
}

long TravelAgency::getFlightbookingCount() const
{
    return flightbookingCount;
}

void TravelAgency::setFlightbookingCount(long value)
{
    flightbookingCount = value;
}

long TravelAgency::getHotelbookingCount() const
{
    return hotelbookingCount;
}

void TravelAgency::setHotelbookingCount(long value)
{
    hotelbookingCount = value;
}

long TravelAgency::getRentalcarresCount() const
{
    return rentalcarresCount;
}

void TravelAgency::setRentalcarresCount(long value)
{
    rentalcarresCount = value;
}

long TravelAgency::getBookingsCount() const
{
    return bookingsCount;
}

void TravelAgency::setBookingsCount(long value)
{
    bookingsCount = value;
}

double TravelAgency::getPriceTotal() const
{
    return priceTotal;
}

void TravelAgency::setPriceTotal(double value)
{
    priceTotal = value;
}

long TravelAgency::getTravelCount() const
{
    return travelCount;
}

void TravelAgency::setTravelCount(long value)
{
    travelCount = value;
}

long TravelAgency::getCustomerCount() const
{
    return customerCount;
}

void TravelAgency::setCustomerCount(long value)
{
    customerCount = value;
}

Travel *TravelAgency::getTravel(Booking *b)
{
    for(unsigned long long i = 0; i < allTravels.size(); i++) {
        if(allTravels[i]->getTid() == b->getTid()) return allTravels[i];
    }
    return nullptr;
}

Customer *TravelAgency::getCustomer(Booking *b)
{
    for(Customer* c : allCustomers) {
        if(c->getCid() == getTravel(b)->getCid()) return c;
    }
    return nullptr;
}

long TravelAgency::getLastImportBookingCount() const
{
    return lastImportBookingCount;
}

void TravelAgency::setLastImportBookingCount(long value)
{
    lastImportBookingCount = value;
}

long TravelAgency::getLastImportTravelCount() const
{
    return lastImportTravelCount;
}

void TravelAgency::setLastImportTravelCount(long value)
{
    lastImportTravelCount = value;
}

long TravelAgency::getLastImportCustomerCount() const
{
    return lastImportCustomerCount;
}

void TravelAgency::setLastImportCustomerCount(long value)
{
    lastImportCustomerCount = value;
}

double TravelAgency::getLastImportPriceTotal() const
{
    return lastImportPriceTotal;
}

void TravelAgency::setLastImportPriceTotal(double value)
{
    lastImportPriceTotal = value;
}
