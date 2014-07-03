/*
 * Object that holds data for a battle between factions
 *
 * Currently defaults to 25x10 battlemap in the constructor
 *
 */

#include "battle.h"
#include <sstream>
#include <iostream>


Battle::Battle() {
	bm = BattleMap(true);
	currentAction = UNIT_SELECTION;
	turn = 0;
	
	blankMenu = std::vector<std::string>();
	
	mainMenu = std::vector<std::string>();
	mainMenu.push_back("Unit List");
	mainMenu.push_back("Conditions");
	mainMenu.push_back("Suspend");
	mainMenu.push_back("End Turn");

	unitMenu = std::vector<std::string>();
	unitMenu.push_back("Wait");

	menu = blankMenu;
	mainMenuSelectionIndex = 0;
	unitMenuSelectionIndex = 0;
}

std::string Battle::getMap() {
	return bm.printMap();
}

std::string Battle::getMenu() {
	int menuSelectionIndex;
	if(currentAction == MAIN_MENU)
		menuSelectionIndex = mainMenuSelectionIndex;
	else if(currentAction == UNIT_MENU)
		menuSelectionIndex = unitMenuSelectionIndex;
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

std::vector<sf::Sprite> Battle::drawMap() {
	return bm.getSprites();
}

void Battle::keyboardRight() {
	switch(currentAction){
		case UNIT_SELECTION:
			bm.moveFocus(BattleMap::EAST);
			break;
		case UNIT_SELECTED:

			break;
		case MAIN_MENU:
			mainMenuSelectionIndex = 
				(mainMenuSelectionIndex + 1) % menu.size();
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

			break;
		case MAIN_MENU:
			mainMenuSelectionIndex = 
				(menu.size() + mainMenuSelectionIndex - 1) % menu.size();
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

			break;
		case MAIN_MENU:
			mainMenuSelectionIndex = 
				(menu.size() + mainMenuSelectionIndex - 1) % menu.size();
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

			break;
		case MAIN_MENU:
			mainMenuSelectionIndex = 
				(mainMenuSelectionIndex + 1) % menu.size();
			break;
		default:
			break;
	}
}

void Battle::keyboardZ() {
	switch(currentAction) {
		case UNIT_SELECTION: {
			
			// if (bm.getSquareAt(bm.confirm())->isOccupied()) {
			// 	currentAction = UNIT_SELECTED;
			// 	menu = blankMenu;
			// }
			// else {
				currentAction = MAIN_MENU;
				menu = mainMenu;
			// }
			break;
		}
		case UNIT_SELECTED:
			currentAction = UNIT_MENU;
			menu = unitMenu;
			break;
		case UNIT_MENU:
			if (unitMenuSelectionIndex == 0) {
				currentAction = UNIT_SELECTION;
				menu = blankMenu;
			}
			break;
		default:
			break;
	}
}
void Battle::keyboardX() {
switch(currentAction){
		case MAIN_MENU:
			currentAction = UNIT_SELECTION;
			menu = blankMenu;
			break;
		case UNIT_SELECTED:
			currentAction = UNIT_SELECTION;
			menu = blankMenu;
			break;
		case UNIT_MENU:
			currentAction = UNIT_SELECTED;
			menu = blankMenu;
			break;
		default:
			break;
	}
}
void Battle::keyboardA() {

}
void Battle::keyboardS() {

}