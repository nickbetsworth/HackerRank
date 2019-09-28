#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

//https://www.hackerrank.com/challenges/cavity-map

typedef std::unordered_map<int, bool> VisitMap;

bool char_to_bool(char c) {
	if (c == '1')
		return true;
	else
		return false;
}

int get_max_area_r(bool* mat, int rows, int cols, int i, VisitMap& visits) {
	visits.erase(i);
	// Left, Right, Above, Below, Top Left Diag, Top Right Diag, Bot Left Diag, Bot Right Diag
	const int directions[] = { -1, 1, -cols, cols, -cols - 1, -cols + 1, cols - 1, cols + 1 };
	int count = 1;
	// Check if the surrounding neighbours are connected

	for (int dir : directions) {
		if (mat[i + dir]) {
			try {
				if (visits.at(i + dir)) {
					count += get_max_area_r(mat, rows, cols, i + dir, visits);
				}
			}
			catch (std::out_of_range e) {

			}
			
		}
	}

	return count;
}

int get_max_area(bool* mat, int rows, int cols, VisitMap visits) {
	int max = 0;
	while (!visits.empty()) {
		// Get the first unvisited node
		int i = visits.begin()->first;
		max = std::max(max, get_max_area_r(mat, rows, cols, i, visits));
	}

	return max;
}

int main() {
	std::unordered_map<int, bool> unvisited;
	int num_rows, num_cols;
	char t;
	std::cin >> num_rows >> num_cols;

	// Make the matrix bigger for sentinel values
	num_rows += 2;
	num_cols += 2;

	// Read in the matrix values, 
	bool* mat = new bool[num_cols * num_rows];
	for (int i = 1; i < num_rows - 1; i++) {
		for (int j = 1; j < num_cols - 1; j++) {
			int index = i * num_cols + j;
			std::cin >> t;
			bool val = char_to_bool(t);
			if (val)
				unvisited[index] = true;

			mat[index] = val;
		}
	}
	
	std::cout << get_max_area(mat, num_rows, num_cols, unvisited) << std::endl;
	
	// Create an adjacency 
	delete mat;
	return 0;
}