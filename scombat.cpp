#include "scombat.h"
#include "resourcemanager.h"

SCombat::SCombat(ENonPlayableHitable* entity1, ENonPlayableHitable* entity2) :
    challenger(new EPlayable(*(static_cast<EPlayable*>(entity1)))),
    enemy(new ENonPlayableHitable(*entity2))
{
    mainPlayer = static_cast<EPlayable*>(challenger);
    mainPlayer->scale(1.5f, 1.5f);
    mainPlayer->setPosition(0, mainPlayer->getPosition().y - 100);

    spawn(static_cast<ENonPlayableHitable*>(enemy));
    enemy->scale(1.7f, 1.7f);
    enemy->setPosition(600, enemy->getPosition().y - 100);

    actionPanel = new EPanel({300, 300}, sf::Color(90, 20, 240, 50));
    spawn(actionPanel);

    actionPanel->appendLine("Atacar");
    actionPanel->appendLine("Fugir");

    actionPanel->actionFunc = [this](short choice){
        deactivatePanel();

        switch( choice )
        {
        case 0:
            enemy->slap(challenger);
            break;

        case 1:
            GameInstance::get().popState();
            break;

        default: break;
        }
    };

    actionPanel->toggleChooseable(true);
    activatePanel(std::move(actionPanel));

    leftPanel = new EPanel({300, 200}, sf::Color(90, 20, 160, 50));
    spawn(leftPanel);

    leftPanel->setPosition(0, 800);
    leftPanel->drawableTextObjects.push_back(new sf::Text);
    leftPanel->drawableTextObjects.back()->setFont(ResourceManager::get().getRef<sf::Font>("arial"));
    leftPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(mainPlayer->life));

    rightPanel = new EPanel({300, 200}, sf::Color(90, 20, 160, 50));
    spawn(rightPanel);

    rightPanel->setPosition(700, 800);
    rightPanel->drawableTextObjects.push_back(new sf::Text);
    rightPanel->drawableTextObjects.back()->setFont(ResourceManager::get().getRef<sf::Font>("arial"));
    rightPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(enemy->life));
}

void SCombat::update()
{
    if( challenger->front() )
    {
        challenger->update();
        leftPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(mainPlayer->life));
    }

    if( enemy->front() )
    {
        enemy->update();
        rightPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(enemy->life));
    }
}
