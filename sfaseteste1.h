#ifndef SFASETESTE1_H
#define SFASETESTE1_H

#include "gamestate.h"
#include "eplayable.h"

class SFaseTeste1 : public GameState
{
public:
    SFaseTeste1();

    void draw(float dt);
    void update(float dt);
    void handleInput();

    sf::RectangleShape rect;
    EPlayable* player = new EPlayable;
};

#endif // SFASETESTE1_H
