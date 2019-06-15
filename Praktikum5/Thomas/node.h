#ifndef NODE_H
#define NODE_H
#include <booking.h>

class Node
{
public:
    Node(Booking* data);

    // Getter
    Node* GetNextNode();
    Node* GetPrevNode();
    Booking* GetData();

    // Setter
    void SetNextNode(Node* next);
    void SetPrevNode(Node* prev);
    void SetData(Booking* data);

private:
    Booking* data;
    Node* prev;
    Node* next;
};

#endif // NODE_H
