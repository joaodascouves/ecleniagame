#include "entity.h"
#include "gameinstance.h"
#include "resourcemanager.h"

#include <iostream>

template<class T>
Entity<T>::Entity()
{
    drawableObjects.push_back(new T);

    status = 0;
    previousStatus = 0;
    spawned = false;
}

template<class T>
Entity<T>::~Entity()
{
    destroy();
    direction = 0;
}

template<class T>
T* Entity<T>::front() const
{
    return drawableObjects.front();
}

template<class T>
void Entity<T>::flipHorizontally()
{
    direction *= -1;
}

template<class T>
void Entity<T>::destroy()
{
    for( auto &obj : drawableObjects )
    {
        delete obj;
        obj = nullptr;
    }

    drawableObjects.clear();
    drawableTextObjects.clear();
}

template<>
void Entity<sf::Sprite>::setTextureName(std::string alias)
{
    textureName = std::move(alias);
    std::cout << textureName << std::endl;

    front()->setTexture(ResourceManager::get().getRef<sf::Texture>(textureName));
}

template<class T>
void Entity<T>::setStatus(const short newStatus)
{
    setStatus(newStatus, false);
}

template<class T>
void Entity<T>::setStatus(const short newStatus, bool refresh)
{
    previousStatus = status;

    status = newStatus;
    currentSequence = newStatus;

    if( refresh )
    {
        if( sequences.at(currentSequence).pos < sequences.at(currentSequence).begin ||
            sequences.at(currentSequence).pos > sequences.at(currentSequence).end )
            sequences.at(currentSequence).pos = sequences.at(currentSequence).begin;

        tickAnimation(-1, true);
    }
}

template<class T>
void Entity<T>::setAlias(std::string newAlias)
{
    alias = std::move(newAlias);
}

template<>
void Entity<sf::Sprite>::configAnimation(int x, int y)
{
    frameWidth = front()->getTexture()->getSize().x/x;
    frameHeight = front()->getTexture()->getSize().y/y;
}

template class Entity<sf::Sprite>;
template class Entity<sf::RectangleShape>;
template class Entity<sf::Text>;
