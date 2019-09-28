#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/priyanka-and-toys


int main()
{
	unsigned num_toys;
	std::cin >> num_toys;

	std::vector<unsigned> toy_weights(num_toys);

	for (int i = 0; i < num_toys; i++)
	{
		std::cin >> toy_weights[i];
	}

	std::sort(toy_weights.begin(), toy_weights.end());

	unsigned units_spent = 0;
	int k = 0;
	while (k < num_toys)
	{
		int current_weight = toy_weights[k];
		units_spent++;
		k++;

		while (toy_weights[k] <= current_weight + 4)
			k++;
	}

	std::cout << units_spent;

	return 0;
}