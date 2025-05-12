#include "event/screenEvent.hpp"

ScreenChangeEvent::ScreenChangeEvent()
{
    this->label = SCREEN_LABEL::NO_LABEL;
    this->type = EventType::SCREEN_CHANGE;
}

ScreenChangeEvent::ScreenChangeEvent(SCREEN_LABEL label)
{
    this->label = label;
}
ScreenChangeEvent::ScreenChangeEvent(std::shared_ptr<Event> event)
{
    this->trigger = event->getTrigger();
    this->type = EventType::SCREEN_CHANGE; 
}