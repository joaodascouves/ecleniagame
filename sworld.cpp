#include "sworld.h"
#include "edoor.h"
#include "resourcemanager.h"
#include "sfaseteste1.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

SWorld::SWorld()
{
    worldView.setSize(800, 600);
    worldView.setCenter(worldView.getSize().x/2, worldView.getSize().y/2);

    sceneryView.setSize(worldView.getSize());
    sceneryView.setCenter(worldView.getCenter());
    sceneryView.setViewport(worldView.getViewport());

//    inventoryView.setCenter(worldView.getCenter());
    interfaceView.setViewport(sf::FloatRect(.0f, .0f, 1.f, 1.f));

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
    ResourceManager::get().clear();

    for( auto& obj : worldEntities )
    {
        obj->destroy();
        delete obj;
    }

    for( auto& obj : worldEntitiesRect )
    {
        obj->destroy();
        delete obj;
    }
}

void SWorld::draw()
{
    GameInstance::get().window.setView(sceneryView);
    for( auto& e : sceneryEntities )
        if( !e->drawableObjects.empty() )
            GameInstance::get().window.draw(*e);

    GameInstance::get().window.setView(worldView);
    for( auto& e : worldEntities )
        if( !e->drawableObjects.empty() )
        GameInstance::get().window.draw(*e);

    if( mainPlayer )
        GameInstance::get().window.draw(*mainPlayer);

    GameInstance::get().window.setView(interfaceView);
    for( auto& e : worldEntitiesRect )
        GameInstance::get().window.draw(*e);

//    GameInstance::get().window.draw(actionDescription);
//    GameInstance::get().window.draw(actionLabel);
}

