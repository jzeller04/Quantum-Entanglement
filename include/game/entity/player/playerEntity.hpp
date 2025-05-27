#pragma once
#include "entity/entity.hpp"
#include "save/playerData/playerData.hpp"

class PlayerEntity : public Entity
{
private:
    bool leftLastFrame = false;
    bool rightLastFrame = false;
    bool dashOnCooldown = false;
    int m_speed = 0; // these are additive to the already base speed/size/fric
    int m_size = 0;
    int m_friction = 0;
public:
    PlayerEntity(const std::string &fileName) : Entity(fileName) {};
    void setStats(const qe::Stats &stats);
    virtual void update(float dt) override;
};