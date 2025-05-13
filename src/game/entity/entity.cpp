#include "entity/entity.hpp"

void Entity::render(std::shared_ptr<sf::RenderWindow> &window)
{
    m_sprite->setPosition({x, y});
    m_sprite->setScale({scale, scale});
    m_sprite->setRotation(sf::Angle(rotationAngle));
    window->draw(*m_sprite);
}
void Entity::update(float dt)
{
    // collision shit, em field shit, etc
}