#include "sfaseteste1.h"
#include "resourcemanager.h"

SFaseTeste1::SFaseTeste1()
{
    sceneryEntities.push_back(new Entity<sf::Sprite>);
    sceneryEntities.back()->setTextureName("es1scenery1");

    sceneryEntities.push_back(new Entity<sf::Sprite>);
    sceneryEntities.back()->setTextureName("es1scenery1");
    sceneryEntities.back()->setPosition(sceneryEntities.at(0)->front()->getGlobalBounds().width, 0);

    grape1 = new EItem();
    grape2 = new EItem();
    door1 = new EDoor<SFaseTeste1>;
    door2 = new EDoor<SFaseTeste1>;

    door1->conditionFunc = std::bind([this](){
//       return mainPlayer->inventory->has("grape");

//        return ( locker->slots[0]->getString() == "0" &&
//                locker->slots[1]->getString() == "0" &&
//                locker->slots[2]->getString() == "0" &&
//                locker->slots[3]->getString() == "1");

        return true;
    });

    ghostTeste = new ES1Ghost;

    ghostTeste1 = new ES1Ghost;
    ghostTeste2 = new ES1Ghost;
    ghostTeste3 = new ES1Ghost;

    banshee = new ES1Banshee;

    banshee->dialogBox->addDialog("Banshee", "Ola, viajante. Voce esta agora na floresta morta.\n"
                                    "Para se chegar a entrada do templo, voce"
                                    " deve inevitavelmente passar pelo cemiterio.\n"
                                    "No entanto, tome cuidado: ha um exercito de fantasmas azuis e fogos fa"
                                    "tuos que \nprotegem a entrada de invasores."
                                    "");

    banshee->dialogBox->addDialog("Banshee", "Para combate-los, acoplei uma lamina eterea em "
                                    "seu corpo virtual. Pressione [Z] para \natacar. "
                                    "Seus golpes cortantes deverao desintegrar o inimigo quando a energia\n"
                                    "deste estiver totalmente esgotada. Lembre-se, todavia, que "
                                    "o mesmo vale para voce."
                                    "");

    banshee->dialogBox->addDialog("Banshee", "Desvende o enigma desse lugar e sobrevivera. Caso contrario,"
                                    "sera eternamente\nengolido pelo oblivion de uma realidade falsa. "
                                    "Ao longo do caminho tentarei te ajudar.\nPressione [A] para "
                                    "interagir com entidades.");

    banshee->dialogBox->addDialog("Banshee", "Que a verdadeira Divindade esteja com voce.");

//    locker = new ES1Locker;

//    spawn(locker);
//    locker->setAlias("locker");
//    locker->setPosition(250, 350 - getFloor());

    spawn(banshee);
    banshee->setAlias("banshee");
    banshee->setPosition(200, 350 - getFloor());

//    spawn(grape1);
//    worldEntities.back()->setAlias("grape");
//    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
//    worldEntities.back()->front()->setTexture(ResourceManager::get().getRef<sf::Texture>("grape"));
//    worldEntities.back()->setPosition(300, 450 - getFloor());

//    spawn(grape2);
//    worldEntities.back()->setAlias("grape");
//    worldEntities.back()->setDescription("Por qual motivo alguem deixaria um cacho de uvas aqui?");
//    worldEntities.back()->front()->setTexture(ResourceManager::get().getRef<sf::Texture>("grape"));
//    worldEntities.back()->setPosition(100, 450 - getFloor());

    spawn(door1);
    door1->setAlias("door1");
    door1->setPosition(1000, 310- getFloor());

//    spawn(door2);
//    door2->setAlias("door2");
//    door2->setPosition(1300, 310- getFloor());

    spawn(ghostTeste);
    ghostTeste->setAlias("ghostTeste");
    ghostTeste->setPosition(400, 395- getFloor());

    spawn(ghostTeste1);
    ghostTeste1->flipHorizontally();
    ghostTeste1->setAlias("ghostTeste1");
    ghostTeste1->setPosition(500, 395- getFloor());

//    spawn(ghostTeste2);
//    ghostTeste2->setAlias("ghostTeste2");
//    ghostTeste2->setPosition(600, 395- getFloor());

//    spawn(ghostTeste3);
//    ghostTeste3->setAlias("ghostTeste3");
//    ghostTeste3->setPosition(700, 395- getFloor());

    mainPlayer = new EPlayable;
    mainPlayer->setPosition(20, 395- getFloor());
}

void SFaseTeste1::_update()
{
    if( mainPlayer->getPosition().x > 800 && !ghostTeste2->isSpawned() )
    {
        spawn(ghostTeste2);
        ghostTeste2->flipHorizontally();
        ghostTeste2->setAlias("ghostTeste2");
        ghostTeste2->setPosition(600, 395- getFloor());
    }
}
