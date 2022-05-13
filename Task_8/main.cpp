#include <iostream>

#include "Stack.h"

using namespace std;

int main()
{
	int n, currentBuild;
	cin >> n;
	Stack stackBuidlds(n);

	for (unsigned int i = 0; i < n; i++)
	{
		cin >> currentBuild;
		stackBuidlds.push(currentBuild);
	}
	cout << endl << stackBuidlds.calculateBuilds() << endl;
}