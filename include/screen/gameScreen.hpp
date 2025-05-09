#pragma once
#include "screen/screen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class GameScreen : public Screen
{
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite; // sprite loads onto texture
public:
    GameScreen();
    void onEnter() override;
    void onExit() override;
    void update(float dt) override;
    void renderWindow(sf::RenderWindow &window) override;
    void handleEvent(const std::shared_ptr<Event> &event) override;
};