#include "resourcemanager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
    //
}

ResourceManager::~ResourceManager()
{
    //
}

void ResourceManager::loadTexture(std::string fname)
{
    std::string alias = fname.substr(0, fname.find('.'));
    textureMap.insert(std::make_pair(alias, new sf::Texture));
    textureMap[alias]->loadFromFile("resources/sprites/" + fname);
}

void ResourceManager::loadFont(std::string fname)
{
    std::string alias = fname.substr(0, fname.find('.'));
    fontMap.insert(std::make_pair(alias, new sf::Font));
    fontMap[alias]->loadFromFile("resources/fonts/" + fname);
}

sf::Texture ResourceManager::getRef(std::string alias)
{
    return *textureMap.at(alias);
}
