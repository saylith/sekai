/*
 * child class of action
 */

#ifndef UNITSELECTION_H
#define UNITSELECTION_H

#include "action.h"

class UnitSelection : public Action {
public:
	UnitSelection(Battle *b);
    void doRight(Battle *b);
    void doUp(Battle *b);
    void doLeft(Battle *b);
    void doDown(Battle *b);
   
    void doZ(Battle *b);
    void doX(Battle *b);
};

#endif /* UNITSELECTION_H */
