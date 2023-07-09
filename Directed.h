#ifndef DIRECTED_H
#define DIRECTED_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "List_Of_Edges.h"
#include "Circle.h"
using namespace std;

class DirectedGraph {
private:
    int n; // number of vertices
    vector<List_Of_Edges> adjList; // adjacency list of each vertex
    vector<List_Of_Edges> adjList_t; // adjacency list of each vertex of GT
    int* degree;

public:
    DirectedGraph(int n, int m)noexcept(false);

    ~DirectedGraph();

    bool Check_if_already_insert(int u, int v);

    void addEdge(int u, int v);

    bool ThereisUnMarkEdge(int v, int* u, bool mark);

    bool unmarked_edges_in_circle(Circle* circle, VartexOfCircle** u);

    Circle* FindCircle(int head);

    bool Is_connected();

    void EulerTour();
    
    
};
#endif
