#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/angry-professor


int main() {
	int num_tests;
	std::cin >> num_tests;

	
	int n; // The number of students in the class
	int k; // The minimum number of students for a class to run
	int time; // The time a particular student arrives
	for (int t = 0; t < num_tests; t++) {
		std::cin >> n >> k;

		std::vector<int> arrival_times;
		// Read in each of the student's arrival times
		for (int i = 0; i < n; i++) {
			std::cin >> time;
			arrival_times.push_back(time);
		}

		int students_present = std::count_if(arrival_times.begin(), arrival_times.end(), [](int time) { return time <= 0; });

		// Output YES if the class is cancelled
		// or NO otherwise
		if (students_present < k) {
			std::cout << "YES";
		}
		else {
			std::cout << "NO";
		}

		std::cout << std::endl;
	}

	return 0;
}