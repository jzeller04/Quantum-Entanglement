#include "event/testEvent.hpp"


TestEvent::TestEvent(EventTrigger trigger, EventType type)
{
    this->trigger = trigger;
    this->type = type;
    this->data = 888;
}

uint32_t TestEvent::getData()
{
    return data;
}
EventType TestEvent::getType() const
{
    return this->type;
}

EventTrigger TestEvent::getTrigger() const
{
    return this->trigger;
}
