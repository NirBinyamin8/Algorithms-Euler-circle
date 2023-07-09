#include "Directed.h"
DirectedGraph::DirectedGraph(int n, int m) {
    int i, u, v;
    this->n = n;
    adjList.resize(n+1);
    adjList_t.resize(n+1);
    degree = (int*)calloc(n+1,sizeof(int));
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (u > n || v > n)
            throw "invalid input";
        if ((adjList[u].size() == 0) ||!Check_if_already_insert(u, v))
        {
            degree[v]++;
            degree[u]--;
            this->addEdge(u, v);

        }
        
    }

}
DirectedGraph::~DirectedGraph()
{
    delete degree;
}
bool DirectedGraph::Check_if_already_insert(int u, int v)
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
void DirectedGraph::addEdge(int u, int v) {
    Edge* e1 = new Edge(v);
    Edge* e1_t = new Edge(u);
    e1->ptr = nullptr;
    e1_t->ptr = nullptr;
    adjList[u].push_back(e1);
    adjList_t[v].push_back(e1_t);
    
}
bool DirectedGraph::Is_connected()
{
    vector<bool> visited(n+1, false);
    vector<bool> visited_t(n+1, false);
    vector<int> stack;
    int nei,curr;
    Edge* head;


    visited[1] = true;
    visited_t[1] = true;

    stack.push_back(1);

    while (!stack.empty()) {
        curr = stack.back();
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
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
            return false;
    }

    stack.push_back(1);
    while (!stack.empty()) {
        curr = stack.back();
        stack.pop_back();
        head = adjList_t[curr].ReturnHead();

        while (head != nullptr)
        {
            nei = head->v;
            if (visited_t[nei] == false)
            {
                visited_t[nei] = true;
                stack.push_back(nei);

            }

            head = head->next;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited_t[i] == false)
            return false;
    }
    return true;




}
void DirectedGraph::EulerTour()
{
    Circle* Main_circle, * l1;
    bool Exist = true, conncted;
    VartexOfCircle* u = nullptr;

    conncted = this->Is_connected();
    if (conncted)
    {
        for (int i = 1; i <= n; i++)
        {
            if (degree[i] != 0)
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
Circle* DirectedGraph::FindCircle(int head)
{
    Circle* circle = new Circle;
    int u;
    int v = head;
    circle->push_back(head);
    bool there_circle = false;
    bool found_circle = false;

    while (!found_circle && ThereisUnMarkEdge(v, &u, true))
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
bool DirectedGraph::ThereisUnMarkEdge(int v, int* u, bool mark)
{
    List_Of_Edges* list = &adjList[v];
    Edge* node;
    node = list->ReturnHead();
    while (node != nullptr)
    {
        if (node->use == false)
        {
            if (mark)
            {
                *u = node->v;
                node->use = true;
                
            }

            return true;
        }
        node = node->next;
    }
    return false;

}
bool DirectedGraph::unmarked_edges_in_circle(Circle* circle, VartexOfCircle** u)
{
    int i;
    VartexOfCircle* var = circle->Head();

    while (var != nullptr)
    {
        if (ThereisUnMarkEdge(var->v, &i, false))
        {
            *u = var;
            return true;
        }
        var = var->next;


    }
    u = nullptr;
    return false;
}

