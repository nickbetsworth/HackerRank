#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/common-child

// Array to store longest common sub sequence found up to the given point
// longest[i][j] represents longest subsequence between strings a[0]->a[i], b[0]->b[j]
// By default all values are initialised to 0
unsigned longest[5000][5000] = { 0 };

unsigned get_longest_common_subsequence(const std::string &a, const std::string &b)
{
	if (a.length() != b.length())
	{
		std::cout << "Unexpected error: String lengths do not match" << std::endl;
		return -1;
	}

	int len = a.length();

	// Initialise the potential starting positions with 1 if they the strings match at the
	// respective positions.
	for (int n = 0; n < len; n++)
	{
		if (a[0] == b[n])
			longest[0][n] = 1;

		if (a[n] == b[0])
			longest[n][0] = 1;
	}

	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < len; j++)
		{
			if (a[i] == b[j])
			{
				longest[i][j] = 1 + longest[i - 1][j - 1];
			}
			else
			{
				longest[i][j] = std::max(longest[i - 1][j], longest[i][j - 1]);
			}
		}
	}

	return longest[len - 1][len - 1];
}

int main()
{
	std::string a, b;
	std::cin >> a >> b;

	std::cout << get_longest_common_subsequence(a, b);

	return 0;
}