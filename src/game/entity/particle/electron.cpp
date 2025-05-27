#include "entity/particle/electron.hpp"

void ElectronEntity::render(std::shared_ptr<sf::RenderWindow> &window)
{
    if(!defined)
        this->rotationAngle = sf::degrees(90);
            
     Entity::render(window);
}
void ElectronEntity::tasks(const sf::Vector2f &pos)
{
    int randN = rand() % 10 + 1;
    if(randN > 6)
    {
        std::cout << randN << std::endl;
        defined = false;
    }
    else
    {
        std::cout << randN << std::endl;
        defined = true;
    }

    // set init spawn point
    this->x = pos.x;
    this->y = pos.y;
}

ElectronEntity::ElectronEntity(const std::string &filename, const sf::Vector2f &pos) : Entity(filename)
{
    this->tasks(pos);
}