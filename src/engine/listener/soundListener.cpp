#include "listener/soundListener.hpp"

bool SoundListener::shouldActOnEvent(const Event& event) const
{
    return event.getType() == EventType::SOUNDEVENT;
}

void SoundListener::onEventTrigger(const Event &event)
{
    const auto& soundEvent = static_cast<const SoundEvent&>(event);
    if(m_buffer.loadFromFile(soundEvent.getFileName()))
    {
        this->m_sound = std::make_shared<sf::Sound>(m_buffer);
        m_sound->play();
        //m_sound.reset();
    }
    else
    {
        std::cout << "Error loading file: " << soundEvent.getFileName() << std::endl;
    }

}