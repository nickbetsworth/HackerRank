#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/counting-valleys/


int main()
{
	size_t num_steps;
	std::cin >> num_steps;

	// Consume the new line character.
	std::getchar();

	size_t num_valleys = 0;

	int current_elevation = 0;

	for (size_t i = 0; i < num_steps; i++)
	{
		char c = std::getchar();
		if (c == 'U')	current_elevation += 1;
		else			current_elevation -= 1;

		if (current_elevation == 0)
		{
			if (c == 'U')	num_valleys++;
		}
	}

	std::cout << num_valleys;

	return 0;
}