#include <iostream>

using namespace std;

struct Node
{
	Node* leftNode_;
	Node* rightNode_;
	unsigned char height_;
	int data_;

	Node(int data) : data_(data), leftNode_(nullptr), rightNode_(nullptr), height_(1) {}

	void printTree()
	{
		if (leftNode_ != nullptr)
		{
			leftNode_->printTree();
		}

		cout << data_ << endl;

		if (rightNode_ != nullptr)
		{
			rightNode_->printTree();
		}
	}
};

unsigned char height(Node* node)
{
	return node ? node->height_ : 0;
}

int bFactor(Node* node)
{
	return(height(node->rightNode_) - height(node->leftNode_));
}

void fixHeight(Node* node)
{
	unsigned char leftHeight = height(node->leftNode_);
	unsigned char rightHeight = height(node->rightNode_);

	node->height_ = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* rotateRight(Node* node)
{
	Node* tempNode = node->leftNode_;
	node->leftNode_ = tempNode->rightNode_;
	tempNode->rightNode_ = node;

	fixHeight(node); fixHeight(tempNode);

	return tempNode;
}

Node* rotateLeft(Node* node)
{
	Node* tempNode = node->rightNode_;
	node->rightNode_ = tempNode->leftNode_;
	tempNode->leftNode_ = node;

	fixHeight(node); fixHeight(tempNode);

	return tempNode;
}

Node* balanceNode(Node* node)
{
	fixHeight(node);

	if (bFactor(node) == 2)
	{
		if (bFactor(node->rightNode_) < 0) { node->rightNode_ = rotateRight(node->rightNode_); }

		return rotateLeft(node);
	}

	if (bFactor(node) == -2)
	{
		if (bFactor(node->leftNode_) > 0) { node->leftNode_ = rotateLeft(node->leftNode_); }

		return rotateRight(node);
	}

	return node;
}

Node* insertData(Node* rootNode, int data)
{
	if (!rootNode) { return new Node(data); }

	if (data < rootNode->data_) { rootNode->leftNode_ = insertData(rootNode->leftNode_, data); }
	else { rootNode->rightNode_ = insertData(rootNode->rightNode_, data); }

	return balanceNode(rootNode);
}

Node* findMinDataNode(Node* node)
{
	return(node->leftNode_ ? findMinDataNode(node->leftNode_) : node);
}

Node* removeMinDataNode(Node* node)
{
	if (node->leftNode_ == 0) { return node->rightNode_; }

	node->leftNode_ = removeMinDataNode(node->leftNode_);

	return balanceNode(node);
}

Node* removeByData(Node* rootNode, int data)
{
	if (!rootNode) { return nullptr; }

	if (data < rootNode->data_) { rootNode->leftNode_ = removeByData(rootNode->leftNode_, data); }
	else if (data > rootNode->data_)
	{
		rootNode->rightNode_ = removeByData(rootNode->rightNode_, data);
	}
	else
	{
		Node* firstTempNode = rootNode->leftNode_;
		Node* secondTempNode = rootNode->rightNode_;

		delete rootNode;

		if (!secondTempNode) { return firstTempNode; }

		Node* minNode = findMinDataNode(secondTempNode);

		minNode->rightNode_ = removeMinDataNode(secondTempNode);
		minNode->leftNode_ = firstTempNode;

		return balanceNode(minNode);
	}

	return balanceNode(rootNode);
}



int main()
{
	int sizeTree; cin >> sizeTree;

	int num; cin >> num;

	Node* rootNode = insertData(nullptr, num);
	
	for (unsigned int i = 0; i < sizeTree - 1; i++)
	{
		cin >> num;

		rootNode = insertData(rootNode, num);
	}

	cout << "TREE" << endl;

	rootNode->printTree();

	return 0;
}