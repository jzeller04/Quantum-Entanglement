#include "util/util.hpp"

sf::Texture qe::textureFromString(std::string fileName)
{
    sf::Texture returnTexture;
    returnTexture.loadFromFile("./assets/" + fileName);
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
bool qe::withinBounds(float x1, float x2, float y1, float y2, sf::Window &window)
{
    int xPos = sf::Mouse::getPosition(window).x;
    int yPos = sf::Mouse::getPosition(window).y;
    return (xPos > x1 && xPos < x2) && (yPos > y1 && yPos < y2);
}