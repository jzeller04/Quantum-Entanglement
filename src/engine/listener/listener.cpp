#include "listener/listener.hpp"

EventListener::EventListener()
{
    m_registerName = "Mystery Listener";
}

EventListener::EventListener(std::string name)
{
    m_registerName = name;
}

std::string EventListener::getName()
{
    return this->m_registerName;
}