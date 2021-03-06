#include "unitspin.h"
#include "unitselection.h"
#include "unitmenu.h"
#include "../../battle/battle.h"

UnitSpin::UnitSpin(Battle *b) {
    std::vector<std::string> options = {
        "Northeast",
        "Northwest", 
        "Southwest",
        "Southeast"};
    b->setMenu(options);
}

void UnitSpin::doRight(Battle *b) {
    b->menuSelectionDown();
}
void UnitSpin::doUp(Battle *b) {
    b->menuSelectionUp();
}
void UnitSpin::doLeft(Battle *b) {
    b->menuSelectionUp();
}
void UnitSpin::doDown(Battle *b) {
    b->menuSelectionDown();
}
void UnitSpin::doZ(Battle *b) {
    // Should confirm spin
    b->menuSelectionClear();
    b->getBattleMap()->moveUnit();
    b->getBattleMap()->clearState();
    b->setAction(new UnitSelection(b));

}
void UnitSpin::doX(Battle *b) {
    b->menuSelectionClear();
    b->setAction(new UnitMenu(b));
    
}