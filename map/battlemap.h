#ifndef BATTLEMAP_H
#define BATTLEMAP_H

#include "square.h"
#include <forward_list>

class BattleMap
{
public:
	enum Direction {
		NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3
	};

	struct Coords {
		int x, y;	
	};

	enum State {
		NONE = '.', // Not accessible or reachable.
		ACCESSIBLE = 'a', // Within movement range.
		REACHABLE = 'r', // Within attack range.
		PATH = 'p' // Part of the path. Also within movement/attack range
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
	State setStateAt(int x, int y, State state);
	State setStateAt(Coords coords, State state);

	Coords getFocus();
	Coords setFocus(int x, int y);
	Coords setFocus(Coords coords);
	Coords moveFocus(Direction direction);
	Coords movePath(Direction direction);

	Coords moveUnit();

	std::string printMap();
	std::vector<sf::Sprite> getSprites();

	void updateStateOnSelection();
	void clearState();
	void setFocusToOrigin();
	void setUnitDirection(Direction direction);

private:

	int width;
	int height;

	struct Path {
		Coords origin;
		std::vector<Direction> directions;
		int max;
	} path;

	std::vector<Square *> squares;
	Coords focus;

	std::vector<State> state;
	
	
	Coords getValidCoordsInDirection(Coords coords, 
		Direction direction, Unit *myUnit = NULL);
	void setRadiusState(Coords selection, int radius, State state);
	void calculateShortestPath();

	
};

#endif