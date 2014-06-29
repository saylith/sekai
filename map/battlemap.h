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
	std::vector<Square *> possibleMoves;
	std::vector<Square *> path;
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
	Square *getFocus();
	Square *moveFocus(Direction direction);
	Square *moveUnit(Square::Coords source, Square::Coords dest);
	Square *movePath(Direction);

	void calculatePossibleMoves(Square *selection);

	Square *confirm();
	Square *cancel();

	void confirmUnitSelection();

	void confirmUnitDestination();

	void confirmUnitWait();

	void cancelMainMenu();

	void cancelUnitSelection();

	void cancelUnitMenu();

private:
	Square::Coords getValidCoordsInDirection(Square::Coords coords, 
		Direction direction, Unit *myUnit = NULL);
	void calculatePossibleMoves(Square *selection, Unit *myUnit, int remaining);
	void clearPossibleMoves();
	void clearPath();
};

#endif