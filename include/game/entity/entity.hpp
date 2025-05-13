#pragma once
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Entity
{
private:
    float x;
    float y;
    float scale;
    sf::Angle rotationAngle;
    std::shared_ptr<sf::Texture> m_texture;
    std::shared_ptr<sf::Sprite> m_sprite;
public:
    virtual void update(float dt);
    virtual void render(std::shared_ptr<sf::RenderWindow> &window);
};
