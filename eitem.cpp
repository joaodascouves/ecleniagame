#include "eitem.h"

EItem::EItem()
{
    setClass("item");

}

EItem::EItem(const EItem& item)
{
    drawableObject->setTexture(*item.drawableObject->getTexture());
    setAlias(item.getAlias());
}
