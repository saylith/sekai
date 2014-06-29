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
	
public:
	enum State {
		SELECTED = 's',
		HIGHLIGHTED = 'h',
		PATH = 'p',
		NONE = '.'
	} state;

	struct Coords {
		int x, y;	
	} coords;

	Square();

	Square(int x = 0, int y = 0,
		Terrain terrain = Terrain(), 
		Landmark landmark = Landmark(),
		Unit *occupant = 0);

	int getX();
	int getY();
	Coords getCoords();
	bool isSelected();
	bool isHighlighted();

	int setX(int x);
	int setY(int y);
	Coords setCoords(Coords coords);


	char setSelected();

	char setHighlighted();

	char resetState();
	char setState(State state);
	State getState();

	Unit *getUnit();
	Unit *setUnit(Unit *unit);
	bool isOccupied();

	char getRepresentation();
};

#endif