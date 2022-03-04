#include <iostream>
#include <chrono>

int main() {
	int n{};
	int vs{};
	int reverse{};
	std::cin >> n;
	int* A = new int[n];

	for (int i = 0; i < n; i++)
		A[i] = std::rand();

	int d = n / 2;
	auto start_time = std::chrono::steady_clock::now();
	while (d > 0) {
		for (int i = 0; i < n - d; i++) {
			int j = i;
			while (j >= 0 && A[j] > A[j + d]) {
				vs++;
				std::swap(A[j], A[j + d]);
				reverse++;
				j--;

			}
			vs++;
		}
		d /= 2;
	}

	auto end_time = std::chrono::steady_clock::now();
	auto work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "vs = " << vs << std::endl;
	std::cout << "reverse = " << reverse << std::endl;
	std::cout << "reverse + vs = " << reverse + vs << std::endl;
	std::cout << "time(miliseconds): " << work_time.count() << std::endl;
}