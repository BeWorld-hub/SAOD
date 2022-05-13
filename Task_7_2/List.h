#ifndef LIST_H
#define LIST_H

#include "Node.h"

#include <iostream>

struct List
{
	Node* firstNode;
	Node* lastNode;

	List();
	bool isEmpty();
	void addInTurn(Node* currentNode);
	std::string removeLastNode(std::string phoneNumber);
	int getTimeCalls(std::string phoneNumber);
	void print();
};

#endif