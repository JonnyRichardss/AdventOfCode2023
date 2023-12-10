#pragma once
#include <string>
#include "Helpers.h"
using namespace std;
class Draw
{
public:
	int red;
	int blue;
	int green;
	Draw();
	Draw(string input);
	bool CheckDraw(int r, int g, int b);
	bool tryFind(string input, string word, int& var);
};

