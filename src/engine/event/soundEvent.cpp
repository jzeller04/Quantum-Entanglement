#include "event/soundEvent.hpp"

std::string SoundEvent::getFileName() const
{
    return this->filename;
}

SoundEvent::SoundEvent(std::string filename) : filename("./assets/sound/" + filename)
{
    this->type = EventType::SOUNDEVENT;
}