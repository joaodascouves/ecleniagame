#include "enonplayable.h"
#include "resourcemanager.h"

#include <iostream>

ENonPlayable::ENonPlayable()
{
    setClass("nonplayable");
}

void ENonPlayable::update()
{
    if( getStatus() == S_STANDING || getStatus() == S_RUNNING )
    {
        timer = clock.getElapsedTime();
        if( timer.asSeconds() > .1f )
            setStatus(S_STANDING, false);
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
        drawableObject->setTextureRect(currentFrame());
        _update();
    }
}

ENonPlayableHitable::ENonPlayableHitable()
{
    setClass("nonplayablehitable");
}

void ENonPlayableHitable::slap(signed short playerDirection)
{
    if( life > 0 )
    {
        move(10 * playerDirection, 0);
        setStatus(S_SLAPPED, true);

        if( --life <= 0 )
            setStatus(S_DYING, true);
    }
}

AntiJoaozin::AntiJoaozin()
{
    ResourceManager::get().loadTexture("agoravai.png");
    drawableObject->setTexture(*ResourceManager::get().textureMap.at("agoravai"));
    drawableObject->setScale(0.23f, 0.23f);

    configAnimation(11, 1);
    addSequence(S_STANDING, {0, 0, 4, 0, 0});
}

ES1Ghost::ES1Ghost()
{
    ResourceManager::get().loadTexture("Mob.png");
    drawableObject->setTexture(*ResourceManager::get().textureMap.at("Mob"));

    configAnimation(10, 1);
    addSequence(S_STANDING, {0, 0, 4, 0, 0});
    addSequence(S_SLAPPED, {0, 5, 6, 0, 0});
    addSequence(S_DYING, {0, 5, 10, 0, 0});
}

void ES1Ghost::_update()
{
    move(-.1, 0);
}
