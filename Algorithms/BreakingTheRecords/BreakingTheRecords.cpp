#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/breaking-best-and-worst-records/


int main()
{
	size_t num_games, score;
	std::cin >> num_games;

	size_t num_times_broken_least = 0;
	size_t num_times_broken_most = 0;

	size_t current_min, current_max;

	std::cin >> current_max;
	current_min = current_max;

	for (size_t i = 0; i<num_games-1; i++)
	{
		std::cin >> score;

		if (score > current_max)
		{
			num_times_broken_most++;
			current_max = score;
		}

		if (score < current_min)
		{
			num_times_broken_least++;
			current_min = score;
		}
	}

	std::cout << num_times_broken_most << " " << num_times_broken_least;

	return 0;
}