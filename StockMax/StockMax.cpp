#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/stockmax

unsigned long get_max_profit(const std::vector<unsigned long> &stock_prices)
{
	unsigned long profit = 0;
	int start_ptr = 0;
	while (start_ptr < stock_prices.size())
	{
		unsigned long max = 0;
		int max_ptr = -1;
		unsigned long running_total = 0;
		unsigned long max_purchase_cost = 0;
		for (int i = start_ptr; i < stock_prices.size(); i++)
		{
			if (stock_prices[i] > max)
			{
				max = stock_prices[i];
				max_ptr = i;

				max_purchase_cost = running_total;
			}

			running_total += stock_prices[i];
		}

		if (max_ptr != start_ptr)
		{
			unsigned long earnings = ((max_ptr - start_ptr) * max) - max_purchase_cost;
			profit += earnings;
		}

		start_ptr = max_ptr+1;
	}

	return profit;
}

int main()
{
	int num_tests, n;
	std::cin >> num_tests;

	for (int i = 0; i < num_tests; i++)
	{
		std::cin >> n;
		std::vector<unsigned long> share_prices(n);

		for (int j = 0; j < n; j++)
		{
			std::cin >> share_prices[j];
		}

		std::cout << get_max_profit(share_prices) << std::endl;
	}

	return 0;
}