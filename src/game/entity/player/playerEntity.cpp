#include "entity/player/playerEntity.hpp"
#include "util/util.hpp"
void PlayerEntity::update(float dt) 
{
    // all game moving logic
    if (qe::upArrow())
        yvelocity -= (0.05f + m_speed);

    if (qe::downArrow())
        yvelocity += (0.05f + m_speed);

    if (qe::leftArrow()) {
        xvelocity -= (0.05f + m_speed);
        if (!leftLastFrame) xscale = -1;
    }

    if (qe::rightArrow()) {
        xvelocity += (0.05f + m_speed);
        if (!rightLastFrame) xscale = 1;
    }

    if (qe::spaceBar() && !dashOnCooldown) {
        x += xvelocity * 30; // mess with this... make it feel better. check pressing keys? mix of them both?
        y += yvelocity * 30;
        dashOnCooldown = true;
        // fuck with velocity and jumping at some point
        // xvelocity = 0;
        // yvelocity = 0;
    }

    // closer to 0, less friction
    float friction = 0.5f + m_friction;
    xvelocity -= friction * xvelocity * dt;
    yvelocity -= friction * yvelocity * dt;

    // Apply motion
    x += xvelocity;
    y += yvelocity;
    if(!qe::spaceBar())
        dashOnCooldown = false;

}
void PlayerEntity::setStats(const qe::Stats &stats)
{
    m_speed = stats.speed;
    m_size = stats.size;
}
//