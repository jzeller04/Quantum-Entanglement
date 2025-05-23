#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <memory>
namespace qe
{
    // filename must be in assets/
    std::shared_ptr<sf::Texture> textureFromString(std::string fileName);

    bool leftClick();
    bool rightClick();

    bool withinBounds(float x1, float x2, float y1, float y2, std::shared_ptr<sf::RenderWindow> window);

    bool rightArrow();
    bool leftArrow();
    bool upArrow();
    bool downArrow();

    bool spaceBar();
}