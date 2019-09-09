#ifndef ENONPLAYABLE_H
#define ENONPLAYABLE_H

#include "entity.h"

class ENonPlayable : public Entity<sf::Sprite>
{
public:
    ENonPlayable();
    virtual ~ENonPlayable(){}

    virtual void update(const float){}
};

class AntiJoaozin : public ENonPlayable
{
public:
    AntiJoaozin();
    virtual ~AntiJoaozin(){}

    virtual void update(const float);
};

#endif // ENONPLAYABLE_H
