#include "es1ghost.h"
#include "resourcemanager.h"

#include "eplayable.h"
#include "sworld.h"

ES1Ghost::ES1Ghost()
{
    addClass("es1ghost");

    setTextureName("es1ghost");
    scale(.5f, .5f);

    configAnimation(8, 1);
    addSequence(S_FLOATING, {0, 0, 4, 0, 0});
    addSequence(S_SLAPPED, {0, 5, 6, 0, 0});
    addSequence(S_DYING, {0, 5, 8, 0, 0});

    direction = D_LEFT;
    horizontalSpeed = 1.3f;
}

//void ES1Ghost::_update()
//{
//    if( direction == D_RIGHT )
//        moveRight();
//    else
//        moveLeft();

//    EPlayable* mainPlayer = static_cast<SWorld*>(GameInstance::get().peekState())->mainPlayer;

//    if( direction == D_LEFT )
//    {
//        if( getPosition().x - mainPlayer->getPosition().x < 200 )
//            horizontalSpeed = 1.8f;
//    }

//    if( direction == D_RIGHT )
//    {
//        if( mainPlayer->getPosition().x - getPosition().x < 200 )
//            horizontalSpeed = 1.8f;
//    }
//}
