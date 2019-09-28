#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

//https://www.hackerrank.com/challenges/jim-and-the-skyscrapers

unsigned long get_possible_routes(const std::vector<unsigned>& skyscrapers) {
	// Maps from skyscraper heights to number of active skyscrapers
	// at that given height
	std::map<unsigned, unsigned> active_counts; 

	unsigned long num_routes = 0;
	// Loop through all skyscrapers
	for (unsigned height : skyscrapers) {
		// If this height already exists in the map
		if (active_counts[height] > 0) {
			num_routes += active_counts[height];
			active_counts[height]++;
		}
		else {
			active_counts[height] = 1;
		}

		// Remove all keys which are less than this
		// Find the iterator to the current height
		auto it = active_counts.find(height);
		// Remove all heights before this (map is ordered, so we can simply remove active_counts.begin() -> it
		if (it != active_counts.begin()) {
			active_counts.erase(active_counts.begin(), it);
		}
	}

	// Multiply the number of routes by 2, as we can go in both directions
	num_routes *= 2;

	return num_routes;
}

int main() {
	int n_ss; // The number of skyscrapers
	std::vector<unsigned> skyscrapers; // Stores the height of the skyscrapers
	

	std::cin >> n_ss;

	// Read in the heights of the skyscrapers
	unsigned ss;
	for (int i = 0; i < n_ss; i++) {
		std::cin >> ss;
		skyscrapers.push_back(ss);
	}

	std::cout << get_possible_routes(skyscrapers);

	return 0;
}