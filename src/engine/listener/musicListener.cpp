#include "listener/musicListener.hpp"

bool MusicListener::shouldActOnEvent(const Event &event) const
{
    return event.getType() == EventType::MUSICEVENT;
}
void MusicListener::onEventTrigger(const Event &event)
{
    const auto& musicEvent = static_cast<const MusicEvent&>(event);
    if(musicEvent.play)
    {
        if(m_music.openFromFile(musicEvent.getFileName()))
        {
            m_music.play();
            m_music.setLooping(musicEvent.loop);
            std::cout << "Music file [" << musicEvent.getFileName() << "] loaded successfully!\n";
        }
        else
        {
            std::cout << "Music file [" << musicEvent.getFileName() << "] failed to load!\n";
        }
        
    }
    else
    {
        m_music.stop();
    }
}