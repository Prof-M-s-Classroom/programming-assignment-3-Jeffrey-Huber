#ifndef GRAPH_H
#define GRAPH_H
#include <iomanip>

class Graph {
public:
    Graph(int vertices); //make a constructor first

    ~Graph(); //make a destructor

    void addEdge(int u, int v, int weight); //set up the add edge method, populate the 2d array, printout graph

    void primMST(); // Must print MST edges and total weight || should be able to run without setting up heap.h
    //

    void printGraph() const;

private:
    int **adjMatrix;
    int numVertices;
};

#endif
