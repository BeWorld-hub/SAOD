#include <iostream>
#include <chrono>

int main() {
	int size{};
	int vs{};
	int reverse{};
	std::cin >> size;
	int* ar = new int[size];
	for (int numIter = 0; numIter < size; numIter++) {
		ar[numIter] = rand() % 100;
	}
	auto start_time = std::chrono::steady_clock::now();

	for (int firstIter = 0; firstIter < size - 1; firstIter++)
		for (int secondIter = firstIter + 1; secondIter < size; secondIter++) {
			if (ar[firstIter] > ar[secondIter]) {
				vs++;
				std::swap(ar[firstIter], ar[secondIter]);
				reverse++;
			}
			else { vs++; }
		}

	std::cout << std::endl;

	auto end_time = std::chrono::steady_clock::now();
	auto work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "time(miliseconds): " << work_time.count() << std::endl;
	std::cout << "vs = " << vs << std::endl;
	std::cout << "reverse = " << reverse << std::endl;
	std::cout << "reverse + vs = " << reverse + vs << std::endl;
	system("pause"); return 0;
}