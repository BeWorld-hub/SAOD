#ifndef NODE_H
#define NODE_H

struct Node
{
	Node(int data);

	int data_;
	Node* nextNode_;
};


#endif