#pragma once
#include "entity/entity.hpp"

class PlayerEntity : public Entity
{
private:
    bool leftLastFrame = false;
    bool rightLastFrame = false;
public:
    PlayerEntity(const std::string &fileName) : Entity(fileName) {};
    virtual void update(float dt) override;
};