#pragma once
#include "listener/listener.hpp"
#include "SFML/Audio.hpp"
#include "event/soundEvent.hpp"
#include <iostream>
class SoundListener : public EventListener
{
private:
    std::shared_ptr<sf::Sound> m_sound = nullptr;
    sf::SoundBuffer m_buffer;
public:
    void onEventTrigger(const Event &event) override;
    bool shouldActOnEvent(const Event& event) const override;

    SoundListener() : EventListener("SoundListener") {};
};