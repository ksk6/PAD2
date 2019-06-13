#ifndef LIST_H
#define LIST_H

#include <node.h>
template <class T>
class List{};

template <>
class List <Booking*>{
public:
    List();

    void insertNode(Booking* booking);

    bool isAtEnd() {
        return (cursor == end);
    }

    void step_back() {
        if (cursor && cursor->GetPreviousNode()) {
            cursor = cursor->GetPreviousNode();
            cerr << "Cursor zurückgeschoben auf " << cursor << endl;
        } else
            cerr << "Cursor ist schon am Anfang " << endl;
    }

    void advance() {
        if (cursor && cursor->GetNextNode()) {
            cursor = cursor->GetNextNode();
            // cerr << "Cursor weitergeschoben auf " << cursor << endl;
        } else
            //  cerr << "Cursor ist schon am Ende " << endl
            ;
    }

    void deleteNode();

    Booking* getNode() {
        return cursor->GetData();
    }

    void reset() {
        cursor = root;
        cerr << "Cursor zurueckgesetzt auf root" << endl;
    }

    //Operatorüberladung
    Booking* operator[](unsigned int i);
    Booking* at(unsigned int i);

    unsigned int  size();




protected:
    Node* root;
    Node* cursor;
    Node* end;
public:

    size_t numElements = 0;
};

#endif // LIST_H
