#include "inventory.h"

Inventory::Inventory()
{
    inventoryShape.setSize(sf::Vector2f(300, 140));
    inventoryShape.setFillColor(sf::Color(195, 55, 122));
    inventoryShape.setPosition(0, 70);

}

void Inventory::acquireItem(EItem *item)
{
    if( items.size() < 10 )
    {
        items.push_back(new EItem(*item));
        items.back()->setPosition(inventoryShape.getPosition().x + (items.size() - 1)*40, inventoryShape.getPosition().y);

        item->destroy();
    }
}
