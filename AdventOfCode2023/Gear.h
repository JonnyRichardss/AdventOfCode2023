#pragma once
#include "Coordinate.h"
class Gear
{
public:
	Coordinate position;
	int countAdjacent;
	int ratio;
	Gear(Coordinate c , int initialMult);
};

