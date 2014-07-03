#ifndef BATTLEMAP_H
#define BATTLEMAP_H

#include "square.h"


class BattleMap
{
public:
	enum Direction {
		NORTH, SOUTH, EAST, WEST
	};

	struct Coords {
		int x, y;	
	} coords;

	BattleMap();

	BattleMap(int width, int height);

	int getWidth();
	int getHeight();

	int setWidth(int width);
	int setHeight(int height);

	Square *getSquareAt(int x, int y);
	Square *getSquareAt(Coords coords);

	std::string printMap();

	Coords setFocus(int x, int y);
	Coords setFocus(Coords coords);
	Coords getFocus();
	Coords moveFocus(Direction direction);
	Coords moveUnit(Coords source, Coords dest);
	Coords movePath(Direction);

	void calculatePossibleMoves(Coords selection);

	Coords confirm();
	Coords cancel();

	void confirmUnitSelection();

	void confirmUnitDestination();

	void confirmUnitWait();

	void cancelMainMenu();

	void cancelUnitSelection();

	void cancelUnitMenu();

	std::vector<sf::Sprite> getSprites();

private:
	int width;
	int height;
	std::vector<Square *> squares;
	std::vector<Coords> possibleMoves;
	std::vector<Coords> path;
	std::map<Coords, sf::Color> highlighted;
	Coords focus;

	Coords getValidCoordsInDirection(Coords coords, 
		Direction direction, Unit *myUnit = NULL);
	void calculatePossibleMoves(Coords selection, Unit *myUnit, int remaining);
	void clearPossibleMoves();
	void clearPath();
};

#endif