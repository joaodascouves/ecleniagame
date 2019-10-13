#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameinstance.h"

class GameState
{
public:
    GameState();
    virtual ~GameState(){}

    GameInstance* game;

    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void handleInput() = 0;
};

#endif // GAMESTATE_H
