#include "sworld.h"
#include "edoor.h"
#include "resourcemanager.h"

#include "sfaseteste1.h"

#include <iostream>

SWorld::SWorld()
{
    worldView.setSize(800, 600);
    worldView.setCenter(worldView.getSize().x/2, worldView.getSize().y/2);
    worldView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

    sceneryView.setSize(worldView.getSize());
    sceneryView.setCenter(worldView.getCenter());
    sceneryView.setViewport(worldView.getViewport());

//    inventoryView.setCenter(worldView.getCenter());
    inventoryView.setViewport(sf::FloatRect(0.f, .8f, 1.f, 1.f));

//    font.loadFromFile("/usr/share/fonts/msttcore/arial.ttf");

//    actionDescription.setFont(font);
//    actionDescription.setCharacterSize(20);
//    actionDescription.setFillColor(sf::Color(250, 0, 0));
//    actionDescription.setString("Teste");
//    actionDescription.setPosition(20, 20);

//    actionLabel.setFont(font);
//    actionLabel.setCharacterSize(20);
//    actionLabel.setFillColor(sf::Color(0, 250, 0));
//    actionLabel.setString("");
//    actionLabel.setPosition(550, 20);
}

SWorld::~SWorld()
{
//    for( auto& t : ResourceManager::get().textureMap )
//        delete t.second;

//    ResourceManager::get().textureMap.clear();

}

void SWorld::draw()
{
    GameInstance::get().window.setView(sceneryView);
    for( auto& e : sceneryEntities )
        if( e->drawableObject )
            GameInstance::get().window.draw(*e);

    GameInstance::get().window.setView(worldView);
    for( auto& e : worldEntities )
        if( e->drawableObject )
        GameInstance::get().window.draw(*e);

    if( mainPlayer )
        GameInstance::get().window.draw(*mainPlayer);

    GameInstance::get().window.setView(inventoryView);
    for( auto& e : worldEntitiesRect )
        GameInstance::get().window.draw(*e);

//    GameInstance::get().window.draw(actionDescription);
//    GameInstance::get().window.draw(actionLabel);

//    if( mainPlayer )
//    {
//        GameInstance::get().window.draw(mainPlayer->inventory->inventoryShape);
//        for( auto& e : mainPlayer->inventory->items )
//        {
//            GameInstance::get().window.draw(*e);
//        }
//    }
}

void SWorld::update()
{
    mainPlayer->currentEntity = nullptr;
    mainPlayer->hitableEntities.clear();
//    actionDescription.setString("Teste.");
//    actionLabel.setString("");

    if( mainPlayer )
    {
        if( mainPlayer->drawableObject->getPosition().x > 800 )
            worldView.setCenter(mainPlayer->drawableObject->getPosition().x + 800.f/6, 600.f/2);

        if( mainPlayer->drawableObject->getPosition().x > worldView.getSize().x/3 &&
            mainPlayer->drawableObject->getPosition().x < 1600 + 300 + mainPlayer->drawableObject->getGlobalBounds().width )
            worldView.setCenter(mainPlayer->drawableObject->getPosition().x + worldView.getSize().x/6, worldView.getSize().y/2);

        for( auto& e : worldEntities )
        {
            if( e->drawableObject )
                e->update();

            if( !e->drawableObject )
                continue;

            if( e->getClass() == "nonplayablehitable" )
            {
                bool hitable = false;

                if( mainPlayer->direction == mainPlayer->D_RIGHT )
                {
                    if( mainPlayer->drawableObject->getPosition().x + mainPlayer->drawableObject->getGlobalBounds().width - 140 >= e->getPosition().x &&
                        mainPlayer->drawableObject->getPosition().x <= e->getPosition().x )
                    {
                        hitable = true;
                    }
                }
                else
                {
                    if( mainPlayer->drawableObject->getPosition().x + 50  >= e->getPosition().x + e->drawableObject->getGlobalBounds().width &&
                        mainPlayer->drawableObject->getPosition().x - 600 <= e->getPosition().x + e->drawableObject->getGlobalBounds().width )
                    {
                        hitable = true;
                    }
                }

                if( hitable )
                {
                    mainPlayer->hitableEntities.push_back(e);
//                    e->drawableObject->setColor(sf::Color(130, 0, 0, 180));
                }
            }

            if( mainPlayer->drawableObject->getPosition().x + mainPlayer->drawableObject->getGlobalBounds().width - 170 >= e->getPosition().x &&
                mainPlayer->drawableObject->getPosition().x <= e->getPosition().x + e->drawableObject->getGlobalBounds().width )
            {
                mainPlayer->currentEntity = e;

                if( e->getClass() == "door" )
                {
//                    actionLabel.setString("Entrar (A)");
//                    actionDescription.setString("Uma porta. Para onde isso leva?");
                }

                if( e->getClass() == "item" )
                {
//                    actionLabel.setString("Pegar (A)");
//                    actionDescription.setString("You see a " + e->getAlias() + ".\n" + e->getDescription());
                }

                if( e->getClass() == "nonplayable" )
                {
//                    actionLabel.setString("Matar (A)");
//                    actionDescription.setString("Esse cara parece comigo.");
                }
            }
        }

        mainPlayer->update();
    }

}

