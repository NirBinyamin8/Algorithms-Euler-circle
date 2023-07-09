#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
using namespace std;
//Class vertices into a circle
class VartexOfCircle
{
public:
	int v;
	VartexOfCircle* next;
	VartexOfCircle* prev;
	VartexOfCircle(int v1)
	{ 
		v = v1;
		next = nullptr;
	    prev = nullptr;
	}

};
//Circle class
class Circle {
private:
	VartexOfCircle* head;
	VartexOfCircle* tail;
	int size;

public:
	//constructor
	Circle();
	~Circle();
	void push_back(int v);
	void add_another_circle(Circle* L1, VartexOfCircle* u); //add another circle to currnt
	int Size();
	VartexOfCircle* Head();
	void print();

};

#endif
