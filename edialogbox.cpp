#include "edialogbox.h"
#include "gameinstance.h"
#include "resourcemanager.h"

EDialogBox::EDialogBox()
{
    addClass("edialogbox");

    drawableObjects.push_back(new sf::RectangleShape);
    front()->setSize(sf::Vector2f(GameInstance::get().window.getSize().x, 300));
    front()->setFillColor(sf::Color(180, 60, 30, 180));

    nextIcon.setFont(ResourceManager::get().getRef<sf::Font>("arial"));
    nextIcon.setCharacterSize(25);
    nextIcon.setStyle(sf::Text::Bold);
    nextIcon.setPosition(950, front()->getSize().y - 50);
    nextIcon.setString(">>");

    drawableTextObjects.push_back(&nextIcon);
}

void EDialogBox::addDialog(std::string newTitle, std::string newBody)
{
    sf::Text* title = new sf::Text;
    sf::Text* body = new sf::Text;

    title->setFont(*ResourceManager::get().fontMap.at("arial"));
    title->setCharacterSize(30);
    title->setStyle(sf::Text::Bold);
    title->setPosition(10, 10);
    title->setString(newTitle);

    body->setFont(*ResourceManager::get().fontMap.at("arial"));
    body->setCharacterSize(25);
    body->setPosition(10, 50 + title->getCharacterSize());
    body->setString(newBody);

    dialog.push_back(std::make_pair(std::move(title), std::move(body)));
    position = dialog.begin();
}

void EDialogBox::preview()
{
    if( position - 1 != dialog.end() )
    {
        //
    }
}

void EDialogBox::next()
{
    if( position != dialog.end() )
    {
        if( getStatus() == -1 )
            show();

        if( drawableTextObjects.size() >= 3 )
        {
            drawableTextObjects.pop_back();
            drawableTextObjects.pop_back();
        }

        drawableTextObjects.push_back(position->first);
        drawableTextObjects.push_back(position->second);

        position++;
    }
    else
    {
        hide();
        rewind();
    }
}

void EDialogBox::rewind()
{
    position = dialog.begin();
}
