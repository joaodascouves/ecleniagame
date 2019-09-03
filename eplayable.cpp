#include "eplayable.h"

EPlayable::EPlayable()
{
    texRun.loadFromFile("/home/void/runanim.bmp");
    drawableObject->setTexture(texRun);
    drawableObject->setScale(0.2f, 0.2f);
    drawableObject->setTextureRect(sf::IntRect(0, 0, 399, 369));
}
