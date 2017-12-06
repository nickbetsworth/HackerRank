#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

//https://www.hackerrank.com/challenges/birthday-cake-candles


int main()
{
	size_t num_candles, candle_height;
	std::cin >> num_candles;

	size_t tallest_candle_height = 0;
	size_t tallest_candle_count = 0;

	for (size_t i = 0; i < num_candles; i++)
	{
		std::cin >> candle_height;
		if (candle_height > tallest_candle_height)
		{
			tallest_candle_height = candle_height;
			tallest_candle_count = 1;
		}
		else if (candle_height == tallest_candle_height)
		{
			tallest_candle_count++;
		}
	}

	std::cout << tallest_candle_count;

	return 0;
}