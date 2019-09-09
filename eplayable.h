#ifndef EPLAYABLE_H
#define EPLAYABLE_H

#include "entity.h"
#include "inventory.h"

class EPlayable : public Entity<sf::Sprite>
{
public:
    EPlayable();
    virtual ~EPlayable(){}

    enum
    {
        S_RUNNING,
        S_STANDING,
        S_WALKING,
        S_JUMPING,
        S_FALLING
    };

    virtual void update(const float dt);
    virtual void handleMovement();

    virtual void moveLeft();
    virtual void moveRight();

    virtual void triggerAction();

    Entity<sf::Sprite>* currentEntity;
    Inventory* inventory;
};

#endif // EPLAYABLE_H