void SWorld::update()
{
//    actionDescription.setString("Teste.");
//    actionLabel.setString("");

    _update();

    if( mainPlayer )
    {
        mainPlayer->currentEntity = nullptr;
        mainPlayer->currentTextEntity = nullptr;
        mainPlayer->hitableEntities.clear();

        for( auto it = worldEntities.begin(); it != worldEntities.end(); it++ )
        {
            if( auto *e = *it)
            {
                if( !e->drawableObjects.empty() )
                {
                    if( !(e->hasClass("enonplayablehitable") && dialogBox) )
                        e->update();
                }

                if( e->getPosition().x < 0 )
                    e->destroy();

                if( !e->direction || e->drawableObjects.empty() )
                {
                    worldEntities.erase(it--);
                    continue;
                }

                if( e->hasClass("enonplayablehitable") )
                {
                    bool hitable = false;

                    if( mainPlayer->direction == mainPlayer->D_RIGHT )
                    {
                        if( mainPlayer->getPosition().x + mainPlayer->front()->getGlobalBounds().width - 140 >= e->getPosition().x &&
                            mainPlayer->getPosition().x - 50 <= e->getPosition().x )
                        {
                            hitable = true;
                        }
                    }
                    else
                    {
                        if( mainPlayer->getPosition().x + 50  >= e->getPosition().x + e->front()->getGlobalBounds().width &&
                            mainPlayer->getPosition().x - 100 <= e->getPosition().x + e->front()->getGlobalBounds().width )
                        {
                            hitable = true;
                        }
                    }

                    if( hitable )
                    {
                        mainPlayer->hitableEntities.push_back(e);
                    }
                }

                if( mainPlayer->getPosition().x + mainPlayer->front()->getGlobalBounds().width - 170 >= e->getPosition().x &&
                    mainPlayer->getPosition().x <= e->getPosition().x + e->front()->getGlobalBounds().width )
                {
                    mainPlayer->currentEntity = e;

                    if( e->hasClass("es1ghost") )
                    {
//                        mainPlayer->slap(mainPlayer->D_LEFT);
//                        if( !mainPlayer )
//                            continue;

//                        e->flipHorizontally();
                    }

                    if( e->hasClass("elocker") )
                    {
                        for( auto &s : static_cast<ES1Locker*>(e)->slots )
                        {
                            if( mainPlayer->getPosition().x + mainPlayer->front()->getGlobalBounds().width - 170 >= e->getPosition().x + s->getPosition().x &&
                                mainPlayer->getPosition().x <= e->getPosition().x + s->getPosition().x + s->getCharacterSize() )
                            {
                                mainPlayer->currentTextEntity = s;
                            }
                        }
                    }

                    if( e->hasClass("edoor") )
                    {
    //                    actionLabel.setString("Entrar (A)");
    //                    actionDescription.setString("Uma porta. Para onde isso leva?");
                    }

                    if( e->hasClass("eitem") )
                    {
    //                    actionLabel.setString("Pegar (A)");
    //                    actionDescription.setString("You see a " + e->getAlias() + ".\n" + e->getDescription());
                    }

                    if( e->hasClass("enonplayable") )
                    {
    //                    actionLabel.setString("Matar (A)");
    //                    actionDescription.setString("Esse cara parece comigo.");
                    }
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
            case sf::Keyboard::Escape:
                keyPress[K_ESCAPE] = true;
                break;

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

    if( !dialogBox )
    {
        if( keyPress[K_LEFT] )
        {
            if( mainPlayer->getPosition().x > 0 )
            {
                mainPlayer->moveLeft();
                if( mainPlayer->getPosition().x > worldView.getSize().x/3 )
                    sceneryView.move(mainPlayer->speed * -.1f, 0);

                if( worldView.getCenter().x - worldView.getSize().x/2 > 0 )
                {
                    if( mainPlayer->speed >= mainPlayer->horizontalSpeed )
                        worldView.move(mainPlayer->speed * -1, 0);
                }
            }
        }

        if( keyPress[K_RIGHT] )
        {
            mainPlayer->moveRight();
            if( mainPlayer->getPosition().x > worldView.getSize().x/3 )
                sceneryView.move(mainPlayer->speed * .1f, 0);

            if( mainPlayer->getPosition().x > worldView.getCenter().x &&
                mainPlayer->getPosition().x < worldView.getCenter().x + worldView.getSize().x/2 )
            {
                if( mainPlayer->speed >= mainPlayer->horizontalSpeed )
                    worldView.move(mainPlayer->speed, 0);
            }
        }

        if( keyPress[K_HIT] )
        {
            if( mainPlayer->getStatus() != mainPlayer->S_HITTING )
            {
                mainPlayer->sequences.at(mainPlayer->S_HITTING).pos = mainPlayer->sequences.at(mainPlayer->S_HITTING).begin;
                mainPlayer->hit();
            }

            keyPress[K_HIT] = false;
        }
    }

    if( keyPress[K_ACTION] )
    {
        if( !dialogBox )
        {
            if( mainPlayer->currentEntity )
                mainPlayer->currentEntity->action(mainPlayer);
        }

        if( dialogBox )
        {
            dialogBox->next();

            if( dialogBox->getStatus() == -1 )
                dialogBox = nullptr;
        }

        keyPress[K_ACTION] = false;
    }

    if( keyPress[K_ESCAPE] )
    {
        GameInstance::get().window.close();
    }
}

void SWorld::spawn(Entity<sf::Sprite> *entity)
{
    entity->spawned = true;
    worldEntities.push_back(entity);
    worldEntities.back()->index = worldEntities.size();
}

void SWorld::spawn(Entity<sf::RectangleShape> *entity)
{
    entity->spawned = true;
    worldEntitiesRect.push_back(entity);
    worldEntitiesRect.back()->index = worldEntitiesRect.size();
}

void SWorld::showDialogBox(EDialogBox *newDialogBox)
{
    if( dialogBoxIterator != worldEntitiesRect.end() )
        worldEntitiesRect.erase(dialogBoxIterator, dialogBoxIterator + 1);

    dialogBox = newDialogBox;
    spawn(dialogBox);

    dialogBoxIterator = worldEntitiesRect.end() - 1;
}

float SWorld::getFloor() const
{
    return 20.f;
}
