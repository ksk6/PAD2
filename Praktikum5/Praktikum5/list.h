#ifndef LIST_H
#define LIST_H



#include <stdexcept>

#include "node.h"
#include <iostream>



template<typename T> class List
{

public:

    // constructor
    List() {
        root = nullptr;
        end = new Node<T>(nullptr);
        cursor = end;
    }

    // functions

    void insert(T data) {

        // Speicherplatz reservieren
        Node<T> *node = new Node<T>(data);

        // wenn Liste leer
        if(root == nullptr) {

            root = node;
            node->setNextNode(end); // setze Nachfolger des neuen Knotens
            end->setPreviousNode(node); // setze Vorgänger des neuen Knotens

        // ansonsten, wenn Liste nicht leer
        } else {

            reset();
            // Finde richtige Position ( sequenzielle Suche )
            while(!isAtEnd()) {
                if(data->getTid() < cursor->getData()->getTid()) {
                    break;
                } else
                if(cursor->getNextNode() != end && data->getTid() <= cursor->getNextNode()->getData()->getTid()) { // <============ METHODE MUSS VORHANDEN SEIN !!! Als Funktionszeiger übergeben? Und wie???
                    advance();
                    break;
                }
                advance();
            }

            node->setNextNode(cursor); // setze Nachfolger des neuen Knotens
            node->setPreviousNode(cursor->getPreviousNode()); // setze Vorgänger des neuen Knotens

            if(cursor->getPreviousNode()) // wenn Vorgänger des Positionszeigers existiert, setze neuen Knoten als Nachfolger des Vorgängers
                cursor->getPreviousNode()->setNextNode(node);

            cursor->setPreviousNode(node); // setze Vorgänger der Node des Positionszeigers
        }

        cursor = node; // Setze Positionszeiger auf den neuen Knoten

        if(!cursor->getPreviousNode()) // wenn Positionszeiger keinen Vorgänger hat, setze root auf Positionszeiger
            root = cursor;
    }

    bool isAtEnd() {
        bool isEnd = false;
        if(cursor == end) {
            isEnd = true;
        }
        return isEnd;
    }

    void advance() {
        if(cursor && cursor->getNextNode())
            cursor = cursor->getNextNode();
    }

    void deleteNode() {
        Node<T> *tmpPrevious;
        Node<T> *tmpNext;

        if (root == nullptr) { // Werfe eine Ausnahme, wenn Liste leer

            throw std::underflow_error("Liste ist leer. Loeschen fehlgeschlagen!");

        } else { // wenn Liste nicht leer

            if (cursor->getPreviousNode() == nullptr) { // Wenn kein Vorgänger existiert ( root-Knoten ausgewählt )

                if (cursor->getNextNode() == end) { // Wenn Liste nur aus einem Knoten besteht

                    delete cursor; // Speicherplatz freigeben
                    root = nullptr;
                    end->setPreviousNode(nullptr);
                    cursor = end; // Positionszeiger auf Ende setzen

                } else { // Liste besteht aus mehreren Knoten ( root-Knoten wird gelöscht )

                    cursor = cursor->getNextNode(); // Setze Positionszeiger auf Nachfolger
                    delete root;
                    cursor->setPreviousNode(nullptr);
                    root = cursor; // Setze Positionszeiger auf den root-Knoten

                }

            } else { // Wenn Vorgänger existiert

                if (cursor->getNextNode() == end) { // Wenn Positionszeiger auf end-Knoten zeigt ( end-Knoten ausgewählt )

                    tmpPrevious = cursor->getPreviousNode(); // Vorgänger-Knoten zwischenspeichern
                    delete cursor; // Speicherplatz freigeben
                    cursor = end; // setze Positionszeiger auf end-Knoten
                    end->setPreviousNode(tmpPrevious); // setze Vorgänger des end-Knotens auf den zwischengespeicherten Vorgänger-Knoten
                    tmpPrevious->setNextNode(end); // setze neuen Knoten als Nachfolger des Vorgänger - Knotens

                } else { // Positionszeiger zeigt auf einen Knoten mitten in der Liste ( nicht an root/end )

                    tmpPrevious = cursor->getPreviousNode(); // zwischenspeichern des Vorgängers
                    tmpNext = cursor->getNextNode(); // zwischenspeichern des Nachfolgers
                    delete cursor; // Speicherplatz freigeben
                    tmpPrevious->setNextNode(tmpNext); // Nachfolger des gelöschten Knotens als Nachfolger des Vorgängers setzen
                    tmpNext->setPreviousNode(tmpPrevious); // Vorgänger des gelöschten Knotens als Vorgänger des Nachfolgers setzen
                    cursor = tmpPrevious; // Positionszeiger auf den Vorgänger des gelöschten Knotens setzen

                }

            }

        }

        return;
    }

    T get() {
        return cursor->getData();
    }

    void reset() {
        if(root)
            cursor = root;
    }

    unsigned long size() {
        unsigned long listsize = 0;

        reset();

        while (!isAtEnd()) {
            advance();
            listsize++;
        }

        return listsize;
    }

    void clear() {
        reset();

        while(!isAtEnd()) {
            deleteNode();
        }
    }

    // operators

    T operator[](const unsigned long long x) {
        reset();

        for(unsigned long long i = 0; i < x; i++) {
            if(!(cursor = cursor->getNextNode()))
                throw std::out_of_range("Ungueltiger Index!");
        }

        return get();
    }


protected:

    Node<T> *root;
    Node<T> *cursor;
    Node<T> *end;

};



#endif // LIST_H
