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
    //std::shared_ptr<ScreenManager> manager;
public:
    MenuScreen(std::shared_ptr<sf::RenderWindow> window, SCREEN_LABEL label, const std::string &fileName);
    void onEnter() override;
    void onExit() override;
    void update(float dt) override;
    void renderWindow() override;
    void handleEvent(const std::shared_ptr<Event> &event) override;
    void addButtonToScreen(Button button);
    void createAndAddButtonToScreen(const std::string &fileTexture, const std::string &buttonText, float xPos, float yPos, float xSize, float ySize, float scale, std::shared_ptr<EventBus> bus, std::shared_ptr<Event> buttonEvent);
};