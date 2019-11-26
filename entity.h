#ifndef ENTITY_H
#define ENTITY_H

#include "animation.h"
#include <vector>

template<class T>
class Entity : public sf::Drawable, public sf::Transformable, public Animation
{
public:
    Entity();
    Entity(const Entity&);
    virtual ~Entity() override;

    void copy(const Entity&);

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

    void hide();
    void show();
    bool isSpawned() const;

    void setTextureName(const std::string&);
    std::string getTextureName() const;

    void setStatus(short);
    void setStatus(short, bool);
    short getStatus() const;

    void addClass(const std::string&);
    void setAlias(const std::string&);
    void setDescription(const std::string&);

    void configAnimation(int, int);

    std::string getAlias() const;
    std::string getDescription() const;

    bool hasClass(const std::string&) const;

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
