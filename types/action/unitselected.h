/*
 * child class of action
 */

#ifndef UNITSELECTED_H
#define UNITSELECTED_H

#include "action.h"

class UnitSelected : public Action {
public:
	UnitSelected(Battle *b);
    void doRight(Battle *b);
    void doUp(Battle *b);
    void doLeft(Battle *b);
    void doDown(Battle *b);
   
    void doZ(Battle *b);
    void doX(Battle *b);
};



#endif /* UNITSELECTED_H */
