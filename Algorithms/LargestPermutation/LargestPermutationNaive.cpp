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
	for (int i = 0; i < array_size; i++)
	{
		std::cin >> a[i];
	}

	// Our objective is to find the largest permutation using at most num_swaps swaps.
	// The idea behind our algorithm will be to always swap the largest value from the
	// unsorted partition of the array, with the beginning of the sorted array.
	//
	// Note that in instances where the maximum value is equal to the first value in
	// the array, no swap should be made.

	// Keeps track of the number of swaps that have been made.
	unsigned swap_counter = 0;
	// Points to the last element in the sorted array (non-inclusive).
	int sorted_ptr = 0;

	while (swap_counter < num_swaps && sorted_ptr < array_size)
	{
		// Initialise the max value found to be the left value which is being swapped out
		// i.e if max_index is still sorted_ptr after locating the max, the array is already
		// sorted up to this point.
		int max_index = sorted_ptr;
		unsigned max_value = a[sorted_ptr];

		// Search for the largest value in the unsorted partition of the array
		for (int i = sorted_ptr+1; i < array_size; i++)
		{
			if (a[i] > max_value)
			{
				max_index = i;
				max_value = a[i];
			}
		}

		// Array already sorted up until this point, no need to increase the swap counter
		if (max_index == sorted_ptr)
		{
			sorted_ptr++;
		}
		else
		{
			unsigned temp = a[sorted_ptr];
			a[sorted_ptr] = a[max_index];
			a[max_index] = temp;

			sorted_ptr++;
			swap_counter++;
		}
	}

	for (int i = 0; i < array_size; i++)
	{
		std::cout << a[i] << " ";
	}

	return 0;
}