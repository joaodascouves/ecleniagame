#include "sfaseteste1.h"
#include "resourcemanager.h"

SFaseTeste1::SFaseTeste1()
{
    ResourceManager::get().loadTexture("montanha2.jpg");
    ResourceManager::get().loadTexture("grape.png");
    ResourceManager::get().loadTexture("cenario1.png");

    sceneryEntities.push_back(new Entity<sf::Sprite>);
    sceneryEntities.back()->drawableObject->setTexture(*ResourceManager::get().textureMap.at("cenario1"));
    sceneryEntities.back()->drawableObject->setScale(2.f, 1.f);
    sceneryEntities.back()->drawableObject->setColor(sf::Color(50, 50, 50));

    grape1 = new EItem();
    grape2 = new EItem();
    door1 = new EDoor(0);
    door2 = new EDoor(0);

    door1->conditionFunc = std::bind([this](){
       return mainPlayer->inventory->has("grape");
    });

    door2->conditionFunc = std::bind([this](){
        return !antiJoaozin->drawableObject;
    });

    antiJoaozin = new AntiJoaozin;

    spawn(grape1);
    worldEntities.back()->setAlias("grape");
    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
    worldEntities.back()->drawableObject->setTexture(*ResourceManager::get().textureMap.at("grape"));
    worldEntities.back()->setPosition(300, 450);

    spawn(grape2);
    worldEntities.back()->setAlias("grape");
    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
    worldEntities.back()->drawableObject->setTexture(*ResourceManager::get().textureMap.at("grape"));
    worldEntities.back()->setPosition(100, 450);

    spawn(door1);
    door1->setAlias("door1");
    door1->setPosition(500, 310);

    spawn(door2);
    door2->setAlias("door2");
    door2->setPosition(1300, 310);

    spawn(antiJoaozin);
    antiJoaozin->setAlias("antiJoaozin");
    antiJoaozin->setPosition(1000, 395);

    mainPlayer = new EPlayable;
    mainPlayer->setPosition(20, 395);
}

void SFaseTeste1::handleInput()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        GameInstance::get().window.close();

    mainPlayer->handleMovement();
}
