#include "entity/player/playerEntity.hpp"
#include "util/util.hpp"
void PlayerEntity::update(float dt)
{
    // all game moving logic
    if (qe::upArrow())
        yvelocity -= 0.05f;

    if (qe::downArrow())
        yvelocity += 0.05f;

    if (qe::leftArrow()) {
        xvelocity -= 0.05f;
        if (!leftLastFrame) xscale = -1;
    }

    if (qe::rightArrow()) {
        xvelocity += 0.05f;
        if (!rightLastFrame) xscale = 1;
    }

    if (qe::spaceBar()) {
        x = 960;
        y = 540;
        xvelocity = 0;
        yvelocity = 0;
    }

    // closer to 1, less friction
    float friction = 1.0f;
    xvelocity -= friction * xvelocity * dt;
    yvelocity -= friction * yvelocity * dt;

    // Apply motion
    x += xvelocity;
    y += yvelocity;

}

