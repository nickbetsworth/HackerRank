#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/bigger-is-greater

std::string get_next_permutation(std::string s) {
	if (std::next_permutation(s.begin(), s.end()))
		return s;
	else
		return "no answer";
}

int main() {
	unsigned num_tests;
	std::cin >> num_tests;

	std::string s;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> s;
		std::cout << get_next_permutation(s) << std::endl;
	}

	return 0;
}