#ifndef EPLAYABLE_H
#define EPLAYABLE_H

#include "entity.h"

class EPlayable : public Entity<sf::Sprite>
{
public:
    EPlayable();
    virtual ~EPlayable(){}

    sf::Texture texRun;
};

#endif // EPLAYABLE_H
