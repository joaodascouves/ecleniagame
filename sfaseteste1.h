#ifndef SFASETESTE1_H
#define SFASETESTE1_H

#include "sworld.h"
#include "edoor.h"
#include "eitem.h"
#include "enonplayable.h"

#include <vector>

class SFaseTeste1 : public SWorld
{
public:
    SFaseTeste1();

    EDoor* door1;
    EDoor* door2;

    EItem* grape1;
    EItem* grape2;

    AntiJoaozin* antiJoaozin;
    ES1Ghost* ghostTeste, *ghostTeste1, *ghostTeste2, *ghostTeste3;
};

#endif // SFASETESTE1_H
