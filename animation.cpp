#include "animation.h"
#include "gameinstance.h"

Animation::Animation()
{

}

sf::IntRect Animation::currentFrame()
{
    sf::IntRect frameRect;
    frameRect.left = frameWidth*sequences.at(currentSequence).pos;
    frameRect.top = 0;
    frameRect.width = frameWidth;
    frameRect.height = frameHeight;

    return frameRect;
}

void Animation::tickAnimation()
{
    tickAnimation(20);
}

void Animation::tickAnimation(int tickMod)
{
    tickAnimation(20, false);
}

void Animation::tickAnimation(int tickMod, bool runOnce)
{
    if( runOnce && sequences.at(currentSequence).pos >= sequences.at(currentSequence).end )
        return;

    if( !(GameInstance::get().tick%tickMod) )
    if( ++sequences.at(currentSequence).pos >= sequences.at(currentSequence).end )
    {
        if( !runOnce ) sequences.at(currentSequence).pos = sequences.at(currentSequence).begin;
        else sequences.at(currentSequence).pos = sequences.at(currentSequence).end - 1;
    }
}
