#include "es1banshee.h"

#include "sworld.h"
#include "resourcemanager.h"

ES1Banshee::ES1Banshee()
{
    addClass("es1banshee");

    setTextureName("es1banshee");

    configAnimation(8, 1);
    addSequence(S_FLOATING, {0, 0, 8, 0, 0});

    dialogBox = new EDialogBox;
}

void ES1Banshee::_update()
{
    if( dialogBox->getStatus() == -1 )
    {
        if( isSequenceCompleted() )
            destroy();
    }
}

void ES1Banshee::action(Entity *mainPlayer)
{
    static_cast<SWorld*>(
                GameInstance::get().peekState())->showDialogBox(std::move(dialogBox));
}
