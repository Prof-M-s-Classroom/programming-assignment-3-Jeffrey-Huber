#include "graph.h"
#include <iostream>
#include <iomanip>

#include "heap.h"

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int *[numVertices];

    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}
Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}
void Graph::addEdge(int u, int v, int weight) {
    if (u < 0 || v < 0 || u >= numVertices || v >= numVertices) {
        std::cout << "Invalid vertex or vertex index out of bounds" << std::endl;
    }

    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}
void Graph::primMST() {
    int parent[numVertices];
    int key[numVertices];
    MinHeap minHeap(numVertices);
    bool inMST[numVertices];

    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
        key[i] = INT_MAX;
        inMST[i] = false;
        minHeap.insert(i, key[i]);
    }

    key[0] = 0;
    minHeap.decreaseKey(0, 0);

    while (!minHeap.isEmpty()) {
        int j = minHeap.extractMin();
        inMST[j] = true;

        for (int i = 0; i < numVertices; i++) {
            int weight = adjMatrix[j][i];

            if (weight > 0 && !inMST[i] && weight < key[i]) {
                key[i] = weight;
                parent[i] = j;

                if (minHeap.isInMinHeap(i)) {
                    minHeap.decreaseKey(i, key[i]);
                }
            }
        }
    }
    int totalWeight = 0;
    for (int k = 1; k < numVertices; k++) {
        if (parent[k] != -1) {
            std::cout << parent[k] << " | " << k << "\t" << adjMatrix[parent[k]][k] << "\n";
            totalWeight += adjMatrix[parent[k]][k];
        }
    }
    std::cout << totalWeight << "\n";
}

void Graph::printGraph() const {
    for (int i = 1; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            std::cout << std::setw(4) << adjMatrix[i][j];
        }
        std::cout << "\n";
    }
}
