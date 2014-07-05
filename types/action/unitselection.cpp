#include "unitselection.h"
#include "unitselected.h"
#include "mainmenu.h"
#include "../../battle/battle.h"
#include "../../map/battlemap.h"
#include <iostream>

UnitSelection::UnitSelection(Battle *b) {

}

void UnitSelection::doRight(Battle *b) {
    b->getBattleMap()->moveFocus(BattleMap::EAST);
}
void UnitSelection::doUp(Battle *b) {
    b->getBattleMap()->moveFocus(BattleMap::NORTH);
}
void UnitSelection::doLeft(Battle *b) {
    b->getBattleMap()->moveFocus(BattleMap::WEST);
}
void UnitSelection::doDown(Battle *b) {
    b->getBattleMap()->moveFocus(BattleMap::SOUTH);
}
void UnitSelection::doZ(Battle *b) {
    BattleMap *bm = b->getBattleMap();

    if (bm->getSquareAt(bm->getFocus())->isOccupied()) {
        b->setAction(new UnitSelected(b));
        bm->updateStateOnSelection();
    }
    else {
        b->setAction(new MainMenu(b));
    }
}
void UnitSelection::doX(Battle *b) {
}

