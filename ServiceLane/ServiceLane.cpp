#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/service-lane

int main() {
	int num_segments, num_test_cases;
	// Stores the list of segments
	std::vector<int> segments;

	std::cin >> num_segments >> num_test_cases;

	// Read in all of the segments
	int segment;
	for (int i = 0; i < num_segments; i++) {
		std::cin >> segment;
		segments.push_back(segment);
	}

	// Run each of the test cases
	int i, j;
	for (int t = 0; t < num_test_cases; t++) {
		std::cin >> i >> j;
		int min_val = *std::min_element(segments.begin() + i, segments.begin() + j + 1);

		std::cout << min_val << std::endl;
	}

	std::cin >> i;
}