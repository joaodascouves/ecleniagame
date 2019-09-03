#include "gameinstance.h"
#include "gamestate.h"

GameInstance::GameInstance()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(800, 600, 32), "teste", sf::Style::Default, settings);
    window.setFramerateLimit(60);
}

void GameInstance::changeState(GameState *newState)
{
    if( !states.empty() )
        popState();

    pushState(newState);
    return;
}

void GameInstance::pushState(GameState *newState)
{
    states.push(std::move(newState));
    return;
}

void GameInstance::popState()
{
    delete states.top();
    states.pop();
    return;
}

GameState* GameInstance::peekState()
{
    if( states.empty() ) return nullptr;
    return states.top();
}

void GameInstance::gameLoop()
{
    sf::Clock clock;

    while( window.isOpen() )
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if( peekState() == nullptr )
            continue;

        peekState()->handleInput();
        peekState()->update(dt);
        window.clear();

        peekState()->draw(dt);
        window.display();
    }

}

