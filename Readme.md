[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jeffrey Huber

## Description
The code creates a minheap and then uses prims algorithm to build an MST by finding the smallest weight that's not in the MST until all vertexs are connected 

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logn)         |
| Extract Min          | O(logn)         |
| Decrease Key         | O(logn)         |
| Prim’s MST Overall   | O(n^2)          |

_Explain why your MST implementation has the above runtime._
Insert: It uses a while loop that runs at logn because each vertext has 2 children.
Extract Min: Would be O(1) but it calls minHeapify which is O(logn) for the same reasons as insert
Decrease Key: O(logn) for the same reason as insert
Prim's MST Overall: It has nested loops so it runs at O(n^2) in this came n would be the number of vertices


## Design Decisions
I decided to add a print graph function to the graph.h, this was mostly for testing purposes
so I could see that the graph was being created right.

## Test Case Description

Input:  
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

    g.primMST();
Output:
0 | 1   2
1 | 2   3
0 | 3   6
1 | 4   5
16

## Test Plan and Edge Cases Tested
The edge cases I tested included a straight line, all of the vertex's being connected to one central, and having more than 5 vertices

## Challenges Faced
At first my Prims method was only looking at nodes that started with zero instead of adding them all
