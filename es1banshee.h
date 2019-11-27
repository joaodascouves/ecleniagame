#ifndef ES1BANSHEE_H
#define ES1BANSHEE_H

#include "enonplayable.h"
#include "edialogbox.h"

class ES1Banshee : public ENonPlayable
{
public:
    ES1Banshee();
    ~ES1Banshee() override = default;

    virtual void _update() override;
    virtual void action(Entity*) override;

    EDialogBox* dialogBox;
};

#endif // ES1BANSHEE_H
