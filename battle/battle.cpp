#include "battle.h"

Battle::Battle() {
	bm = BattleMap(5, 3);
}

std::string Battle::getMap() {
	return bm.printMap();
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
			currentAction = UNIT_MENU;
			break;
		default:
			break;
	}
}
void Battle::keyboardX() {
switch(currentAction){
		case UNIT_MENU:
			currentAction = UNIT_SELECTION;
			bm.cancel();
			break;
		default:
			break;
	}
}
void Battle::keyboardA() {

}
void Battle::keyboardS() {

}