#include "entity.h"
#include "gameinstance.h"

template<class T>
Entity<T>::Entity()
{
    //
}

template<class T>
void Entity<T>::flipHorizontally()
{
    direction *= -1;
    drawableObject->scale(-1, 1);
//    drawableObject->move(-1*drawableObject->getGlobalBounds().height *direction, 0);
}

template<class T>
void Entity<T>::setStatus(const short newStatus)
{
    setStatus(newStatus, 0);
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

        tickAnimation(10);
    }
}
