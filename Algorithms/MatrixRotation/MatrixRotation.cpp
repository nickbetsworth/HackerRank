#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
//https://www.hackerrank.com/challenges/matrix-rotation-algo

int mod(long x, long m) {
	return (x % m + m) % m;
}


int main() {
	int m; // Matrix row count
	int n; // Matrix col count
	long r; // Number of rotations
	std::cin >> m >> n >> r;

	long *mat = new long[m * n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> mat[i * n + j];
		}
	}

	// Pointers to the current top and bottom rows of the segment (see image matrix_split.png)
	int pt_top = 0;
	int pt_bot = m - 1;
	long *mat_rotated = new long[m * n]; // Stores the final rotated matrix

	// Work out if we need to terminate early due to having a smaller number of columns
	// than rows, whilst still having an even number of columns. An alternative solution
	// could be to transpose the array if this holds true.
	// Alternatively, different logic / reverse of column/row major loops could be used,
	// however this would clutter the code.
	bool early_termination = std::min(m, n) == n && m != n;

	// Move the two pointers toward each other, one step at a time, until they meet
	while (pt_top < pt_bot) {

		// Due to the way we iterate through the matrix, we need to terminate early if
		// the matrix has the previously mentioned properties, and has exceeded a given
		// point.
		if (early_termination) {
			if (pt_top >= n / 2) {
				break;
			}
		}

		std::vector<int> indices;
		
		// Works out the lower and upper bound on the column iterators, for the given row
		int col_start = pt_top;
		int col_end = n - pt_top - 1;

		int row, col;

		// Iterate down left pillar, bottom left to right, up right pillar, and across the top from left to right

		// Left pillar downwards
		col = col_start;
		for (row = pt_top; row <= pt_bot; row++) {
			int index = row * n + col;
			indices.push_back(index);
		}

		// Bottom, from left to right
		row = pt_bot;
		for (col = col_start + 1; col < col_end; col++) {
			int index = row * n + col;
			indices.push_back(index);
		}

		// Right pillar upwards
		col = col_end;
		for (row = pt_bot; row >= pt_top; row--) {
			int index = row * n + col;
			indices.push_back(index);
		}

		// Top, from right to left
		row = pt_top;
		for (col = col_end - 1; col > col_start; col--) {
			int index = row * n + col;
			indices.push_back(index);
		}
		
		// Create the rotated matrix
		for (int i = 0; i < indices.size(); i++) {
			int new_index = indices.at(mod(i - r, indices.size()));

			mat_rotated[indices.at(i)] = mat[new_index];
		}
		
		pt_top++; pt_bot--;
	}

	// Output the rotated matrix
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << mat_rotated[i * n + j] << " ";
		}
		std::cout << std::endl;
	}

	// Release memory
	delete[] mat;
	delete[] mat_rotated;

	return 0;
}