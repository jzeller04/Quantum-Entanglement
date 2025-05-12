#include "bus/eventBus.hpp"
#include "event/testEvent.hpp"
#include "listener/testListener.hpp"

EventBus::EventBus()
{
    m_eventListeners.reserve(100);
    this->m_lostEventHandler = std::make_unique<LostEventHandler>();
    //TestListener busListener(0);
    auto busListener = std::make_shared<TestListener>(0);
    auto busEvent = std::make_shared<TestEvent>(EventTrigger::BUS_REGISTER, EventType::REGISTER);
    m_eventListeners.emplace_back(busListener);
    m_eventQueue.push(busEvent);
}

void EventBus::registerListener(const std::shared_ptr<EventListener> &eventListener)
{
    m_eventListeners.emplace_back(eventListener);
    std::cout << "Registered: " << eventListener->getName() << std::endl;
}

void EventBus::queueEvent(const std::shared_ptr<Event> &event)
{
    m_eventQueue.push(event);
}

void EventBus::releaseEvents()
{
    while ((!m_eventQueue.empty()))
    {
        auto event = m_eventQueue.front(); // store and then pop
        m_eventQueue.pop();
        std::cout << "Releasing event: [" << typeToString(event->type) << "] [" << triggerToString(event->trigger) << "]" << std::endl;
        bool lost = true;
        for(auto& listener : m_eventListeners)
        {
            if(listener->shouldActOnEvent(event))
            {
                lost = false;
                listener->onEventTrigger(event);
                std::cout << "Triggering event: [" << typeToString(event->type) << "] [" << triggerToString(event->trigger) << "]" << std::endl;
            }

        }
        if(lost)
        {
            m_lostEventHandler->printEventInfo(event);
        }
        
    }
    
}
