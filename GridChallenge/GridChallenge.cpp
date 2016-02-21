#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/grid-challenge

bool can_be_ordered(std::vector<std::string> grid)
{
	int n = grid.size();
	// Sort each of the rows
	for (auto& s : grid)
	{
		std::sort(s.begin(), s.end());
	}

	// We know that the rows are already sorted.
	// Check if we have lexicographical order across the columns.

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (grid[j][i] > grid[j + 1][i])
				return false;
		}
	}

	return true;
}

int main()
{
	int num_tests;
	std::cin >> num_tests;

	for (int k = 0; k < num_tests; k++)
	{
		int n;
		std::cin >> n;
		std::vector<std::string> grid(n);

		// Read in the grid, and sort each row before storing it.
		std::string row;
		for (int i = 0; i < n; i++)
		{
			std::cin >> row;
			grid[i] = row;
		}

		if (can_be_ordered(grid))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}