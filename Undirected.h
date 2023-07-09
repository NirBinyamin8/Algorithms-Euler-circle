#ifndef UNDIRECTED_H
#define UNDIRECTED_H
#include <iostream>
#include <vector>

#include "List_Of_Edges.h"
#include "Circle.h"

using namespace std;

class UndirectedGraph {
private:
    int n; // number of vertices
    vector<List_Of_Edges> adjList; // adjacency list of each vertex

public:
    UndirectedGraph(int n,int m)noexcept(false);

    bool Check_if_already_insert(int u, int v);

    void addEdge(int u, int v);

    //main funcation of euler circle finder
    void EulerTour();
    //find circle funcation
    Circle* FindCircle(int head);
    //checks if there un usage edges to vartex v and return bool ver + the number of the unusage vartex in u
    bool ThereisUnMarkEdge(int v, int* u,bool mark);

    //check if there unusage edges in the main circle 
    bool unmarked_edges_in_circle(Circle* circle, VartexOfCircle** u);

    bool Is_connected();

    
};
#endif
