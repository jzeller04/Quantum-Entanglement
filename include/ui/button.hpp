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
    std::shared_ptr<sf::Texture> buttonTexture;
    sf::Sprite buttonSprite;
    //sf::Text buttonText;

    std::shared_ptr<EventBus> bus;
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<Event> buttonEvent;


    float m_xPos;
    float m_yPos;

    void sendButtonEvent();
public:
    // file name for texture, button text, xPos, yPos, xSize, ySize, scale, eventBus, window
    Button(const std::string &fileTexture, const std::string &buttonText, float xPos, float yPos, float xSize, float ySize, float scale, std::shared_ptr<EventBus> bus, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Event> buttonEvent );
    void createButton(std::string fileTexture, std::string buttonText = "", float xPos = 0, float yPos = 0, float xSize = 0, float ySize = 0, float scale = 1);
    virtual void drawButton();
    virtual bool onLeftClick();
    virtual bool onRightClick();
    virtual void update();
    void sendButtonScreenChangeEvent();
};