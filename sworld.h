#ifndef SWORLD_H
#define SWORLD_H

#include "gamestate.h"
#include "entity.h"
#include <vector>

class SWorld : public GameState
{
public:
    SWorld();

    virtual void draw(const float dt);
    virtual void update(const float dt);

    sf::View worldView;
    std::vector<Entity<sf::Sprite>*> worldEntities;
};

#endif // SWORLD_H
