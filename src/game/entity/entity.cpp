#include "entity/entity.hpp"


Entity::Entity() : 
    m_texture(std::make_shared<sf::Texture>())
{
    x = 100;
    y = 100;
    rotationAngle = sf::degrees(0);
    xscale = 1;
    yscale = 1;
}
Entity::Entity(std::string fileTexture) : 
    m_texture(std::make_shared<sf::Texture>())
{
    x = 100; // need entity spawning logic
    y = 100;
    rotationAngle = sf::degrees(0);
    xscale = 1;
    yscale = 1;
    std::cout << "Entity Creating...";
    if(m_texture->loadFromFile(fileTexture))
    {
        std::cout << "File: [" << fileTexture << "] Loaded successfully" << std::endl;
        m_sprite = std::make_shared<sf::Sprite>(*m_texture);
    }
    else
    {
        std::cout << "File: [" << fileTexture << "] failed to load successfully" << std::endl;
    }

    std::cout << " Created!" << std::endl;
}
void Entity::render(std::shared_ptr<sf::RenderWindow> &window)
{
    m_sprite->setPosition({x, y});
    m_sprite->setScale({xscale, yscale});
    sf::FloatRect bounds = m_sprite->getLocalBounds();
    if (xscale == -1)
        m_sprite->setOrigin({bounds.size.x, bounds.size.y / 2.f});
    else
        m_sprite->setOrigin({0, bounds.size.y / 2.f});
        m_sprite->setRotation(rotationAngle);
    window->draw(*m_sprite);
}
void Entity::update(float dt)
{
    x += .5;
    y += .5;
}

sf::Vector2f Entity::getPos()
{
    return {this->x, this->y};
}