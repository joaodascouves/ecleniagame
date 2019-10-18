#include "eplayable.h"
#include "gameinstance.h"
#include "resourcemanager.h"
#include "edoor.h"

#include "sfaseteste1.h"

#include <iostream>

EPlayable::EPlayable()
{
    addClass("emainplayer");

    front()->setOrigin(120, 0);
    setTextureName("emainplayer");

    configAnimation(11, 2);
    addSequence(S_STANDING, {0, 0, 4, 0, 0});
    addSequence(S_RUNNING, {0, 5, 11, 0, 0});
    addSequence(S_HITTING, {1, 1, 4, 0, 0});
    addSequence(S_SLAPPED, {0, 6, 6, 0, 0});
    addSequence(S_DYING, {0, 6, 6, 0, 0});

    inventory = new Inventory;
    life = 10;
    horizontalSpeed = 3.5f;
}

void EPlayable::_update()
{
    if( getSequence().pos == 1 )
        if( getStatus() == S_HITTING )
        {
            for( auto &e : hitableEntities )
                static_cast<ENonPlayableHitable*>(e)->slap(direction);
        }
}

void EPlayable::hit()
{
    timer = hitClock.getElapsedTime();
    if( timer.asSeconds() >  .2f )
    {
        if( getStatus() != S_HITTING )
            setStatus(S_HITTING, true);

        hitClock.restart();
        clock.restart();
    }
}
