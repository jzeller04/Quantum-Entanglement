#include "screen/screen.hpp"


Screen::Screen(SCREEN_LABEL label, std::shared_ptr<EventBus> eventBus)
{
    this->label = label;
    this->bus = eventBus;
    m_music = std::make_shared<MusicEvent>("track1.wav");
}
SCREEN_LABEL Screen::getLabel()
{
    return this->label;
}
Screen::~Screen()
{
    std::cout << "Screen destroyed" << std::endl;
}
std::string labelToString(SCREEN_LABEL label)
{
    switch (label)
    {
    case SCREEN_LABEL::MAIN_MENU: return "MAIN_MENU"; break;
    case SCREEN_LABEL::PAUSE_MENU: return "PAUSE_MENU"; break;
    case SCREEN_LABEL::SETTINGS_MENU: return "SETTINGS_MENU"; break;
    case SCREEN_LABEL::LEVEL_SCREEN_1: return "LEVEL_SCREEN_1"; break;
    
    default: return "NO_LABEL"; break;

    }
}
void Screen::setMusic(std::shared_ptr<MusicEvent> musicEvent)
{
    this->m_music = musicEvent;
}
void Screen::playMusic()
{
    bus->queueEvent(m_music);
}


