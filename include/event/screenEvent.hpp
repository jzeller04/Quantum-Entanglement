#include "event/event.hpp"
#include "screen/screen.hpp"

class ScreenChangeEvent : public Event
{
public:
    ScreenChangeEvent();
    ScreenChangeEvent(SCREEN_LABEL label);
    SCREEN_LABEL label;
};