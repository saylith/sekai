#include "mainmenu.h"
#include "../../battle/battle.h"
#include "unitselection.h"

MainMenu::MainMenu(Battle *b) {
	std::vector<std::string> options = {
		"Unit List",
		"Conditions", 
		"Suspend",
		"End Turn"};
	b->setMenu(options);
}

void MainMenu::doRight(Battle *b) {
    b->menuSelectionDown();
}
void MainMenu::doUp(Battle *b) {
    b->menuSelectionUp();
}
void MainMenu::doLeft(Battle *b) {
    b->menuSelectionUp();
}
void MainMenu::doDown(Battle *b) {
    b->menuSelectionDown();
}
void MainMenu::doZ(Battle *b) {
    // Should be able to select based on index
    //int index = b->getMenuIndex();
}
void MainMenu::doX(Battle *b) {
	b->menuSelectionClear();
    b->setAction(new UnitSelection(b));
}
