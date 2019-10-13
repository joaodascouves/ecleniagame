#ifndef ENONPLAYABLE_H
#define ENONPLAYABLE_H

#include "entity.h"

class ENonPlayable : public Entity<sf::Sprite>
{
public:
    ENonPlayable();
    virtual ~ENonPlayable(){}

    enum
    {
        S_STANDING,
        S_RUNNING,
        S_HITTING,
        S_SLAPPED,
        S_DYING
    };

    virtual void update();
    virtual void _update(){}
};

class ENonPlayableHitable : public ENonPlayable
{
public:
    ENonPlayableHitable();
    virtual ~ENonPlayableHitable(){}

    virtual void slap(signed short);

    unsigned short life = 3;
};

class AntiJoaozin : public ENonPlayable
{
public:
    AntiJoaozin();
    virtual ~AntiJoaozin(){}
};

class ES1Ghost : public ENonPlayableHitable
{
public:
    ES1Ghost();
    virtual ~ES1Ghost(){}

    virtual void _update();
};

#endif // ENONPLAYABLE_H
