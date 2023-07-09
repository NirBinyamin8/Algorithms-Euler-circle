#include "Circle.h"
Circle::Circle()
{
	head = new VartexOfCircle(-1);
	tail = head;
	size = 0;
}
Circle::~Circle()
{
	VartexOfCircle* cur=head;

	while (cur= nullptr)
	{
		VartexOfCircle* next = cur->next;
		delete cur;
		cur = next;

	}

}
void Circle::push_back(int v)
{
	VartexOfCircle* vertax = new VartexOfCircle(v);
	vertax->next = nullptr;
	vertax->prev = tail;
	tail->next = vertax;
	tail = vertax;
	size++;

}
void Circle::add_another_circle(Circle* L1, VartexOfCircle* u)
{
	L1->tail->next = u->next;
	u->prev->next = L1->head->next;
	//dummy head of L1
	delete L1->head;
	//irrlevet anymore
	delete u;
}
int Circle::Size()
{
	return size;
}
VartexOfCircle* Circle::Head()
{
	return head->next;
}
void Circle::print()
{
	VartexOfCircle* cur = head->next;
	cout << "(";
	while (cur != nullptr)
	{
		cout << cur->v;
		cur = cur->next;
		if (cur != nullptr)
			cout << ",";
	}
	cout << ")";

}