#include <iostream>

using namespace std;

int _vs = 0;

class Binary
{
public:
	~Binary()
	{
		if (_left != nullptr)
		{
			if (_right != nullptr)
			{
				delete _right;
				_right = nullptr;
			}

			delete _left;
			_left = nullptr;
		}
	}

	void Add_value(int x)
	{
		if (_value == NULL)
		{
			_value = x;
		}
		else if (x >= _value)
		{
			if (_right == nullptr)
			{
				_right = new Binary;
				_right->_value = x;

				return;
			}

			_right->Add_value(x);
		}
		else
		{
			if (_left == nullptr)
			{
				_left = new Binary;
				_left->_value = x;

				return;
			}
				
			_left->Add_value(x);
		}
	}
	void Print_tree()
	{
		if (_left != nullptr)
		{
			_left->Print_tree();
		}

		cout << _value << endl;
		
		if (_right != nullptr)
		{
			_right->Print_tree();
		}
	}

	void Find_value(int x)
	{
		if (this == nullptr)
		{
			cout << "NOT FIND" << endl;

			return;
		} 
		else if (x == _value)
		{
			cout << "FIND" << endl;

			return;
		}
		else
		{
			_vs++;
		}

		if (x >= _value)
		{
			_right->Find_value(x);
		}
		else
		{
			_left->Find_value(x);
		}
	}

	int Get_vs()
	{
		return _vs;
	}

private:
	int _value = NULL;
	Binary* _left = nullptr;
	Binary* _right = nullptr;
};

int main()
{
	int size;
	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}

	Binary root;

	for (int i = 0; i < size; i++)
	{
		root.Add_value(arr[i]);
	}

	cout << "Write the value that u need find: ";
	cin >> size;
	
	root.Find_value(size);
	cout << "vs = " << root.Get_vs();

	return 0;
}