void SWorld::handleInput()
{
    sf::Event ev;

    while( GameInstance::get().window.pollEvent(ev) )
    {
        if( ev.type == sf::Event::KeyPressed )
        {
            if( ev.key.code == sf::Keyboard::Escape )
                GameInstance::get().window.close();

            switch( ev.key.code )
            {
            case sf::Keyboard::Left:
                keyPress[K_LEFT] = true;
                break;

            case sf::Keyboard::Right:
                keyPress[K_RIGHT] = true;
                break;

            default: break;
            }
        }

        if( ev.type == sf::Event::KeyReleased )
        {
            switch( ev.key.code )
            {
            case sf::Keyboard::Left:
                keyPress[K_LEFT] = false;
                break;

            case sf::Keyboard::Right:
                keyPress[K_RIGHT] = false;
                break;

            case sf::Keyboard::Z:
                keyPress[K_HIT] = true;
                break;

            case sf::Keyboard::A:
                keyPress[K_ACTION] = true;
                break;

            default: break;
            }
        }
    }

    if( keyPress[K_LEFT] )
    {
        if( mainPlayer->drawableObject->getPosition().x > 0 )
        {
            mainPlayer->moveLeft();
            if( mainPlayer->drawableObject->getPosition().x > worldView.getSize().x/3 )
                sceneryView.move(-.5f, 0);
        }
    }

    if( keyPress[K_RIGHT] )
    {
        mainPlayer->moveRight();
        if( mainPlayer->drawableObject->getPosition().x > worldView.getSize().x/3 )
            sceneryView.move(.5f, 0);
    }

    if( keyPress[K_HIT] )
    {
        mainPlayer->sequences.at(mainPlayer->S_HITTING).pos = mainPlayer->sequences.at(mainPlayer->S_HITTING).begin;
        mainPlayer->hit();
        keyPress[K_HIT] = false;
    }

    if( keyPress[K_ACTION] )
    {
        if( mainPlayer->currentEntity )
        {
            if( mainPlayer->currentEntity )
            {
                if( mainPlayer->currentEntity->getClass() == "item" )
                    mainPlayer->inventory->acquireItem(static_cast<EItem *>(mainPlayer->currentEntity));

                if( mainPlayer->currentEntity->getClass() == "door" )
                {
                    if( !static_cast<EDoor*>(mainPlayer->currentEntity)->location )
                        if( static_cast<EDoor*>(mainPlayer->currentEntity)->conditionFunc() )
                        {
                            SFaseTeste1* newLocation = new SFaseTeste1;

                            if( mainPlayer->currentEntity->getAlias() == "door1" )
                            {
                                if( newLocation->door2 )
                                {
                                    newLocation->mainPlayer->drawableObject->setPosition(
                                                newLocation->door2->getPosition().x, 0);

                                    newLocation->sceneryView.setCenter(newLocation->door2->getPosition().x - 400, worldView.getSize().y/2);
                                }
                            }

                            static_cast<EDoor*>(mainPlayer->currentEntity)->enterDoor(mainPlayer, newLocation);
                        }
                }

                if( mainPlayer->currentEntity->getClass() == "nonplayablehitable" )
                    mainPlayer->currentEntity->destroy();
            }
        }

        keyPress[K_ACTION] = false;
    }
}

void SWorld::spawn(Entity<sf::Sprite> *entity)
{
    worldEntities.push_back(entity);
    worldEntities.back()->index = worldEntities.size();
}

float SWorld::getFloor() const
{
    return 20.f;
}
