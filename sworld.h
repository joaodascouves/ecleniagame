#ifndef SWORLD_H
#define SWORLD_H

#include "gamestate.h"
#include "eplayable.h"

#include <vector>

class SWorld : public GameState
{
public:
    SWorld();

    virtual void draw(const float dt);
    virtual void update(const float dt);

    virtual float getFloor() const;

    sf::View worldView;
    sf::View inventoryView;

    sf::Text actionDescription;
    sf::Font font;

    std::vector<Entity<sf::Sprite>*> worldEntities;
    std::vector<Entity<sf::RectangleShape>*> worldEntitiesRect;

    EPlayable* mainPlayer;
};

#endif // SWORLD_H
