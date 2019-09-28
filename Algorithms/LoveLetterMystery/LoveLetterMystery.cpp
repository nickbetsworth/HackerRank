#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/the-love-letter-mystery

int min_operations(const std::string& s) {
	int operations = 0;
	// Loop through the first half of the array, and find the corresponding character
	// in the other half of the array that needs to be matched up
	for (int i = 0; i < s.length() / 2; i++) {
		// The character that needs to be matched up with
		int j = s.length() - 1 - i;

		// Calculate the difference
		int difference = abs(s.at(i) - s.at(j));
		operations += difference;
	}

	return operations;
}

int main() {
	int num_test_cases;


	std::cin >> num_test_cases;

	std::string s;
	for (int t = 0; t < num_test_cases; t++) {
		std::cin >> s;
		std::cout << min_operations(s) << std::endl;
	}
}