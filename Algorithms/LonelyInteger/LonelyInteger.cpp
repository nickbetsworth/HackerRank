#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/lonely-integer


int main() {
	int num_ints;

	std::cin >> num_ints;

	int val = 0;
	int input;
	for (int t = 0; t < num_ints; t++) {
		std::cin >> input;
		val ^= input;
	}

	std::cout << val;
}