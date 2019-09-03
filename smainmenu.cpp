#include "smainmenu.h"
#include "sfaseteste1.h"

SMainMenu::SMainMenu()
{
    //
}

void SMainMenu::draw(float dt)
{
    //
}

void SMainMenu::update(float dt)
{
    //
}

void SMainMenu::handleInput()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        GameInstance::get().window.close();

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
        GameInstance::get().changeState(new SFaseTeste1);
}
