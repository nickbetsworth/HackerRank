#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/apple-and-orange

int main() {
	int s, t, a, b, m, n;
	std::cin >> s >> t >> a >> b >> m >> n;

	// Pre-compute the range of distances for apples and oranges, which would result
	// in them falling on the house.

	int a_min_dist = s - a;
	int a_max_dist = t - a;
	int o_min_dist = s - b;
	int o_max_dist = t - b;

	int dist;
	int num_apples = 0;
	for (int i = 0; i < m; i++)
	{
		std::cin >> dist;
		if (dist >= a_min_dist && dist <= a_max_dist) num_apples++;
	}

	int num_oranges = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> dist;
		if (dist >= o_min_dist && dist <= o_max_dist) num_oranges++;
	}

	std::cout << num_apples << std::endl;
	std::cout << num_oranges;

	return 0;
}