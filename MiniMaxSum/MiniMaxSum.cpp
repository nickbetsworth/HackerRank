#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/mini-max-sum

int main() {
	long sum = 0;
	long min = std::numeric_limits<long>::max();
	long max = std::numeric_limits<long>::min();
	
	long temp;

	for (int i = 0; i < 5; i++)
	{
		std::cin >> temp;

		sum += temp;
		min = std::min(min, temp);
		max = std::max(max, temp);
	}

	std::cout << (sum - max) << " " << (sum - min);

	return 0;
}