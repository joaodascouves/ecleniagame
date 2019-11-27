#ifndef ES1LOCKER_H
#define ES1LOCKER_H

#include "entity.h"

class ES1Locker : public Entity<sf::Sprite>
{
public:
    ES1Locker();
    ~ES1Locker() override = default;

    sf::Text* slots[4];

    virtual void update() override;
    virtual void action(Entity*) override;
};

#endif // ES1LOCKER_H
