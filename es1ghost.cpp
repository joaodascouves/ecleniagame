#include "es1ghost.h"
#include "resourcemanager.h"

ES1Ghost::ES1Ghost()
{
    addClass("es1ghost");

    setTextureName("es1ghost");
    scale(.5f, .5f);

    configAnimation(8, 1);
    addSequence(S_FLOATING, {0, 0, 4, 0, 0});
    addSequence(S_SLAPPED, {0, 5, 6, 0, 0});
    addSequence(S_DYING, {0, 5, 8, 0, 0});

    direction = D_LEFT;
    horizontalSpeed = 0.6f;
}

void ES1Ghost::_update()
{
    if( direction == D_RIGHT )
        moveRight();
    else
        moveLeft();
}
