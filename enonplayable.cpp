#include "enonplayable.h"
#include "resourcemanager.h"

#include <iostream>

ENonPlayable::ENonPlayable()
{
    addClass("enonplayable");
}

void ENonPlayable::update()
{
    if( getStatus() == -1 )
        return;

    if( getPosition().x < 0 - front()->getGlobalBounds().width )
        return destroy();

    if( getStatus() == S_RUNNING )
    {
        timer = clock.getElapsedTime();
        if( timer.asSeconds() > .1f )
        {
            setStatus(S_STANDING, false);
            speed = 0.1f;
        }
    }
    else if( sequences.at(currentSequence).cycle )
    {
        if( getStatus() != S_DYING )
        {
            sequences.at(currentSequence).cycle = 0;
            setStatus(S_STANDING, false);
        }
    }

    if( tickAnimation(15) && getStatus() == S_DYING )
        destroy();
    else
    {
        front()->setTextureRect(currentFrame());
        _update();
    }
}
