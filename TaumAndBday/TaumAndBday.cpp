#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/taum-and-bday

int main() {
	int num_tests;

	std::cin >> num_tests;

	long num_black, num_white; // Number of black and white presents required
	long cost_black, cost_white, cost_convert;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> num_black >> num_white;
		std::cin >> cost_black >> cost_white >> cost_convert;

		// Stores the cost of the cheapest and most expensive presents respectively
		long cheap_cost, expensive_cost;
		// Stores the number of cheap presents required, and number of expensive
		long cheap_num, expensive_num;

		if (cost_black < cost_white) {
			cheap_cost = cost_black;
			cheap_num = num_black;
			expensive_cost = cost_white;
			expensive_num = num_white;
		}
		else {
			cheap_cost = cost_white;
			cheap_num = num_white;
			expensive_cost = cost_black;
			expensive_num = num_black;
		}

		// Determine whether or not it is worthwhile converting the expensive ones..
		// If so, reduce the 'expensive' price, to the cost of converting the cheap one
		if (cheap_cost + cost_convert < expensive_cost)
			expensive_cost = cheap_cost + cost_convert;

		// Calculate the final cost
		long cost = cheap_cost * cheap_num + expensive_cost * expensive_num;

		std::cout << cost << std::endl;
	}

	return 0;
}