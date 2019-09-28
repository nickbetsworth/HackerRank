#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
//https://www.hackerrank.com/challenges/identify-smith-numbers

// Gets a list of prime numbers/factors up to and including n
std::set<unsigned int> get_primes(unsigned int n) {
	std::set<unsigned int> primes;

	// Use the sieve method to construct the prime list
	// and initialise all values to 0
	bool* ar = new bool[n + 1]();

	for (int i = 2; i <= n; i++) {
		for (int j = 2 * i; j <= n; j += j) {
			ar[j] = true;
		}
	}

	// Iterate through the array and add all false values (primes)
	for (int i = 2; i <= n; i++) {
		if (ar[i] == false)
			primes.insert(i);
	}

	delete[] ar;

	return primes;
}

unsigned int get_digit_sum(unsigned int n) {
	unsigned int sum = 0;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

unsigned int get_prime_factor_sum(unsigned int n) {
	// Only get the first x primes (otherwise we run in to memory issues with sieve)
	unsigned int prime_count = std::min(600000u, n);
	unsigned int sum = 0;

	auto primes = get_primes(prime_count);

	while (n > 1) {
		for (auto prime : primes) {
			if (n % prime == 0) {
				sum += get_digit_sum(prime);
				n /= prime;
				break;
			}
		}
	}

	return sum;
}

bool is_smith(unsigned int n) {
	unsigned int digit_sum = get_digit_sum(n);
	unsigned int prime_fac_sum = get_prime_factor_sum(n);

	return digit_sum == prime_fac_sum;
}

int main() {
	unsigned int n;
	std::cin >> n;

	std::cout << is_smith(n) << std::endl;

	return 0;
}