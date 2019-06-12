#ifndef NODE_H
#define NODE_H
#include <booking.h>
class Node{
public: Node(Booking* b)
        :b(b), previousNode(nullptr), nextNode(nullptr) { }
    Node* GetNextNode() const{return nextNode;}
    void SetNextNode(Node* nextNode) { this->nextNode= nextNode; }
    Node* GetPreviousNode() const{ return previousNode; }
    void SetPreviousNode(Node* previousNode) {
        this->previousNode= previousNode;
    }
    Booking* GetData() const{return b; }
    void SetData(Booking* b) { this->b= b;}
private:
    Booking* b;
    Node* previousNode;
    Node* nextNode;
};

#endif // NODE_H
