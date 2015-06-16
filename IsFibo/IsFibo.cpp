#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

//https://www.hackerrank.com/challenges/is-fibo

typedef unsigned long long Big_Int;
typedef std::unordered_map<Big_Int, bool> Fib_Map;
const Big_Int MAX_NUM = 10000000000ULL;

// Creates a fibonacci map of numbers contained within
// the fibonacci sequence, up to and including n
Fib_Map create_fib_map(Big_Int n) {
	Fib_Map fib_map;
	fib_map[0] = true;
	fib_map[1] = true;

	Big_Int n1 = 0;
	Big_Int n2 = 1;
	Big_Int temp;
	while (n2 < n) {
		temp = n1 + n2;
		n1 = n2;
		n2 = temp;

		fib_map[temp] = true;
	}

	return fib_map;
}

int main() {
	unsigned num_tests;
	std::cin >> num_tests;

	Fib_Map fib_map = create_fib_map(MAX_NUM);

	Big_Int num_in;
	for (int i = 0; i < num_tests; i++) {
		std::cin >> num_in;

		// If this fibonacci number is within the sequence
		if (fib_map.find(num_in) != fib_map.end())
			std::cout << "IsFibo" << std::endl;
		else
			std::cout << "IsNotFibo" << std::endl;
	}

	return 0;
}