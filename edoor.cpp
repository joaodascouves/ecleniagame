#include "edoor.h"
#include "eplayable.h"
#include "resourcemanager.h"

#include "sfaseteste1.h"

template<class T>
EDoor<T>::EDoor()
{
    addClass("edoor");
    setStatus(S_LOCKED);

    ResourceManager::get().loadTexture("door.png");

    front()->setTexture(*ResourceManager::get().textureMap.at("door"));
    front()->setScale(.2f, .28f);

    configAnimation(5, 1);
    addSequence(S_LOCKED, {0, 0, 0, 0, 0});
    addSequence(S_OPENED, {0, 0, 5, 0, 0});

    location = nullptr;
    conditionFunc = std::bind([](){ return true; });
}

template<class T>
EDoor<T>::~EDoor()
{
//    if( location )
//        delete location;
}

template<class T>
void EDoor<T>::update()
{
    tickAnimation(20, true);
    front()->setTextureRect(currentFrame());

    timer = clock.getElapsedTime();

    if( location && getStatus() == S_OPENED && timer.asSeconds() > 0.8f &&
        sequences.at(currentSequence).pos + 1 == sequences.at(currentSequence).end )
        GameInstance::get().changeState(location);

}

template<class T>
void EDoor<T>::action(Entity* mainPlayer)
{
    if( conditionFunc() )
    {
        setStatus(S_OPENED);
        if( !location )
            location = new T;

        location->mainPlayer->inventory = new Inventory(*static_cast<EPlayable*>(mainPlayer)->inventory);

        timer = clock.restart();
    }
}

template class EDoor<SFaseTeste1>;
