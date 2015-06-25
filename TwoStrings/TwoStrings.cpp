#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/two-strings

inline int char_to_index(const char& c) {
	return c - 'a';
}

// We can simply get away by finding any two common characters between the strings
// As we are only required to find the presence of a sub-string, not the location
bool has_common_substring(const std::string& s1, const std::string& s2) {
	bool has_char_1[26] = { false };
	bool has_char_2[26] = { false };

	for (const char c : s1) 
		has_char_1[char_to_index(c)] = true;
	for (const char c : s2)
		has_char_2[char_to_index(c)] = true;

	for (int i = 0; i < 26; i++) {
		if (has_char_1[i] && has_char_2[i])
			return true;
	}

	return false;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	std::string s1, s2;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> s1 >> s2;

		if (has_common_substring(s1, s2))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}