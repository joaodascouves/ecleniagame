#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    static TextureManager& get()
    {
        static TextureManager instance;
        return instance;
    }

    void loadTexture(std::string);
    void clearTextures();

    sf::Texture getRef(std::string);

//private:
    std::map<std::string, sf::Texture*> textureMap;
};

#endif // TEXTUREMANAGER_H
