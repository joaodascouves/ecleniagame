#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <SFML/Graphics.hpp>
#include <stack>

class GameState;

class GameInstance
{
public:
    GameInstance();
    ~GameInstance(){}

    static GameInstance& get()
    {
        static GameInstance gameInstance;
        return gameInstance;
    }

    sf::RenderWindow window;
    std::stack<GameState*> states;

    void changeState(GameState*);
    void pushState(GameState*);
    void popState();

    GameState* peekState();
    void gameLoop();

    float fps;
    float totalTime;

    unsigned long tick;
};

#endif // GAMEINSTANCE_H
