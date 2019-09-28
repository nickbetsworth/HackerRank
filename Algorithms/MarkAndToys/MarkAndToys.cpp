#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/mark-and-toys


int main()
{
	unsigned num_products, money;
	std::cin >> num_products >> money;

	std::vector<unsigned> products(num_products);

	for (int i = 0; i < num_products; i++)
	{
		std::cin >> products[i];
	}

	std::sort(products.begin(), products.end());

	unsigned num_items = 0;
	unsigned spent = 0;

	while (spent < money)
	{
		spent += products[num_items];

		if (spent <= money)
			num_items++;
	}

	std::cout << num_items;

	return 0;
}