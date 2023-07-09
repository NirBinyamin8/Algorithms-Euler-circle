#include "List_Of_Edges.h"
List_Of_Edges::List_Of_Edges()
{
    head = new Edge(-1);
    tail = nullptr;
    head->next = tail;
    size_ = 0;

}
List_Of_Edges::~List_Of_Edges()
{
    if (this->size_ == 0)
        delete head;
    else
    {
        Edge* cur = head;
        while (cur != nullptr) {
            Edge* next = cur->next;
            delete cur;
            cur = next;
        }

    }
   
}

void List_Of_Edges::push_back(Edge* v) {
    v->next = nullptr;
    if (tail == nullptr)
    {
        v->prev = head;
        head->next = v;
        tail = v;

    }
    else
    {
        v->prev = tail;
        tail->next = v;
        tail = v;
    }
    
    size_++;
}

int List_Of_Edges::size() const
{
    return (size_);
}

Edge* List_Of_Edges::ReturnHead()
{
    return head->next;
}

Edge* List_Of_Edges::ReturnTail()
{
    return this->tail;
}