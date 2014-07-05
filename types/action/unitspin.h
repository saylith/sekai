/*
 * child class of action
 */

#ifndef UNITSPIN_H
#define UNITSPIN_H
 
#include "action.h"

class UnitSpin : public Action {
public:
	UnitSpin(Battle *b);	
    void doRight(Battle *b);
    void doUp(Battle *b);
    void doLeft(Battle *b);
    void doDown(Battle *b);

    void doZ(Battle *b);
    void doX(Battle *b);
};



#endif /* UNITSPIN_H */
