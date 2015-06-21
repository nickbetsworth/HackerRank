#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/encryption

std::string encrypt_string(const std::string& s) {
	unsigned string_length = s.length();
	double sqrt_length = sqrt(string_length);
	unsigned rows = floor(sqrt_length + 0.5);
	unsigned cols = ceil(sqrt_length);

	std::string encrypted = "";
	unsigned string_pos;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			string_pos = j * cols + i;

			if (string_pos >= s.length())
				break;
			else
				encrypted += s.at(string_pos);
		}

		// New word, add a space
		encrypted += ' ';
	}
	
	return encrypted;
}

int main() {
	std::string s;
	std::cin >> s;

	std::cout << encrypt_string(s) << std::endl;

	return 0;
}