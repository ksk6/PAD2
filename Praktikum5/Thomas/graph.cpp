#include "graph.h"

template <class T, int maxNodes>
Graph<T, maxNodes>::Graph() {
    numVertices = numArcs = 0;
    for (int i = 0; i < maxNodes; i++)
        for (int j = 0; j < maxNodes; j++)
            arcs[i][j] = noArc;
}

template <class T, int maxNodes>
Graph<T, maxNodes>::~Graph() {
    ;
}


// ----- Getter -----
template <class T, int maxNodes>
int Graph<T, maxNodes>::getOrd(int n) {
    if (n >= 0 && n < maxNodes && vertices[n].living) {
        return vertices[n].ord;
    }
    return -1;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getPredecessor(int n) {
    return vertices[n].predecessor;
}

template <class T, int maxNodes>
T Graph<T, maxNodes>::getVertexValue(int n) {
    if (n >= 0 && n < maxNodes && vertices[n].living) {
        return vertices[n].value;
    }
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getMaxNodes() {
    return maxNodes;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getColor(int n) {
    return vertices[n].color;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getStart(int n) {
    return vertices[n].start;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getEnd(int n) {
    return vertices[n].end;
}

template <class T, int maxNodes>
double Graph<T, maxNodes>::getArc(int v, int w) {
    if (isArc(v, w))
        return arcs[v][w];
    return noArc;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getNumArcs() {
    return numArcs;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getNumVertices() {
    return numVertices;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getIndegree(int n) {
    return vertices[n].indegree;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::getOutdegree(int n) {
    return vertices[n].outdegree;
}


// ----- Setter -----
template <class T, int maxNodes>
void Graph<T, maxNodes>::setPredecessor(int n, int pre) {
    vertices[n].predecessor = pre;
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::setOrd(int n, int o) {
    if (n >= 0 && n < maxNodes && vertices[n].living) {
        vertices[n].ord = o;
    }
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::setVertexValue(int n, T m) {
    if (n >= 0 && n < maxNodes && vertices[n].living) {
        vertices[n].value = m;
    }
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::setColor(int n, color_node color) {
    if (n >= 0 && n < maxNodes && vertices[n].living)
        vertices[n].color = color;
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::setStart(int n, int time) {
    if (n >= 0 && n < maxNodes && vertices[n].living)
        vertices[n].start = time;
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::setEnd(int n, int time) {
    if (n >= 0 && n < maxNodes && vertices[n].living)
        vertices[n].end = time;
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::setArcWeight(int v, int w, double weight) {
    arcs[v][w] = weight;
}


template <class T, int maxNodes>
void Graph<T, maxNodes>::insertVertex(int n, T m) {
    if (n >= 0 && n < maxNodes) {
        vertices[n].living = true;
        vertices[n].value = m;
    }
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::insertVertex(int n, T*m) {
    if (n >= 0 && n < maxNodes) {
        vertices[n].living = true;
        vertices[n].value = m;
    }
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::firstVertex() {
    for (int i = 0; i < maxNodes; i++)
        if (vertices[i].living == true)
            return i;
    return -1;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::nextVertex(int n) { // nächster Knoten nach n (-1 wenn n der letzte ist)
    if (n < 0 || n > maxNodes - 2) return -1;
    for (int i = n + 1; i < maxNodes; i++)
        if (vertices[i].living == true)
            return i;
    return -1;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::firstArc(int v) {
    if (vertices[v].living == true)
        for (int i = 0; i < maxNodes; i++)
            if (isArc(v, i))
                return i;
    return -1;
}

template <class T, int maxNodes>
int Graph<T, maxNodes>::nextArc(int v, int n) {
    if (vertices[v].living == true)
        for (int i = n + 1; i < maxNodes; i++)
            if (isArc(v, i))
                return i;
    return -1;
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::deleteVertex(int n) {
    if (n >= 0 && n < maxNodes) {
        vertices[n].living = false;
        vertices[n].color = WHITE;
        vertices[n].value = vertices[n].ord = vertices[n].start =
                vertices[n].end = vertices[n].indegree =
                vertices[n].outdegree = vertices[n].predecessor = 0;
    }
    for (int i = 0; i < maxNodes; i++) {
        //  Vorhandene Kanten zum Knoten löschen
        arcs[i][n] = noArc;
        arcs[n][i] = noArc;
    }
}

template <class T, int maxNodes>
bool Graph<T, maxNodes>::isVisited(int n) {
    if (n >= 0 && n < maxNodes && vertices[n].living) {
        return vertices[n].color;
    }
    return false;
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::insertArc(int v, int w, double weight) {
    if (v >= 0 && v < maxNodes && w >= 0 && w < maxNodes && vertices[v].living && vertices[w].living && weight >= 0) {
        arcs[v][w] = weight;
        vertices[v].outdegree++;
        vertices[v].ord++;
        vertices[w].indegree++;
        vertices[w].ord++;
    }
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::insertArc(int v, int w) {
    insertArc(v, w, 0);
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::deleteArc(int v, int w) {
    if (v >= 0 && v < maxNodes && w >= 0 && w < maxNodes && vertices[v].living && vertices[w].living) {
        arcs[v][w] = noArc;
        vertices[v].outdegree--;
        vertices[v].ord--;
        vertices[w].indegree--;
        vertices[w].ord--;
    }
}

template <class T, int maxNodes>
bool Graph<T, maxNodes>::isArc(int v, int w) {
    if (v >= 0 && v < maxNodes && w >= 0 && w < maxNodes)
        return arcs[v][w] != noArc;
    return false;
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::printVertices() {
    cout << "Knoten:" << endl;
    for (int i = 0; i < maxNodes; i++) {
        printVertex(i);
    }
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::printVertex(int n) {
    string color;
    if (vertices[n].living) {
        if (getColor(n) == 0)
            color = "WHITE";
        else if (getColor(n) == 1)
            color = "GREY";
        else
            color = "BLACK";
        cout << "Nummer: " << n << " Wert: " << getVertexValue(n) << " Ordnung: " << getOrd(n)
                << " Farbe: " << setw(6) << color << " Start: " << getStart(n) << " Ende: " << getEnd(n)
                << " Vorgaenger: " << getPredecessor(n) << endl;
    }
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::printAdjMatrix() {
    cout << "Adjazenz Matrix:" << endl;
    cout << "    ";
    for (int i = 1; i < maxNodes; i++)
        cout << setw(5) << i << " ";
    cout << "\n  --";
    for (int i = 1; i < maxNodes; i++)
        cout << "------";
    cout << endl;
    for (int i = 1; i < maxNodes; i++) {
        cout << "  " << i << "|";
        for (int j = 1; j < maxNodes; j++) {
            if (isArc(i, j))
                cout << setw(5) << getArc(i, j) << " ";
            else
                cout << setw(5) << "-" << " ";
        }
        cout << endl;
    }
}

template <class T, int maxNodes>
void Graph<T, maxNodes>::deleteGraph() {
    for (int i = 0; i < maxNodes; i++)
        deleteVertex(i);
    for (int i = 0; i < maxNodes; i++)
        for (int j = 0; j < maxNodes; j++)
            deleteArc(i, j);
}
