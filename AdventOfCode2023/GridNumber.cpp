#include "GridNumber.h"

GridNumber::GridNumber(vector<string>& grid, int val, Coordinate startCoord, Coordinate endCoord) {
	value = val;
	for (int row = startCoord.row; row <= endCoord.row; row++) {
		for (int col = startCoord.col; col <= endCoord.col; col++) {
			allCoords.push_back(Coordinate(row, col));
		}
	}
	VerifySymbolNeighbour(grid);
}

void GridNumber::VerifySymbolNeighbour(vector<string>& grid) {
	bool hasSymbol = false;
	vector<Coordinate> neighbours = AllValidNeighbours(grid);
	for (vector<Coordinate>::iterator i = neighbours.begin(); i != neighbours.end(); i++) {
		char c = grid[i->row][i->col];
		if (!isalnum(c) && c != '.') {
			hasSymbol = true;
			break;
		}
	}
	if (!hasSymbol) {
		value = 0;
	}
}

vector<Coordinate> GridNumber::AllValidNeighbours(vector<string>& grid) {
	vector<Coordinate> output;
	for (vector<Coordinate>::iterator i = allCoords.begin(); i != allCoords.end(); i++) {
		vector<Coordinate> allNeighbours = i->GetAllNeighbours();
		for (vector<Coordinate>::iterator j = allNeighbours.begin(); j != allNeighbours.end(); j++) {
			if (j->col >= 0 && j->row >= 0 && j->row < grid.size() && j->col < grid[0].size()) {
				output.push_back(*j);
			}
		}
	}
	return output;
}
