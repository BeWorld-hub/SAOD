#ifndef STACK_H
#define STACK_H

#include "Node.h"

struct Stack
{
	Node* lastNode_;
	int size_;
	int currentNum_;
	Stack(int size);

	bool isEmpty();
	bool isFull();
	void push(int data);
	Node* get();
	int operator[] (int index);

	int getMax(int dataFirst, int dataSecond);
	int getMin(int dataFirst, int dataSecond); 
	int calculateBuilds();
};
#endif