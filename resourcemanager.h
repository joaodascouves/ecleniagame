#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

    void clear();

    template<class T>
    T& getRef(std::string);

//private:
    std::map<std::string, sf::Texture*> textureMap;
    std::map<std::string, sf::Font*> fontMap;
    std::map<std::string, sf::SoundBuffer*> soundMap;
};

#endif // RESOURCEMANAGER_H
