#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/cut-the-sticks


int main() {
	int num_ints;
	std::vector<int> sticks;

	std::cin >> num_ints;

	int input;
	for (int t = 0; t < num_ints; t++) {
		std::cin >> input;
		sticks.push_back(input);
	}

	// Cut the sticks until all sticks are of length 0
	while (sticks.size() > 0) {
		// Output the number of sticks affected
		std::cout << sticks.size() << std::endl;

		// Find the minimum length stick
		int min_stick = *std::min_element(sticks.begin(), sticks.end());

		// Cut all sticks by the minimum amounts
		std::transform(sticks.begin(), sticks.end(), sticks.begin(), [min_stick](int val) { return val - min_stick; });

		// Remove sticks which are at or below 0 length
		sticks.erase(std::remove_if(sticks.begin(), sticks.end(), [](int val) { return val <= 0; }), sticks.end());
	}
}