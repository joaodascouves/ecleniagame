#ifndef SCOMBAT_H
#define SCOMBAT_H

#include "sworld.h"
#include "epanel.h"

class SCombat : public SWorld
{
public:
    SCombat(ENonPlayableHitable*, ENonPlayableHitable*);

    virtual void update() override;
    virtual void controls() override {}

    EPanel* leftEPanel, *rightEPanel, *actionPanel;
    ENonPlayableHitable* challenger, *enemy;
};

#endif // SCOMBAT_H
