#pragma once
#include "Coordinate.h"
#include <string>
#include <vector>
using namespace std;
class GridNumber
{
public:
	int value;
	vector<Coordinate> allCoords;
	GridNumber(vector<string>& grid, int val, Coordinate startCoord, Coordinate endCoord);
	void VerifySymbolNeighbour(vector<string>& grid);
	vector<Coordinate> AllValidNeighbours(vector<string>& grid);
};

