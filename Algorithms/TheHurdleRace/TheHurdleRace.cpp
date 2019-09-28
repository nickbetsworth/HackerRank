#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/the-hurdle-race/problem


int main()
{
	size_t n, k;
	std::cin >> n >> k;

	size_t height;
	size_t max_height = 0;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> height;
		max_height = std::max(max_height, height);
	}

	if (k >= max_height)	std::cout << "0";
	else					std::cout << (max_height - k);

	return 0;
}