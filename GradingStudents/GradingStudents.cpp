#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/grading


int main()
{
	size_t num_grades, grade;
	std::cin >> num_grades;

	for (size_t i = 0; i < num_grades; i++)
	{
		std::cin >> grade;

		if (grade < 38)		std::cout << grade << std::endl;
		else				std::cout << ((grade % 5) < 2 ? (grade + grade % 5) : grade) << std::endl;
	}

	return 0;
}