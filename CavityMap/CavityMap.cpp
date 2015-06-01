#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/cavity-map

struct Map {
	int n; // Size of the map (n x n)
	int* data; // Map data (n x n array)
};

bool is_cavity(Map map, int pos_x, int pos_y) {
	int value = map.data[pos_x * map.n + pos_y];
	if (value > map.data[(pos_x - 1) * map.n + pos_y] &&
		value > map.data[(pos_x + 1) * map.n + pos_y] &&
		value > map.data[pos_x * map.n + pos_y - 1] &&
		value > map.data[pos_x * map.n + pos_y + 1]) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	Map map;
	std::cin >> map.n;

	// Create an array to store the map
	map.data = new int[map.n * map.n];
	// A vector to store all locations where an X should be marked
	std::vector<std::pair<int, int>> x_locations;

	std::string s;
	for (int i = 0; i < map.n; i++) {
		// Read in the current row of numbers
		std::cin >> s;

		// Add each of the digits to the array
		for (int j = 0; j < map.n; j++) {
			// Convert the character to an integer and store it
			map.data[i * map.n + j] = static_cast<int>(s.at(j) - '0');
		}
	}

	// Check each possible location (non-border) if it is a cavity
	for (int i = 1; i < map.n - 1; i++) {
		for (int j = 1; j < map.n - 1; j++) {
			if (is_cavity(map, i, j))
				x_locations.push_back(std::make_pair(i, j));
		}
	}
	
	// Replace all X locations in data with a -1, so that when we print we know to place an X
	// We did not place the -1 during previous loop, as other locations may have relied on that value
	// May have been better to just run with 2 copies of the array ^
	for (auto x_location : x_locations) {
		map.data[x_location.first * map.n + x_location.second] = -1;
	}

	// Output the final result

	for (int i = 0; i < map.n; i++) {
		for (int j = 0; j < map.n; j++) {
			int val = map.data[i * map.n + j];
			if (val == -1)
				std::cout << "X";
			else
				std::cout << val;
		}

		std::cout << std::endl;
	}

	return 0;
}