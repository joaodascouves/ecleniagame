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
    if( direction == -1 )
        frameRect.left += frameWidth;

    frameRect.top = frameHeight*sequences.at(currentSequence).row;
    frameRect.width = frameWidth * direction;
    frameRect.height = frameHeight;

    return frameRect;
}

void Animation::addSequence(int status, sequenceMap newSequence)
{
    sequences.insert(std::pair<int, sequenceMap>(status, std::move(newSequence)));
}

bool Animation::hasSequence(int status)
{
    return sequences.find(status) != sequences.end();
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
    sequenceEnd = false;

    if( runOnce && sequences.at(currentSequence).pos >= sequences.at(currentSequence).end )
    {
        sequenceEnd = true;
        return sequenceEnd;
    }

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

        sequenceEnd = true;
    }

    return sequenceEnd;
}
