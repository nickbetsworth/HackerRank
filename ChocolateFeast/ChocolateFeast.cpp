#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/chocolate-feast

unsigned get_free_bar_count(const unsigned num_wrappers, const unsigned wrappers_required) {
	// Work out how many free bars we get from the current wrappers
	unsigned free_bars = num_wrappers / wrappers_required;
	// If we have new bars available
	if (free_bars > 0) {
		// Workout how many leftovers we had from the previous swap
		unsigned leftovers = num_wrappers % wrappers_required;
		// Recursively get free bars using the wrappers
		free_bars += get_free_bar_count(free_bars + leftovers, wrappers_required);
	}
	
	return free_bars;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	unsigned money; // How much money he has
	unsigned price; // Price of chocolate bar
	unsigned wrappers; // Number of wrappers required for free chocolate bar
	for (int t = 0; t < num_tests; t++) {
		std::cin >> money >> price >> wrappers;

		// Work out how many he can initially buy
		unsigned num_bars = money / price;

		std::cout << num_bars + get_free_bar_count(num_bars, wrappers) << std::endl;
	}

	return 0;
}