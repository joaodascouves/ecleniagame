#include "inventory.h"

Inventory::Inventory()
{
    inventoryShape.setSize(sf::Vector2f(300, 140));
    inventoryShape.setFillColor(sf::Color(195, 55, 122));
    inventoryShape.setPosition(0, 70);

}

Inventory::Inventory(const Inventory& inventory)
{
    for( auto& i : inventory.items )
        acquireItem(i.second);

    inventoryShape.setSize(sf::Vector2f(300, 140));
    inventoryShape.setFillColor(sf::Color(195, 55, 122));
    inventoryShape.setPosition(0, 70);
}

void Inventory::acquireItem(EItem *item)
{
    if( items.size() < 10 )
    {
        items.insert(std::make_pair(item->getAlias(), new EItem(*item)));
        items[item->getAlias()]->setPosition(inventoryShape.getPosition().x + (items.size() - 1)*40, inventoryShape.getPosition().y);

        item->destroy();
    }
}

bool Inventory::has(std::string alias)
{
    return !(items.find(alias) == items.end());
}
