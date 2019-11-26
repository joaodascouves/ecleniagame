#include "entity.h"
#include "gameinstance.h"
#include "resourcemanager.h"

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

template<>
void Entity<sf::Sprite>::setTextureName(const std::string& alias)
{
    textureName = std::move(alias);
    front()->setTexture(ResourceManager::get().getRef<sf::Texture>(textureName));
}

template<>
std::string Entity<sf::Sprite>::getTextureName() const
{
    return textureName;
}

template<>
void Entity<sf::Sprite>::copy(const Entity& entity)
{
    for( auto it = entity.drawableObjects.begin() + 1; it<entity.drawableObjects.end(); it++ )
    {
        drawableObjects.push_back(new sf::Sprite);
        drawableObjects.back()->setTexture(*(*it)->getTexture());
        drawableObjects.back()->setPosition((*it)->getPosition());
        drawableObjects.back()->setScale((*it)->getScale());
    }

    setScale(entity.getScale());
    setPosition(entity.getPosition());
    setTextureName(entity.getTextureName());

    sequences = entity.sequences;

    frameWidth = entity.frameWidth;
    frameHeight = entity.frameHeight;

    direction = entity.direction;
}

template<>
Entity<sf::Sprite>::Entity(const Entity& entity)
{
    copy(entity);
    Entity();
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

template<class T>
void Entity<T>::hide()
{
    if( status != -1 )
    {
        previousStatus = status;
        status = -1;
    }
}

template<class T>
void Entity<T>::show()
{
    if( status != previousStatus)
        status = previousStatus;
}

template<class T>
bool Entity<T>::isSpawned() const
{
    return spawned;
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
short Entity<T>::getStatus() const
{
    return status;
}

template<class T>
void Entity<T>::setAlias(const std::string& newAlias)
{
    alias = std::move(newAlias);
}

template<class T>
void Entity<T>::setDescription(const std::string& newDescription)
{
    description = std::move(newDescription);
}

template<class T>
void Entity<T>::addClass(const std::string& newClass)
{
    classes.push_back(std::move(newClass));
}

template<>
void Entity<sf::Sprite>::configAnimation(int x, int y)
{
    frameWidth = front()->getTexture()->getSize().x/x;
    frameHeight = front()->getTexture()->getSize().y/y;
}

template<class T>
std::string Entity<T>::getAlias() const
{
    return alias;
}

template<class T>
std::string Entity<T>::getDescription() const
{
    return description;
}

template<class T>
bool Entity<T>::hasClass(const std::string& searchClass) const
{
    bool result = std::find(classes.begin(), classes.end(), searchClass) != classes.end();
    return result;
}

template class Entity<sf::Sprite>;
template class Entity<sf::RectangleShape>;
