#pragma once
#include <SFML/Graphics.hpp>
#include "event/event.hpp"
#include <memory>
class TestEvent : public Event
{
private:
    int data;
public:
    TestEvent(EventTrigger trigger, EventType type);
    uint32_t getData();
    virtual EventType getType() const override;
    virtual EventTrigger getTrigger() const override;
};