#include "level/levelScreen.hpp"

void LevelScreen::load()
{
}
LevelScreen::LevelScreen(std::shared_ptr<sf::RenderWindow> window, SCREEN_LABEL label, const std::string &fileName, std::shared_ptr<EventBus> eventBus) : Screen(label, eventBus),
      m_backgroundTexture(std::make_shared<sf::Texture>())
{
    std::cout << "Level Screen creating...";
    if (!m_backgroundTexture->loadFromFile("./assets/level/background/" + fileName)) {
        std::cerr << "Failed to load background texture!" << std::endl;
        // You might want to handle the failure more gracefully.
    }
    m_backgroundTexture->setRepeated(true);
    m_backgroundSprite = std::make_shared<sf::Sprite>(*m_backgroundTexture);
    //this->m_backgroundSprite->setTexture(*m_backgroundTexture);
    this->window = window;
    std::cout<< " Created!" << std::endl;


    // may want to have a seperate class for this so i can do more shit with it... in fact yeah not that im thinkin about it that is what im gonna need to do. TDL!!!!!


    map = sf::RectangleShape(sf::Vector2f(256000,144000));
    map.setTexture(m_backgroundTexture.get());
    map.setTextureRect(sf::IntRect({0,0},{256000,144000}));
}

void LevelScreen::update(float dt)
{
    for(auto &entities : m_entities)
        entities->update(dt);
    m_player->update(dt);
}

void LevelScreen::renderWindow(std::shared_ptr<sf::View> camera)
{
    camera->setCenter(m_player->getPos());
    window->draw(map);
    for(auto &entities : m_entities)
        entities->render(window);
    m_player->render(window);
}
void LevelScreen::addEntity(std::shared_ptr<Entity> entityToAdd)
{
    m_entities.emplace_back(entityToAdd);
}

void LevelScreen::onEnter()
{
    this->m_player = std::make_shared<PlayerEntity>("./assets/entity/player/playerDefault.png");
}
void LevelScreen::onExit()
{
    
}
void LevelScreen::handleEvent(const std::shared_ptr<Event> &event)
{

}