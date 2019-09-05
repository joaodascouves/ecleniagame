#include "sfaseteste1.h"
#include "texturemanager.h"

#include <iostream>

SFaseTeste1::SFaseTeste1()
{
    rect.setSize(sf::Vector2f(80, 80));
    rect.setFillColor(sf::Color(60, 50, 100));

    TextureManager::get().loadTexture("montanha2.jpg");

    worldEntities.push_back(new Entity<sf::Sprite>);
    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("montanha2"));
    worldEntities.back()->drawableObject->setPosition(0, 0);
    worldEntities.back()->drawableObject->setScale(1.2f, 1.2f);

    worldEntities.push_back(new Entity<sf::Sprite>);
    worldEntities.back()->drawableObject->setTexture(*TextureManager::get().textureMap.at("montanha2"));
    worldEntities.back()->drawableObject->setPosition(TextureManager::get().textureMap.at("montanha2")->getSize().x, 0);
    worldEntities.back()->drawableObject->setScale(1.2f, 1.2f);

    worldEntities.push_back(player);

    GameInstance::get().window.setView(worldView);
}

void SFaseTeste1::update(float dt)
{
    player->update(dt);

    if( player->drawableObject->getPosition().x > 200 &&
        player->drawableObject->getPosition().x < TextureManager::get().getRef("montanha2").getSize().x + 400  + player->drawableObject->getGlobalBounds().height )
        worldView.setCenter(player->drawableObject->getPosition().x + 200, 300);

    GameInstance::get().window.setView(worldView);
}

void SFaseTeste1::handleInput()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        GameInstance::get().window.close();

    player->handleMovement();
}
