#ifndef EDOOR_H
#define EDOOR_H

#include "gameinstance.h"
#include "sworld.h"
#include "entity.h"
#include "eplayable.h"

#include <functional>

class EDoor : public Entity<sf::Sprite>
{
public:
    EDoor();
    EDoor(const short);
    virtual ~EDoor();

    enum
    {
        S_LOCKED,
        S_OPENED
    };

    SWorld* location;

    std::function<bool()> conditionFunc;

    void setType(const short);
    int getType(short) const;

    virtual void update(const float);
    virtual void enterDoor(EPlayable*, SWorld*);
};

#endif // EDOOR_H
