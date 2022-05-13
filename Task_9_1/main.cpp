#include <iostream>

#include "Queue.h"

using namespace std;

int main()
{
	setlocale(0, "rus");

	Queue carsQueue;
	
	for (int arrivalTime = 0; arrivalTime != -1; )
	{
		cin >> arrivalTime;
		carsQueue.push(arrivalTime);
		carsQueue.execQueue();
	}

	return 0;
}