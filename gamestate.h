#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameinstance.h"

class GameState
{
public:
    GameState();
    virtual ~GameState(){}

    GameInstance* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};

#endif // GAMESTATE_H
