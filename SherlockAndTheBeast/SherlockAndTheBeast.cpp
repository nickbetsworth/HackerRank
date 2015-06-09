#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
//https://www.hackerrank.com/challenges/sherlock-and-the-beast

std::string get_largest_decent_number(const int n) {
	// Hard code the cases where this algorithm fails
	switch (n) {
	case 1:
		return "-1";
	case 2:
		return "-1";
	case 4:
		return "-1";
	case 7:
		return "-1";
	}

	// Work out how many 3s we need
	int num_3s;

	// n % 3, number of uneven 5s
	// == 0, no need to do anything
	// == 1, e.g 10, 13, 16, 19, 22 Replace 2x sets of 3s (10 3s)
	// == 2, e.g 11, 14, 17, 20, 23 Replace 1x set of 3s (5 3s)
	switch (n % 3) {
	case 0:
		num_3s = 0;
		break;
	case 1:
		num_3s = 10;
		break;
	case 2:
		num_3s = 5;
		break;
	}

	int num_5s = n - num_3s;

	return std::string(num_5s, '5') + std::string(num_3s, '3');
}

int main() {
	int num_tests, num_digits;
	std::cin >> num_tests;
	
	for (int i = 0; i < num_tests; i++) {
		std::cin >> num_digits;
		std::cout << get_largest_decent_number(num_digits) << std::endl;
	}

	return 0;
}