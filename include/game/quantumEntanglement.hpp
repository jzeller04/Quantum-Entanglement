#pragma once
#include "event/event.hpp"
#include "event/testEvent.hpp"
#include "listener/testListener.hpp"
#include <iostream>
#include "bus/eventBus.hpp"
#include <SFML/Graphics.hpp>
#include <listener/screenManager.hpp>
#include "screen/menuScreen.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "screen/animatedScreen.hpp"
#include "event/screenEvent.hpp"
#include "level/levelScreen.hpp"
#include "entity/player/playerEntity.hpp"
#include "listener/soundListener.hpp"
#include "listener/musicListener.hpp"
#include "save/playerData/playerData.hpp"


class QuantumEntanglement
{
private:
    std::shared_ptr<qe::PlayerData> m_playerSave;
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<EventBus> m_bus;
    sf::Clock m_clock;
    std::shared_ptr<ScreenManager> m_screenManager;
public:
    QuantumEntanglement();
    void init();
    void run();
    ~QuantumEntanglement() = default;
};