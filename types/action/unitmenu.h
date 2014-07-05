/*
 * child class of action
 */

#ifndef UNITMENU_H
#define UNITMENU_H

#include "action.h"

class UnitMenu : public Action {
public:
	UnitMenu(Battle *b);
    void doRight(Battle *b);
    void doUp(Battle *b);
    void doLeft(Battle *b);
    void doDown(Battle *b);

    void doZ(Battle *b);
    void doX(Battle *b);
};



#endif /* UNITMENU_H */
