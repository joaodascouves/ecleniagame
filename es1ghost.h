#ifndef ES1GHOST_H
#define ES1GHOST_H

#include "enonplayablehitable.h"

class ES1Ghost : public ENonPlayableHitable
{
public:
    ES1Ghost();
    ~ES1Ghost() override = default;

    //virtual void _update() override;
};

#endif // ES1GHOST_H
