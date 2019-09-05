#ifndef EPLAYABLE_H
#define EPLAYABLE_H

#include "entity.h"

class EPlayable : public Entity<sf::Sprite>
{
public:
    EPlayable();
    virtual ~EPlayable(){}

    virtual void update(const float dt);
    virtual void handleMovement();
    virtual void moveLeft();
    virtual void moveRight();
};

#endif // EPLAYABLE_H
