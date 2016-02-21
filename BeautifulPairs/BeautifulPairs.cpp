#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/contests/101hack34/challenges/beautiful-pairs


int main()
{
	int array_size;
	std::cin >> array_size;

	std::vector<unsigned> a(array_size);
	std::vector<unsigned> b(array_size);

	for (int i = 0; i < array_size; i++)
	{
		std::cin >> a[i];
	}

	for (int i = 0; i < array_size; i++)
	{
		std::cin >> b[i];
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	unsigned num_pairs = 0;
	int a_ptr = 0;
	int b_ptr = 0;

	bool unused_val = false;

	while (a_ptr < array_size && b_ptr < array_size)
	{
		if (a[a_ptr] == b[b_ptr])
		{
			num_pairs++;
			a_ptr++; b_ptr++;
		}
		else if (a[a_ptr] < b[b_ptr])
		{
			a_ptr++;
			unused_val = true;
		}
		else
		{
			b_ptr++;
			unused_val = true;
		}
	}

	if (unused_val)
		num_pairs++;
	else
		num_pairs--;

	std::cout << num_pairs;

	return 0;
}