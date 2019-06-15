#include "node.h"

Node::Node(Booking* data)
{
    this->data = data; // Inhalt
    prev = nullptr;    // Verweis auf vorherigen Node
    next = nullptr;    // Verweis auf nächsten Node
}


// ----- Getter -----
Node* Node::GetNextNode(){ return next; }
Node* Node::GetPrevNode(){ return prev; }
Booking* Node::GetData(){ return data; }


// ----- Setter -----
void Node::SetNextNode(Node* next){ this->next = next; }
void Node::SetPrevNode(Node* prev){ this->prev = prev; }
void Node::SetData(Booking* data){ this->data = data; }
