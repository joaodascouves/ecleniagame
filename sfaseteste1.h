#ifndef SFASETESTE1_H
#define SFASETESTE1_H

#include "sworld.h"
#include "eplayable.h"

#include <vector>

class SFaseTeste1 : public SWorld
{
public:
    SFaseTeste1();

    void update(float dt);
    void handleInput();

    sf::RectangleShape rect;
    EPlayable* player = new EPlayable;
};

#endif // SFASETESTE1_H
