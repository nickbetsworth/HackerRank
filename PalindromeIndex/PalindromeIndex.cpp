#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/palindrome-index

int get_palindrome_index(const std::string &s) {
	// Split the string in to a left half and a right half
	std::string left_half = std::string(s.begin(), s.begin() + ceil(s.size() / 2.0));
	std::string right_half = std::string(s.rbegin(), s.rbegin() + s.size() / 2);

	int misplaced = -1;

	for (int left_ptr = 0, right_ptr = 0;
		left_ptr < s.size() / 2 && right_ptr < s.size() / 2;
		++left_ptr, ++right_ptr) {
		if (left_half.at(left_ptr) != right_half.at(right_ptr)) {
			// If we have already set misplaced then we must have chosen the wrong misplaced character
			if (misplaced != -1) {
				// Set the misplaced character to the opposite half of the array
				return s.size() - 1 - misplaced;
			}
			else {
				if (left_half.at(left_ptr + 1) == right_half.at(right_ptr)) {
					misplaced = left_ptr;
					++left_ptr;
				}
				else {
					misplaced = s.size() - 1 - right_ptr;
					++right_ptr;
				}
			}
		}
	}

	return misplaced;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	std::string s;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> s;
		std::cout << get_palindrome_index(s) << std::endl;
	}

	return 0;
}