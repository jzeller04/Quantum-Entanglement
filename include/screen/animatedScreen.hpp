#pragma once
#include "screen/screen.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <filesystem>
#include <memory>
class AnimatedScreen : public Screen
{
private:
    std::vector<std::shared_ptr<sf::Texture>> m_textures;
    sf::Sprite m_backgroundSprite;
    std::vector<std::string> getFileNamesInDirectory(const std::string& fileDir);
    float m_timeSinceLastFrame = 0.f;
    size_t m_currentFrame = 0;
    float m_frameDuration = 2.0f; // 2 seconds per frame
public:
    AnimatedScreen(SCREEN_LABEL label = SCREEN_LABEL::NO_LABEL, const std::string filePth = "", float frameTime = 2.0f);
    void loadTextures(std::string fileDir);
    void onEnter() override;
    void onExit() override;
    void update(float dt) override;
    void renderWindow(sf::RenderWindow &window) override;
    void handleEvent(const std::shared_ptr<Event> &event) override;
};