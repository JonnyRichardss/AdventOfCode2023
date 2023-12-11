#include "Gear.h"

Gear::Gear(Coordinate c,int initialMult = 1) {
	countAdjacent = 1;
	ratio = 1 * initialMult;
	position = c;
}




