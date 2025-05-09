#pragma once
#include <memory>
#include "listener/listener.hpp"
#include "event/event.hpp"
#include <vector>
#include <queue>
#include <iostream>

class EventBus
{
private:
    std::vector<std::shared_ptr<EventListener>> m_eventListeners;
    std::queue<std::shared_ptr<Event>> m_eventQueue;
public:
    EventBus();
    void registerListener(const std::shared_ptr<EventListener>& eventListener);
    void queueEvent(const std::shared_ptr<Event> &event);
    void releaseEvents();
};
