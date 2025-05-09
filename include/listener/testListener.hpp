#pragma once
#include "listener/listener.hpp"

class TestListener : public EventListener
{
private:
    int data;
public:
    TestListener(int data);
    int getListenerData();
    void onEventTrigger(const std::shared_ptr<Event>& event) override;
    bool shouldActOnEvent(const std::shared_ptr<Event> &event) const override;
};