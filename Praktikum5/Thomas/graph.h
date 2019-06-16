#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cfloat>  // wg. MAXFLOAT
using namespace std;

const double noArc = FLT_MAX;
const double weightBackEdge = -1.0;
const double weightCrossEdge = -2.0;
const double weightForwardEdge = -3.0;

enum color_node {
    WHITE = 0, GREY = 1, BLACK = 2
};

template <class T, int maxNodes>
class Graph
{
private:

    class Vertex
    {
    public:
        Vertex(){ // Konstruktor
            indegree = outdegree = ord = 0;
            living = false;
            color = WHITE;
            start = end = 0;
            predecessor = -1;
        }
        T value; // Daten des Knotens
        int indegree; // Eingangsgrad
        int outdegree; // Ausgangsgrad
        int ord; // Ordnungszahl des Knotens
        bool living; // Knoten existiert
        color_node color; //Farbcodierung für Bearbeitungszustand
        int start, end; //Start und Ende der Bearbeitungszeit für DFS
        int predecessor; //Für aufspannenden Baum
        int numVertices; // Anzahl der Knoten eines Digraphen
    };

    int numVertices; // Anzahl der Knoten eines Digraphen
    int numArcs; // Anzahl der Kanten eines Digraphen
    Vertex vertices[maxNodes]; // repraesentiert Knoten des Digraphen
    double arcs[maxNodes][maxNodes]; // repraesentiert bewertete Kanten des Graphen

public:// Operationen auf dem Graphen
    Graph(); // Graphen generieren
    ~Graph(); // Graphen freigeben

    // Getter
    T getVertexValue(int n); // gibt Wert des Knoten n zurueck
    double getArc(int v, int w); // gibt Kantenbewertung  von (v,w) zurck
    int getNumVertices(); // Anzahl der Knoten
    int getMaxNodes(); // Max. Anzahl der Knoten
    int getNumArcs(); // Anzahl der Kanten
    int getIndegree(int n); // liefert Eingangsgrad eines Knotens
    int getOutdegree(int n); // liefert Ausgangsgrad eines Knotens
    int getColor(int n); //liefert Farbe des Knotens
    int getStart(int n); //liefert Startzeitpunkt
    int getEnd(int n); //liefert Endzeitpunkt
    int getOrd(int v); // Ordnungsnummer des Knotens v liefern
    int getPredecessor(int n); //liefert Vorgaengerknoten

    // Setter
    void setVertexValue(int n, T m); // Aendert Wert des Knoten n
    void setColor(int n, color_node color); // Knoten n als nicht besucht, besucht oder abgeschlossen markieren
    void setStart(int n, int time); //Startzeitpunkt der Bearbeitung für DFS setzen
    void setEnd(int n, int time); //Endzeitpunkt der Bearbeitung für DFS setzen
    void setOrd(int v, int n); // Ordnungsnummer n im Knoten v setzen
    void setPredecessor(int n, int pre); //Vorgängerknoten setzen

    void insertVertex(int n, T m); // fgt neuen Knoten n mit Markierung m ein
    void deleteVertex(int n); // entfernt Knoten n
    int firstVertex(); // Erster Knoten des Graphen
    int nextVertex(int n); // nächster Knoten nach n (-1 wenn keiner existiert)
    void insertArc(int v, int w, double weight);//fgt Kante (v,w) mit Gewicht weight ein
    void insertArc(int v, int w); // fgt Kante (v,w) mit Gewicht 0 ein
    void deleteArc(int v, int w); // loescht Kante (v,w)
    int firstArc(int v); // Erster Kante des Knoten v des Graphen
    int nextArc(int v, int n); //naechste Kante des Knotens v nach n (-1 wenn keine existiert)
    bool isVisited(int n); // true, wenn Knoten n besucht, sonst false
    void setArcWeight(int v, int w, double weight); //aendert Kantengewicht
    bool isArc(int v, int w); // existiert Kante (v,w)?
    void printVertex(int n); // Ausgabe des Knotens n eines Graphen
    void printVertices(); // Ausgabe aller Knotens eines Graphen
    void printAdjMatrix(); // Adjazenzmatrix ausgeben
    void deleteGraph(); // alle Knoten und Kanten loeschen
};

#endif // GRAPH_H
