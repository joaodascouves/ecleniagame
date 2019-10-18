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
    short status;
    short previousStatus;
    bool spawned;

    sf::Clock clock;
    sf::Time timer;

    T* front() const;

    virtual void flipHorizontally();
    virtual void update(){}
    virtual void destroy();
    virtual void action(Entity*){}

    void hide(){ if( status!= -1 ){ previousStatus = status; status = -1; } }
    void show(){ status = previousStatus; }
    bool isSpawned() const { return spawned; }

    void setTextureName(std::string);

    void setStatus(short);
    void setStatus(short, bool);
    short getStatus() const { return status; }

    void addClass(std::string newClass){ classes.push_back(std::move(newClass)); }
    void setAlias(std::string);
    void setDescription(std::string newDescription){ description = std::move(newDescription); }

    void configAnimation(int, int);

    std::string getAlias() const { return alias; }
    std::string getDescription() const { return description; }
    bool hasClass(std::string searchClass) const
    {
        return std::find(classes.begin(), classes.end(), searchClass) != classes.end();
    }

private:
    std::string alias;
    std::string description;
    std::string textureName;

    std::vector<std::string> classes;

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
