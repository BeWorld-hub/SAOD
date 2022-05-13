#include "Node.h"

#include <iostream>

struct Queue
{
	Node* lastNode_;
	int numElements_;

	Queue();
	bool isEmpty();
	bool isFull();
	void push(int time);
	Node* remove();
	int operator[] (int index);
	void execQueue();
};

