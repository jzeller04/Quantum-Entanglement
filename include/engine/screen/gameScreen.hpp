#pragma once
#include "screen/screen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class GameScreen : public Screen
{
private:
    std::shared_ptr<sf::Texture> backgroundTexture;
    sf::Sprite backgroundSprite; // sprite loads onto texture
public:
    GameScreen();
    void onEnter() override;
    void onExit() override;
    void update(float dt) override;
    void renderWindow() override;
    void handleEvent(const std::shared_ptr<Event> &event) override;
};