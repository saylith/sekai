#ifndef SQUARE_H
#define SQUARE_H

#include "../units/unit.h"
#include "../units/saylith.h"
#include "landmark.h"
#include "terrain.h"

class Square
{
	Unit *occupant;
	Terrain terrain;
	Landmark landmark;

	int x, y;
	char state;

public:
	Square();

	Square(int x = 0, int y = 0,
		Terrain terrain = Terrain(), 
		Landmark landmark = Landmark(),
		Unit *occupant = 0);

	int getX();
	int getY();
	bool isFocused();
	bool isSelected();
	bool isHighlighted();

	int setX(int x);
	int setY(int y);

	char setFocused();

	char setSelected();

	char setHighlighted();

	char resetState();

	Unit *getUnit();
	Unit *setUnit(Unit *unit);
	bool isOccupied();

	char getRepresentation();
};

#endif