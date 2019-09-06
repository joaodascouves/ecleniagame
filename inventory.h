#ifndef INVENTORY_H
#define INVENTORY_H

#include "eitem.h"
#include <vector>

class Inventory
{
public:
    Inventory();

    sf::RectangleShape inventoryShape;
    std::vector<EItem*> items;

    void acquireItem(EItem*);
};

#endif // INVENTORY_H
