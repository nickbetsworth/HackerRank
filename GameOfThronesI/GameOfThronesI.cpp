#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/game-of-thrones

const unsigned NUM_CHARS = 26;

bool is_anagram_palindrome(const std::string& s) {
	unsigned counts[NUM_CHARS] = { 0 };

	for (int i = 0; i < s.length(); i++) {
		int index = s.at(i) - 'a';
		counts[index]++;
	}

	bool uneven_found = false;
	// Calculate how many uneven (non multiple of 2) characters we have
	// At MOST there can only be 1, (if we have an odd sized string)
	for (int i = 0; i < NUM_CHARS; i++) {
		if (counts[i] % 2 != 0) {
			// If this is the second uneven character we have found,
			// palindrome is not possible, in any case
			if (uneven_found)
				return false;
			else
				uneven_found = true;
		}
	}
	// If we have an even length string, they must be symmetrical,
	// and hence x = 0
	if (s.length() % 2 == 0)
		return uneven_found == false;
	// Otherwise, we must have one uneven character to be placed centrally
	else
		return uneven_found == true
}
int main() {
	std::string s;
	std::cin >> s;

	if (is_anagram_palindrome(s))
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;

	return 0;
}