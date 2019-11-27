#ifndef SCOMBAT_H
#define SCOMBAT_H

#include "sworld.h"
#include "epanel.h"

class SCombat : public SWorld
{
public:
    SCombat(ENonPlayableHitable*, ENonPlayableHitable*);
    ~SCombat() override = default;

    virtual void update() override;
    virtual void controls() override {}

    EPanel* leftPanel, *rightPanel, *actionPanel;
    ENonPlayableHitable* challenger, *enemy;
};

#endif // SCOMBAT_H
