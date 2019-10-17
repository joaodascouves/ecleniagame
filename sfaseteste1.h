#ifndef SFASETESTE1_H
#define SFASETESTE1_H

#include "sworld.h"
#include "edoor.h"
#include "eitem.h"
#include "enonplayable.h"

#include "es1locker.h"
#include "es1ghost.h"
#include "es1banshee.h"

#include <vector>

class SFaseTeste1 : public SWorld
{
public:
    SFaseTeste1();

    virtual void _update();

    EDoor<SFaseTeste1>* door1;
    EDoor<SFaseTeste1>* door2;

    EItem* grape1;
    EItem* grape2;

    ES1Ghost* ghostTeste, *ghostTeste1, *ghostTeste2, *ghostTeste3;

    ES1Banshee* banshee;
    ES1Locker* locker;
};

#endif // SFASETESTE1_H
