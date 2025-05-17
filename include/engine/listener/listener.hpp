#pragma once
#include <memory>
#include "event/event.hpp"
#include "string"

class EventListener
{
private:
    std::string m_registerName;
public:
    EventListener();
    EventListener(std::string name);
    virtual ~EventListener() = default;

    virtual void onEventTrigger(const Event& event) = 0;

    virtual bool shouldActOnEvent(const Event& event) const {return true;};

    std::string getName();
};
