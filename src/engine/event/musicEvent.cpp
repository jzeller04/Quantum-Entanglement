#include "event/musicEvent.hpp"

MusicEvent::MusicEvent(std::string filename) : filename("./assets/sound/music/" + filename)
{
    this->type = EventType::MUSICEVENT;
}
std::string MusicEvent::getFileName() const
{
    return this->filename;
}