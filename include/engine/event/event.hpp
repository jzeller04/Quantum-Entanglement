#pragma once
#include <string>

enum class EventType
{
    SCREEN_CHANGE,
    REGISTER,
    SOUNDEVENT,
    MUSICEVENT
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


    virtual EventType getType() const {return this->type;};
    virtual EventTrigger getTrigger() const {return this->trigger;};

    EventTrigger trigger;
    EventType type;
};


std::string triggerToString(EventTrigger trigger);
std::string typeToString(EventType type);