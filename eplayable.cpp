#include "gameinstance.h"
#include "resourcemanager.h"
#include "eplayable.h"
#include "edoor.h"

#include "sfaseteste1.h"

EPlayable::EPlayable() : inventory(new Inventory)
{
    addClass("emainplayer");

    setTextureName("emainplayer1");
    front()->setOrigin(120, 0);

    configAnimation(11, 2);
    addSequence(S_STANDING, {0, 0, 4, 0, 0});
    addSequence(S_RUNNING, {0, 5, 11, 0, 0});
    addSequence(S_HITTING, {1, 1, 4, 0, 0});
    addSequence(S_SLAPPED, {1, 5, 5, 0, 0});
    addSequence(S_DYING, {1, 5, 11, 0, 0});

    //hitSound.setBuffer(ResourceManager::get().getRef<sf::SoundBuffer>("blade"));

    life = 10;
    horizontalSpeed = 3.5f;
}

EPlayable::EPlayable(const EPlayable& player)
{
    copy(player);

    currentEntity = player.currentEntity;
    currentRectEntity = player.currentRectEntity;
    currentTextEntity = player.currentTextEntity;

    inventory = player.inventory;

    EPlayable();
}

void EPlayable::_update()
{
    if( getSequence().pos > 2 )
        if( getStatus() == S_HITTING )
        {
            for( auto &e : hitableEntities )
                static_cast<ENonPlayableHitable*>(e)->slap(this);
        }
}

void EPlayable::hit()
{
    timer = hitClock.getElapsedTime();
    if( timer.asSeconds() >  .2f )
    {
//        hitSound.play();

        if( getStatus() != S_HITTING )
            setStatus(S_HITTING, true);

        hitClock.restart();
        clock.restart();
    }
}

sf::FloatRect EPlayable::getRelativeBounds()
{
    sf::FloatRect relativeBounds;

    relativeBounds.top = 0;
    relativeBounds.left = 0;
    relativeBounds.width = frameWidth;

    switch( getStatus() )
    {
    case S_HITTING:
        relativeBounds.width -= 120;
        relativeBounds.left += 50;
        break;

    default:
        relativeBounds.width -= 200;
        break;
    }

    relativeBounds.height = frameHeight;

    return relativeBounds;
}
