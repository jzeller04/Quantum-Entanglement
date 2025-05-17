#include "entity/player/playerEntity.hpp"
#include "util/util.hpp"
void PlayerEntity::update(float dt)
{
    // all game moving logic
    if(qe::upArrow())
    {
        //y = (y - 5) + yvelocity;
        yvelocity -= 0.05;
        yvelocity -= yvelocity*dt;
    }

    if(qe::downArrow())
    {
        //y = (y + 5) + yvelocity;
        yvelocity += 0.05;
        yvelocity += yvelocity*dt;
    }
       
     if (qe::leftArrow())
    {
        //x = (x - 5) + xvelocity;
        xvelocity -= 0.05;
        xvelocity -= xvelocity*dt;
        if (!leftLastFrame)
        {
            xscale = -1; // Flip left

            // Adjust origin if needed:
            //m_sprite->setOrigin(m_sprite->getLocalBounds().size.x);
        }
    }

    if (qe::rightArrow())
    {
        //x = (x + 5) + xvelocity;
        xvelocity += 0.05;
        xvelocity += xvelocity*dt;
        if (!rightLastFrame)
        {
            xscale = 1;
        }
    }
    if(qe::spaceBar())
    {
        x = 960;
        y = 540;
    }
        
    
    y += yvelocity;
    x += xvelocity;

    // Update previous frame values
    leftLastFrame = qe::leftArrow();
    rightLastFrame = qe::rightArrow();
}

