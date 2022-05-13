#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List list;
	string phone, caller;
	int time;

	for (unsigned int i = 0; i < 10; i++)
	{
		cin >> phone >> time >> caller;

		Node* currentNode = new Node(phone, time, caller);

		list.addInTurn(currentNode);
	}

	list.print();

	return 0;
}