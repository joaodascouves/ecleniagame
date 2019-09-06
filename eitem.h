#ifndef EITEM_H
#define EITEM_H

#include "entity.h"

class EItem : public Entity<sf::Sprite>
{
public:
    EItem();
    EItem(const EItem&);

    //
};

#endif // EITEM_H
