#ifndef ENONPLAYABLE_H
#define ENONPLAYABLE_H

#include "entity.h"

class ENonPlayable : public Entity<sf::Sprite>
{
public:
    ENonPlayable();
    ~ENonPlayable() override = default;

    enum
    {
        S_STANDING,
        S_FLOATING = 0,
        S_RUNNING,
        S_HITTING,
        S_SLAPPED,
        S_DYING
    };

    virtual void update() override;
    virtual void _update(){}

    float speed = .0f;
};

#endif // ENONPLAYABLE_H
