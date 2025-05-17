#include "listener/testListener.hpp"
#include "event/event.hpp"
#include "event/testEvent.hpp"
#include <iostream>
TestListener::TestListener(int data)
{
    this->data = data;
}
int TestListener::getListenerData()
{
    return data;
}
void TestListener::onEventTrigger(const Event &event)
{
    std::cout << "Hello from event bus!" << std::endl;
}
bool TestListener::shouldActOnEvent(const Event &event) const
{
    return event.getTrigger() == EventTrigger::BUS_REGISTER;
}