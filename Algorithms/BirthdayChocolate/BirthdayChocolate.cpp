#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/the-birthday-bar/


int main()
{
	int num_squares, d, m;

	std::cin >> num_squares;

	std::vector<int> squareValues(num_squares);
	for (int i = 0; i < num_squares; i++)
	{
		std::cin >> squareValues[i];
	}

	std::cin >> d >> m;

	int num_combinations = 0;
	for (int i = 0; i <= num_squares - m; i++)
	{
		int current_sum = 0;

		for (int j = 0; j < m; j++)
		{
			current_sum += squareValues[i + j];
		}

		if (current_sum == d)	num_combinations++;
	}

	std::cout << num_combinations;

	return 0;
}