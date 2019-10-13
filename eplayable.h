#ifndef EPLAYABLE_H
#define EPLAYABLE_H

#include "enonplayable.h"
#include "inventory.h"

class EPlayable : public ENonPlayableHitable
{
public:
    EPlayable();
    virtual ~EPlayable(){}

    sf::Clock hitClock;

    virtual void _update();

    virtual void moveLeft();
    virtual void moveRight();
    virtual void hit();

    virtual void triggerAction();

    Entity<sf::Sprite>* currentEntity;
    std::vector<Entity<sf::Sprite>*> hitableEntities;

    Inventory* inventory;
};

#endif // EPLAYABLE_H
