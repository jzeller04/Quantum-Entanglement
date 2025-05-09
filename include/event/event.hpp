#pragma once
#include <string>

enum class EventType
{
    SCREEN_CHANGE,
    REGISTER
};

enum class EventTrigger
{
    LEFT_CLICK,
    RIGHT_CLICK,
    BUS_REGISTER

};

class Event 
{
public:
    virtual ~Event() = default;
    Event() = default;

    EventTrigger trigger;
    EventType type;

    virtual EventType getType() const = 0;
    virtual EventTrigger getTrigger() const = 0;

};


std::string triggerToString(EventTrigger trigger);
std::string typeToString(EventType type);