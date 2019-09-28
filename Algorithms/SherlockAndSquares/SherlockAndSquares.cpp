#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/sherlock-and-squares

// Calculates the number of square numbers s, a <= s <= b
unsigned get_num_square_ints(unsigned a, unsigned b) {
	unsigned count = 0;
	
	// Work out the first integer which produces a square within the range a <= s <= b
	unsigned sqrt_a = ceil(sqrt(a));
	// Work out the final integer which produces a square within the range a <= s <= b
	unsigned sqrt_b = floor(sqrt(b)) + 1;
	return sqrt_b - sqrt_a;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	unsigned a, b;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> a >> b;
		std::cout << get_num_square_ints(a, b) << std::endl;
	}

	return 0;
}