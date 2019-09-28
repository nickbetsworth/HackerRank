#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/halloween-party

long long calculate_max_pieces(long long k) {
	long long splits_on_x_axis = k / 2;
	// Add k % 2 incase k is an odd number
	long long splits_on_y_axis = k / 2 + k % 2;

	return splits_on_x_axis * splits_on_y_axis;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	int k; // The number of splits that may be made
	for (int t = 0; t < num_tests; t++) {
		std::cin >> k;

		std::cout << calculate_max_pieces(k) << std::endl;
	}

	return 0;
}