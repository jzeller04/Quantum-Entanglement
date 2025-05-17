#pragma once
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Entity
{
private:

    std::shared_ptr<sf::Texture> m_texture = nullptr;

public:
    Entity();
    Entity(std::string fileTexture);
    virtual void update(float dt);
    void render(std::shared_ptr<sf::RenderWindow> &window);
    void flip(int flip);
    void undoFlip();
    // virtual void enter();
    // virtual void exit();
protected:
    float x;
    float y;
    float xscale;
    float yscale;
    sf::Angle rotationAngle;
    std::shared_ptr<sf::Sprite> m_sprite = nullptr;
    float xvelocity = 0;
    float yvelocity = 0;
};
