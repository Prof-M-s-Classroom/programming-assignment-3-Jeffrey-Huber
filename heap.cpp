#include "heap.h"
#include <iostream>
#include <climits>

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];

    for (int i = 0; i < capacity; i++) {
        heapArray[i] = i;
        keyArray[i] = INT_MAX;
        position[i] = i;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

void MinHeap::insert(int vertex, int key) {
    keyArray[vertex] = key;
    heapArray[size] = vertex;
    position[vertex] = size;

    int i = size++;

    while (i != 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

int MinHeap::extractMin() {
    if (size == 0) {
        std::cout << "Empty MinHeap" << std::endl;
        return -1;
    }

    int root = heapArray[0];
    int lastVertex = heapArray[size - 1];
    heapArray[0] = lastVertex;

    position[lastVertex] = 0;
    position[root] = -1;

    size--;
    minHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[i] = newKey;

    while (i > 0 && keyArray[heapArray[(i - 1) / 2]] > keyArray[heapArray[i]]) {
        int higherIdx = (i - 1) / 2;
        int higherVertex = heapArray[higherIdx];
        int currentVertex = heapArray[i];

        std::swap(heapArray[i], heapArray[higherIdx]);
        position[currentVertex] = higherIdx;
        position[higherVertex] = i;
        i = higherIdx;
    }
}

bool MinHeap::isInMinHeap(int vertex) {
    if (position[vertex] < 0) {
        return false;
    }

    return true;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

void MinHeap::minHeapify(int idx) {
    int small = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[small]]) {
        small = left;
    }

    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[small]]) {
        small = right;
    }


    if (small != idx) {
        int smallVertex = heapArray[small];
        int currentVertex = heapArray[idx];
        std::swap(heapArray[idx], heapArray[small]);
        position[currentVertex] = small;
        position[smallVertex] = idx;
        minHeapify(small);
    }
}
