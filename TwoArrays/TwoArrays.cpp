#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/two-arrays

bool meets_min_cost(int min_cost, std::vector<unsigned> &a, std::vector<unsigned> &b)
{
	// Sort array a in ascending order, array b in descending order.
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end(), std::greater<unsigned>());

	// Ensure that the sum of all paired values between a and b are at least the value of k.

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] + b[i] < min_cost)
			return false;
	}

	return true;
}

int main()
{
	unsigned num_tests;
	std::cin >> num_tests;

	for (int i = 0; i < num_tests; i++)
	{
		int n, k;
		std::cin >> n >> k;

		std::vector<unsigned> a(n);
		std::vector<unsigned> b(n);

		for (int i = 0; i < n; i++)
		{
			std::cin >> a[i];
		}

		for (int i = 0; i < n; i++)
		{
			std::cin >> b[i];
		}

		if (meets_min_cost(k, a, b))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}