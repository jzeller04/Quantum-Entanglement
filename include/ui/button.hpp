#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;
    sf::Text buttonText;

    float m_xPos;
    float m_yPos;
public:
    Button(std::string fileTexture, std::string buttonText = "");
};