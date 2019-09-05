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

    short direction = D_RIGHT;
    short status = -1;
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
template class Entity<sf::RectangleShape>;

#endif // ENTITY_H
