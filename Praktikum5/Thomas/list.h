#ifndef LIST_H
#define LIST_H
#include <booking.h>
#include <node.h>

template <class T>
class List{};

template <>
class List<Booking*>
{
public:
    List();

    void InsertNode(Booking* data);
    void DeleteNode();
    Booking* GetNode();
    bool IsAtEnd();
    void Advance();
    void Back();
    void Reset();

    Booking* operator[](int i);
    Booking* at(int i);

    size_t Size();
    size_t numElements = 0;

protected:
    Node* root;
    Node* cursor;
    Node* end;
};

#endif // LIST_H
