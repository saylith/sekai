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

public:
	BattleMap();

	BattleMap(int width, int height);

	int getWidth();
	int getHeight();

	int setWidth(int width);
	int setHeight(int height);

	Square* getSquareAt(int x, int y);

	std::string printMap();
};

#endif