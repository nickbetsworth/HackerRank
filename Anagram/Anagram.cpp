#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/anagram

// In order for one string to be an anagram of another
// Both strings must contain exactly the same letter counts, for all possible characters
// So we find the counts of letters in each string, and sum the absolute differences

// Converts a character in the range 'a'-'z' to an index 0-25
inline unsigned char_to_index(const char& c) {
	return c - 'a';
}

// Counts the number of changes that must be made to 
int count_changes(const std::string& s) {
	// If we have different size substrings, no anagram is possible
	if (s.length() % 2 == 1)
		return -1;

	std::string s1 = std::string(s.begin(), s.begin() + s.size() / 2);
	std::string s2 = std::string(s.begin() + s.size() / 2, s.end());

	// Counts the frequencies of 'a'-'z' in s1 and s2 respectively
	// Use signed numbers just to prevent underflow when calculating difference
	int s1_counts[26] = { 0 };
	int s2_counts[26] = { 0 };

	for (char c : s1)
		s1_counts[char_to_index(c)]++;

	for (char c : s2)
		s2_counts[char_to_index(c)]++;

	unsigned changes_required = 0;

	for (int i = 0; i < 26; i++)
		changes_required += abs(s1_counts[i] - s2_counts[i]);

	// Divide by 2, as we currently have calculated the number of different characters
	// across both strings. But we only require changes to be made to one of the strings.
	changes_required /= 2;

	return changes_required;
}

int main() {
	unsigned num_tests;
	std::cin >> num_tests;

	std::string s;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> s;

		std::cout << count_changes(s) << std::endl;
	}
	
	return 0;
}