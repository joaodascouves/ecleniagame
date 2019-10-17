#include "es1locker.h"
#include "eplayable.h"
#include "resourcemanager.h"

ES1Locker::ES1Locker()
{
    addClass("elocker");

    ResourceManager::get().loadTexture("bruno-borges9.jpg");
    ResourceManager::get().loadFont("arial.ttf");

    front()->setTexture(*ResourceManager::get().textureMap.at("bruno-borges9"));
    front()->setScale(.5f, .2f);

    int leftSpace = -20;

    for( auto &s : slots )
    {
        s = new sf::Text;
        s->setFont(*ResourceManager::get().fontMap.at("arial"));
        s->setString("0");
        s->setCharacterSize(40);
        s->setFillColor(sf::Color(255, 0, 0));
        s->setPosition(leftSpace += 100, 50);

        drawableTextObjects.push_back(s);
    }
}

void ES1Locker::update()
{
    //
}

void ES1Locker::action(Entity* mainPlayer)
{
    if( static_cast<EPlayable*>(mainPlayer)->currentTextEntity )
    {
        int numericVal = atoi((const char *)static_cast<EPlayable*>(mainPlayer)->currentTextEntity->getString().toUtf8().c_str());
        if( numericVal < 9 )
            numericVal++;
        else
            numericVal = 0;

        static_cast<EPlayable*>(mainPlayer)->currentTextEntity->setString(std::to_string(numericVal));
    }
}
