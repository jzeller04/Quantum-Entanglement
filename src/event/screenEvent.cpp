#include "event/screenEvent.hpp"

ScreenChangeEvent::ScreenChangeEvent()
{
    this->label = SCREEN_LABEL::NO_LABEL;
}

ScreenChangeEvent::ScreenChangeEvent(SCREEN_LABEL label)
{
    this->label = label;
}