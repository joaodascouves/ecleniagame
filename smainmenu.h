#ifndef SMAINMENU_H
#define SMAINMENU_H

#include "gamestate.h"

class SMainMenu : public GameState
{
public:
    SMainMenu();

    void draw(float dt);
    void update(float dt);
    void handleInput();
};

#endif // SMAINMENU_H
