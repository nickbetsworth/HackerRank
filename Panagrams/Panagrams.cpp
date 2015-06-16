#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

//https://www.hackerrank.com/challenges/pangrams

int main() {
	// State the required characters so that they may be modified if necessary
	// (Rather than binding it to a sequence of ascii values)
	const std::string required_chars = "abcdefghijklmnopqrstuvwxyz";
	std::string sentence;
	// Read in the sentence
	std::getline(std::cin, sentence);
	// Convert the sentence to lower case
	std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
	// Use an unordered map to store the existence of characters
	// Constant insertion & lookup
	std::unordered_map<char, bool> char_presence_map;

	for (char c : sentence) {
		char_presence_map[c] = true;
	}

	bool is_pangram = true;
	for (char c : required_chars) {
		// If we have found a character which did not exist in the sentence
		if (!char_presence_map[c]) {
			is_pangram = false;
			break;
		}
	}

	if (is_pangram)
		std::cout << "pangram" << std::endl;
	else
		std::cout << "not pangram" << std::endl;

	return 0;
}