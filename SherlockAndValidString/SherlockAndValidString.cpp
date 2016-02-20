#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//https://www.hackerrank.com/challenges/sherlock-and-valid-string

struct Frequency
{
	Frequency() { set = false; count = 0; }

	void SetFrequency(int frequency) { this->frequency = frequency; set = true; count++; }
	bool IsSet() { return set; }
	void IncreaseCount() { count++; }

	unsigned frequency;
	unsigned count;
	bool set;
};

bool IsValidString(const std::string &s)
{
	// Array to store the frequency of each letter in the alphabet.
	// Index [0..25] -> [a..z]
	unsigned alpha_freq[26] = { 0 };

	// Tally up the frequency of each character.
	for (auto c : s)
	{
		alpha_freq[c - 'a']++;
	}

	// Now we need to decide if this is a "valid" string, with only one removal.
	// This holds true if one of the following is the case:
	//  - All characters have the same frequency.
	//  - All characters have the same frequency, except one character, whose frequency is one.
	//  - All characters have the same frequency, except one character, whose frequency is one greater than the common frequency.
	//
	// This is done by iterating through each frequency to determine any differences.
	// If we locate more than two different unique frequencies, this is always an invalid string.
	// If we locate two different unique frequencies, the string is valid IFF frequency of string a is 1, or equivalent
	//  to the frequency of string b + 1.
	// If we locate one unique frequency, the string is always valid.
	//
	// One edge case we need to consider is if two different unique frequencies have a count of 1.
	// (i.e both of them are effectively outliers).

	Frequency a;
	Frequency b;
	// Initialise with the frequency of the first character (a).
	a.SetFrequency(alpha_freq[0]);

	for (int i = 1; i < 26; i++)
	{
		unsigned freq = alpha_freq[i];

		// If there were no occurences of this character, we can skip this character.
		if (freq == 0)
			continue;

		// Determine whether this should increment the a or b frequency.
		if (a.frequency == freq)
		{
			a.IncreaseCount();
		}
		else
		{
			if (b.IsSet())
			{
				if (b.frequency == freq)
				{
					b.IncreaseCount();
				}
				// If this is the third different frequency found, it must be an invalid string.
				else
				{
					return false;
				}
			}
			else
			{
				// Setup the b frequency if it has not already been set
				b.SetFrequency(alpha_freq[i]);
			}
		}
	}

	// If all characters had the same frequency (it's possible in this case that some characters did not occur).
	if (b.IsSet() == false)
		return true;
	// If there was only 1 character, we can remove this to create a valid string.
	if (a.frequency == 1 && a.count == 1 || b.frequency == 1 && b.count == 1)
		return true;
	// If a has one too many characters, and only occured once, we can easily delete this.
	if (a.frequency == (b.frequency + 1) && a.count == 1)
		return true;
	// Same check for b frequency.
	else if (b.frequency == (a.frequency + 1) && b.count == 1)
		return true;
	// All other cases indicate an invalid string.
	else
		return false;
}

int main() {
	std::string line;
	std::cin >> line;

	if (IsValidString(line))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}

	return 0;
}