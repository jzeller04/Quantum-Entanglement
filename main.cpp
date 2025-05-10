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

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920,1080}), "QE");
    window.setFramerateLimit(144);
    EventBus bus;

    auto screenManager = std::make_shared<ScreenManager>("Screen Manager");
    bus.registerListener(screenManager);
    std::shared_ptr<MenuScreen> mainMenu = std::make_shared<MenuScreen>();
    std::shared_ptr<AnimatedScreen> pauseScreen = std::make_shared<AnimatedScreen>(SCREEN_LABEL::PAUSE_MENU, "./assets/settings", 0.01);

    mainMenu->createAndAddButtonToScreen("testButton.png", "Test Button!", 100, 100, 1, 1, 1, std::make_shared<EventBus>(bus));

    screenManager->registerScreen(mainMenu);
    screenManager->registerScreen(pauseScreen);

    screenManager->setScreen(mainMenu);

    bool leftClickHandle = true; // this could most definetely be a handler class of some kind. Im going to need more than just one handler.
    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        //std::cout << (int)dt.asSeconds() << std::endl;
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        bus.releaseEvents();

        window.clear();
        screenManager->renderScreen(window);
        screenManager->updateScreen(dt);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && leftClickHandle)
        {
            auto screenChangeEvent = std::make_shared<TestEvent>(EventTrigger::LEFT_CLICK, EventType::SCREEN_CHANGE);
            bus.queueEvent(screenChangeEvent);
            leftClickHandle = false;
            if(screenManager->getCurrentScreen() == mainMenu)
            {
                auto gameMenu = std::make_shared<GameScreen>();
                screenManager->setNextScreenByLabel(SCREEN_LABEL::PAUSE_MENU);
            }
            if(screenManager->getCurrentScreen() != mainMenu)
                screenManager->setNextScreenByLabel(SCREEN_LABEL::MAIN_MENU);
        }
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            leftClickHandle = true;

        //window.draw(shape);
        window.display();
    }
}