#include "sfaseteste1.h"

SFaseTeste1::SFaseTeste1()
{
    rect.setSize(sf::Vector2f(80, 80));
    rect.setFillColor(sf::Color(60, 50, 100));
}

void SFaseTeste1::draw(float dt)
{
    GameInstance::get().window.draw(rect);
    GameInstance::get().window.draw(*player);
}

void SFaseTeste1::update(float dt)
{
    player->update(dt);
}

void SFaseTeste1::handleInput()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        GameInstance::get().window.close();

    player->handleMovement();
}
