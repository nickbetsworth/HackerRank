#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/gem-stones

// Solution works by representing each rock by a string of unique bits,
// where each bit represents a potential element (1 denotes the element exists, 0 otherwise)
// We then perform a bitwise AND operation across all rock's elements,
// and are thus left with a single string of bits that contains the common elements

// Stores in terms of bits the elements that make up a particular rock
// 32 bit is sufficient as we only require 26 bits ('a'-'z')
typedef unsigned long rock_elements;

// Gets a bitwise representation of the elements contained within the rock composition
rock_elements get_elements(const std::string& composition) {
	rock_elements elements = 0;
	for (int i = 0; i < composition.length(); i++) {
		char c = composition.at(i);
		unsigned index = c - 'a'; // Convert char to index 0-25
		elements = elements | (1 << index);
	}

	return elements;
}

// Counts the number of set bits in the given data
unsigned count_set_bits(rock_elements elements) {
	unsigned set_bits = 0;
	for (int i = 0; i < 26; i++) {
		if (elements % 2 == 1)
			set_bits++;

		elements = elements >> 1;
	}

	return set_bits;
}

int main() {
	int num_rocks;
	std::cin >> num_rocks;

	std::string composition;
	rock_elements common_elements = std::numeric_limits<rock_elements>::max();
	for (int i = 0; i < num_rocks; i++) {
		// Read in the composition for this rock
		std::cin >> composition;

		common_elements &= get_elements(composition);
	}

	std::cout << count_set_bits(common_elements) << std::endl;

	return 0;
}