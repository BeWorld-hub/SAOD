#include <iostream>
#include <chrono>

using namespace std;

int* Init(const int& n)
{
	int* pointer = new int[n];

	srand(NULL);

	for (int i = 0; i < n; i++)
	{
		pointer[i] = rand();
	}

	return pointer;
}

void Find(const int* pointer_array, const int& key, const int& size)
{
	int vs = 0;
	int i = 0;

	auto time_start = chrono::steady_clock::now();

	while (pointer_array[i] != key)
	{
		vs++;
		i++;
		
		if (i == size - 1) { cout << "None" << endl; break; }
	}

	auto time_end = chrono::steady_clock::now();

	auto work_time = chrono::duration_cast<chrono::milliseconds>(time_end - time_start);

	cout << "time(milisec): " << work_time.count() << endl;

	cout << "vs: " << vs;
}

int main()
{
	int size = 0;
	int key = 0;

	cout << "size = ";
	cin >> size;

	cout << "key = ";
	cin >> key;

	Find(Init(size), 13, size);

	system("pause"); 
	return 0;
}