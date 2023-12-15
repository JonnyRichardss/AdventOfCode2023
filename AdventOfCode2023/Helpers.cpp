#include "Helpers.h"

 vector<string> Split(string input, char delim) {
	vector<string> words;
	stringstream ss(input);
	string word;
	while (getline(ss, word, delim)) {
		words.push_back(word);
	}
	return words;
}
int grabInt(string input) {
	string digits;
	 for (string::iterator i = input.begin(); i != input.end(); i++) {
		 if (isdigit(*i)) {
			 digits.push_back(*i);
		 }
	 }
	 return stoi(digits);
 }
