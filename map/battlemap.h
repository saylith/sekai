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
	};

	enum State {
		NONE = '.', // Not accessible or reachable.
		ACCESSIBLE = 'a', // Within movement range.
		REACHABLE = 'r', // Within attack range.
		PATH = 'p' // Part of a path. Within movement range.
	};

	BattleMap(int width = 0, int height = 0);
	BattleMap(bool testing);

	int getWidth();
	int getHeight();

	int setWidth(int width);
	int setHeight(int height);

	Square *getSquareAt(int x, int y);
	Square *getSquareAt(Coords coords);

	State getStateAt(int x, int y);
	State getStateAt(Coords coords);
	State setStateAt(State state, int x, int y);
	State setStateAt(State state, Coords coords);

	Coords getFocus();
	Coords setFocus(int x, int y);
	Coords setFocus(Coords coords);
	Coords moveFocus(Direction direction);

	Coords moveUnit(Coords source, Coords dest);

	std::string printMap();
	std::vector<sf::Sprite> getSprites();

	void updateStateOnSelection(Coords selection);

private:
	int width;
	int height;

	std::vector<Square *> squares;
	Coords focus;

	std::vector<State> state;
	
	Coords getValidCoordsInDirection(Coords coords, 
		Direction direction, Unit *myUnit = NULL);
	void calculateAccessibleSquares(Coords selection, Unit *myUnit, int remaining);
	void calculateReachableSquares(std::vector<Coords> reachable);
	void calculateShortestPath();

	void clearReachable();
	void clearAccessible();
	void clearPaths();
	void clearState();
};

#endif