#ifndef ES1BANSHEE_H
#define ES1BANSHEE_H

#include "enonplayable.h"
#include "edialogbox.h"

class ES1Banshee : public ENonPlayable
{
public:
    ES1Banshee();
    virtual ~ES1Banshee(){}

    virtual void _update();
    virtual void action(Entity*);

    EDialogBox* dialogBox;
};

#endif // ES1BANSHEE_H
