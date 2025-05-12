#include "event/event.hpp"
#include "event/testEvent.hpp"
#include "listener/testListener.hpp"
#include <iostream>
#include "bus/eventBus.hpp"
#include <SFML/Graphics.hpp>
#include <listener/screenManager.hpp>
#include "screen/menuScreen.hpp"
#include <SFML/Window.hpp>
#include <screen/gameScreen.hpp>
#include <SFML/Graphics.hpp>
#include "screen/animatedScreen.hpp"
#include "event/screenEvent.hpp"

int main()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode({1920,1080}), "QE");
    window->setFramerateLimit(144);
    auto bus = std::make_shared<EventBus>();

    auto screenManager = std::make_shared<ScreenManager>("Screen Manager");
    bus->registerListener(screenManager);
    std::shared_ptr<MenuScreen> mainMenu = std::make_shared<MenuScreen>(window, SCREEN_LABEL::MAIN_MENU, "testBackground.png");
    std::shared_ptr<MenuScreen> pauseScreen = std::make_shared<MenuScreen>(window, SCREEN_LABEL::SETTINGS_MENU, "settings/settings1.png");
    //std::shared_ptr<AnimatedScreen> pauseScreen = std::make_shared<AnimatedScreen>(SCREEN_LABEL::PAUSE_MENU, "./assets/settings", 0.5, window);
    auto testEvent = std::make_shared<TestEvent>(EventTrigger::RIGHT_CLICK, EventType::SOUNDEVENT);
    mainMenu->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 100, 100, 1, 1, 1, bus, std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::SETTINGS_MENU));
    pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 800, 100, 1, 1, 1, bus, std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::MAIN_MENU));
    pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 1500, 800, 1, 1, 1, bus, testEvent);

    screenManager->registerScreen(mainMenu);
    screenManager->registerScreen(pauseScreen);

    screenManager->setScreen(mainMenu);

    bool leftClickHandle = true; // this could most definetely be a handler class of some kind. Im going to need more than just one handler.
    sf::Clock clock;
    while (window->isOpen())
    {
        float dt = clock.restart().asSeconds();
        //std::cout << (int)dt.asSeconds() << std::endl;
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }
        bus->releaseEvents();

        window->clear();
        screenManager->renderScreen();
        screenManager->updateScreen(dt);

        window->display();
    }
}