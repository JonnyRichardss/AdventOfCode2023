#pragma once
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<string> Split(string input, char delim);

//grabs every digit in a given string and returns it as a number
//note to self: can't get negative numbers 
int GrabInt(string input);

