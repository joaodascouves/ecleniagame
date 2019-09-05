#ifndef SFASETESTE1_H
#define SFASETESTE1_H

#include "sworld.h"
#include "eplayable.h"
#include "edoor.h"

#include <vector>

class SFaseTeste1 : public SWorld
{
public:
    SFaseTeste1();

    void handleInput();

    EDoor* door1 = new EDoor(0);
};

#endif // SFASETESTE1_H
