#include "sfaseteste1.h"
#include "resourcemanager.h"

SFaseTeste1::SFaseTeste1()
{
    ResourceManager::get().loadTexture("montanha2.jpg");
    ResourceManager::get().loadTexture("grape.png");
    ResourceManager::get().loadTexture("cenario1.png");

    sceneryEntities.push_back(new Entity<sf::Sprite>);
    sceneryEntities.back()->drawableObject->setTexture(*ResourceManager::get().textureMap.at("cenario1"));

    sceneryEntities.push_back(new Entity<sf::Sprite>);
    sceneryEntities.back()->drawableObject->setTexture(*ResourceManager::get().textureMap.at("cenario1"));
    sceneryEntities.back()->setPosition(sceneryEntities.at(0)->drawableObject->getGlobalBounds().width, 0);

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
    ghostTeste = new ES1Ghost;

    ghostTeste1 = new ES1Ghost;
    ghostTeste2 = new ES1Ghost;
    ghostTeste3 = new ES1Ghost;

    spawn(grape1);
    worldEntities.back()->setAlias("grape");
    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
    worldEntities.back()->drawableObject->setTexture(*ResourceManager::get().textureMap.at("grape"));
    worldEntities.back()->setPosition(300, 450 - getFloor());

    spawn(grape2);
    worldEntities.back()->setAlias("grape");
    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
    worldEntities.back()->drawableObject->setTexture(*ResourceManager::get().textureMap.at("grape"));
    worldEntities.back()->setPosition(100, 450 - getFloor());

    spawn(door1);
    door1->setAlias("door1");
    door1->setPosition(500, 310- getFloor());

    spawn(door2);
    door2->setAlias("door2");
    door2->setPosition(1300, 310- getFloor());

    spawn(antiJoaozin);
    antiJoaozin->setAlias("antiJoaozin");
    antiJoaozin->setPosition(1000, 395- getFloor());

    spawn(ghostTeste);
    ghostTeste->setAlias("ghostTeste");
    ghostTeste->setPosition(400, 395- getFloor());

    spawn(ghostTeste1);
    ghostTeste1->setAlias("ghostTeste1");
    ghostTeste1->setPosition(500, 395- getFloor());

    spawn(ghostTeste2);
    ghostTeste2->setAlias("ghostTeste2");
    ghostTeste2->setPosition(1000, 395- getFloor());

    spawn(ghostTeste3);
    ghostTeste3->setAlias("ghostTeste3");
    ghostTeste3->setPosition(1200, 395- getFloor());

    mainPlayer = new EPlayable;
    mainPlayer->setPosition(20, 395- getFloor());
}
