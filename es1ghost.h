#ifndef ES1GHOST_H
#define ES1GHOST_H

#include "enonplayablehitable.h"

class ES1Ghost : public ENonPlayableHitable
{
public:
    ES1Ghost();
    virtual ~ES1Ghost(){}

    virtual void _update();
};

#endif // ES1GHOST_H
