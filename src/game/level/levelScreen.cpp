#include "level/levelScreen.hpp"

void LevelScreen::load()
{
}
LevelScreen::LevelScreen(std::shared_ptr<sf::RenderWindow> window, SCREEN_LABEL label, const std::string &fileName) : Screen(label)
{
    this->m_backgroundTexture->loadFromFile("./assets/level/background/" + fileName);
    this->m_backgroundSprite->setTexture(*m_backgroundTexture);
    this->window = window;
}