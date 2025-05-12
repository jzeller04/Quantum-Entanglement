#pragma once
#include <iostream>
#include <memory>
#include "event/event.hpp"
class LostEventHandler
{
private:

public:
    LostEventHandler();
    void printEventInfo(const std::shared_ptr<Event> &event);
};