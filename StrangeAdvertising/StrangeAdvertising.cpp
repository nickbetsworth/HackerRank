#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

//https://www.hackerrank.com/challenges/strange-advertising

int main() {
	int num_days;
	std::cin >> num_days;

	int total_likes = 0;
	int num_advertised = 5;

	for (int i = 0; i < num_days; i++)
	{
		int num_likes = num_advertised / 2;
		total_likes += num_likes;
		num_advertised = num_likes * 3;
	}

	std::cout << total_likes;

	return 0;
}