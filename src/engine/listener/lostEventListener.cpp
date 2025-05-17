#include "listener/lostEventListener.hpp"

void LostEventHandler::printEventInfo(const Event &event)
{
    std::cout << "Event caught in lost event handler! Event info: [" << triggerToString(event.trigger) << "]" << "[" << typeToString << "]" << std::endl;
}
LostEventHandler::LostEventHandler()
{
}