#include "es1locker.h"
#include "eplayable.h"
#include "resourcemanager.h"

ES1Locker::ES1Locker()
{
    addClass("elocker");

    setTextureName("es1locker");
    front()->setScale(.5f, .2f);

    int leftSpace = -20;

    for( auto &s : slots )
    {
        s = new sf::Text;
        s->setFont(ResourceManager::get().getRef<sf::Font>("arial"));
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
    if( static_cast<EPlayable*>(mainPlayer)->currentTextEntity.back() )
    {
        int numericVal = atoi((const char *)static_cast<EPlayable*>(mainPlayer)->currentTextEntity.back()->getString().toUtf8().c_str());
        if( numericVal < 9 )
            numericVal++;
        else
            numericVal = 0;

        static_cast<EPlayable*>(mainPlayer)->currentTextEntity.back()->setString(std::to_string(numericVal));
    }
}
