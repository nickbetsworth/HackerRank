#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem


int main()
{
	const size_t ORDINARY_CLOUD = 0;
	const size_t THUNDER_CLOUD = 1;

	size_t n;
	std::cin >> n;

	std::vector<size_t> clouds(n);

	size_t num_jumps = 0;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> clouds[i];
	}

	for (size_t i = 1; i < n; i++)
	{
		if (i < n-1 && clouds[i + 1] == ORDINARY_CLOUD)
		{
			num_jumps++;
			i++;
		}
		else if (clouds[i] == ORDINARY_CLOUD)
		{
			num_jumps++;
		}
	}

	std::cout << num_jumps;

	return 0;
}