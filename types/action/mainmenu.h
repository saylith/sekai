/*
 * child class of action
 */

#ifndef MAINMENU_H
#define MAINMENU_H

#include "action.h"

class MainMenu : public Action {
public:
	MainMenu(Battle *b);
    void doRight(Battle *b);
    void doUp(Battle *b);
    void doLeft(Battle *b);
    void doDown(Battle *b);

    void doZ(Battle *b);
    void doX(Battle *b);
};



#endif /* MAINMENU_H */
