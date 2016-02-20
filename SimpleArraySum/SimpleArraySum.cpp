#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/simple-array-sum

int main() {
	int array_size;
	std::cin >> array_size;

	long total = 0;
	for (int i = 0; i < array_size; i++) {
		int num;
		std::cin >> num;

		total += num;
	}

	std::cout << total;

	return 0;
}