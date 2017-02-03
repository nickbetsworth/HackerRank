#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/kangaroo

int main() {
	int x1, v1, x2, v2;
	std::cin >> x1 >> v1 >> x2 >> v2;

	// x1 + t(v1) = x2 + t(v2);
	// t(v1) - t(v2) = x2 - x1;
	// t(v1 - v2) - x2 - x1;
	// t = (x2 - x1) / (v1 - v2);

	if (v1 - v2 == 0 && x1 != x2)			std::cout << "NO";
	else if ((x2 - x1) / (v1 - v2) < 0)		std::cout << "NO";
	else if ((x2 - x1) % (v1 - v2) != 0)	std::cout << "NO";
	else									std::cout << "YES";

	return 0;
}