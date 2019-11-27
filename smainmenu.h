#ifndef SMAINMENU_H
#define SMAINMENU_H

#include "gamestate.h"

class SMainMenu : public GameState
{
public:
    SMainMenu();
    ~SMainMenu() override = default;

    void draw();
    void update();
    void handleInput();
};

#endif // SMAINMENU_H
