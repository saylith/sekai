#ifndef BATTLE_H
#define BATTLE_H

#include "../map/battlemap.h"

class Battle
{
	enum Action {
		UNIT_SELECTION, 
		UNIT_SELECTED, 
		UNIT_SPIN,
		UNIT_MENU, 
		MAIN_MENU, 
		BUSY
	};

	BattleMap bm;
	
	int turn;
	int numPlayers;

	std::vector<std::string> menu;
	std::vector<std::string> blankMenu;
	std::vector<std::string> mainMenu;
	std::vector<std::string> unitMenu;
	int mainMenuSelectionIndex;
	int unitMenuSelectionIndex;

	Action currentAction;

public:
	Battle();

	std::string getMap();
	std::string getMenu();
	std::vector<sf::Sprite> drawMap();

	void keyboardRight();
	void keyboardUp();
	void keyboardDown();
	void keyboardLeft();
	void keyboardZ();
	void keyboardX();
	void keyboardA();
	void keyboardS();
};
#endif
