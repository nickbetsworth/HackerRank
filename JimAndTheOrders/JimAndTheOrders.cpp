#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/jim-and-the-orders


int main()
{
	int num_orders;
	std::cin >> num_orders;

	std::vector<unsigned> receive_times(num_orders);
	std::vector<int> indices(num_orders);

	unsigned order_time, process_time;
	for (int i = 0; i < num_orders; i++)
	{
		std::cin >> order_time >> process_time;
		receive_times[i] = order_time + process_time;
		indices[i] = i;
	}

	std::sort(indices.begin(), indices.end(), 
		[&receive_times](unsigned i1, unsigned i2)
		{ 
		if (receive_times[i1] < receive_times[i2])
			return true;
		else if (receive_times[i1] > receive_times[i2])
			return false;
		// If both orders will be done at the same time, we must order based off the order ids.
		else
			return i1 < i2;
		});

	for (int i = 0; i < num_orders; i++)
	{
		std::cout << indices[i] + 1 << " ";
	}

	return 0;
}