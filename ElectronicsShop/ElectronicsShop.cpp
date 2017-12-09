#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/electronics-shop/


int main()
{
	size_t s, n, m;
	std::cin >> s >> n >> m;

	std::vector<size_t> keyboardPrices(n);
	std::vector<size_t> usbPrices(m);

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> keyboardPrices[i];
	}

	for (size_t i = 0; i < m; i++)
	{
		std::cin >> usbPrices[i];
	}


	size_t max_price = 0;

	// Brute-force solution.
	// Find the maximal pairing that satisfies the cost.
	// This could be optimised by sorting the lists in to ascending order, and terminating
	// on the inner array if the sum exceeds the valid amount. Brute-force solution seems
	// to solve all cases, no timeouts.
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			size_t cost = keyboardPrices[i] + usbPrices[j];
			if (cost > max_price && cost <= s) max_price = cost;
		}
	}

	if (max_price == 0)	std::cout << "-1";
	else				std::cout << max_price;

	return 0;
}