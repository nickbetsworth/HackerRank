#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

//https://www.hackerrank.com/challenges/find-maximum-index-product

typedef unsigned long long num_type;

// Stores a number from the array, for which we are searching for a larger number
struct Active_Num {
	int index;
	num_type num;
};

// Determines how to compare (<) an Active_Num (uses it's value instead of index)
struct Active_Num_Cmp {
	bool operator()(const Active_Num& num1, const Active_Num& num2) {
		return num1.num < num2.num;
	}
};

// Maps from a given index in the array, to the index at which the first larger number was found
typedef std::unordered_map<int, int> Index_Map;
// Stores a list of numbers for which we are searching for larger numbers
typedef std::set<Active_Num, Active_Num_Cmp> Active_Num_Set;

// Finds the index j of the first number greater than that of the number at index i
// such that index j < index i but value j > value i
// If no such index exists, 0 is given
Index_Map get_indexes(const std::vector<num_type>& nums) {
	// Stores the first index j, for which a number larger than that of index i is found
	// ( i => j )
	Index_Map indexes;

	// Stores the numbers for which we are searching for larger numbers
	Active_Num_Set active_indexes;
	// Sweep from left to right in the array
	for (int i = 0; i < nums.size(); i++) {
		Active_Num current_num = { i, nums.at(i) };

		// Find the first active number which is greater than the current number
		auto upper = active_indexes.upper_bound(current_num);
		auto it = active_indexes.begin();

		// For all numbers BEFORE the greater number (upper) we have found
		// we know that index i is the first larger number found
		while (it != upper) {
			// Ensure that this is not the special case in which num1 == num2
			if (current_num.num != it->num) {
				// We have found the first larger number
				indexes[it->index + 1] = i + 1;
				// This number is no longer active
				active_indexes.erase(it++);
			}
			else {
				++it;
			}
		}

		active_indexes.insert(current_num);
	}

	// For all of the remaining indexes, give 0 as there is no existing index j
	for (auto active_index : active_indexes) {
		indexes[active_index.index + 1] = 0;
	}

	return indexes;
}

int main() {
	int num_count;
	std::cin >> num_count;

	std::vector<num_type> nums;

	num_type num;
	for (int i = 0; i < num_count; i++) {
		std::cin >> num;
		nums.push_back(num);
	}

	// Find the list of larger indexes for each number, where the index is growing
	Index_Map fwd_map = get_indexes(nums);
	// Reverse the array so we can re-use the get_indexes function, as if the index is shrinking
	std::reverse(nums.begin(), nums.end());
	Index_Map bwd_map = get_indexes(nums);

	// Calculate the maximum product of the growing and shrinking indexes
	long long max_product = 0;
	// Leave the first and last out, as they will always result in 0
	for (int i = 2; i < num_count; i++) {
		int index_right = fwd_map[i];

		// Need to reverse both the indexes and values, as we performed the calculation
		// on a reversed array
		int index_left_unreversed = bwd_map[(nums.size() - i) + 1];
		int index_left = 0;
		
		// If the index is 0 before reversal, then make sure it remains 0
		if (index_left_unreversed > 0)
			index_left = (nums.size() - index_left_unreversed) + 1;

		long long product = static_cast<long long>(index_left) * index_right;

		max_product = std::max(product, max_product);
	}

	std::cout << max_product << std::endl;

	return 0;
}