#include "Card.h"
#include "Helpers.h"
#include <functional>
Card::Card(string input)
{

	vector<string> parts = Split(input, ':');
	ID = GrabInt(parts[0]);
	string nums = parts[1];
	parts.clear();
	parts = Split(nums, '|');

	auto GetAllNums = [](vector<string> input)->vector<int>
	{
		vector<int> output;
		for (string s : input) {
			if (s == "") continue;
			output.push_back(stoi(s));
		}
		return output;
	};
	 OurNumbers = GetAllNums(Split(parts[0], ' '));
	WinningNumbers = GetAllNums(Split(parts[1], ' '));
}

int Card::GetValue()
{
	bool foundFirst = false;
	int output = 0;
	for (int i : OurNumbers) {
		auto foundNum = find(WinningNumbers.begin(), WinningNumbers.end(), i);
		if (foundNum != WinningNumbers.end()) {
			if (!foundFirst) { foundFirst = true; output = 1; continue; }
			output *= 2;
		}
	}
	return output;
}
