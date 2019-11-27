#include "sworld.h"
#include "edoor.h"
#include "resourcemanager.h"
#include "sfaseteste1.h"
#include "scombat.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

SWorld::SWorld() : dialogBox(nullptr), currentPanel(nullptr)
{
    worldView.setSize(800, 600);
    worldView.setCenter(worldView.getSize().x/2, worldView.getSize().y/2);

    sceneryView.setSize(worldView.getSize());
    sceneryView.setCenter(worldView.getCenter());
    sceneryView.setViewport(worldView.getViewport());

    std::fill_n(keyPress, 7, 0);

    mainPlayer = nullptr;
}

SWorld::~SWorld()
{
    //ResourceManager::get().clear();

    for( auto& obj : worldEntities )
    {
        obj->destroy();
        delete obj;
    }

    for( auto& obj : sceneryEntities )
    {
        obj->destroy();
        delete obj;
    }

    for( auto& obj : worldEntitiesRect )
    {
        //obj->destroy();
        //delete obj;
    }

    delete mainPlayer;
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

    //GameInstance::get().window.draw(*actionDescription);
//    GameInstance::get().window.draw(actionLabel);
}

void SWorld::update()
{
    _update();

    if( mainPlayer )
    {
        if( mainPlayer->currentEntity.back() )
            mainPlayer->currentEntity.pop_back();

        if( mainPlayer->currentTextEntity.back() )
            mainPlayer->currentTextEntity.pop_back();

        mainPlayer->hitableEntities.clear();

        for( auto it = worldEntities.begin(); it != worldEntities.end(); it++ )
        {
            if( auto *e = *it)
            {
                if( e->spawned )
                {
                    if( !(e->hasClass("enonplayablehitable") && dialogBox) )
                        e->update();
                }

                if( e->getPosition().x < 0 )
                    e->destroy();

                if( !e->direction || !e->spawned || e->drawableObjects.empty() )
                {
                    worldEntities.erase(it--);
                    continue;
                }

                if( e->hasClass("enonplayablehitable") )
                {
                    bool hitable = false;

                    if( mainPlayer->direction == mainPlayer->D_RIGHT )
                    {
                        if( mainPlayer->getPosition().x + mainPlayer->getRelativeBounds().width >= e->getPosition().x &&
                            mainPlayer->getPosition().x - 60 <= e->getPosition().x )
                        {
                            hitable = true;
                        }
                    }
                    else
                    {
                        if( mainPlayer->getPosition().x + 50  >= e->getPosition().x + e->getRelativeBounds().width &&
                            mainPlayer->getPosition().x - 100 <= e->getPosition().x + e->getRelativeBounds().width )
                        {
                            hitable = true;
                        }
                    }

                    if( hitable )
                    {
                        mainPlayer->hitableEntities.push_back(e);
                    }
                }

                if( mainPlayer->spawned )
                {
                    if( mainPlayer->front() )
                        mainPlayer->update();

                    if( mainPlayer->getPosition().x + mainPlayer->getRelativeBounds().width >= e->getPosition().x &&
                            mainPlayer->getPosition().x + 60 <= e->getPosition().x + e->getRelativeBounds().width )
                    {
                        mainPlayer->currentEntity.push_back(e);

                        if( e->hasClass("es1ghost") )
                        {
                            if( !currentPanel )
                            {
                                EPanel* combatPrompt = new EPanel({300, 300}, sf::Color(30, 20, 250, 220));
                                spawn(combatPrompt);

                                combatPrompt->appendLine("Desafiar");
                                combatPrompt->appendLine("Ignorar");
                                combatPrompt->toggleChooseable(true);

                                combatPrompt->actionFunc = [this, e, &combatPrompt](short choice){

                                    deactivatePanel();

                                    if( choice == 0 )
                                    {
                                        SCombat* combatState  = new SCombat(
                                                    static_cast<ENonPlayableHitable*>(mainPlayer),
                                                    static_cast<ENonPlayableHitable*>(e)
                                                    );

                                        combatState->sceneryEntities.push_back(new Entity<sf::Sprite>);
                                        combatState->sceneryEntities.back()->setTextureName("es1scenery1");

                                        std::fill_n(keyPress, 7, 0);

                                        GameInstance::get().pushState(combatState);
                                    }

                                    if( choice == 1 )
                                    {
                                        combatPrompt->hide();
                                    }

                                };

                                activatePanel(std::move(combatPrompt));
                            }

                            //                        ENonPlayableHitable* enemy = static_cast<ENonPlayableHitable*>(e);
                            //                        enemy->speed = 0.5f;

                            //                        if( mainPlayer->getStatus() != ENonPlayableHitable::S_HITTING &&
                            //                                e->getStatus() != ENonPlayableHitable::S_SLAPPED &&
                            //                                e->getStatus() != ENonPlayableHitable::S_DYING )
                            //                        {
                            //                            mainPlayer->slap(enemy);

                            //                            if( e->direction == mainPlayer->direction &&
                            //                                e->getPosition().x > mainPlayer->getPosition().x )
                            //                            {
                            //                                e->flipHorizontally();
                            //                            }

                            //                            if( !mainPlayer )
                            //                                continue;
                            //                        }
                        }

                        if( e->hasClass("elocker") )
                        {
                            for( auto &s : static_cast<ES1Locker*>(e)->slots )
                            {
                                if( mainPlayer->getPosition().x + mainPlayer->front()->getGlobalBounds().width - 170 >= e->getPosition().x + s->getPosition().x &&
                                        mainPlayer->getPosition().x <= e->getPosition().x + s->getPosition().x + s->getCharacterSize() )
                                {
                                    mainPlayer->currentTextEntity.push_back(s);
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

            if( !mainPlayer->currentEntity.back() )
            {
                if( currentPanel )
                {
                    currentPanel->hide();
                    destroyPanel();
                }
            }
        }
    }

}

void SWorld::handleInput()
{
    sf::Event ev;

    keyPress[K_UP] = false;
    keyPress[K_DOWN] = false;
    keyPress[K_HIT] = false;
    keyPress[K_ACTION] = false;

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

            case sf::Keyboard::Up:
                keyPress[K_UP] = true;
                break;

            case sf::Keyboard::Down:
                keyPress[K_DOWN] = true;
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

    controls();

    if( keyPress[K_ESCAPE] )
    {
        GameInstance::get().window.close();
    }

    if( keyPress[K_ACTION] )
    {
            if( mainPlayer->currentEntity.back() )
                mainPlayer->currentEntity.back()->action(mainPlayer);

            if( mainPlayer->currentRectEntity.back() )
                mainPlayer->currentRectEntity.back()->action(nullptr);
    }

    if( currentPanel )
    {
        if( keyPress[K_UP] )
            currentPanel->moveChoice(true);

        if( keyPress[K_DOWN] )
            currentPanel->moveChoice(false);
    }
}

void SWorld::controls()
{
    if( mainPlayer )
    if( mainPlayer->front() && mainPlayer->life > 0 )
    {
        if( !dialogBox )
        {
            if( keyPress[K_LEFT] )
            {
                if( mainPlayer->getPosition().x > 0 && mainPlayer->getStatus() != ENonPlayableHitable::S_SLAPPED )
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
                if( mainPlayer->getStatus() != ENonPlayableHitable::S_HITTING )
                {
                    mainPlayer->sequences.at(ENonPlayableHitable::S_HITTING).pos = mainPlayer->sequences.at(ENonPlayableHitable::S_HITTING).begin;
                    mainPlayer->hit();
                }
            }
        }
    }
}

void SWorld::spawn(Entity<sf::Sprite> *entity)
{
    entity->spawned = true;
    worldEntities.push_back(entity);
    worldEntities.back()->index = worldEntities.size();
}

void SWorld::spawn(Entity<sf::RectangleShape>* entity)
{
    entity->spawned = true;
    entity->index = worldEntitiesRect.size() + 1;
    worldEntitiesRect.push_back(entity);
}

void SWorld::showDialogBox(EDialogBox* newDialogBox)
{
    if( mainPlayer->currentRectEntity.back() )
        return;

    if( dialogBoxIterator != worldEntitiesRect.rend() && dialogBoxIterator.base() > worldEntitiesRect.begin() )
        worldEntitiesRect.erase(--(dialogBoxIterator.base()));

    spawn(newDialogBox);
    dialogBox = newDialogBox;

    dialogBoxIterator = worldEntitiesRect.rbegin();
    mainPlayer->currentRectEntity.push_back(dialogBox);
}

void SWorld::hideDialogBox()
{
    dialogBox = nullptr;
    mainPlayer->currentRectEntity.pop_back();
}

void SWorld::activatePanel(EPanel* panel)
{
    panel->toggleActive(true);
    currentPanel = panel;

    mainPlayer->currentRectEntity.push_back(currentPanel);
}

void SWorld::deactivatePanel()
{
    currentPanel->toggleActive(false);
    currentPanel = nullptr;

    mainPlayer->currentRectEntity.pop_back();
}

void SWorld::destroyPanel()
{
    currentPanel->destroy();
    currentPanel = nullptr;

    mainPlayer->currentRectEntity.pop_back();
}

float SWorld::getFloor() const
{
    return 20.f;
}
