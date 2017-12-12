#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/permutation-equation/problem


int main()
{
	size_t n, num;
	std::cin >> n;

	std::map<int, int> numMap;

	for (size_t i = 1; i <= n; i++)
	{
		std::cin >> num;
		numMap[num] = i;
	}

	for (size_t i = 1; i <= n; i++)
	{
		std::cout << numMap[numMap[i]] << std::endl;
	}

	return 0;
}