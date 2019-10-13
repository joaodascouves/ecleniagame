#include "entity.h"
#include "gameinstance.h"

template<class T>
Entity<T>::Entity()
{
    drawableObject = new T;
    status = 0;
}

template<class T>
void Entity<T>::flipHorizontally()
{
    direction *= -1;
    drawableObject->scale(-1, 1);
}

template<class T>
void Entity<T>::destroy()
{
    delete drawableObject;
    drawableObject = nullptr;
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

template<>
void Entity<sf::Sprite>::configAnimation(int x, int y)
{
    frameWidth = drawableObject->getTexture()->getSize().x/x;
    frameHeight = drawableObject->getTexture()->getSize().y/y;
}
