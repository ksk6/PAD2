#include "list.h"
#include <stdexcept>
using namespace std;

List<Booking*>::List() {
    root = nullptr; // root darf nur bei einer leeren Liste gleich NULL sein
    end = new Node(nullptr);  // Dummyknoten
    cursor = end;
}

Booking* List<Booking*>::operator[](int i){
    if( i < 0 || unsigned(i)>= this->numElements)
        throw out_of_range("Indexüberschreitung!");
    return this->getNode();
}

void List<Booking*>::insertNode(Booking *b) {

    Node* node = new Node(b); // erzeuge neuen Knoten, bei dem vorhergehender
    // und nachfolgender Knoten per Default auf NULL
    // gesetzt sind (siehe Konstruktor von node)

    do{
        if(cursor->GetData()->getId()>node->GetData()->getId())
            cursor = cursor->GetPreviousNode();
        else
            break;

    }while(true);

    if (root == nullptr) {
        // Leere Liste: Der root-Knoten wird auf den neuen Knoten umgesetzt und der
        // neue Knoten wird mit dem end-Knoten verkettet:
        root = node;
        node->SetNextNode(end);
        end->SetPreviousNode(node);
        this->numElements++; //Node hinzugefügt, Anzahl inkrementieren
    } else {
        // Der Nachfolger des neuen Knotens wird initialisiert mit dem Cursor-Knoten;
        // es wird also VOR dem aktuellen Element eingefuegt:
        node->SetNextNode(cursor);

        // Der Vorgaenger des neuen Knotens wird mit dem Vorgaenger des Cursors
        // initialisiert, auch wenn dieser nullptr ist:
        node->SetPreviousNode(cursor->GetPreviousNode());

        // Falls der Vorgaenger-Knoten existiert, wird der neue Knoten als
        // dessen Nachfolger eingesetzt:
        if (cursor->GetPreviousNode())
            cursor->GetPreviousNode()->SetNextNode(node);
        // Jetzt wird noch der neue Knoten als Vorgaenger des Cursor-Knotens
        // eingetragen:
        cursor->SetPreviousNode(node);
        this->numElements++; //Node hinzugefügt, Anzahl inkrementieren
    }
    // Alle Links sind eingetragen; jetzt kann der cursor umgesetzt werden:
    cursor = node;

    // Falls der neue Knoten der erste in der Liste ist, wird root umgehängt:
    if (!cursor->GetPreviousNode())
        root = cursor;
}

void List<Booking*>::deleteNode() {
    Node* tmpPrevious; // temporaere Variablen, fuer den Fall, dass der
    Node* tmpNext;     // zu loeschende Knoten in der Mitte der Liste ist

    if (root == nullptr) {
        // Liste leer, nichts zu loeschen
        throw underflow_error("Versuch aus leerer Liste zu loeschen");
    } else {
        if (cursor->GetPreviousNode() == nullptr) {
            if (cursor->GetNextNode() == end) {
                // Fall 1: Die Liste besteht nur aus einem einzigen Knoten
                // Knoten loeschen, Speicher freigeben,Zeiger root und cursor loeschen
                delete cursor;
                root = nullptr;
                end->SetPreviousNode(nullptr);
                cursor = end;
            } else {
                // Fall 2: Die Liste besteht aus mehreren Knoten, von denen der
                // erste (also der root-Knoten) geloescht werden soll.
                // Anschliessend wird der Speicherplatz wieder freigegeben

                // Zeiger auf den naechsten Knoten setzen
                cursor = cursor->GetNextNode();
                delete (root);

                // Cursor-Knoten ist jetzt erster Knoten: Vorgaenger auf NULL setzen:
                cursor->SetPreviousNode(nullptr);

                // Neuen root-Knoten setzen:
                root = cursor;
            }
        } else { //Vorgaengerknoten nicht leer
            if (cursor->GetNextNode() == end) {
                // Fall 3: Die Liste besteht aus mehreren Knoten, von denen der
                // letzte geloescht werden soll.
                // Anschliessend wird der Speicherplatz fuer diesen Knoten
                // wieder freigegeben
                tmpPrevious = cursor->GetPreviousNode();
                delete cursor;
                // cursor-Knoten auf den Endknoten setzen
                cursor = end;
                end->SetPreviousNode(tmpPrevious);
                tmpPrevious->SetNextNode(end);
            } else {//Naechster Knoten ist nicht der Endknoten
                // Fall 4: Die Liste besteht aus mehreren Knoten.
                // Es wird weder der erste noch der letzte Knoten geloescht.
                // Die Adresse des vorhergehenden Knotens in tmpPrevious sichern,
                // und die Adresse des naechsten Knotens in tmpNext sichern.
                tmpPrevious = cursor->GetPreviousNode();
                tmpNext = cursor->GetNextNode();
                // Den aktuellen Knoten loeschen
                delete cursor;

                // Die Knoten tmpPrevious und tmpNext verketten
                tmpPrevious->SetNextNode(tmpNext);
                tmpNext->SetPreviousNode(tmpPrevious);

                // Den Zeiger auf das Element nach dem alten Knoten setzen
                cursor = tmpNext;
            }
        }
        this->numElements--; //Node gelöscht maximale Anzahl dekrementieren
    }
    return;
}
