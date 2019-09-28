#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/migratory-birds/


int main()
{
	size_t birdCounts[5] = {0};
	size_t num_birds, bird_id;

	std::cin >> num_birds;

	for (size_t i = 0; i < num_birds; i++)
	{
		std::cin >> bird_id;
		birdCounts[bird_id - 1]++;
	}

	size_t max = 0;
	size_t max_id = 0;
	for (size_t i = 0; i < 5; i++)
	{
		if (birdCounts[i] > max)
		{
			max = birdCounts[i];
			max_id = i;
		}
	}

	std::cout << max_id + 1;

	return 0;
}