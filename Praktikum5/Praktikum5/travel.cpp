#include "travel.h"



// --------------------------------- CONSTRUCTORS ---------------------------------



Travel::Travel()
{

}



// --------------------------------- FUNCTIONS ---------------------------------



bool Travel::findBooking(long bid) const
{
    for(Booking* b : travelBookings) {
        if(b->getBid() == bid) return true;
    }
    return false;
}



void Travel::addBooking(Booking* booking) {
    if(!findBooking(booking->getBid())) travelBookings.push_back(booking);
}

int Travel::getBookingsCount() const
{
    return static_cast<int>(travelBookings.size());
}



void Travel::buildGraph()
{
    // Knoten einfügen
    for(Booking* b : travelBookings) {
        dependencies->insertVertex(b->getBid(), b);
    }

    // Kanten (Abhängigkeiten) einfügen
    for(Booking* b : travelBookings) {
        if(b->getArc1() != -1) {
            dependencies->insertArc(b->getArc1(), b->getBid(), 0);
        }
        if(b->getArc2() != -1) {
            dependencies->insertArc(b->getArc2(), b->getBid(), 0);
        }
    }

    cout << endl << "== Travel: " << getTid() << " ===========================================================================================" << endl << endl;
    cout.flush();

    // Tiefensuche & Topologische Sortierung
    cout << endl << ">>> SCHRITTE DER DFS <<<" << endl;
    DepthFirstSearch(*dependencies);


    cout << endl << "Anzahl Buchungen (Knoten): " << dependencies->getNumVertices() << endl;


    vector<node> nodes;

    for(int i = 0; i < dependencies->getNumVertices(); i++) {
        long n_bid = travelBookings.at(i)->getBid();
        node n;
        n.booking = dependencies->getVertexValue(n_bid);
        n.end = dependencies->getEnd(n_bid);

        nodes.push_back(n);
    }

    // Sortieren und in vector nodes einfügen
    int i, j;
    node key;

    // insertion-sort
    for (i = 1; i < dependencies->getNumVertices(); i++) {
        key = nodes.at(i);
        j = i - 1;

        while (j >= 0 && nodes.at(j).end < key.end) {
            nodes.at(j + 1) = nodes.at(j);
            j = j - 1;
        }
        nodes.at(j + 1) = key;
    }


            // Ausgabe nodes sortiert (TEST)
            cout << endl << ">>> NODES SORTIERT <<<" << endl;
            for(int i=0; i < dependencies->getNumVertices(); i++) {
                cout << "BookingID (Nummer): " << setw(5) << nodes.at(i).booking->getBid()
                     << "    |    " << "Ende: " << setw(5) << nodes.at(i).end
                     << "    |    " << "Buchungstyp:  " << left << setw(22) << nodes.at(i).booking->getBookingType()
                     << endl;
            }

            // Ausgabe (TEST)
            cout << endl << ">>> TRAVELBOOKINGS UNSORTIERT <<<" << endl;
            for(Booking* b : travelBookings) {
                cout << "BookingID (Nummer): " << setw(5) << b->getBid()
                     << "    |    " << "Buchungstyp:  " << left << setw(22) << b->getBookingType()
                     << endl;
            }

    // Sortierte Nodes in vector travelBookings kopieren
    travelBookings.clear(); // zuerst leeren
    for(node n : nodes) {
        travelBookings.push_back(n.booking);
    }

            // Ausgabe (TEST)
            cout << endl << ">>> TRAVELBOOKINGS SORTIERT <<<" << endl;
            for(Booking* b : travelBookings) {
                cout << "BookingID (Nummer): " << setw(5) << b->getBid()
                     << "    |    " << "Buchungstyp:  " << left << setw(22) << b->getBookingType()
                     << endl;
                cout.flush();
            }

    //cout << "CheckRoundTrip: " << checkRoundtrip(); // TEST

}



// --------------------------------- CHECK FUNCTIONS ------------------------------------



bool Travel::checkRoundtrip() //Startflughafen einer Reise mit letztem Zielflughafen vergleichen
{
    FlightBooking *start = nullptr;
    FlightBooking *end = nullptr;

    // Erste FlightBooking bekommen
    for(Booking* b : travelBookings) {
        if(FlightBooking * fb = dynamic_cast<FlightBooking*>(b)) {
            start = fb;
            break;
        }
    }

    // Letzte FlightBooking bekommen
    for(int i = (travelBookings.size() - 1); i >= 0; i--) {
        if(FlightBooking * fb = dynamic_cast<FlightBooking*>(travelBookings.at(i))) {
            end = fb;
            break;
        }
    }

    // Start- und Endflughafen vergleichen
    if(start && end && start->getFromDest() == end->getToDest()) {
        return true;
    } else {
        return false;
    }

}


bool Travel::checkMissingHotel()
{
    Booking *last = nullptr;
    bool check = true;

    for(Booking *b : travelBookings) {
        if(!dynamic_cast<RentalCarReservation*>(b)) {

            if(last && last->getToDate() < b->getFromDate()) {
                check = false;
                break;
            }

            last = b;

        } else {
            continue;
        }
    }

    return check;
}


bool Travel::checkNeedlessHotel()
{
    Booking *last = nullptr;
    bool check = true;

    for(Booking *b : travelBookings) {
        if(!dynamic_cast<RentalCarReservation*>(b)) {

            if(last && last->getToDate() > b->getFromDate()) {
                check = false;
                break;
            }

            last = b;

        } else {
            continue;
        }
    }

    return check;
}


bool Travel::checkNeedlessRentalCar()
{
    Booking *last = nullptr;
    bool check = true;

    for(Booking *b : travelBookings) {
        if(!dynamic_cast<HotelBooking*>(b)) {

            if(last && last->getToDate() > b->getFromDate()) {
                check = false;
                break;
            }

            last = b;

        } else {
            continue;
        }
    }

    return check;
}



// --------------------------------- GETTER/SETTER ---------------------------------



long Travel::getTid() const
{
    return tid;
}

void Travel::setTid(long value)
{
    tid = value;
}

long Travel::getCid() const
{
    return cid;
}

void Travel::setCid(long value)
{
    cid = value;
}
