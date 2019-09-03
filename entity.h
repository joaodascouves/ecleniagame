#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

template<class T>
class Entity : public sf::Drawable, public sf::Transformable
{
public:
    Entity();
    virtual ~Entity(){}

    T* drawableObject = new T;

    enum { D_LEFT = -1, D_RIGHT = 1 };
    short direction = D_RIGHT;

    virtual void flipHorizontally();
    virtual void update(const float dt){};

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(*drawableObject, states);
    }
};

template class Entity<sf::Sprite>;

#endif // ENTITY_H
