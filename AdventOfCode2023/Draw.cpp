#include "Draw.h"

Draw::Draw() {
	red = 0;
	green = 0;
	blue = 0;
}

Draw::Draw(string input) : Draw() {
	//split on comma
	vector<string> parts = Split(input, ',');
	for (vector<string>::iterator i = parts.begin(); i != parts.end(); i++) {
		if (tryFind(*i, "red", red) || tryFind(*i, "green", green) || tryFind(*i, "blue", blue)) {
			continue;
		}
	}
}

 bool Draw::CheckDraw(int r, int g, int b) {
	if (red <= r && green <= g && blue <= b) {
		return true;
	}
	return false;
}

 bool Draw::tryFind(string input, string word, int& var) {
	if (input.find(word) != string::npos) {
		var = grabInt(input);
		return true;
	}
	return false;
}

 void Draw::UpdateMinCubes(int &r, int &g, int &b)
 {
	 if (red > r) {
		 r = red;
	 }
	 if (green > g) {
		 g = green;
	 }
	 if (blue > b) {
		 b = blue;
	 }
 }
