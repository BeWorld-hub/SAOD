#include <Bits.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int SIZE_ARRAY = 100100;
const int BASE = 2017;
const int MOD = 10000000007;

INT64 hash_text[SIZE_ARRAY];
INT64 hash_string[SIZE_ARRAY];
INT64 power[SIZE_ARRAY];

void init_hash(const string& data, INT64 *hash, int base, int mod)
{
	hash[0] = 0;
	INT64 text_length = data.length();

	for (int i = 1; i < text_length; i++)
	{
		hash[i] = (hash[i - 1] * base % mod) + ((signed char)data[i - 1] % mod);
	}
}
void clear_hash(INT64 *hash)
{
	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		hash[i] = NULL;
	}
}

void init_power(INT64 *power, int base, int mod)
{
	power[0] = 1;

	for (int i = 1; i < SIZE_ARRAY; ++i)
	{
		power[i] = power[i - 1] * base % mod;
	}
}

INT64 get_hash(int size_of_text, INT64* hash, INT64* power, int mod)
{
	return(hash[size_of_text - 1]);
}

int main()
{
	ifstream file("Text.txt");
	string text;
	string string_that_find;
	if (file.is_open())
	{
		while (!file.eof())
		{
			string temp;
			getline(file, temp);

			text += temp;
		}
	}
	file.close();
	getline(cin, string_that_find);

	init_power(power, BASE, MOD);
	init_hash(string_that_find, hash_string, BASE, MOD);
	INT64 text_length = text.size();
	int _iterator = 0;
	while (true)
	{
		init_hash(text, hash_text, BASE, MOD);

		if (get_hash(text.size() - 1, hash_text, power, MOD) == get_hash(string_that_find.size() - 1, hash_string, power, MOD))
		{
			cout << "FIND" << endl;
			cout << "vs = " << _iterator;
			break;
		}
		if (_iterator == text.size() - 1) { cout << "NOT FIND"; break; };

		text.erase(0,1);
		clear_hash(hash_text);
		_iterator++;
	}
	
	return 0;
}