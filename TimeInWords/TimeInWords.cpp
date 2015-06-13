#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

//https://www.hackerrank.com/challenges/the-time-in-words

// Time unit
// Initially used uchar, but peculiar behaviour when dealing with
// maps keys that are uchars
typedef int t_unit;
typedef std::map<t_unit, std::string> WordMap;

WordMap create_word_map() {
	WordMap m;

	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";
	m[5] = "five";
	m[6] = "six";
	m[7] = "seven";
	m[8] = "eight";
	m[9] = "nine";
	m[10] = "ten";
	m[11] = "eleven";
	m[12] = "twelve";
	m[13] = "thirteen";
	m[14] = "fourteen";
	m[15] = "fifteen";
	m[16] = "sixteen";
	m[17] = "seventeen";
	m[18] = "eighteen";
	m[19] = "nineteen";
	m[20] = "twenty";
	
	// Handles cases 20-29
	for (int i = 1; i <= 9; i++)
		m[20 + i] = m[20] + " " + m[i];

	return m;
}

std::string get_time_string(t_unit hours, t_unit minutes) {
	WordMap m = create_word_map(); // Load in the word map
	std::string s; // Stores the final string

	// Work out the next hour (if we are x to hour)
	t_unit next_hour = (hours + 1) % 12;
	
	// The string is dependent upon the minutes
	// Deal with all of the special cases first
	if (minutes == 0)
		s = m[hours] + " o' clock";
	// Special case (no plural)
	else if (minutes == 1)
		s = "one minute past " + m[hours];
	else if (minutes == 15)
		s = "quarter past " + m[hours];
	else if (minutes == 30)
		s = "half past " + m[hours];
	else if (minutes == 45)
		s = "quarter to " + m[next_hour];
	// Special case (no plural)
	else if (minutes == 59)
		s = "one minute to " + m[next_hour];
	else if (minutes < 30)
		s = m[minutes] + " minutes past " + m[hours];
	else if (minutes > 30)
		s = m[60 - minutes] + " minutes to " + m[next_hour];

	return s;
}

int main() {
	t_unit hours, minutes;
	std::cin >> hours >> minutes;

	std::cout << get_time_string(hours, minutes) << std::endl;
	return 0;
}