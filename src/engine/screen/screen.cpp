#include "screen/screen.hpp"


Screen::Screen(SCREEN_LABEL label)
{
    this->label = label;
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


