#include "gameinstance.h"
#include "gamestate.h"

GameInstance::GameInstance()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(1366, 768, 32), "teste", sf::Style::Default, settings);
    window.setFramerateLimit(100);
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
        float currentTime = clock.restart().asSeconds();
        totalTime += currentTime;
        fps = 1.f/currentTime;

        if( peekState() == nullptr )
            continue;

        peekState()->handleInput();
        peekState()->update(currentTime);
        window.clear();

        peekState()->draw(currentTime);
        window.display();

        if( ++tick >= 9999999 )
            tick = 0;
    }

}

