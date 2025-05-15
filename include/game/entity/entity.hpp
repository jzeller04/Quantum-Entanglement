#pragma once
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Entity
{
private:
    float x;
    float y;
    float scale;
    sf::Angle rotationAngle;
    std::shared_ptr<sf::Texture> m_texture = nullptr;
    std::shared_ptr<sf::Sprite> m_sprite = nullptr;
public:
    Entity();
    Entity(std::string fileTexture);
    virtual void update(float dt);
    virtual void render(std::shared_ptr<sf::RenderWindow> &window);
    // virtual void enter();
    // virtual void exit();
};
