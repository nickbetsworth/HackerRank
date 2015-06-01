#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

//https://www.hackerrank.com/challenges/manasa-and-stones

int main() {
	int num_tests;
	std::cin >> num_tests;

	unsigned stones; // Total number of stones
	unsigned a; // Difference a
	unsigned b; // Difference b
	for (int t = 0; t < num_tests; t++) {
		std::cin >> stones >> a >> b;
		// Decrement the number of stones, as the first stone is always 0
		stones--;

		// Use a set to store the numbers, as we may only output each number once
		std::set<long long> results;

		// Run through all possible combinations of quantities of a and b stones
		for (int num_a = 0, num_b = stones; num_a <= stones; num_a++, num_b--) {
			long long value = num_a * a + num_b * b;
			results.insert(value);
		}

		for (long long result : results) {
			std::cout << result << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}