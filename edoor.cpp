#include "edoor.h"
#include "texturemanager.h"

EDoor::EDoor()
{
    EDoor(0);

}

EDoor::EDoor(const short type)
{
    setClass("door");

    TextureManager::get().loadTexture("door.png");

    drawableObject->setTexture(*TextureManager::get().textureMap.at("door"));
    drawableObject->setScale(.2f, .28f);

    setStatus(S_OPENED);

    sequences.push_back({0, 0, 0, 0});
    sequences.push_back({0, 0, 5, 0});

    frameWidth = drawableObject->getTexture()->getSize().x/5;
    frameHeight = drawableObject->getTexture()->getSize().y/1;
}

void EDoor::update(const float dt)
{
//    tickAnimation(20, true);
    drawableObject->setTextureRect(currentFrame());
}

void EDoor::openDoor(EPlayable *player)
{
    setStatus(S_OPENED);
}
