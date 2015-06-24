#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/make-it-anagram

// In order for one string to be an anagram of another
// Both strings must contain exactly the same letter counts, for all possible characters
// So we find the counts of letters in each string, and sum the absolute differences

// Converts a character in the range 'a'-'z' to an index 0-25
inline unsigned char_to_index(const char& c) {
	return c - 'a';
}

// Counts the number of deletions that are required to make s1 and s2 an anagram
unsigned count_deletions(const std::string& s1, const std::string& s2) {
	// Counts the frequencies of 'a'-'z' in s1 and s2 respectively
	// Use signed numbers just to prevent underflow when calculating difference
	int s1_counts[26] = { 0 };
	int s2_counts[26] = { 0 };

	for (char c : s1)
		s1_counts[char_to_index(c)]++;

	for (char c : s2)
		s2_counts[char_to_index(c)]++;

	unsigned deletions_required = 0;

	for (int i = 0; i < 26; i++)
		deletions_required += abs(s1_counts[i] - s2_counts[i]);

	return deletions_required;
}

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;

	std::cout << count_deletions(s1, s2) << std::endl; 

	return 0;
}