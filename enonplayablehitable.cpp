#include "enonplayablehitable.h"
#include "gameinstance.h"
#include "sworld.h"

#include <iostream>

ENonPlayableHitable::ENonPlayableHitable()
{
    addClass("enonplayablehitable");
}

ENonPlayableHitable::ENonPlayableHitable(const ENonPlayableHitable& entity) :
    life(entity.life), horizontalSpeed(entity.horizontalSpeed)
{
    copy(entity);
    ENonPlayableHitable();
}

void ENonPlayableHitable::moveLeft()
{
    if( direction == D_RIGHT ) flipHorizontally();
    move(speed * -1, 0);

    if( speed < horizontalSpeed )
    {
        if( speed == 0 ) speed = .2f;
        speed *= 1.2f;
    }

    if ( hasSequence(S_RUNNING) && getStatus() != S_RUNNING )
        setStatus(S_RUNNING, true);

    clock.restart();
}

void ENonPlayableHitable::moveRight()
{
    if( direction == D_LEFT ) flipHorizontally();
    move(speed, 0);

    if( speed < horizontalSpeed )
    {
        if( speed == 0 ) speed = .2f;
        speed *= 1.2f;
    }

    if ( hasSequence(S_RUNNING) && getStatus() != S_RUNNING )
        setStatus(S_RUNNING, true);

    clock.restart();
}

void ENonPlayableHitable::slap(ENonPlayableHitable* enemy)
{
    if( life > 0 )
    {
        timer = slapClock.getElapsedTime();

        if( timer.asSeconds() > .3f )
        {
            if( !(hasClass("emainplayer") && getStatus() == S_SLAPPED) )
            {
                setStatus(S_SLAPPED, true);

                SWorld* currentLevel = static_cast<SWorld*>(GameInstance::get().peekState());
                if( getPosition().x - 50 > currentLevel->worldView.getCenter().x - currentLevel->worldView.getSize().x/2 &&
                        getPosition().x + 50 < currentLevel->worldView.getCenter().x + currentLevel->worldView.getSize().x/2 )
                {
                    if( enemy->getPosition().x >= getPosition().x )
                    {
                        move(-30, 0);
                    }

                    else
                    {
                        move(30, 0);
                    }
                }


                if( !hasClass("emainplayer") )
                {
                    if(  enemy->direction == direction )
                        flipHorizontally();
                }

                if( --life <= 0 )
                    setStatus(S_DYING, true);
            }

            slapClock.restart();
        }
    }
}
