#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "util/util.hpp"
#include <iostream>
#include "bus/eventBus.hpp"
#include "event/testEvent.hpp"

class Button
{
private:
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;
    sf::Text buttonText;

    std::shared_ptr<EventBus> bus;
    std::shared_ptr<sf::RenderWindow> window;

    float m_xPos;
    float m_yPos;

    void sendButtonEvent();
public:
    // Button(std::string fileTexture, std::string buttonText = "");
    Button(std::string fileTexture, std::string buttonText, float xPos, float yPos, float xSize, float ySize, float scale, std::shared_ptr<EventBus> bus);
    void createButton(std::string fileTexture, std::string buttonText = "", float xPos = 0, float yPos = 0, float xSize = 0, float ySize = 0, float scale = 1);
    void drawButton();
    bool onLeftClick();
    bool onRightClick();
    void update();
};