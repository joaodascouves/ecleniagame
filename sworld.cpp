#include "sworld.h"
#include <iostream>

SWorld::SWorld()
{
    worldView.setSize(800.f, 600.f);
    worldView.setCenter(800.f/2, 600.f/2);
    worldView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, .8f));

//    inventoryView.setCenter(worldView.getCenter());
    inventoryView.setViewport(sf::FloatRect(0.f, .8f, 1.f, 1.f));

    font.loadFromFile("/usr/share/fonts/msttcore/arial.ttf");

    actionDescription.setFont(font);
    actionDescription.setCharacterSize(20);
    actionDescription.setFillColor(sf::Color(250, 0, 0));
    actionDescription.setString("Teste");
    actionDescription.setPosition(20, 20);

    actionLabel.setFont(font);
    actionLabel.setCharacterSize(20);
    actionLabel.setFillColor(sf::Color(0, 250, 0));
    actionLabel.setString("");
    actionLabel.setPosition(550, 20);
}

void SWorld::draw(const float dt)
{
    GameInstance::get().window.setView(worldView);
    for( auto& e : worldEntities )
        if( e->drawableObject )
        GameInstance::get().window.draw(*e);

    if( mainPlayer )
        GameInstance::get().window.draw(*mainPlayer);

    GameInstance::get().window.setView(inventoryView);
    for( auto& e : worldEntitiesRect )
        GameInstance::get().window.draw(*e);

    GameInstance::get().window.draw(actionDescription);
    GameInstance::get().window.draw(actionLabel);

    if( mainPlayer )
    {
        GameInstance::get().window.draw(mainPlayer->inventory->inventoryShape);
        for( auto& e : mainPlayer->inventory->items )
        {
            GameInstance::get().window.draw(*e);
        }
    }
}

void SWorld::update(const float dt)
{
    mainPlayer->currentEntity = nullptr;
    actionDescription.setString("Teste.");
    actionLabel.setString("");

    if( mainPlayer )
    {
        mainPlayer->update(dt);

        if( mainPlayer->drawableObject->getPosition().x > 800.f/3 &&
            mainPlayer->drawableObject->getPosition().x < 1600 + 300 + mainPlayer->drawableObject->getGlobalBounds().height )
            worldView.setCenter(mainPlayer->drawableObject->getPosition().x + 800.f/6, 600.f/2);

        for( auto& e : worldEntities )
        {
            if( !e->drawableObject )
                continue;

            e->update(dt);

            if( mainPlayer->drawableObject->getPosition().x + mainPlayer->drawableObject->getGlobalBounds().width  -170 >= e->getPosition().x &&
                mainPlayer->drawableObject->getPosition().x <= e->getPosition().x + e->drawableObject->getGlobalBounds().width )
            {
                mainPlayer->currentEntity = e;

                if( e->getClass() == "door" )
                {
                    e->tickAnimation(20, true);
                    actionDescription.setString("Colidiu! PlayerX:" + std::to_string(mainPlayer->drawableObject->getPosition().x)+
                                                " ObjX:" + std::to_string(e->getPosition().x));
                }

                if( e->getClass() == "item" )
                {
                    actionLabel.setString("Pegar (A)");
                    actionDescription.setString("You see a " + e->getAlias() + ".\n" + e->getDescription());
                }
            }
        }
    }

}

void SWorld::spawn(Entity<sf::Sprite> *entity)
{
    worldEntities.push_back(entity);
    worldEntities.back()->index = worldEntities.size();
}

float SWorld::getFloor() const
{
    return 480.f;
}
