#include "battle.h"

Battle::Battle() {
	bm = BattleMap(25, 10);
	currentAction = UNIT_SELECTION;
	turn = 0;
	menu = "";
}

std::string Battle::getMap() {
	return bm.printMap();
}

std::string Battle::getMenu() {
	return menu;
}

void Battle::keyboardRight() {
	switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(0);
			break;
		default:
			break;
	}

}
void Battle::keyboardUp() {
switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(1);
			break;
		default:
			break;
	}
}
void Battle::keyboardLeft() {
switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(2);
			break;
		default:
			break;
	}
}
void Battle::keyboardDown() {
switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(3);
			break;
		default:
			break;
	}
}

void Battle::keyboardZ() {
switch(currentAction){
		case UNIT_SELECTION:
			bm.confirm();
			currentAction = MAIN_MENU;
			menu = "MAIN MENU\nUnits\nObjectives\nEnd Turn";
			break;
		default:
			break;
	}
}
void Battle::keyboardX() {
switch(currentAction){
		case MAIN_MENU:
			currentAction = UNIT_SELECTION;
			bm.cancel();
			menu = "";
			break;
		default:
			break;
	}
}
void Battle::keyboardA() {

}
void Battle::keyboardS() {

}