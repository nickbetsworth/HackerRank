#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

//https://www.hackerrank.com/challenges/sherlock-and-anagrams

double factorial(double f)
{
	double total = 1;

	for (double i = f; i >= 2; i--)
	{
		total *= i;
	}

	return total;
}

int main() {
	int num_cases;
	std::cin >> num_cases;

	std::string line;
	for (int k = 0; k < num_cases; k++) {
		std::cin >> line;
	
		int string_length = line.length();
		
		// Maps from an ordered set of characters(duplicates permitted), to the number
		// of times that ordered set is encountered. This can be used to easily deduce
		// the number of anagramatic pairs within the given string.
		std::map<std::multiset<char>, unsigned> char_map;
		
		// Iterate over all possible substrings for the given string.
		for (int start_pos = 0; start_pos < string_length; start_pos++)
		{
			for (int i = start_pos; i < string_length; i++)
			{
				std::string substr = line.substr(start_pos, (i - start_pos) + 1);

				// Add all characters to a multi set. This results in anagramatic pairs being 
				// classified as an equivalent multiset, due to the ordering of the characters, 
				// which allows us to easily keep track of the number of pairs.
				std::multiset<char> char_set;
				std::for_each(substr.begin(), substr.end(), [&char_set](char c) { char_set.insert(c); });

				char_map[char_set]++;
			}
		}

		// Sum up the number of distinct anagramatic pairs within the given string.
		double total = 0;
		for (auto k : char_map)
		{
			unsigned num_items = k.second;

			// If there are possible pairs.
			if (num_items > 1)
			{
				// Formula to calculate the number of distinct anagramatic pairs.
				double num_pairs = factorial(num_items) / (2 * factorial(num_items - 2));
				total += num_pairs;
			}

			
		}

		std::cout << total << std::endl;
	}

	return 0;
}