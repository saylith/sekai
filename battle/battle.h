#ifndef BATTLE_H
#define BATTLE_H

#include "../map/battlemap.h"
#include "../types/action/action.h"
#include <string>
#include <vector>

class Battle
{
	BattleMap bm;
	
	int turn;
	int numPlayers;

	std::vector<std::string> menu;
	int menuSelectionIndex;

	Action *action;

public:
	Battle();

	std::string getMap();
	std::string getMenu();
	std::vector<sf::Sprite> drawMap();
	BattleMap *getBattleMap();
	void setAction(Action *action);
	void setMenu(std::vector<std::string> string);
	void keyboardRight();
	void keyboardUp();
	void keyboardDown();
	void keyboardLeft();
	void keyboardZ();
	void keyboardX();
	void keyboardA();
	void keyboardS();

	int menuSelectionUp();
	int menuSelectionDown();
	int menuSelectionClear();
};
#endif
