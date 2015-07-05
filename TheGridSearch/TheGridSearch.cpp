#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/the-grid-search

// Determines whether or not the provided region in grid (starting at column and row (start_x, start_y) respectively)
// matches that of the pattern provided
inline bool matches_pattern(int start_x, int start_y, std::vector<std::string> grid, std::vector<std::string> pattern) {
	int pattern_width = pattern.front().length();

	for (auto it_grid_y = grid.begin() + start_y, it_pattern_y = pattern.begin(); 
		it_grid_y != grid.begin() + start_y + pattern.size(); 
		++it_grid_y, ++it_pattern_y) {

		
		if (it_grid_y->substr(start_x, pattern_width) != *it_pattern_y) 
			return false;
	}

	return true;
}

// Determines whether or not the provided pattern exists within the grid
bool contains_pattern(std::vector<std::string> grid, std::vector<std::string> pattern) {
	// Note: we have limited starting positions in grid
	// For example, if we have a grid width of 4 and a pattern width of 2, the pattern must begin at or before
	// x-position 2 of the grid

	int grid_width = grid.front().length();
	int grid_height = grid.size();
	int pattern_width = pattern.front().length();
	int pattern_height = pattern.size();
	// First char of pattern
	char first_pattern = pattern.front().front();

	// Loop through potential starting points for the pattern
	for (int y = 0; y <= grid_height - pattern_height; ++y) {
		for (int x = 0; x <= grid_width - pattern_width; ++x) {
			// Only check for matches, if this first character matches
			// Reduces a lot of overhead for the function call
			//if (first_pattern == grid.at(y).at(x))
			if (grid.at(y).substr(x, pattern_width) == pattern.front())
				if (matches_pattern(x, y, grid, pattern))
					return true;
		}
	}

	return false;
}

int main() {
	int num_tests;
	std::cin >> num_tests;

	int num_rows, num_cols, num_rows_pattern, num_cols_pattern;
	std::string in_row, in_row_pattern;
	for (int i = 0; i < num_tests; i++) {

		// Read in the grid
		std::cin >> num_rows >> num_cols;
		std::vector<std::string> grid_strings;
		for (int j = 0; j < num_rows; j++) {
			std::cin >> in_row;
			grid_strings.push_back(in_row);
		}


		// Read in the pattern
		std::cin >> num_rows_pattern >> num_cols_pattern;
		std::vector<std::string> pattern_strings;

		for (int j = 0; j < num_rows_pattern; j++) {
			std::cin >> in_row_pattern;
			pattern_strings.push_back(in_row_pattern);
		}


		// Determine whether the pattern exists within the grid
		if (contains_pattern(grid_strings, pattern_strings))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}