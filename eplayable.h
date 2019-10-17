#ifndef EPLAYABLE_H
#define EPLAYABLE_H

#include "enonplayablehitable.h"
#include "inventory.h"

class EPlayable : public ENonPlayableHitable
{
public:
    EPlayable();
    virtual ~EPlayable(){}

    sf::Clock hitClock;

    virtual void _update();
    virtual void hit();

    Entity<sf::Sprite>* currentEntity;
    sf::Text* currentTextEntity;

    std::vector<Entity<sf::Sprite>*> hitableEntities;

    Inventory* inventory;
};

#endif // EPLAYABLE_H
