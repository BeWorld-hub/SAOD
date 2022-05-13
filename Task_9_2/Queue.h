struct Queue
{
	int* arr_;
	int numElements_;

	Queue();
	bool isEmpty();
	bool isFull();
	void push(int timeData);
	int remove();
	int operator[] (int index);
};
