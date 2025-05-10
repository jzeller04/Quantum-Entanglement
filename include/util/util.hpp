#pragma once
#include <SFML/Graphics.hpp>
#include <string>
namespace qe
{
    // filename must be in assets/button
    sf::Texture textureFromString(std::string fileName);

    bool leftClick();
    bool rightClick();

    bool withinBounds(float x1, float x2, float y1, float y2, sf::Window &window);
}