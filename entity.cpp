#include "entity.h"

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
}
