#ifndef EPLAYABLE_H
#define EPLAYABLE_H

#include "entity.h"
#include "animation.h"

class EPlayable : public Entity<sf::Sprite>, public Animation
{
public:
    EPlayable();
    virtual ~EPlayable(){}

    virtual void update(const float dt);
    virtual void handleMovement();

    enum
    {
        S_STANDING,
        S_RUNNING,
        S_WALKING,
        S_JUMPING,
        S_FALLING
    };

    int playerStatus = S_STANDING;

    sf::Texture texRun;
};

#endif // EPLAYABLE_H
