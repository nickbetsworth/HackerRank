#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/designer-pdf-viewer

int main() {
	int heights[26];
	std::string s;

	for (int i = 0; i < 26; i++)
	{
		std::cin >> heights[i];
	}

	std::cin >> s;

	// Identify the letter within string s with the maximum height

	int max_height = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int char_id = (int)s.at(i) - 'a';
		int height = heights[char_id];

		max_height = std::max(height, max_height);
	}

	int area = max_height * s.length();
	std::cout << area;

	return 0;
}