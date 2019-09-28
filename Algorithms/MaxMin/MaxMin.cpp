#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/angry-children

/*
IDEA:
If we sort the list, then we no longer need to manually compute
the min/max of each subset. The min as at the lowest index,
max is at the largest index (of the sub-array).
*/
int main() {
	int array_size, sub_size;
	std::vector<int> nums;
	std::cin >> array_size >> sub_size;

	int x;
	for (int i = 0; i < array_size; i++) {
		std::cin >> x;
		nums.push_back(x);
	}

	std::sort(nums.begin(), nums.end());

	int min_unfairness = std::numeric_limits<int>::max();
	// Check each possible subset, to find the one where unfairness is minimised (max - min)
	for (int i = 0; i <= array_size - sub_size; i++) {
		int min = nums.at(i);
		int max = nums.at(i + sub_size - 1);
		int unfairness = max - min;
		
		min_unfairness = std::min(min_unfairness, unfairness);
	}

	std::cout << min_unfairness << std::endl;

	return 0;
}