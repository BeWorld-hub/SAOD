#include "Queue.h"

Queue::Queue() : lastNode_(nullptr), numElements_(0) {}

bool Queue::isEmpty()
{
	return lastNode_ == nullptr;
}

bool Queue::isFull()
{
	return numElements_ == 5;
}

void Queue::push(int time)
{
	if (isFull()) { std::cout << "ITS FULL" << std::endl; return; }

	Node* currentNode = new Node(time);
	numElements_++;

	if (isEmpty())
	{
		lastNode_ = currentNode; return;
	}

	currentNode->nextNode_ = lastNode_;
	lastNode_ = currentNode;
}

Node* Queue::remove()
{
	if (isEmpty()) { std::cout << "ITS EMTY" << std::endl; return nullptr; }

	Node* currentNode = lastNode_;
	while (currentNode->nextNode_->nextNode_ != nullptr)
	{
		currentNode = currentNode->nextNode_;
	}

	Node* tempNode = currentNode->nextNode_;
	currentNode->nextNode_ = nullptr;
	numElements_--;
	
	return tempNode;
}

int Queue::operator[] (int index)
{
	if (isEmpty() || 5 <= index < 0) return -1;

	Node* currentNode = lastNode_;

	for (unsigned int i = 0; i < index; i++)
	{
		currentNode = currentNode->nextNode_;
	}

	return currentNode->time_;
}

void Queue::execQueue()
{
	Node* currentNode = lastNode_;

	std::cout << "Прибытие: ";
	while (currentNode != nullptr)
	{
		std::cout << currentNode->time_ << " ";

		currentNode = currentNode->nextNode_;
	}

	currentNode = lastNode_;
	int outTime = lastNode_->time_ + 10;
	static int waitTime = 0;

	std::cout << std::endl << "Убытие: ";
	while (currentNode != nullptr)
	{
		std::cout << outTime << " ";
		outTime += 10;
		currentNode = currentNode->nextNode_;
	}
	std::cout << std::endl << "Среднее время ожидания: " <<(float)(waitTime / numElements_);
	waitTime += waitTime + 10;
}