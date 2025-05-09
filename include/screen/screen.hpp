#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "event/event.hpp"
#include <iostream>
#include <string>

enum class SCREEN_LABEL
{
    MAIN_MENU,
    PAUSE_MENU,
    SETTINGS_MENU,

};

class Screen
{
private:
    SCREEN_LABEL label;
public:
    virtual void onEnter() = 0; // handle all init rendering
    virtual void onExit() = 0; // handle destruction of everything that was on the screen if its not still being used
    virtual void handleEvent(const std::shared_ptr<Event> &event) = 0;
    virtual void update(float dt) = 0;
    virtual void renderWindow(sf::RenderWindow &window) = 0;  // use in onEnter  
    SCREEN_LABEL getLabel();
    virtual ~Screen();
    Screen(SCREEN_LABEL label);
};

std::string labelToString(SCREEN_LABEL label);


