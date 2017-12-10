#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/cats-and-a-mouse/problem


int main()
{
	size_t q;
	std::cin >> q;

	for (size_t i = 0; i < q; i++)
	{
		int x, y, z;
		std::cin >> x >> y >> z;

		// Compute the absolute difference in position between cat A and the mouse, and cat B and the mouse.

		int dist_a = std::abs(z - x);
		int dist_b = std::abs(z - y);

		if (dist_a < dist_b)		std::cout << "Cat A" << std::endl;
		else if (dist_b < dist_a)	std::cout << "Cat B" << std::endl;
		else						std::cout << "Mouse C" << std::endl;
	}

	return 0;
}