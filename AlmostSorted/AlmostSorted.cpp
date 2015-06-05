#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/almost-sorted

// Represents an integer value which has not been set
const int UNSET = -1;

// Checks if it is possible to make a swap to sort the array
// (and inherently handles the case of the array already being sorted)
// Returns true if it is possible to sort the array by 1 swap
bool swap_available(int* nums, const int array_size) {
	int first_misplaced = UNSET;
	int second_misplaced = UNSET;
	// Check availability of a swap
	for (int i = 1; i < array_size - 1; i++) {
		if (first_misplaced == UNSET) {
			if (nums[i] > nums[i + 1])
				first_misplaced = i;
		}
		else if (second_misplaced == UNSET) {
			if (nums[i] > nums[i + 1])
				second_misplaced = i + 1;
		}
		else {
			if (nums[i] > nums[i + 1])
				return false;
		}
	}

	

	// If there were no misplaced elements, the array is already sorted
	if (first_misplaced == UNSET && second_misplaced == UNSET) {
		std::cout << "yes" << std::endl;
		return true;
	}
	// If there is only 1 misplaced element, take the second misplaced to be the last element in the array
	else if (first_misplaced != UNSET && second_misplaced == UNSET)
		second_misplaced = array_size - 2; // 1 element before the back of the array, due to the sentinel value

	// Check if the specified swaps will actually make the array sorted
	// Temporarily swap the two values in the array
	std::swap(nums[first_misplaced], nums[second_misplaced]);
	for (int i = 1; i < array_size - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			// Swap the values back
			std::swap(nums[first_misplaced], nums[second_misplaced]);
			return false;
		}
	}

	// Swap the values back
	std::swap(nums[first_misplaced], nums[second_misplaced]);

	std::cout << "yes" << std::endl;
	std::cout << "swap " << first_misplaced << " " << second_misplaced << std::endl;

	return true;
}

// Determines if it is possible to sort the array by reversing a sub-section of the array
// Returns true if this is possible, false otherwise
bool reverse_available(const int* nums, const int array_size) {
	// Check for an available reverse
	int start_index = UNSET;
	int end_index = UNSET;
	for (int i = 1; i < array_size - 1; i++) {
		// If element i to i+1 is in descending order
		if (nums[i] > nums[i + 1]) {
			// Mark this element as the first part of the sub-array
			// that is incorrectly positioned, if we have not already begun a sub-array
			if (start_index == UNSET) {
				start_index = i;
			}
			// If we have already claimed to have found the end of the reverseable sub-array
			// Then this array is not sortable, as this element is misplaced within a disjoint sub-array
			else if (end_index != UNSET) {
				return false;
			}
		}
		// If element i to i+1 is in ascending order
		else {
			// Mark the current element as the last part of the sub-array
			// that is incorrectly positioned, if we have specified the starting position,
			// as this element is now correctly positioned (ascending)
			if (start_index != UNSET && end_index == UNSET) {
				end_index = i;
			}
		}
	}

	// If no mis-placed element was found, the array is already sorted
	if (start_index == UNSET) {
		std::cout << "yes" << std::endl;
		return true;
	}
	else {
		// Ensure that the reversed sub-array will result in a sorted array
		if (nums[start_index] < nums[end_index + 1] && nums[end_index] > nums[start_index - 1]) {
			std::cout << "yes" << std::endl;
			std::cout << "reverse " << start_index << " " << end_index << std::endl;

			return true;
		}
		else { 
			return false;
		}
			
	}
}

int main() {
	const int NEG_SENTINEL = -1;
	const int POS_SENTINEL = 1000001;

	int array_size;
	std::cin >> array_size;

	array_size += 2; // Increase the array size by 2 for the sentinel values
	int* nums = new int[array_size];

	// Use a sentinel value to reduce number of boundary checks necessary
	nums[0] = NEG_SENTINEL;
	nums[array_size - 1] = POS_SENTINEL;

	for (int i = 1; i < array_size - 1; i++) {
		std::cin >> nums[i];
	}

	// If there is no swap available
	if (!swap_available(nums, array_size)) {
		// If there is no reverse available
		if (!reverse_available(nums, array_size)) {
			std::cout << "no" << std::endl;
		}
	}

	return 0;
}