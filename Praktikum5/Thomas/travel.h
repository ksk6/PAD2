#ifndef TRAVEL_H
#define TRAVEL_H
#include <booking.h>
#include <dataconverter.h>
#include <graph.h>
#include <vector>


class Travel
{
public:
    Travel();
    Travel(long tid, long cid, Graph<DataConverter*, 200>* g);
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

private:
    long id, customerID;
    vector<Booking*> travelBookings;
    Graph<DataConverter*, 200>* graph;
};

#endif // TRAVEL_H
