#include "Game.h"

bool Game::CheckGame(int red, int green, int blue) {
	for (vector<Draw>::iterator i = allDraws.begin(); i != allDraws.end(); i++) {
		if (!i->CheckDraw(red, green, blue)) {
			return false;
		}
	}
	return true;
}

Game::Game(string input) {
	//split
	//add each Draw() to allDraws
	vector<string> parts = Split(input, ':');
	id = grabInt(parts[0]);
	vector<string> drawStrings = Split(parts[1], ';');

	for (vector<string>::iterator i = drawStrings.begin(); i != drawStrings.end(); i++) {
		allDraws.push_back(Draw(*i));
	}

}
