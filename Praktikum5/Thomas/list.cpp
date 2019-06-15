#include "list.h"

List<Booking*>::List()
{
    root = nullptr;
    end = new Node(nullptr);
    cursor = end;
}


// Gibt den Inhalt des Knotens x zurück.
Booking* List<Booking*>::operator[](int i){
    cout << "Elemente: " << numElements << " AT: " << i << endl;
    if( i > 1*-(numElements)-1 && i < numElements-1 ){
        throw out_of_range("Indexueberschreitung!");
    }

    Node* node = nullptr;

    if(i >= 0){
        // list[2] --> start, k1, >>k2<<, k3
        node = root;
        for(int j=0; j<i; j++){
            node = node->GetNextNode();
        }
    }else{
        // list[-2] --> k6, >>k7<<, k8, end
        node = end;
        for(int j=i; j<0; j++){
            node = node->GetPrevNode();
        }
    }

    return node->GetData();
}

// Gibt den Inhalt des Knotens x zurück.
Booking* List<Booking*>::at(int i){
    return this->operator[](i);
}

// Knotenpunkt einfügen.
void List<Booking*>::InsertNode(Booking* data){
    long travelID = data->getTravelId();
    cursor = root;

    while(cursor != nullptr && cursor->GetNextNode()){
        if(travelID < cursor->GetData()->getTravelId()){ break; }
        cursor = cursor->GetNextNode();
    }

    //do{
    //    if(cursor != nullptr && cursor->GetData()->getId()>travelID){ cursor = cursor->GetPrevNode(); }
    //    else{ break; }
    //}while(true);

    Node* node = new Node(data);

    // Knoten korrekt eingliedern
    if(root == nullptr){
        root = node;
        node->SetNextNode(end);
        end->SetPrevNode(node);
    }else{
        node->SetNextNode(cursor);
        node->SetPrevNode(cursor->GetPrevNode());
        if(cursor->GetPrevNode()){
            cursor->GetPrevNode()->SetNextNode(node);
        }
        cursor->SetPrevNode(node);
    }

    cursor = node;
    if(!cursor->GetPrevNode()){ root = cursor; }

    numElements++;
}

// Knoten löschen.
void List<Booking*>::DeleteNode(){
    Node* tmpPrev;
    Node* tmpNext;

    if(root == nullptr){
        throw underflow_error("Kann kein Element aus leerer Liste geloescht werden.");
    }else{
        if(cursor->GetPrevNode() == nullptr){
            if(cursor->GetNextNode() == end){
                // Letzte Knoten in der Liste wird gelöscht.
                delete cursor;
                root = nullptr;
                end->SetPrevNode(nullptr);
                cursor = end;
            }else{
                // Mehrere Knoten in der Liste und erste wird gelöscht.
                cursor = cursor->GetNextNode();
                delete root;
                cursor->SetPrevNode(nullptr);
                root = cursor;
            }
        }else{
            if(cursor->GetNextNode() == end){
                // Mehrere Knoten in der Liste und letzte wird gelöscht.
                tmpPrev = cursor->GetPrevNode();
                delete cursor;
                cursor = end;
                end->SetPrevNode(tmpPrev);
                tmpPrev->SetNextNode(end);
            }else{
                // Mehrere Knoten in der letzte und irgend eines wird gelöscht.
                tmpPrev = cursor->GetPrevNode();
                tmpNext = cursor->GetNextNode();
                delete cursor;
                tmpPrev->SetNextNode(tmpNext);
                tmpNext->SetPrevNode(tmpPrev);
                cursor = tmpPrev;
            }
        }
    }

    numElements--;
}

// Positionszeiger zeigt auf die letzte Position.
bool List<Booking*>::IsAtEnd(){
    return (cursor == end);
}

// Bewegt den Positionszeiger eine Position weiter,
// falls nicht das Ende der Liste erreicht wurde.
void List<Booking*>::Advance(){
    if(cursor && cursor->GetNextNode()){
        cursor = cursor->GetNextNode();
    }
}

// Bewegt den Positionszeiger eine Position zurück,
// falls nicht der Start der Liste erreicht wurde.
void List<Booking*>::Back(){
    if (cursor && cursor->GetNextNode()) {
        cursor = cursor->GetNextNode();
    }
}

// Gibt den Inhalt des aktuellen Nodes zurück.
Booking* List<Booking*>::GetNode(){ return cursor->GetData(); }

// Liste wird zurück gesetzt.
void List<Booking*>::Reset(){ cursor = root; numElements = 0; }

// Gibt die Anzahl an Knoten der Liste zurück.
size_t List<Booking*>::Size(){ return numElements; }
