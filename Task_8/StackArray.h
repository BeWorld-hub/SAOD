#ifndef STACKARRAY_H
#define STACKARRAT_H

struct StackArray
{
	int* array_;
	int currentNum_;
	int size_;
	StackArray(int size);
	void push(int data);
	void drop();
	int operator[] (int index);
	bool isFull();
	bool isEmpty();
	int getMax(int dataFirst, int dataSecond);
	int  getMin(int dataFirst, int dataSecond);
};
#endif