#pragma once
#include "listener/listener.hpp"
#include <SFML/Audio.hpp>
#include "event/musicEvent.hpp"
#include <iostream>
class MusicListener : public EventListener
{
private:
    sf::Music m_music;
public:
    void onEventTrigger(const Event &event) override;
    bool shouldActOnEvent(const Event& event) const override;

    MusicListener() : EventListener("MusicListener") {};
};