#include "unitmenu.h"
#include "unitselected.h"
#include "unitspin.h"
#include "../../battle/battle.h"

UnitMenu::UnitMenu(Battle *b) {
    std::vector<std::string> options = {
        "Wait"};
    b->setMenu(options);
}

void UnitMenu::doRight(Battle *b) {
    b->menuSelectionDown();
}
void UnitMenu::doUp(Battle *b) {
    b->menuSelectionUp();
}
void UnitMenu::doLeft(Battle *b) {
    b->menuSelectionUp();
}
void UnitMenu::doDown(Battle *b) {
    b->menuSelectionDown();
}
void UnitMenu::doZ(Battle *b) {
 //    Should be able to select based on index
 //    int index = b->getMenuIndex();
 //    if(index == 0) {
	// 	b->setAction(UNIT_SPIN);
	// }
    b->menuSelectionClear();
    b->setAction(new UnitSpin(b));
}
void UnitMenu::doX(Battle *b) {
    b->menuSelectionClear();
    b->setAction(new UnitSelected(b));
    
}
