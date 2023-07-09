#ifndef List_Of_Edges_H
#define List_Of_Edges_H
#include <iostream>

class Edge {
public:
    int v;
    Edge* next;
    Edge* prev;
    Edge* ptr;
    bool use = false;

    Edge(int v, Edge* next = nullptr, Edge* prev = nullptr, Edge* ptr = nullptr)
        : v(v), next(next), prev(prev), ptr(ptr) {}
};

class List_Of_Edges {
private:
    Edge* head;
    Edge* tail;
    int size_;
public:
    List_Of_Edges();
    

    ~List_Of_Edges();

    void push_back(Edge* v);


    int size() const;
 

    Edge* ReturnHead();
    Edge* ReturnTail();
  

};

#endif
