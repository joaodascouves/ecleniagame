#ifndef EITEM_H
#define EITEM_H

#include "entity.h"

class EItem : public Entity<sf::Sprite>
{
public:
    EItem();
    EItem(const EItem&);
    ~EItem() override = default;

    virtual void action(Entity*) override;
};

#endif // EITEM_H
