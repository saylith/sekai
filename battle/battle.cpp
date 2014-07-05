/*
 * Object that holds data for a battle between factions
 *
 * Currently defaults to 25x10 battlemap in the constructor
 *
 */

#include "battle.h"
#include <sstream>
#include <iostream>

#include "../types/action/action.h"
#include "../types/action/unitselection.h"

Battle::Battle() {
	bm = BattleMap(true);
	// currentAction = UNIT_SELECTION;
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
	action = new UnitSelection(this);
}

std::string Battle::getMap() {
	return bm.printMap();
}

void Battle::setMenu(std::vector<std::string> string) {
	menu = string;
}

std::string Battle::getMenu() {
	int menuSelectionIndex;
	// if(currentAction == MAIN_MENU)
	// 	menuSelectionIndex = mainMenuSelectionIndex;
	// else if(currentAction == UNIT_MENU)
	// 	menuSelectionIndex = unitMenuSelectionIndex;
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

BattleMap *Battle::getBattleMap() {
	return &bm;
}

void Battle::setAction(Action *action) {

	if(this->action != NULL)
		free(this->action);
	this->action = action;

}

void Battle::keyboardRight() {
	action->doRight(this);
}
void Battle::keyboardUp() {
	action->doUp(this);
}
void Battle::keyboardLeft() {
	action->doLeft(this);
}
void Battle::keyboardDown() {
	action->doDown(this);
}

void Battle::keyboardZ() {
	action->doZ(this);
}
void Battle::keyboardX() {
	action->doX(this);
}
void Battle::keyboardA() {

}
void Battle::keyboardS() {

}
