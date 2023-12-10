#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Draw.h"
#include "Helpers.h"
using namespace std;
class Game
{
public:
	int id;
	vector<Draw> allDraws;
	bool CheckGame(int red, int green, int blue);
	Game(string input);
	
};

