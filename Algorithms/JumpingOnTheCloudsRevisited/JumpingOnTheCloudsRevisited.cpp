#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited

int main() {
	size_t num_clouds, jump_distance;

	std::cin >> num_clouds >> jump_distance;

	size_t num_jumps = num_clouds / jump_distance;
	

	// Account for the returning jump to the first cloud here.

	size_t cloud_type;
	std::cin >> cloud_type;
	size_t energy = 100  - (cloud_type == 0 ? 1 : 3);


	// Perform the remaining jumps.

	for (size_t i = 0; i < num_jumps-1; i++)
	{
		for (size_t j = 0; j < jump_distance; j++)
		{
			std::cin >> cloud_type;
		}

		if (cloud_type == 0)	energy -= 1;
		else					energy -= 3;
	}

	std::cout << energy;

	return 0;
}