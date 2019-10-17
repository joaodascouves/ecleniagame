#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"
#include <vector>

template<class T>
class Entity : public sf::Drawable, public sf::Transformable, public Animation
{
public:
    Entity();
    virtual ~Entity();

    std::vector<T*> drawableObjects;
    std::vector<sf::Text*> drawableTextObjects;

    short index;
    short status = -1;
    short previousStatus = 0;
    bool spawned = false;

    sf::Clock clock;
    sf::Time timer;

    T* front() const { return drawableObjects.front(); }

    virtual void flipHorizontally();
    virtual void update(){}
    virtual void destroy();
    virtual void action(Entity*){}

    virtual void moveLeft(){}
    virtual void moveRight(){}

    void hide(){ if( status!= -1 ){ previousStatus = status; status = -1; } }
    void show(){ status = previousStatus; }

    void setStatus(short);
    void setStatus(short, bool);
    short getStatus() const { return status; }
    bool isSpawned() const { return spawned; }

    void addClass(std::string newClass){ e_class.push_back(std::move(newClass)); }
    void setAlias(std::string newAlias){ e_alias = std::move(newAlias); }
    void setDescription(std::string newDescription){ description = std::move(newDescription); }

    void configAnimation(int, int);

    std::string getAlias() const { return e_alias; }
    std::string getDescription() const { return description; }
    bool hasClass(std::string searchClass) const
    {
        return std::find(e_class.begin(), e_class.end(), searchClass) != e_class.end();
    }

private:
    std::string e_alias;
    std::string description;
    std::vector<std::string> e_class;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if( status != -1 )
        {
            states.transform *= getTransform();
            for( auto& obj : drawableObjects )
                target.draw(*obj, states);

            for( auto& obj : drawableTextObjects )
                target.draw(*obj, states);
        }
    }
};

#endif // ENTITY_H
