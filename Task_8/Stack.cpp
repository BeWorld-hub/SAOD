#include "Stack.h"

Stack::Stack(int size) : size_(size), lastNode_(nullptr), currentNum_(0) {}

bool Stack::isEmpty()
{
	return(currentNum_ == 0);
}

void Stack::push(int data)
{
	if (currentNum_ == size_) { throw; }
	else
	{
		Node* currentNode = new Node(data);

		if (isEmpty()) {}
		else
		{
			currentNode->nextNode_ = lastNode_;
		}
		lastNode_ = currentNode;
		currentNum_++;
	}
}

Node* Stack::get()
{
	if (isEmpty()) { throw;	}
	else
	{
		Node* currentNode = lastNode_;

		lastNode_ = lastNode_->nextNode_;

		currentNum_--;
		return currentNode;
	}
}

int Stack::operator[] (int index)
{
	Node* currentNode = lastNode_;

	for (unsigned int i = 1; i < index; i++)
	{
		currentNode = currentNode->nextNode_;
	}

	return currentNode->data_;
}

bool Stack::isFull()
{
	return(currentNum_ == size_);
}

int Stack::getMax(int dataFirst, int dataSecond)
{
	if (dataFirst >= dataSecond) { return dataFirst; }
	else return dataSecond;
}

int Stack::getMin(int dataFirst, int dataSecond)
{
	if (dataFirst >= dataSecond) { return dataSecond; }
	else return dataFirst;
}

int Stack::calculateBuilds()
{
	int currentHeight = lastNode_->data_;
	int numBuilds = 1;
	Node* currentNode = lastNode_;

	while (currentNode != nullptr)
	{
		if (currentNode->data_ > currentHeight) 
		{ 
			numBuilds++; 
			currentHeight = currentNode->data_;
		}

		currentNode = currentNode->nextNode_;
	}

	return numBuilds;
}