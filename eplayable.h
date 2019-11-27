#ifndef EPLAYABLE_H
#define EPLAYABLE_H

#include "enonplayablehitable.h"
#include "inventory.h"

#include <SFML/Audio.hpp>
#include <list>

class EPlayable : public ENonPlayableHitable
{
public:
    EPlayable();
    EPlayable(const EPlayable&);
    ~EPlayable() override = default;

    sf::Clock hitClock;

    virtual void _update() override;
    virtual void hit();

    virtual sf::FloatRect getRelativeBounds() override;

    std::list<Entity<sf::Sprite>*> currentEntity;
    std::list<Entity<sf::RectangleShape>*> currentRectEntity;

    std::list<sf::Text*> currentTextEntity;

    std::vector<Entity<sf::Sprite>*> hitableEntities;

    Inventory* inventory;

    //sf::Sound hitSound;
};

#endif // EPLAYABLE_H
