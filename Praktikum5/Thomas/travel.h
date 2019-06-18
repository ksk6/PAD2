#ifndef TRAVEL_H
#define TRAVEL_H
#include "algorithmen.cpp"
#include <booking.h>
#include <dataconverter.h>
#include <graph.h>
#include <heap.h>
#include <vector>

class Travel
{
public:
    Travel();
    Travel(long tid, long cid);
    void addBooking(Booking* booking);

    // Getter
    long getId() const;
    long getCustomerID() const;
    vector<Booking *> getTravelBookings() const;
    Graph<DataConverter*, 200>* getGraph() const;

    // Setter
    void setCustomerID(long value);
    void setId(long value);
    void setTravelBookings(const vector<Booking *> &value);
    void setGraph(Graph<DataConverter*, 200>* g);

    void addKnoten(int dataID, DataConverter* data, vector<int> vorherigeBuchungen);

    void topologischSortieren();
    bool checkRoundtrip();
    bool checkMissingHotel();
    bool checkNeedlessHotel();
    bool checkNeedlessRentalCar();

private:
    long id, customerID;
    vector<Booking*> travelBookings;
    Graph<DataConverter*, 200>* graph;
    node_data sortedArray[200];
};

#endif // TRAVEL_H
