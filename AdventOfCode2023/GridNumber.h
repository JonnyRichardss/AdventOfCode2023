#pragma once
#include "Coordinate.h"
#include "Gear.h"
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
	void AddAllGears(vector<string>& grid,vector<Gear> &ExistingGears);
	vector<Coordinate> AllValidNeighbours(vector<string>& grid);

};

