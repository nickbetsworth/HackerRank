#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/day-of-the-programmer/


int main()
{
	size_t year;
	std::cin >> year;

	if (year == 1918)
	{
		std::cout << "26.09.1918";
	}
	else if (year < 1918)
	{
		if (year % 4 == 0)	std::cout << "12.09." << year;
		else				std::cout << "13.09." << year;
	}
	else
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))	std::cout << "12.09." << year;
		else														std::cout << "13.09." << year;
	}

	return 0;
}