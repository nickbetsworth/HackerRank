#include <iostream>
#include <algorithm>

//https://www.hackerrank.com/challenges/diagonal-difference

int main() {
	int size;
	std::cin >> size;

	int n;
	long diagonal_1_sum = 0;
	long diagonal_2_sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cin >> n;
			// Diagonal 1 is where i == j
			if (i == j)
				diagonal_1_sum += n;
			// Diagonal 2 is where i == size - (j + 1)
			if (i == size - (j + 1))
				diagonal_2_sum += n;
		}
	}

	std::cout << abs(diagonal_2_sum - diagonal_1_sum) << std::endl;

	return 0;
}