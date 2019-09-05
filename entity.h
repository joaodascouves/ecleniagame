#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"

template<class T>
class Entity : public sf::Drawable, public sf::Transformable, public Animation
{
public:
    Entity();
    virtual ~Entity(){}

    T* drawableObject = new T;

    enum { D_LEFT = -1, D_RIGHT = 1 };
    enum
    {
        S_RUNNING,
        S_STANDING,
        S_WALKING,
        S_JUMPING,
        S_FALLING
    };

    short direction = D_RIGHT;
    short status = S_STANDING;
    short previousStatus = -1;

    virtual void flipHorizontally();
    virtual void update(const float dt){};

    virtual void moveLeft(){}
    virtual void moveRight(){}

    void setStatus(short);
    void setStatus(short, bool);

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(*drawableObject, states);
    }
};

template class Entity<sf::Sprite>;

#endif // ENTITY_H
