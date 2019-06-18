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
        for(int id : vorherigeBuchungen){
            graph->insertArc(dataID, id);
        }
    }

    graph->printVertices();
}



void Travel::topologischSortieren(){
    DepthFirstSearch(*graph);
    vector<node_data> ndata = vector<node_data>();

    for (int i = 0; i < 200; i++) {

        DataConverter* ddata = graph->getVertexValue(i);
        string bezeichner = "";

        if(ddata != nullptr){
            switch (ddata->bookingArt) {
                case BookingArt::FLIGHT: bezeichner = to_string(ddata->fData->getId()); break;
                case BookingArt::HOTEL: bezeichner = to_string(ddata->hData->getId()); break;
                case BookingArt::CAR: bezeichner = to_string(ddata->rData->getId()); break;
            }
        }

        if(bezeichner != ""){
            node_data node = node_data();
            node.i = stoi(bezeichner); //i
            node.bezeichner = bezeichner;
            node.end = graph->getEnd(i);
            ndata.push_back(node);
            //sortedArray[i].i = i;
            //sortedArray[i].bezeichner = bezeichner;
            //sortedArray[i].end = graph->getEnd(i);
        }
    }

    int a = 0;
    //Heap heap = Heap(sortedArray, 200);
}

bool Travel::checkRoundtrip(){

}

bool Travel::checkMissingHotel(){

}

bool Travel::checkNeedlessHotel(){

}

bool Travel::checkNeedlessRentalCar(){

}
