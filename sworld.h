#ifndef SWORLD_H
#define SWORLD_H

#include "gamestate.h"
#include "eplayable.h"
#include "edialogbox.h"
#include "epanel.h"

#include <vector>

class SWorld : public GameState
{
public:
    SWorld();
    virtual ~SWorld() override;

    virtual void draw() override;
    virtual void update() override;
    virtual void _update(){}

    virtual void handleInput() override;
    virtual void controls();

    virtual float getFloor() const;

    void spawn(Entity<sf::Sprite>*);
    void spawn(Entity<sf::RectangleShape>*);

    void showDialogBox(EDialogBox*);
    void hideDialogBox();

    void activatePanel(EPanel*);
    void deactivatePanel();
    void destroyPanel();

    enum
    {
        K_LEFT,
        K_RIGHT,
        K_HIT,
        K_ACTION,
        K_ESCAPE,
        K_UP,
        K_DOWN
    };

    short keyPress[7];

    sf::View sceneryView;
    sf::View worldView;
    sf::View interfaceView;

    float screenSpeed = 50.0f;

    sf::Text* actionLabel;
    sf::Text* actionDescription;

    std::vector<Entity<sf::Sprite>*> sceneryEntities;
    std::vector<Entity<sf::Sprite>*> worldEntities;
    std::vector<Entity<sf::RectangleShape>*> worldEntitiesRect;

    EPlayable* mainPlayer;
    EDialogBox* dialogBox;
    EPanel* currentPanel;

    std::vector<Entity<sf::RectangleShape>*>::reverse_iterator dialogBoxIterator;
};

#endif // SWORLD_H
