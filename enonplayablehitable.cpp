#include "enonplayablehitable.h"

ENonPlayableHitable::ENonPlayableHitable()
{
    addClass("enonplayablehitable");
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

void ENonPlayableHitable::slap(signed short enemyDirection)
{
    if( life > 0 )
    {
        setStatus(S_SLAPPED, true);

        move(40 * horizontalSpeed * enemyDirection, 0);
        if( !hasClass("emainplayer") )
        {

            if(  enemyDirection == direction )
                flipHorizontally();
        }

        if( --life <= 0 )
            setStatus(S_DYING, true);
    }
}
