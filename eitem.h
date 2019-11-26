#ifndef EITEM_H
#define EITEM_H

#include "entity.h"

class EItem : public Entity<sf::Sprite>
{
public:
    EItem();
    EItem(const EItem&);

    virtual void action(Entity*) override;
};

#endif // EITEM_H
