#include "event/event.hpp"
#include "event/testEvent.hpp"
#include "listener/testListener.hpp"
#include <iostream>
#include "bus/eventBus.hpp"
#include <SFML/Graphics.hpp>
#include <listener/screenManager.hpp>
#include "screen/mainMenuScreen.hpp"
#include <SFML/Window.hpp>
#include <screen/gameScreen.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920,1080}), "QE");
    window.setFramerateLimit(144);
    EventBus bus;

    auto screenManager = std::make_shared<ScreenManager>("Screen Manager");
    bus.registerListener(screenManager);
    std::shared_ptr<Screen> mainMenu = std::make_shared<MainMenuScreen>();

    screenManager->registerScreen(mainMenu);

    screenManager->setScreen(mainMenu);
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    bool leftClickHandle = true; // this could most definetely be a handler class of some kind. Im going to need more than just one handler.
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        bus.releaseEvents();

        window.clear();
        screenManager->renderScreen(window);
        screenManager->updateScreen(1.0f/60.0f);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && leftClickHandle)
        {
            auto screenChangeEvent = std::make_shared<TestEvent>(EventTrigger::LEFT_CLICK, EventType::SCREEN_CHANGE);
            bus.queueEvent(screenChangeEvent);
            leftClickHandle = false;
            if(screenManager->getCurrentScreen() == mainMenu)
            {
                auto gameMenu = std::make_shared<GameScreen>();
                screenManager->setNextScreenAndChange(gameMenu);
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