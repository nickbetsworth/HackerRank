#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

//https://www.hackerrank.com/challenges/save-the-prisoner

int main() {
	int num_cases, num_prisoners, num_sweets, s;

	std::cin >> num_cases;

	for (int i = 0; i < num_cases; i++)
	{
		std::cin >> num_prisoners >> num_sweets >> s;
		int poisoned_id = ((s + num_sweets - 1) % num_prisoners);

		if (poisoned_id == 0)	poisoned_id = num_prisoners;

		std::cout << poisoned_id << std::endl;
	}

	return 0;
}