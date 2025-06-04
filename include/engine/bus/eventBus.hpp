#pragma once
#include <memory>
#include "listener/listener.hpp"
#include "event/event.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include "listener/lostEventListener.hpp"

class EventBus
{
private:
    std::vector<std::shared_ptr<EventListener>> m_eventListeners;
    std::queue<std::shared_ptr<Event>> m_eventQueue;
    std::unique_ptr<LostEventHandler> m_lostEventHandler;
public:
    EventBus();
    void registerListener(const std::shared_ptr<EventListener>& eventListener);
    void queueEvent(std::shared_ptr<Event> event);
    void releaseEvents();
};

