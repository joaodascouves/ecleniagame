#include "eplayable.h"
#include "gameinstance.h"
#include "texturemanager.h"

#include <iostream>

EPlayable::EPlayable()
{
    TextureManager::get().loadTexture("agoravai.png");
    TextureManager::get().textureMap.at("agoravai")->setSmooth(false);

    drawableObject->setOrigin(500.f, 0);
    drawableObject->setTexture(*TextureManager::get().textureMap.at("agoravai"));
    drawableObject->setScale(.23f, .23f);
    drawableObject->setTextureRect(sf::IntRect(0 + 5, 0, 399 - 5, 369));

    sequences.push_back({0, 5, 11, 0});
    sequences.push_back({0, 0, 4, 0});

    frameWidth = TextureManager::get().textureMap.at("agoravai")->getSize().x/11;
    frameHeight = TextureManager::get().textureMap.at("agoravai")->getSize().y/1;
}

void EPlayable::update(const float dt)
{
    drawableObject->setTextureRect(currentFrame());

    setStatus(S_STANDING, true);
}

void EPlayable::moveLeft()
{
    if( direction == D_RIGHT ) flipHorizontally();
    drawableObject->move(-2, 0);

    setStatus(S_RUNNING, true);
    tickAnimation();
}

void EPlayable::moveRight()
{
    if( direction == D_LEFT ) flipHorizontally();
    drawableObject->move(2, 0);

    setStatus(S_RUNNING, true);
    tickAnimation();
}

void EPlayable::handleMovement()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
        moveLeft();

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
        moveRight();
}

void EPlayable::triggerAction()
{
    //
}
