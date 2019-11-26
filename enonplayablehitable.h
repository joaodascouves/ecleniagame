#ifndef ENONPLAYABLEHITABLE_H
#define ENONPLAYABLEHITABLE_H

#include "enonplayable.h"

class ENonPlayableHitable : public ENonPlayable
{
public:
    ENonPlayableHitable();
    ENonPlayableHitable(const ENonPlayableHitable&);

    virtual ~ENonPlayableHitable() override {}

    sf::Clock slapClock;

    virtual void moveLeft();
    virtual void moveRight();
    virtual void slap(ENonPlayableHitable*);

    unsigned short life = 3;
    float horizontalSpeed = .9f;
};

#endif // ENONPLAYABLEHITABLE_H
