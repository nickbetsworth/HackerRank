#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

//https://www.hackerrank.com/challenges/find-maximum-index-product

typedef unsigned long long num_type;
typedef std::unordered_map<int, int> Index_Map;

// Finds the index j of the first number greater than that of the number at index i
// such that index j < index i but value j > value i
// If no such index exists, 0 is given
Index_Map get_indexes(const std::vector<num_type>& nums) {
	Index_Map indexes;
	std::vector<int> active_indexes;
	for (int i = 0; i < nums.size(); i++) {
		num_type current_num = nums.at(i);
		// Check if the current number is greater than any of the active numbers
		std::vector<int>::iterator active_it;
		for (active_it = active_indexes.begin(); active_it != active_indexes.end();) {
			if (current_num > nums.at(*active_it)) {
				indexes[*active_it + 1] = i + 1; // Add one to the index, as indices start at 1 rather than 0
				active_it = active_indexes.erase(active_it);
			}
			else {
				++active_it;
			}
		}

		active_indexes.push_back(i);
	}

	// For all of the remaining indexes, give 0 as there is no existing index j
	for (int active_index : active_indexes) {
		indexes[active_index + 1] = 0;
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

	Index_Map fwd_map = get_indexes(nums);
	std::reverse(nums.begin(), nums.end());
	Index_Map bwd_map = get_indexes(nums);

	int max_product = 0;
	// Leave the first and last out, as they will always result in 0
	for (int i = 2; i < num_count; i++) {
		int index_right = fwd_map[i];
		int index_left_unreversed = bwd_map[(nums.size() - i) + 1];
		int index_left = 0;
		
		if (index_left_unreversed > 0)
			index_left = (nums.size() - index_left_unreversed) + 1;

		//std::cout << i << " vs " << (nums.size() - i) + 1 << std::endl;
		//std::cout << index_left << " times " << index_right << std::endl;
		int product = index_left * index_right;

		max_product = std::max(product, max_product);
	}

	std::cout << max_product << std::endl;

	return 0;
}