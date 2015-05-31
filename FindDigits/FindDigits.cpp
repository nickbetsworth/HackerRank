#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/find-digits

// Converts an integer in to a list of its respective digits
std::vector<unsigned> digitize(const unsigned number) {
	std::vector<unsigned> digits;
	// Make a copy of the number
	unsigned number_copy = number;
	while (number_copy > 0) {
		unsigned digit = number_copy % 10;
		// Only add non-zero digits
		if (digit > 0)
			digits.push_back(digit);

		number_copy /= 10;
	}

	return digits;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	int n; // The number of splits that may be made
	for (int t = 0; t < num_tests; t++) {
		std::cin >> n;

		auto digits = digitize(n);
		// Output the number of digits that can evenly divide the number
		std::cout << std::count_if(digits.begin(), digits.end(), [n](unsigned digit){ return n % digit == 0; }) << std::endl;
	}

	return 0;
}