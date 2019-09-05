#include "sfaseteste1.h"
#include "texturemanager.h"

#include <iostream>

SFaseTeste1::SFaseTeste1()
{
    TextureManager::get().loadTexture("montanha2.jpg");
    TextureManager::get().loadTexture("door.png");

//    worldEntities.push_back(new Entity<sf::Sprite>);
//    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("montanha2"));
//    worldEntities.back()->drawableObject->setPosition(0, 0);
//    worldEntities.back()->drawableObject->setScale(1.5f, 1.5f);

//    worldEntities.push_back(new Entity<sf::Sprite>);
//    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("montanha2"));
//    worldEntities.back()->drawableObject->setPosition(TextureManager::get().textureMap.at("montanha2")->getSize().x * 1.5f, 0);
//    worldEntities.back()->drawableObject->setScale(1.5f, 1.5f);

    worldEntities.push_back(door1);
    door1->setPosition(500, 310);

    mainPlayer = new EPlayable;
    mainPlayer->setPosition(20, 395);
}

void SFaseTeste1::handleInput()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        GameInstance::get().window.close();

    mainPlayer->handleMovement();
}
