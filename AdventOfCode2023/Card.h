#pragma once
#include <vector>
#include <string>
using namespace std;
class Card
{
public:
	Card(string input);
	int GetValue();
	int ID;
private:
	vector<int> OurNumbers;
	vector<int> WinningNumbers;
};

