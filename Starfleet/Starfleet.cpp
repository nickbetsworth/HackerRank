#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
//https://www.hackerrank.com/challenges/starfleet

typedef std::vector<int> SpaceFighters;
typedef std::unordered_map<int, SpaceFighters> SpaceFighterMap;

int get_max_coverage(const int yu, const int yd, const SpaceFighterMap& map) {
	assert(yu >= yd);

	int max = 0;
	//std::cout << "Box from " << yd << " to " << yu << std::endl;
	// Loop through each of the frequencies
	for (auto k : map) {
		SpaceFighters sf = k.second;
		//std::cout << "Searching freq " << k.first << std::endl;
		// Find the first element at this frequency which is within the bounding box
		auto lower_it = std::lower_bound(sf.begin(), sf.end(), yd);
		// If there are elements at this frequency within this bounding box
		if (lower_it != sf.end()) {
			auto upper_it = std::upper_bound(lower_it, sf.end(), yu);

			//std::cout << "Start: " << *lower_it << " End: " << *upper_it << std::endl;
			//std::cout << "Elements: ";
			for (auto it = lower_it; it != upper_it; it++) {
				//std::cout << *it << " ";
			}
			//std::cout << std::endl;
			int count = upper_it - lower_it;

			if (count > max)
				max = count;
		}
	}

	return max;
}

int main() {
	// Map from frequencies, to a list containing all y positions of ships
	// based at that frequency
	SpaceFighterMap space_fighters_freq;
	std::unordered_set<int> frequencies; // Stores the available frequencies

	int num_space_fighters, num_queries, velocity;

	std::cin >> num_space_fighters >> num_queries >> velocity;

	int x, y, f;
	// Read in the positions and frequencies of each of the space fighters
	for (int i = 0; i < num_space_fighters; i++) {
		std::cin >> x >> y >> f;

		// We can ignore the x co-ordinate, as this is irrelevant for the problem
		// Add this space fighter to the vector for the given frequency
		frequencies.insert(f);
		space_fighters_freq[f].push_back(y);
		std::push_heap(space_fighters_freq[f].begin(), space_fighters_freq[f].end());
	}

	// Sort each of the vectors
	//for (int f : frequencies) {
		//std::sort(space_fighters_freq[f].begin(), space_fighters_freq[f].end());
		//std::sort_heap(space_fighters_freq[f].begin(), space_fighters_freq[f].end());
	//}

	int yu, yd, t;
	// Run through each of the test cases
	for (int i = 0; i < num_queries; i++) {
		std::cin >> yu >> yd >> t;
		std::cout << get_max_coverage(yu, yd, space_fighters_freq) << std::endl;
	}

	return 0;
}