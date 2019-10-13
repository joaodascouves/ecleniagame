#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"

template<class T>
class Entity : public sf::Drawable, public sf::Transformable, public Animation
{
public:
    Entity();
    virtual ~Entity(){}

    T* drawableObject;

    enum { D_LEFT = -1, D_RIGHT = 1 };

    short index;
    short direction = D_RIGHT;
    short status = -1;
    short previousStatus = -1;

    sf::Clock clock;
    sf::Time timer;

    virtual void flipHorizontally();
    virtual void update(){};
    virtual void destroy();

    virtual void moveLeft(){}
    virtual void moveRight(){}

    void setStatus(short);
    void setStatus(short, bool);
    short getStatus() const { return status; }

    void setClass(std::string newClass){ e_class = std::move(newClass); }
    void setAlias(std::string newAlias){ e_alias = std::move(newAlias); }
    void setDescription(std::string newDescription){ description = std::move(newDescription); }

    void configAnimation(int, int);

    std::string getAlias() const { return e_alias; }
    std::string getClass() const { return e_class; }
    std::string getDescription() const { return description; }

private:
    std::string e_alias;
    std::string e_class;
    std::string description;

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
