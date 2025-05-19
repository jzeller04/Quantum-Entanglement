#pragma once
#include "event/event.hpp"


class SoundEvent : public Event
{
private:
    std::string filename;
public:
    SoundEvent(std::string filename);
    std::string getFileName() const;

    // maybe add setter if need?
};