#ifndef SWORLD_H
#define SWORLD_H

#include "gamestate.h"
#include "eplayable.h"

#include <vector>

class SWorld : public GameState
{
public:
    SWorld();
    virtual ~SWorld();

    enum
    {
        K_LEFT,
        K_RIGHT,
        K_HIT,
        K_ACTION
    };

    short keyPress[4] = {0, 0, 0, 0};

    virtual void draw();
    virtual void update();
    virtual void handleInput();

    virtual float getFloor() const;

    void spawn(Entity<sf::Sprite>*);

    sf::View sceneryView;
    sf::View worldView;
    sf::View inventoryView;

    sf::Text actionLabel;
    sf::Text actionDescription;

    std::vector<Entity<sf::Sprite>*> sceneryEntities;
    std::vector<Entity<sf::Sprite>*> worldEntities;
    std::vector<Entity<sf::RectangleShape>*> worldEntitiesRect;

    EPlayable* mainPlayer;
};

#endif // SWORLD_H
