#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/alternating-characters

unsigned calc_min_deletions(const std::string& s) {
	unsigned deletions = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s.at(i - 1) == s.at(i))
			deletions++;
	}

	return deletions;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	std::string s;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> s;
		std::cout << calc_min_deletions(s) << std::endl;
	}

	return 0;
}