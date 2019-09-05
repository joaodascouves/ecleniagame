#include "sworld.h"

SWorld::SWorld()
{
    worldView.setSize(800.f, 600.f);
    worldView.setCenter(400.f, 300.f);
}

void SWorld::draw(const float dt)
{
    for( auto& e : worldEntities )
        GameInstance::get().window.draw(*e);
}

void SWorld::update(const float dt)
{
    //
}
