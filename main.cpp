#include "gameinstance.h"
#include "smainmenu.h"

int main()
{
    GameInstance::get().pushState(new SMainMenu);
    GameInstance::get().gameLoop();

    return 0;
}
