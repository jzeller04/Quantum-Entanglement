#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "event/event.hpp"
#include <iostream>
#include <string>
#include "ui/button.hpp"
#include "event/musicEvent.hpp"

enum class SCREEN_LABEL
{
    MAIN_MENU,
    PAUSE_MENU,
    SETTINGS_MENU,
    LEVEL_SCREEN_1,
    NO_LABEL

};

class Screen
{
private:
    SCREEN_LABEL label;
    std::shared_ptr<MusicEvent> m_music;
public:
    virtual void onEnter() = 0; // handle all init rendering
    virtual void onExit() = 0; // handle destruction of everything that was on the screen if its not still being used
    virtual void handleEvent(const std::shared_ptr<Event> &event) = 0;
    virtual void update(float dt) = 0;
    virtual void renderWindow() = 0;  // use in onEnter  
    SCREEN_LABEL getLabel();
    virtual void playMusic();
    virtual ~Screen();
    Screen(SCREEN_LABEL label, std::shared_ptr<EventBus> eventBus);
    void setMusic(std::shared_ptr<MusicEvent> musicEvent);
    
protected:
    std::shared_ptr<EventBus> bus;
    std::shared_ptr<sf::RenderWindow> window;
};

std::string labelToString(SCREEN_LABEL label);


