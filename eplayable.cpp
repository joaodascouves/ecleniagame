#include "eplayable.h"
#include "gameinstance.h"
#include "resourcemanager.h"
#include "edoor.h"

#include "sfaseteste1.h"

#include <iostream>

EPlayable::EPlayable()
{
    ResourceManager::get().loadTexture("agoravai.png");
    ResourceManager::get().textureMap.at("agoravai")->setSmooth(false);

    drawableObject->setOrigin(500.f, 0);
    drawableObject->setTexture(*ResourceManager::get().textureMap.at("agoravai"));
    drawableObject->setScale(.23f, .23f);
    drawableObject->setTextureRect(sf::IntRect(0 + 5, 0, 399 - 5, 369));

    sequences.push_back({0, 5, 11, 0});
    sequences.push_back({0, 0, 4, 0});

    frameWidth = ResourceManager::get().textureMap.at("agoravai")->getSize().x/11;
    frameHeight = ResourceManager::get().textureMap.at("agoravai")->getSize().y/1;

    inventory = new Inventory;
}

void EPlayable::update(const float dt)
{
    drawableObject->setTextureRect(currentFrame());
    setStatus(S_STANDING, true);
}

void EPlayable::moveLeft()
{
    if( direction == D_RIGHT ) flipHorizontally();
    drawableObject->move(-20, 0);

    setStatus(S_RUNNING, true);
    tickAnimation();
}

void EPlayable::moveRight()
{
    if( direction == D_LEFT ) flipHorizontally();
    drawableObject->move(20, 0);

    setStatus(S_RUNNING, true);
    tickAnimation();
}

void EPlayable::handleMovement()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
        moveLeft();

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
        moveRight();

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
    {
        if( currentEntity )
        {
            if( currentEntity->getClass() == "item" )
                inventory->acquireItem(static_cast<EItem *>(currentEntity));

            if( currentEntity->getClass() == "door" )
            {
                if( !static_cast<EDoor*>(currentEntity)->location )
                if( static_cast<EDoor*>(currentEntity)->conditionFunc() )
                {
                    SFaseTeste1* newLocation = new SFaseTeste1;

                    if( currentEntity->getAlias() == "door1" )
                    {
                        if( newLocation->door2 )
                            newLocation->mainPlayer->drawableObject->setPosition(
                                        newLocation->door2->getPosition().x, 0);
                    }

                    static_cast<EDoor*>(currentEntity)->enterDoor(this, newLocation);
                }
            }

            if( currentEntity->getClass() == "nonplayable" )
                currentEntity->destroy();
        }
    }
}

void EPlayable::triggerAction()
{
    //
}
