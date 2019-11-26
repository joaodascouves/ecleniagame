#ifndef INVENTORY_H
#define INVENTORY_H

#include "eitem.h"
#include <map>

class Inventory
{
public:
    Inventory();
    Inventory(const Inventory&);

    sf::RectangleShape inventoryShape;
    std::map<std::string, EItem*> items;

    void acquireItem(EItem*);
    bool has(const std::string&);
};

#endif // INVENTORY_H
