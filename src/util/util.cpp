#include "util/util.hpp"

std::shared_ptr<sf::Texture> qe::textureFromString(std::string fileName)
{
    auto returnTexture = std::make_shared<sf::Texture>();
    if (!returnTexture->loadFromFile("./assets/"+fileName)) {
        std::cerr << "Failed to load texture: " << fileName << "\n";
    }
    return returnTexture;
}
bool qe::leftClick()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}
bool qe::rightClick()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
}
bool qe::withinBounds(float x1, float x2, float y1, float y2, std::shared_ptr<sf::RenderWindow> window)
{
    int xPos = sf::Mouse::getPosition(*window).x;
    int yPos = sf::Mouse::getPosition(*window).y;
    return (xPos > x1 && xPos < x2) && (yPos > y1 && yPos < y2);
}