#pragma once
#include "entity/entity.hpp"
#include <ctime>

class ElectronEntity : public Entity
{
private:
    bool defined; // for QE shit
    void tasks(const sf::Vector2f &pos); // rename ts!!!

public:
    ElectronEntity(const std::string &filename, const sf::Vector2f &pos);
    //void update(float dt) override;
    void render(std::shared_ptr<sf::RenderWindow> &window) override;

};