#include "eitem.h"
#include "eplayable.h"

EItem::EItem()
{
    addClass("item");
}

EItem::EItem(const EItem& item)
{
    front()->setTexture(*item.front()->getTexture());
    setAlias(item.getAlias());
    addClass("item");
}

void EItem::action(Entity *mainPlayer)
{
    static_cast<EPlayable*>(mainPlayer)->inventory->acquireItem(
                static_cast<EItem *>(static_cast<EPlayable*>(mainPlayer)->currentEntity));
}

