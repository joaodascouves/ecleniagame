#include "eplayable.h"
#include "gameinstance.h"
#include "resourcemanager.h"
#include "edoor.h"

#include "sfaseteste1.h"

#include <iostream>

EPlayable::EPlayable()
{
    setClass("mainPlayer");

    ResourceManager::get().loadTexture("sheet1.png");
    ResourceManager::get().textureMap.at("sheet1")->setSmooth(true);

    drawableObject->setOrigin(120, 0);
    drawableObject->setTexture(*ResourceManager::get().textureMap.at("sheet1"));
    drawableObject->setTextureRect(sf::IntRect(0 + 5, 0, 399 - 5, 369));

    configAnimation(11, 2);
    addSequence(S_STANDING, {0, 0, 4, 0, 0});
    addSequence(S_RUNNING, {0, 5, 11, 0, 0});
    addSequence(S_HITTING, {1, 1, 4, 0, 0});

    inventory = new Inventory;
}

void EPlayable::_update()
{
    if( sequences.at(currentSequence).cycle )
        if( getStatus() == S_HITTING )
        {
            for( auto &e : hitableEntities )
                static_cast<ENonPlayableHitable*>(e)->slap(direction);
        }
}

void EPlayable::moveLeft()
{
    if( direction == D_RIGHT ) flipHorizontally();
    drawableObject->move(-3.5, 0);

    if ( getStatus() != S_RUNNING )
        setStatus(S_RUNNING, true);

    clock.restart();
}

void EPlayable::moveRight()
{
    if( direction == D_LEFT ) flipHorizontally();
    drawableObject->move(3.5, 0);

    if ( getStatus() != S_RUNNING )
        setStatus(S_RUNNING, true);

    clock.restart();
}

void EPlayable::hit()
{
    if( getStatus() != S_HITTING )
        setStatus(S_HITTING, true);

    clock.restart();
}

void EPlayable::triggerAction()
{
    //
}
