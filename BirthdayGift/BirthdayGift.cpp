#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/bday-gift

int main() {
	int num_steps;
	std::cin >> num_steps;

	double ev = 0;
	int n;
	for (int i = 0; i < num_steps; i++) {
		std::cin >> n;

		// Expected value at each step
		// Is half it's value (as it will occurr 1/2 times)
		ev += n / 2.0;
	}

	printf("%.1f", ev);

	return 0;
}