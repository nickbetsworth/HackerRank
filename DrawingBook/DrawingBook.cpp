#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/drawing-book/


int main()
{
	size_t num_pages, page_id;
	std::cin >> num_pages >> page_id;

	size_t num_turns;
	if (page_id > num_pages / 2)	num_turns = (num_pages - page_id + ((num_pages+1) % 2)) / 2;
	else							num_turns = (page_id) / 2;

	std::cout << num_turns;

	return 0;
}