#include "animation.h"
#include "gameinstance.h"

Animation::Animation()
{

}

sf::IntRect Animation::currentFrame()
{
    sf::IntRect frameRect;
    frameRect.left = frameWidth*frameCount;
    frameRect.top = 0;
    frameRect.width = frameWidth;
    frameRect.height = frameHeight;

    return frameRect;
}

void Animation::tickAnimation()
{
    if( !(GameInstance::get().tick%10) )
    if( ++frameCount >= sequences.at(currentSequence).end )
        frameCount = sequences.at(currentSequence).begin;
}
