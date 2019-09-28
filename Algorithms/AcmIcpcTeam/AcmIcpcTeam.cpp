#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/acm-icpc-team


// Converts a character to a bit(boolean)
bool char_to_bit(const char c) {
	if (c == '1')
		return true;
	else
		return false;
}
int main() {
	int num_people, num_topics;
	std::cin >> num_people >> num_topics;

	// Create a multi-dimensional array to store the topic knowledges
	// Each bit represents whether or not a person knows a topic
	bool* topics = new bool[num_people * num_topics];

	// Read in the topics that each person is 'well-versed' in
	std::string s;
	for (int i = 0; i < num_people; i++) {
		std::cin >> s;

		// Loop through each character ('0' or '1') and convert it to a bit
		for (int j = 0; j < num_topics; j++) {
			topics[i * num_topics + j] = char_to_bit(s.at(j));
		}
	}

	// Determine the maximum number of well-versed topics for a pair,
	// and the amount of pairs which are well-versed in this many topics
	int max_topics = 0;
	int num_pairs = 0;
	for (int p1 = 0; p1 < num_people - 1; p1++) {
		for (int p2 = p1 + 1; p2 < num_people; p2++) {
			int known_topics = 0;
			for (int i = 0; i < num_topics; i++) {
				// If at least one of the individuals knows topic i, increase the
				// number of known topics
				if (topics[p1 * num_topics + i] | topics[p2 * num_topics + i])
					known_topics++;
			}
			
			// If this is a new maximum number of topics
			if (known_topics > max_topics) {
				max_topics = known_topics;
				num_pairs = 1;
			}
			// If this matches the maximum number of known topics,
			// increment the number of pairs that know this many topics
			else if (known_topics == max_topics) {
				num_pairs++;
			}
		}
	}

	std::cout << max_topics << std::endl;
	std::cout << num_pairs << std::endl;

	return 0;
}