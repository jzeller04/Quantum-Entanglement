#pragma once
#include "screen/screen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ui/button.hpp"

class MenuScreen : public Screen
{
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite; // sprite loads onto texture
    std::vector<Button> buttons;
public:
    MenuScreen(std::shared_ptr<sf::RenderWindow> window);
    void onEnter() override;
    void onExit() override;
    void update(float dt) override;
    void renderWindow() override;
    void handleEvent(const std::shared_ptr<Event> &event) override;
    void addButtonToScreen(Button button);
    void createAndAddButtonToScreen(std::string fileTexture, std::string buttonText = "", float xPos = 0, float yPos = 0, float xSize = 0, float ySize = 0, float scale = 1, std::shared_ptr<EventBus> bus = nullptr);
};