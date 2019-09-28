#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

//https://www.hackerrank.com/challenges/plus-minus

int main() {
	int array_size;
	std::cin >> array_size;

	int pos_count = 0, neg_count = 0, zero_count = 0;
	
	int n;
	for (int i = 0; i < array_size; i++) {
		std::cin >> n;

		if (n > 0)
			pos_count++;
		else if (n < 0)
			neg_count++;
		else
			zero_count++;
	}

	double pos_rate = static_cast<double>(pos_count) / array_size;
	double neg_rate = static_cast<double>(neg_count) / array_size;
	double zero_rate = static_cast<double>(zero_count) / array_size;

	std::cout << std::setprecision(3);
	std::cout << pos_rate << std::endl;
	std::cout << neg_rate << std::endl;
	std::cout << zero_rate << std::endl;

	return 0;
}