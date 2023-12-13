#pragma once
#include <vector>
#include <string>
using namespace std;
class Card
{
public:
	Card(string input);
	int GetValue();
	int GetNumWins();
	vector<Card> MakeCopies(const vector<Card>& allCards);
	int ID;
private:
	vector<int> OurNumbers;
	vector<int> WinningNumbers;
};

