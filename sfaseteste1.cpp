#include "sfaseteste1.h"
#include "texturemanager.h"

SFaseTeste1::SFaseTeste1()
{
    TextureManager::get().loadTexture("montanha2.jpg");
    TextureManager::get().loadTexture("grape.png");

//    worldEntities.push_back(new Entity<sf::Sprite>);
//    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("montanha2"));
//    worldEntities.back()->drawableObject->setPosition(0, 0);
//    worldEntities.back()->drawableObject->setScale(1.5f, 1.5f);

//    worldEntities.push_back(new Entity<sf::Sprite>);
//    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("montanha2"));
//    worldEntities.back()->drawableObject->setPosition(TextureManager::get().textureMap.at("montanha2")->getSize().x * 1.5f, 0);
//    worldEntities.back()->drawableObject->setScale(1.5f, 1.5f);

    spawn(new EItem);
    worldEntities.back()->setAlias("grape");
    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("grape"));
    worldEntities.back()->setPosition(300, 450);

    spawn(new EItem);
    worldEntities.back()->setAlias("grape");
    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("grape"));
    worldEntities.back()->setPosition(100, 450);

    spawn(door1);
    door1->setPosition(500, 310);

    spawn(door2);
    door2->setPosition(1300, 310);

    mainPlayer = new EPlayable;
    mainPlayer->setPosition(20, 395);
}

void SFaseTeste1::handleInput()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        GameInstance::get().window.close();

    mainPlayer->handleMovement();
}
