#ifndef EDOOR_H
#define EDOOR_H

#include "entity.h"
#include "eplayable.h"

class EDoor : public Entity<sf::Sprite>
{
public:
    EDoor();
    EDoor(const short);
    virtual ~EDoor(){}

    enum
    {
        S_LOCKED,
        S_OPENED
    };

    void setType(const short);
    int getType(short) const;

    virtual void update(const float);
    virtual void openDoor(EPlayable*);
};

#endif // EDOOR_H
