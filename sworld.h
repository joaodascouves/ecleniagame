#ifndef SWORLD_H
#define SWORLD_H

#include "gamestate.h"
#include "eplayable.h"
#include "edialogbox.h"

#include <vector>

class SWorld : public GameState
{
public:
    SWorld();
    virtual ~SWorld();

    virtual void draw();
    virtual void update();
    virtual void _update(){}
    virtual void handleInput();

    virtual float getFloor() const;

    void spawn(Entity<sf::Sprite>*);
    void spawn(Entity<sf::RectangleShape>*);

    void showDialogBox(EDialogBox*);

    enum
    {
        K_LEFT,
        K_RIGHT,
        K_HIT,
        K_ACTION,
        K_ESCAPE
    };

    short keyPress[5] = {0, 0, 0, 0, 0};

    sf::View sceneryView;
    sf::View worldView;
    sf::View interfaceView;

    float screenSpeed = 50.0f;

    sf::Text actionLabel;
    sf::Text actionDescription;

    std::vector<Entity<sf::Sprite>*> sceneryEntities;
    std::vector<Entity<sf::Sprite>*> worldEntities;
    std::vector<Entity<sf::RectangleShape>*> worldEntitiesRect;

    EPlayable* mainPlayer;
    EDialogBox* dialogBox = nullptr;

    std::vector<Entity<sf::RectangleShape>*>::iterator dialogBoxIterator;
};

#endif // SWORLD_H
