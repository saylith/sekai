/*
 * replacement for action enum from battle.h
 * children: unitSelection,
		unitSelected,
		unitSpin,
		unitMenu,
		mainMenu,
		busy
 */

#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <string>

class Battle;
class Action
{
    public:
    virtual void doRight(Battle *b) = 0;
    virtual void doUp(Battle *b) = 0;
    virtual void doLeft(Battle *b) = 0;
    virtual void doDown(Battle *b) = 0;
   
    virtual void doZ(Battle *b) = 0;
    virtual void doX(Battle *b) = 0;
};

#endif /* ACTION_H */
