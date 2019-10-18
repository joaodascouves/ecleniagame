#include "resourcemanager.h"
#include <iostream>
#include <type_traits>

ResourceManager::ResourceManager()
{
    //
}

ResourceManager::~ResourceManager()
{
    clear();
}

void ResourceManager::clear()
{
    for( auto& obj : textureMap ) delete obj.second;
    for( auto& obj : fontMap ) delete obj.second;
    for( auto& obj : soundMap ) delete obj.second;

    textureMap.clear();
    fontMap.clear();
    soundMap.clear();
}

template<class T>
T& ResourceManager::getRef(std::string alias)
{
    std::map<std::string, T*>* resourceMap;
    std::string directory;
    std::string extension;

    T* resource = nullptr;

    if constexpr( std::is_same<T, sf::Texture>::value )
    {
        directory = "sprites/";
        extension = ".png";
        resourceMap = &textureMap;
    }

    if constexpr( std::is_same<T, sf::Font>::value )
    {
        directory = "fonts/";
        extension = ".ttf";
        resourceMap = &fontMap;
    }

    if constexpr( std::is_same<T, sf::SoundBuffer>::value )
    {
        directory = "sounds/";
        extension = ".wav";
        resourceMap = &soundMap;
    }

    if( resourceMap )
    {
        if( resourceMap->find(alias) == resourceMap->end() )
        {
            resourceMap->insert(std::make_pair(alias, new T));
            if( ((*resourceMap)[alias]->loadFromFile("resources/" + directory + alias + extension)) )
            {
                resource = resourceMap->at(alias);
            }
        }
        else
        {
            if( resourceMap->at(alias) )
                resource = resourceMap->at(alias);
        }
    }

    return *resource;
}

template sf::Texture& ResourceManager::getRef<sf::Texture>(std::string);
template sf::Font& ResourceManager::getRef<sf::Font>(std::string);
template  sf::SoundBuffer& ResourceManager::getRef<sf::SoundBuffer>(std::string);
