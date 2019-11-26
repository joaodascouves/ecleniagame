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

    actionPanel = new EPanel;
    spawn(actionPanel);

    actionPanel->front()->setFillColor(sf::Color(90, 20, 240, 50));
    actionPanel->front()->setSize(sf::Vector2f(300, 300));
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
    activatePanel(actionPanel);

    leftEPanel = new EPanel;
    spawn(leftEPanel);

    leftEPanel->front()->setFillColor(sf::Color(90, 20, 160, 50));
    leftEPanel->front()->setSize(sf::Vector2f(300, 200));

    leftEPanel->setPosition(0, 800);
    leftEPanel->drawableTextObjects.push_back(new sf::Text);
    leftEPanel->drawableTextObjects.back()->setFont(ResourceManager::get().getRef<sf::Font>("arial"));
    leftEPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(mainPlayer->life));

    rightEPanel = new EPanel;
    spawn(rightEPanel);

    rightEPanel->front()->setFillColor(sf::Color(90, 20, 160, 50));
    rightEPanel->front()->setSize(sf::Vector2f(300, 200));

    rightEPanel->setPosition(700, 800);
    rightEPanel->drawableTextObjects.push_back(new sf::Text);
    rightEPanel->drawableTextObjects.back()->setFont(ResourceManager::get().getRef<sf::Font>("arial"));
    rightEPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(enemy->life));
}

void SCombat::update()
{
    if( challenger->front() )
    {
        challenger->update();
        leftEPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(mainPlayer->life));
    }

    if( enemy->front() )
    {
        enemy->update();
        rightEPanel->drawableTextObjects.back()->setString("HP: " + std::to_string(enemy->life));
    }
}
