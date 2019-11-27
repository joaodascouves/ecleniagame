#include "epanel.h"
#include "resourcemanager.h"

EPanel::EPanel(const sf::Vector2f& size, const sf::Color& color) :
    chooseable(false),
    choice(1),
    choiceMark(new sf::Text)
{
    choiceMark->setFont(ResourceManager::get().getRef<sf::Font>("arial"));
    choiceMark->setString(">");

    front()->setSize(size);
    front()->setFillColor(color);

    drawableTextObjects.push_back(choiceMark);
}

void EPanel::appendLine(const std::string &text)
{
    sf::Text* newLine = new sf::Text;
    newLine->setFont(ResourceManager::get().getRef<sf::Font>("arial"));
    newLine->setPosition(20, (drawableTextObjects.size() * 60) - 60);
    newLine->setString(text);

    drawableTextObjects.push_back(newLine);
}

void EPanel::toggleChooseable(const bool mode)
{
    chooseable = mode;
}

void EPanel::toggleActive(const bool focus)
{
    active = focus;
}

void EPanel::moveChoice(const bool upDown)
{
    if( isChooseable() )
    {
        signed short way = (upDown ? -1 : 1);

        choice += 1 * way;
        if( !upDown && choice > drawableTextObjects.size() - 1 )
            choice = 1;

        else
        if( upDown && choice < 1)
            choice = drawableTextObjects.size() - 1;


        choiceMark->setPosition(drawableTextObjects.at(choice)->getPosition().x - 20,
                                drawableTextObjects.at(choice)->getPosition().y);



    }
}

bool EPanel::isChooseable() const
{
    return chooseable;
}

bool EPanel::isActive() const
{
    return active;
}

short EPanel::getChoice() const
{
    return choice - 1;
}

void EPanel::action(Entity *entity)
{
    actionFunc(getChoice());
    hide();
}
