#ifndef BATTLEMAP_H
#define BATTLEMAP_H

#include "square.h"
#include <string>
#include <vector>


class BattleMap
{
	int width;
	int height;
	std::vector<Square *> squares;
	Square* focus;

public:
	enum Direction {
		NORTH, SOUTH, EAST, WEST
	};

	BattleMap();

	BattleMap(int width, int height);

	int getWidth();
	int getHeight();

	int setWidth(int width);
	int setHeight(int height);

	Square *getSquareAt(int x, int y);
	Square *getSquareAt(Square::Coords coords);

	std::string printMap();

	Square *setFocus(int x, int y);
	Square *setFocus(Square::Coords coords);
	Square *moveFocus(Direction direction);
	Square *moveUnit(Direction direction);
	Square *confirm();
	Square *cancel();

private:
	Square::Coords getValidCoordinatesInDirection(Square::Coords coords, 
		Direction direction);
};

#endif