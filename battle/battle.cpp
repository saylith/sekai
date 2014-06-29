#include "battle.h"
#include <sstream>
#include <iostream>


Battle::Battle() {
	bm = BattleMap(25, 10);
	currentAction = UNIT_SELECTION;
	turn = 0;
	
	blankMenu = std::vector<std::string>();
	
	mainMenu = std::vector<std::string>();
	mainMenu.push_back("Unit List");
	mainMenu.push_back("Conditions");
	mainMenu.push_back("Suspend");
	mainMenu.push_back("End Turn");

	menu = blankMenu;
	menuSelectionIndex = 0;
}

std::string Battle::getMap() {
	return bm.printMap();
}

std::string Battle::getMenu() {
	if(menu.size() == 0)
		return "";

	std::stringstream ss;
	for(int i = 0; i < menu.size(); i++) {
		if(i == menuSelectionIndex)
			ss << ">";
		else
			ss << " ";
		ss << menu.at(i) << std::endl;
	}
	return ss.str();
}

void Battle::keyboardRight() {
	switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(BattleMap::EAST);
			break;
		case UNIT_SELECTED:
			bm.moveUnit(BattleMap::EAST);
			break;
		case MAIN_MENU:
			menuSelectionIndex = (menuSelectionIndex + 1) % menu.size();
			break;
		default:
			break;
	}

}
void Battle::keyboardUp() {
switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(BattleMap::NORTH);
			break;
		case UNIT_SELECTED:
			bm.moveUnit(BattleMap::NORTH);
			break;
		case MAIN_MENU:
			menuSelectionIndex = 
				(menu.size() + menuSelectionIndex - 1) % menu.size();
			break;
		default:
			break;
	}
}
void Battle::keyboardLeft() {
switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(BattleMap::WEST);
			break;
		case UNIT_SELECTED:
			bm.moveUnit(BattleMap::WEST);
			break;
		case MAIN_MENU:
			menuSelectionIndex = 
				(menu.size() + menuSelectionIndex - 1) % menu.size();
			break;
		default:
			break;
	}
}
void Battle::keyboardDown() {
switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(BattleMap::SOUTH);
			break;
		case UNIT_SELECTED:
			bm.moveUnit(BattleMap::SOUTH);
			break;
		case MAIN_MENU:
			menuSelectionIndex = (menuSelectionIndex + 1) % menu.size();
			break;
		default:
			break;
	}
}

void Battle::keyboardZ() {
	switch(currentAction) {
		case UNIT_SELECTION: {
			
			if (bm.confirm()->isSelected()) {
				currentAction = UNIT_SELECTED;
				menu = blankMenu;
			}
			else {
				currentAction = MAIN_MENU;
				menu = mainMenu;
			}
			break;
		}
		default:
			break;
	}
}
void Battle::keyboardX() {
switch(currentAction){
		case MAIN_MENU:
			currentAction = UNIT_SELECTION;
			bm.cancel();
			menu = blankMenu;
			break;
		case UNIT_SELECTED:
			currentAction = UNIT_SELECTION;
			bm.cancel();
			menu = blankMenu;
		default:
			break;
	}
}
void Battle::keyboardA() {

}
void Battle::keyboardS() {

}