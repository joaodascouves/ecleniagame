#include "edoor.h"
#include "resourcemanager.h"

EDoor::EDoor()
{
    EDoor(0);

}

EDoor::EDoor(const short type)
{
    setClass("door");
    setStatus(S_LOCKED);

    ResourceManager::get().loadTexture("door.png");

    drawableObject->setTexture(*ResourceManager::get().textureMap.at("door"));
    drawableObject->setScale(.2f, .28f);

    configAnimation(5, 1);
    addSequence(S_LOCKED, {0, 0, 0, 0, 0});
    addSequence(S_OPENED, {0, 0, 5, 0, 0});

    location = nullptr;
    conditionFunc = std::bind([](){ return true; });
}

EDoor::~EDoor()
{
//    if( location )
//        delete location;
}

void EDoor::update()
{
    tickAnimation(20, true);
    drawableObject->setTextureRect(currentFrame());

    timer = clock.getElapsedTime();

    if( location && getStatus() == S_OPENED && timer.asSeconds() > 0.8f &&
        sequences.at(currentSequence).pos + 1 == sequences.at(currentSequence).end )
        GameInstance::get().changeState(location);

}

void EDoor::enterDoor(EPlayable* player, SWorld* newLocation)
{
    if( conditionFunc() )
    {
        setStatus(S_OPENED);
        location = newLocation;
        location->mainPlayer->inventory = new Inventory(*player->inventory);

        timer = clock.restart();
    }
}
