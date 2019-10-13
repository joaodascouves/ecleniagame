#include "animation.h"
#include "gameinstance.h"

Animation::Animation()
{
    //
}

sf::IntRect Animation::currentFrame()
{
    sf::IntRect frameRect;
    frameRect.left = frameWidth*sequences.at(currentSequence).pos;
    frameRect.top = frameHeight*sequences.at(currentSequence).row;
    frameRect.width = frameWidth;
    frameRect.height = frameHeight;

    return frameRect;
}

void Animation::addSequence(int status, sequenceMap newSequence)
{
    sequences.insert(std::pair<int, sequenceMap>(status, std::move(newSequence)));
}

sequenceMap Animation::getSequence()
{
    return sequences.at(currentSequence);
}

sequenceMap Animation::getSequence(int status)
{
    return sequences.at(status);
}

bool Animation::tickAnimation()
{
    return tickAnimation(20);
}

bool Animation::tickAnimation(int tickMod)
{
    return tickAnimation(tickMod, false);
}

bool Animation::tickAnimation(int tickMod, bool runOnce)
{
    if( runOnce && sequences.at(currentSequence).pos >= sequences.at(currentSequence).end )
        return true;

    if( !(GameInstance::get().tick % tickMod) || tickMod == -1 )
    if( ++sequences.at(currentSequence).pos >= sequences.at(currentSequence).end )
    {
        if( !runOnce )
        {
            sequences.at(currentSequence).pos = sequences.at(currentSequence).begin;
            sequences.at(currentSequence).cycle++;
        }
        else
        {
            sequences.at(currentSequence).pos = sequences.at(currentSequence).end - 1;
        }

        return true;
    }

    return false;
}
