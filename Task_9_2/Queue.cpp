#include "Queue.h"

Queue::Queue()
{
	arr_ = new int[5];
	numElements_ = 0;
}

bool Queue::isEmpty()
{
	return numElements_ == 0;
}

bool Queue::isFull()
{
	return numElements_ == 5;
}

void Queue::push(int timeData)
{
	if (isFull()) { return; }

	arr_[numElements_] = timeData;
	numElements_++;
}

int Queue::remove()
{
	if (isEmpty()) { return-748234278; }

	int* newArr = new int[5];
	int temp;
	
	for (unsigned int i = 1; i < 5; i++)
	{
		newArr[i - 1] = arr_[i];
	}
	temp = arr_[0];

	delete[] arr_;
	arr_ = newArr;
	numElements_--;

	return temp;
}

int Queue::operator[] (int index)
{
	if (isEmpty() || 4 < index < 0) { return(-89598729); }

	return arr_[index];
}