#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/largest-permutation


int main()
{
	int array_size, num_swaps;
	std::cin >> array_size >> num_swaps;

	std::vector<unsigned> a(array_size);
	// Each item in this array, corresponds to the index at which that item lives within a.
	std::vector<int> index_array(array_size+1);
	for (int i = 0; i < array_size; i++)
	{
		std::cin >> a[i];
		index_array[a[i]] = i;
	}

	// Keeps track of the number of swaps that have been made.
	unsigned swap_counter = 0;
	// Points to the last element in the sorted array (non-inclusive).
	int sorted_ptr = 0;
	unsigned expected_num = array_size;

	while (swap_counter < num_swaps && sorted_ptr < array_size)
	{
		// If this element is not already sorted.
		if (expected_num != a[sorted_ptr])
		{
			int expected_index = index_array[expected_num];

			unsigned temp = a[sorted_ptr];
			a[sorted_ptr] = expected_num;
			a[expected_index] = temp;

			index_array[temp] = expected_index;
			index_array[expected_num] = sorted_ptr;

			swap_counter++;
		}

		sorted_ptr++;
		expected_num--;
	}

	for (int i = 0; i < array_size; i++)
	{
		std::cout << a[i] << " ";
	}

	return 0;
}