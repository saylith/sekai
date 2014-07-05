/*
 * child class of action
 */

#ifndef BUSY_H
#define BUSY_H

#include "action.h"

class Busy : public Action {
public:
	Busy(Battle *b);
    void doRight(Battle *b);
    void doUp(Battle *b);
    void doLeft(Battle *b);
    void doDown(Battle *b);

    void doZ(Battle *b);
    void doX(Battle *b);
};



#endif /* BUSY_H */
