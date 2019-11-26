#ifndef EDOOR_H
#define EDOOR_H

#include "gameinstance.h"
#include "entity.h"

#include <functional>

template<class T>
class EDoor : public Entity<sf::Sprite>
{
public:
    EDoor();
    virtual ~EDoor() override;

    enum
    {
        S_LOCKED,
        S_OPENED
    };

    T* location;

    std::function<bool()> conditionFunc;

    void setType(const short);
    int getType(short) const;

    virtual void update() override;
    virtual void action(Entity*) override;
};

#endif // EDOOR_H
