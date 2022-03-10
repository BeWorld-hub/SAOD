#include <iostream>
#include <chrono>
#include <vector>

int vs = 0;

bool IsArraySort(const int array[], int size_array)
{
	for (int i = 0; i < size_array - 1; i++)
	{
		if (array[i] > array[i + 1]) { return false; }
		vs++;
	}

	return true;
}

int main() {
	int n = 0;
	int reverse = 0;

	std::cin >> n;
	int* major_array;
	major_array = new int[n];
	for (int i = 0; i < n; i++)
	{
		major_array[i] = std::rand();
	}
	auto start_time = std::chrono::steady_clock::now();
	
	while (!IsArraySort(major_array, n))
	{
		std::vector<int> first;
		std::vector<int> second;
		int i = 0;
		
			while (i < n)
			{
				bool flag = true;
				while (flag && i < n) {
					first.push_back(major_array[i]);
					if (major_array[i] > major_array[i + 1]) { flag = false; }

					vs++; 

					i++;
					
				}
				flag = true;
				while (flag && i < n) {
					second.push_back(major_array[i]);
					if (major_array[i] > major_array[i + 1]) { flag = false; }

					vs++; 

					i++;
				}
			}
		

		for (int i = 0; i < n; i++)
		{
			if (first.size() != 0 && second.size() != 0)
			{
				int min_value = std::min(first[0], second[0]);
				vs++;
				major_array[i] = min_value;
				reverse++;
				if (min_value == first[0] && first.size() != 0)
				{
					first.erase(first.begin());
				}
				else if (second.size() != 0)
				{
					second.erase(second.begin());
				}
			}
			else if (first.size() != 0)
			{
				major_array[i] = first[0];
				first.erase(first.begin());
				reverse++;
			}
			else
			{
				major_array[i] = second[0];
				second.erase(second.begin());
				reverse++;
			}
		}
	}

	auto end_time = std::chrono::steady_clock::now();
	auto work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "vs = " << vs << std::endl;
	std::cout << "reverse = " << reverse << std::endl;
	std::cout << "reverse + vs = " << reverse + vs << std::endl;
	std::cout << "time(miliseconds): " << work_time.count() << std::endl;
}