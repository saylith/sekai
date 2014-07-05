#include "unitselected.h"
#include "unitselection.h"
#include "unitmenu.h"
#include "../../battle/battle.h"
#include "../../map/battlemap.h"

UnitSelected::UnitSelected(Battle *b) {
	
}

void UnitSelected::doRight(Battle *b) {
    b->getBattleMap()->movePath(BattleMap::EAST);
}
void UnitSelected::doUp(Battle *b) {
    b->getBattleMap()->movePath(BattleMap::NORTH);
}
void UnitSelected::doLeft(Battle *b) {
    b->getBattleMap()->movePath(BattleMap::WEST);
}
void UnitSelected::doDown(Battle *b) {
    b->getBattleMap()->movePath(BattleMap::SOUTH);
}
void UnitSelected::doZ(Battle *b) {
    b->setAction(new UnitMenu(b));
}
void UnitSelected::doX(Battle *b) {
    b->setAction(new UnitSelection(b));
    b->getBattleMap()->setFocusToOrigin();
    b->getBattleMap()->clearState();
}

