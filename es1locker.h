#ifndef ES1LOCKER_H
#define ES1LOCKER_H

#include "entity.h"

class ES1Locker : public Entity<sf::Sprite>
{
public:
    ES1Locker();
    virtual ~ES1Locker(){}

    sf::Text* slots[4];

    virtual void update();
    virtual void action(Entity*);
};

#endif // ES1LOCKER_H
