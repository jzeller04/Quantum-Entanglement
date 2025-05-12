#include "event/event.hpp"

std::string triggerToString(EventTrigger trigger)
{
    switch (trigger)
    {
    case EventTrigger::LEFT_CLICK: return "LEFT_CLICK"; break;
    case EventTrigger::RIGHT_CLICK: return "RIGHT_CLICK"; break;
    case EventTrigger::BUS_REGISTER: return "BUS REGISTER"; break;
    default:
        return "NO_TRIGGER";
        break;
    }
}

std::string typeToString(EventType type)
{
    switch (type)
    {
    case EventType::SCREEN_CHANGE: return "SCREEN_CHANGE"; break;
    case EventType::REGISTER: return "REGISTER"; break;
        
    default:
        return "NO_TYPE";
        break;
    }
}


