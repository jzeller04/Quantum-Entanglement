#include "level/levelScreen.hpp"

void LevelScreen::load()
{
}
LevelScreen::LevelScreen(std::shared_ptr<sf::RenderWindow> window, SCREEN_LABEL label, const std::string &fileName) : Screen(label),
      m_backgroundTexture(std::make_shared<sf::Texture>())
{
    std::cout << "Level Screen creating...";
    if (!m_backgroundTexture->loadFromFile("./assets/level/background/" + fileName)) {
        std::cerr << "Failed to load background texture!" << std::endl;
        // You might want to handle the failure more gracefully.
    }
    m_backgroundSprite = std::make_shared<sf::Sprite>(*m_backgroundTexture);
    //this->m_backgroundSprite->setTexture(*m_backgroundTexture);
    this->window = window;
    std::cout<< " Created!" << std::endl;
}

void LevelScreen::update(float dt)
{
    for(auto &entities : m_entities)
        entities->update(dt);
}

void LevelScreen::renderWindow()
{
    window->draw(*m_backgroundSprite);
    for(auto &entities : m_entities)
        entities->render(window);
}
void LevelScreen::addEntity(std::shared_ptr<Entity> entityToAdd)
{
    m_entities.emplace_back(entityToAdd);
}

void LevelScreen::onEnter()
{

}
void LevelScreen::onExit()
{
    
}
void LevelScreen::handleEvent(const std::shared_ptr<Event> &event)
{

}