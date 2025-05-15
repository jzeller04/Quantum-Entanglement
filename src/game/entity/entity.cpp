#include "entity/entity.hpp"


Entity::Entity() : 
    m_texture(std::make_shared<sf::Texture>())
{
    x = 100;
    y = 100;
    rotationAngle = sf::degrees(0);
    scale = 1;
}
Entity::Entity(std::string fileTexture) : 
    m_texture(std::make_shared<sf::Texture>())
{
    x = 100;
    y = 100;
    rotationAngle = sf::degrees(0);
    scale = 1;
    std::cout << "Entity Creating...";
    m_texture->loadFromFile(fileTexture);
    m_sprite = std::make_shared<sf::Sprite>(*m_texture);
    std::cout << " Created!" << std::endl;
}
void Entity::render(std::shared_ptr<sf::RenderWindow> &window)
{
    m_sprite->setPosition({x, y});
    m_sprite->setScale({scale, scale});
    m_sprite->setRotation(rotationAngle);
    window->draw(*m_sprite);
}
void Entity::update(float dt)
{
    x++;
}