#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/sherlock-and-gcd

// Works out the greatest common denominator of a and b
int gcd(int a, int b) {

	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main() {
	int num_tests, array_size, current_gcd, num;
	std::cin >> num_tests;

	for (int i = 0; i < num_tests; i++) {
		std::cin >> array_size;

		// Read in the first number, and take this as the starting GCD
		std::cin >> current_gcd;
		
		// Loop through the remaining inputs (array_size - 1 as we took one already)
		for (int j = 0; j < array_size - 1; j++) {
			std::cin >> num;
			current_gcd = gcd(current_gcd, num);
		}

		// If there was a subset with no common denominator > 1
		if (current_gcd == 1)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}