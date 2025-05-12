#pragma once
#include <string>

enum class EventType
{
    SCREEN_CHANGE,
    REGISTER,
    SOUNDEVENT
};

enum class EventTrigger
{
    LEFT_CLICK,
    RIGHT_CLICK,
    BUS_REGISTER,
    BUTTON

};

class Event 
{
public:
    virtual ~Event() = default;
    Event() = default;

    EventTrigger trigger;
    EventType type;

    virtual EventType getType() const {return this->type;};
    virtual EventTrigger getTrigger() const {return this->trigger;};

};


std::string triggerToString(EventTrigger trigger);
std::string typeToString(EventType type);