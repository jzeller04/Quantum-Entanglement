#pragma once
#include <memory>
#include "screen/screen.hpp"
#include <vector>


class Entity; // tdl

class LevelScreen : Screen
{
private:
    std::vector<std::shared_ptr<Entity>> m_entities;
    std::shared_ptr<sf::Texture> m_backgroundTexture;
    std::shared_ptr<sf::Sprite> m_backgroundSprite = nullptr;

    void load();

    // implement leveldata
public:
    LevelScreen(std::shared_ptr<sf::RenderWindow> window, SCREEN_LABEL label, const std::string &fileName);
    void update(float dt) override;
    void onEnter() override;
    void onExit() override;
    void renderWindow() override;
    void handleEvent(const std::shared_ptr<Event> &event) override;
    void addEntity();
};