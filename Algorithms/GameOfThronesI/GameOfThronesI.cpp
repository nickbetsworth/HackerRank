#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/game-of-thrones

const unsigned NUM_CHARS = 26;

// Works out if there is an available permutation of a string which is palidrome
// This goes by the idea that every character, must have a matching character
// With the exception of one single uneven character, which is placed in the center
// (Note for an evenly sized string, it is not possible to have only 1 uneven character)
bool is_anagram_palindrome(const std::string& s) {
	unsigned counts[NUM_CHARS] = { 0 };

	for (int i = 0; i < s.length(); i++) {
		int index = s.at(i) - 'a';
		counts[index]++;
	}

	bool uneven_found = false;
	// 
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
	
	return true;
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