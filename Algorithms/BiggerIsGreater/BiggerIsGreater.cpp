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

std::string get_next_permutation_custom(std::string s) {
	// Iterate backwards over the string, to find the last ordered character
	// that we can swap. That is, char at [i + 1] > char at [i].
	int pos1 = -1;
	for (int i = s.size() - 2; i >= 0; i--) {
		if (s.at(i + 1) > s.at(i)) {
			pos1 = i;
			break;
		}
	}

	// If there is no possible permutation
	if (pos1 == -1) {
		return "no answer";
	}
	else {
		const char at_pos1 = s.at(pos1);
		int pos2 = pos1 + 1;
		// Find the last character after pos1, that is > than that of pos
		for (int i = s.size() - 1; i > pos1; i--) {
			if (s.at(i) > at_pos1) {
				pos2 = i;
				break;
			}
		}

		// Swap the two characters we have found
		std::swap(s[pos1], s[pos2]);
		// Sort the sub-string from the first character we found, to the end of the string
		std::sort(s.begin() + pos1 + 1, s.end());

		return s;
	}
		
}

int main() {
	unsigned num_tests;
	std::cin >> num_tests;

	std::string s;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> s;
		std::cout << get_next_permutation_custom(s) << std::endl;
	}

	return 0;
}