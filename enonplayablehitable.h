#ifndef ENONPLAYABLEHITABLE_H
#define ENONPLAYABLEHITABLE_H

#include "enonplayable.h"

class ENonPlayableHitable : public ENonPlayable
{
public:
    ENonPlayableHitable();
    virtual ~ENonPlayableHitable(){}

    virtual void moveLeft();
    virtual void moveRight();
    virtual void slap(signed short);

    unsigned short life = 3;
    float horizontalSpeed = .9f;
};

#endif // ENONPLAYABLEHITABLE_H
