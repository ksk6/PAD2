#include "travel.h"

Travel::Travel()
{

}

Travel::Travel(long tid, long cid)
{
    this->id = tid;
    this->customerID = cid;
    this->graph = new Graph<DataConverter*, 200>;
}


// Getter
long Travel::getId() const { return id; }
long Travel::getCustomerID() const { return customerID; }
vector<Booking *> Travel::getTravelBookings() const { return travelBookings; }
Graph<DataConverter*, 200>* Travel::getGraph() const { return graph; }

// Setter
void Travel::setCustomerID(long value) { customerID = value; }
void Travel::setId(long value) { id = value; }
void Travel::setTravelBookings(const vector<Booking *> &value) { travelBookings = value; }
void Travel::setGraph(Graph<DataConverter*, 200>* g){ graph = g; }

void Travel::addBooking(Booking* booking){
    this->travelBookings.push_back(booking);
}

void Travel::addKnoten(int dataID, DataConverter *data, vector<int> vorherigeBuchungen){
    graph->insertVertex(dataID, data);

    if(vorherigeBuchungen.size() > 0){
        for(int id : vorherigeBuchungen){ graph->insertArc(dataID, id); }
    }
}
