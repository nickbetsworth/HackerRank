#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/organizing-containers-of-balls/


int main()
{
	size_t num_queries, n, num_balls;
	std::cin >> num_queries;

	for (size_t q = 0; q < num_queries; q++)
	{
		std::cin >> n;

		// Read in the number of balls in each container, and the total number of balls with a given ID.
		std::vector<size_t> ball_counts(n);
		std::vector<size_t> container_counts(n);

		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				std::cin >> num_balls;
				ball_counts[i] += num_balls;
				container_counts[j] += num_balls;
			}
		}

		// Sort both of the lists and cross compare them.
		std::sort(ball_counts.begin(), ball_counts.end());
		std::sort(container_counts.begin(), container_counts.end());

		bool possible = true;
		for (size_t i = 0; i < n; i++)
		{
			if (ball_counts[i] != container_counts[i])
			{
				possible = false;
				break;
			}
		}

		if (possible)	std::cout << "Possible" << std::endl;
		else			std::cout << "Impossible" << std::endl;
	}

	return 0;
}