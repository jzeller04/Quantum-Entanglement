#include "event/screenEvent.hpp"

ScreenChangeEvent::ScreenChangeEvent()
{
    this->label = SCREEN_LABEL::NO_LABEL;
    this->type = EventType::SCREEN_CHANGE;
    std::cout << "Created Screen Change Event! : Label: " << labelToString(label) << std::endl;
}

ScreenChangeEvent::ScreenChangeEvent(SCREEN_LABEL label)
{
    this->label = label;
    this->type = EventType::SCREEN_CHANGE;
    std::cout << "Created Screen Change Event! : Label: " << labelToString(label) << std::endl;
}
ScreenChangeEvent::ScreenChangeEvent(const Event& event)
{
    this->trigger = event.getTrigger();
    this->type = EventType::SCREEN_CHANGE; 
}