#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/filling-jars

int main() {
	int array_size, num_ops;
	std::cin >> array_size >> num_ops;

	unsigned long long total = 0;
	int a, b, n;
	for (int i = 0; i < num_ops; i++) {
		std::cin >> a >> b >> n;

		int bin_count = (b - a) + 1;
		// Cast one number to a ULL to prevent overflow of multiplication
		total += static_cast<unsigned long long>(bin_count) * n;
	}

	unsigned long long average = total / array_size;

	std::cout << average << std::endl;

	return 0;
}