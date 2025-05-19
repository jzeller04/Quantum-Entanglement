#pragma once
#include "event/soundEvent.hpp"

class MusicEvent : public Event
{
private:
    std::string filename;
public:
    bool loop = true;
    bool play = true;
    bool stop = false;

    MusicEvent(std::string filename);
    std::string getFileName() const;
};