#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/compare-the-triplets

int main() {
	int a[3], b[3];

	for (int i = 0; i < 3; i++)
	{
		std::cin >> a[i];
	}

	for (int i = 0; i < 3; i++)
	{
		std::cin >> b[i];
	}


	int a_score = 0;
	int b_score = 0;
	for (int i = 0; i < 3; i++)
	{
		if (a[i] > b[i])		a_score++;
		else if (b[i] > a[i])	b_score++;
	}

	std::cout << a_score << " " << b_score;

	return 0;
}