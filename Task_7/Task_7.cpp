#include <iostream>

using namespace std;

struct node
{
	int _data;
	node* _next_node;

	node(int value) : _data(value), _next_node(nullptr) {}
};

struct list
{
	node* _first_node;
	node* _last_node;

	list() : _first_node(nullptr), _last_node(nullptr) {}

	~list()
	{
		node* iterator = _first_node;
		
		while (iterator != nullptr)
		{
			node* temp = iterator->_next_node;
			delete iterator;
			iterator = temp;
		}
	}

	bool is_empty()
	{
		return(_first_node == nullptr);
	}

	void push_forward(int value)
	{
		node* list_node = new node(value);

		if (is_empty())
		{
			_first_node = list_node;
			_last_node = list_node;
		}
		else
		{
			list_node->_next_node = _first_node;
			_first_node = list_node;
		}
	}

	void print()
	{
		if (is_empty()) { cout << "emty"; return; }

		node* iterator = _first_node;

		while (iterator != nullptr)
		{
			cout << iterator->_data << "\t";
			iterator = iterator->_next_node;
		}
	}
	int find(int value)
	{
		if (is_empty()) { return -89458492; }

		int index = 0;
		node* iterator = _first_node;

		while (iterator != nullptr)
		{
			if (value == iterator->_data)
			{
				return index;
			}
			else
			{
				index++;
				iterator = iterator->_next_node;
			}
		}
		return -1;
	}

	int size()
	{
		int index = 0;
		node* iterator = _first_node;

		while (iterator != nullptr)
		{
			index++; iterator = iterator->_next_node;
		}
		return index;
	}

	int operator[] (int index)
	{
		if (index >= size()) { throw exception("Out of range! index >= list.size"); }
		else if (index < 0) { throw exception("Out of range! index < 0"); }

		node* iterator = _first_node;
		int step = 0;

		while (iterator != nullptr)
		{
			if (step == index) { return iterator->_data; }
			
			iterator = iterator->_next_node;
			step++;
		}
	}
};

int main()
{
	srand(NULL);
	list l1;
	list l2;
	list l;

	for (int i = 0; i < 10; i++)
	{
		l1.push_forward(rand() % 100);
		l2.push_forward(rand() % 100);
	}
	
	for (int i = 0; i < l1.size(); i++)
	{
		if (l1.find(l2[i]) == -1) { l.push_forward(l2[i]); }
	}

	cout << "l1:" << endl;
	l1.print();

	cout << endl << "l2:" << endl;
	l2.print();

	cout << endl << "l:" << endl;
	l.print();

	return 0;
}