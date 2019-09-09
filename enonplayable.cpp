#include "enonplayable.h"
#include "resourcemanager.h"

ENonPlayable::ENonPlayable()
{
    setClass("nonplayable");
}

AntiJoaozin::AntiJoaozin()
{
    ResourceManager::get().loadTexture("agoravai.png");
    drawableObject->setTexture(*ResourceManager::get().textureMap.at("agoravai"));
    drawableObject->setScale(0.23f, 0.23f);

    sequences.push_back({0, 0, 4, 0});
    frameWidth = ResourceManager::get().textureMap.at("agoravai")->getSize().x/11;
    frameHeight = ResourceManager::get().textureMap.at("agoravai")->getSize().y/1;
}

void AntiJoaozin::update(const float dt)
{
    tickAnimation(20);
    drawableObject->setTextureRect(currentFrame());
}
