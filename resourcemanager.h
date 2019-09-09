#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    static ResourceManager& get()
    {
        static ResourceManager instance;
        return instance;
    }

    void loadTexture(std::string);
    void loadFont(std::string);

    void clearTextures();

    sf::Texture getRef(std::string);

//private:
    std::map<std::string, sf::Texture*> textureMap;
    std::map<std::string, sf::Font*> fontMap;
};

#endif // RESOURCEMANAGER_H
