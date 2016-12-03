#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/circular-array-rotation

long mod(long a, long b)
{
	return (a%b + b) % b;
}

int main() {
	int n, k, q;

	std::cin >> n >> k >> q;

	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	int val;
	for (int i = 0; i < q; i++)
	{
		std::cin >> val;
		int index = mod(val - k, n);
		std::cout << arr[index] << std::endl;
	}

	return 0;
}