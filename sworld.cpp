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
    actionDescription.setColor(sf::Color(0, 255, 0));
    actionDescription.setString("Teste");
    actionDescription.setPosition(20, 20);
}

void SWorld::draw(const float dt)
{
    GameInstance::get().window.setView(worldView);
    for( auto& e : worldEntities )
        GameInstance::get().window.draw(*e);

    if( mainPlayer )
        GameInstance::get().window.draw(*mainPlayer);

    GameInstance::get().window.setView(inventoryView);
    for( auto& e : worldEntitiesRect )
        GameInstance::get().window.draw(*e);

    GameInstance::get().window.draw(actionDescription);
}

void SWorld::update(const float dt)
{
    actionDescription.setString("Teste.");

    if( mainPlayer )
    {
        mainPlayer->update(dt);

        if( mainPlayer->drawableObject->getPosition().x > 800.f/3 &&
            mainPlayer->drawableObject->getPosition().x < 1600 + 300 + mainPlayer->drawableObject->getGlobalBounds().height )
            worldView.setCenter(mainPlayer->drawableObject->getPosition().x + 800.f/6, 600.f/2);

        for( auto& e : worldEntities )
        {
            e->update(dt);

            if( mainPlayer->drawableObject->getPosition().x + mainPlayer->drawableObject->getGlobalBounds().width  -170 >= e->getPosition().x &&
                mainPlayer->drawableObject->getPosition().x <= e->getPosition().x + e->drawableObject->getGlobalBounds().width )
            {
                e->tickAnimation(20, true);
                actionDescription.setString("Colidiu! PlayerX:" + std::to_string(mainPlayer->drawableObject->getPosition().x)+
                                            " ObjX:" + std::to_string(e->drawableObject->getGlobalBounds().left));
            }
        }
    }

}

float SWorld::getFloor() const
{
    return 480.f;
}
