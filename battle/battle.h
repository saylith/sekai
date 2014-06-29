#ifndef BATTLE_H
#define BATTLE_H

#include "../map/battlemap.h"

class Battle
{
	enum Action {
		UNIT_SELECTION, UNIT_MENU, MAIN_MENU, BUSY
	};

	BattleMap bm;
	int turn;
	Action currentAction;

public:
	Battle();

	std::string getMap();

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