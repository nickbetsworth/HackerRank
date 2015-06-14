#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
//https://www.hackerrank.com/challenges/kaprekar-numbers

typedef unsigned long long ull;

std::pair<ull, ull> split_number(ull num) {
	// Split the number in to a list of digits
	std::vector<int> digits;

	while (num > 0) {
		digits.push_back(num % 10);
		num /= 10;
	}

	// Reverse the list (as the digits will currently be in reverse order)
	std::reverse(digits.begin(), digits.end());

	// Split the list in to two even parts (or in the case that we have an odd
	// number of digits, give the remaining digit to right split)
	const int half_size = digits.size() / 2;
	const int left_size = half_size;
	const int right_size = half_size + digits.size() % 2;
	std::vector<int> left_digits(digits.begin(), digits.begin() + left_size);
	std::vector<int> right_digits(digits.begin() + left_size, digits.end());

	// Create each number from each of the lists
	int current_power = left_digits.size() - 1;
	ull left_val = 0;
	for (int digit : left_digits) {
		left_val += digit * pow(10, current_power--);
	}

	current_power = right_digits.size() - 1;
	ull right_val = 0;
	for (int digit : right_digits) {
		right_val += digit * pow(10, current_power--);
	}

	return std::make_pair(left_val, right_val);
}

bool is_kaprekar(ull num) {
	auto num_split = split_number(num * num);

	return (num_split.first + num_split.second) == num;
}

int main() {
	int p, q;
	std::cin >> p >> q;

	std::vector<ull> kaprekar_numbers;
	for (ull i = p; i <= q; i++) {
		if (is_kaprekar(i))
			kaprekar_numbers.push_back(i);
	}

	if (kaprekar_numbers.empty())
		std::cout << "INVALID RANGE" << std::endl;
	else
		std::for_each(kaprekar_numbers.begin(), kaprekar_numbers.end(), [](ull num) { std::cout << num << " "; });

	return 0;
}