#include "Undirected.h"
UndirectedGraph ::UndirectedGraph(int n,int m) {
    int i, u, v;
    this->n = n;
    adjList.resize(n+1);

    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (u > n || v > n)
            throw "invalid input";
        if ((adjList[u].size() == 0) || (adjList[v].size() == 0) ||!Check_if_already_insert(u, v))
            this->addEdge(u, v);

        
    }

}
bool UndirectedGraph::Is_connected()

{
    vector<bool> visited(n+1, false);
    int nei;
    Edge* head;
    visited[1] = true;
    vector<int> stack;
    stack.push_back(1);

    while (!stack.empty()) {
        int curr = stack.back();
        stack.pop_back();
        head = adjList[curr].ReturnHead();
        while (head != nullptr)
        {
            nei = head->v;
            if (visited[nei] == false)
            {
                visited[nei] = true;
                stack.push_back(nei);

            }
            
            head = head->next;
        }

    }

    for (int i = 1; i <=n; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
       
        

}

bool UndirectedGraph::Check_if_already_insert(int u, int v)
{
    Edge* cur = adjList[u].ReturnHead();

    while (cur != nullptr)
    {
        if (cur->v == v)
            return true;
        cur = cur->next;
    }
    return false;
}

void UndirectedGraph::addEdge(int u, int v) {
    Edge* e1= new Edge(v);
    Edge* e2=new Edge(u);
    e1->ptr = e2;
    e2->ptr = e1;
    adjList[u].push_back(e1);
    adjList[v].push_back(e2);
}

bool UndirectedGraph::ThereisUnMarkEdge(int v, int* u,bool mark)
{
    List_Of_Edges* list = &adjList[v];
    Edge* node;
    node = list->ReturnHead();
    while (node!=nullptr)
    {
        if (node->use == false)
        {
            if (mark)
            {
                *u = node->v;
                node->use = true;
                node->ptr->use = true;

            }
            
            return true;
        }
        node = node->next;
    }
    return false;

}

Circle* UndirectedGraph::FindCircle(int head)
{
    Circle* circle=new Circle;
    int u;
    int v= head;
    circle->push_back(head);
    bool there_circle = false;
    bool found_circle = false;

    while (!found_circle&&ThereisUnMarkEdge(v, &u,true))
    {
        circle->push_back(u);
        if (head == u)//find one circle
            found_circle = true;
        v = u;
        there_circle = true;

    }
    if (!there_circle)
    {
        delete circle;
        return nullptr;
    }
  
    return circle;
}

bool UndirectedGraph::unmarked_edges_in_circle(Circle* circle, VartexOfCircle** u)
{
    int i;
    VartexOfCircle* var = circle->Head();

    while (var != nullptr)
    {
        if (ThereisUnMarkEdge(var->v, &i,false))
        {
            *u = var;
            return true;
        }
        var = var->next;


    }
    u = nullptr;
    return false;
}

void UndirectedGraph::EulerTour()
{
    Circle *Main_circle, *l1;
    bool Exist = true,conncted;
    VartexOfCircle* u=nullptr;

    conncted = this->Is_connected();
    if (conncted)
    {
        for (int i = 1; i <=n; i++)
        {
            if (adjList[i].size() % 2 != 0)
            {
                cout << "The graph is not aulerian" << endl;
                Exist = false;
                break;
            }

        }
        if (Exist)
        {
            Main_circle = this->FindCircle(1);


            while (unmarked_edges_in_circle(Main_circle, &u))
            {
                l1 = FindCircle(u->v);
                Main_circle->add_another_circle(l1, u);

            }
            cout << "The graph is aulerian" << endl;
            Main_circle->print();

        }
    }
    else
        cout << "The graph is not aulerian" << endl;
    
    
    





}
