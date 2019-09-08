#include "texturemanager.h"
#include <iostream>

TextureManager::TextureManager()
{
    //
}

TextureManager::~TextureManager()
{
    //
}

void TextureManager::loadTexture(std::string fname)
{
    std::string alias = fname.substr(0, fname.find('.'));
    textureMap.insert(std::make_pair(alias, new sf::Texture));
    textureMap[alias]->loadFromFile("sprites/" + fname);
}

sf::Texture TextureManager::getRef(std::string alias)
{
    return *textureMap.at(alias);
}
