#ifndef SQUARE_H
#define SQUARE_H

//#include "../units/unit.h"
#include "landmark.h"
#include "terrain.h"

class Square
{

//	Unit occupant;
	Terrain terrain;
	Landmark landmark;

	int x, y;

public:
	Square();

	Square(int x = 0, int y = 0, 
		//Unit unit = Unit(),
		Terrain terrain = Terrain(), 
		Landmark landmark = Landmark());

	int getX();
	int getY();

	int setX(int x);
	int setY(int y);

	char getRepresentation();
};

#endif