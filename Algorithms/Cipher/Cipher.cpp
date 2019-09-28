#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

//https://www.hackerrank.com/challenges/cipher

char ascii_to_bit(char c) {
	return static_cast<char>(c - '0');
}

int main() {
	int num_bits, num_shifts;
	std::string s; // The ciphered bit sequence
	std::cin >> num_bits >> num_shifts;

	std::cin >> s;

	int ciphered_length = num_bits + num_shifts - 1;
	int deciphered_length = num_bits;

	char* ciphered = new char[ciphered_length];
	char* deciphered = new char[deciphered_length];

	// Convert the cipher in to an array of integers
	for (int i = 0; i < s.length(); i++) {
		ciphered[i] = ascii_to_bit(s.at(i));
	}

	// Keeps track of the number of loop iterations that have taken place
	int num_its = 0;
	// Rather than XORing the array of bits each time, we can keep track of the result
	// of previous XORs, as a single bit, and maintain this to reduce the number of operations
	char current_xor = 0;
	// Stores the previous bits, so we can reverse the XORs to maintain current_xor
	std::queue<char> previous_bits;
	// Loop from the end of the ciphered array, to the point at which we will have
	// deciphered all characters (length of deciphered array as iterations)
	for (int i = ciphered_length - 1; i >= (ciphered_length - num_bits); i--) {
		int result = ciphered[i];
		
		// If we have reached the maximum width of XORs (we are no longer XORing from newly shifted arrays)
		if (num_its >= num_shifts) {
			// We need to remove the oldest bit
			current_xor ^= previous_bits.front();
			previous_bits.pop();
		}

		result ^= current_xor;

		previous_bits.push(result);

		current_xor ^= result;

		deciphered[deciphered_length - 1 - num_its] = result;

		num_its++;
	}

	for (int i = 0; i < deciphered_length; i++) {
		std::cout << static_cast<char>(deciphered[i] + '0');
	}
	
	return 0;
}