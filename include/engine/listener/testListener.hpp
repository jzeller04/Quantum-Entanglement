#pragma once
#include "listener/listener.hpp"
#include <vector>
#include <SFML/Audio.hpp>
class TestListener : public EventListener
{
private:
    int data;
public:
    TestListener(int data);
    int getListenerData();
    void onEventTrigger(const Event& event) override;
    bool shouldActOnEvent(const Event &event) const override;
};

