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
#include "level/levelScreen.hpp"
#include "entity/player/playerEntity.hpp"
int main()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode({1920,1080}), "QE");
    window->setFramerateLimit(144);
    auto bus = std::make_shared<EventBus>();

    auto screenManager = std::make_shared<ScreenManager>("Screen Manager");
    bus->registerListener(screenManager);
    std::shared_ptr<MenuScreen> mainMenu = std::make_shared<MenuScreen>(window, SCREEN_LABEL::MAIN_MENU, "menu/mainmenu.png");
    std::shared_ptr<MenuScreen> pauseScreen = std::make_shared<MenuScreen>(window, SCREEN_LABEL::PAUSE_MENU, "settings/settings1.png");
    std::shared_ptr<LevelScreen> levelScreen = std::make_shared<LevelScreen>(window, SCREEN_LABEL::LEVEL_SCREEN_1,"grid.png");
    //std::shared_ptr<AnimatedScreen> pauseScreen = std::make_shared<AnimatedScreen>(SCREEN_LABEL::PAUSE_MENU, "./assets/settings", 0.5, window);
    std::shared_ptr<Event> event1 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::PAUSE_MENU);
    std::shared_ptr<Event> event2 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::LEVEL_SCREEN_1);
    std::shared_ptr<Event> event3 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::MAIN_MENU);

    //ScreenChangeEvent event3(SCREEN_LABEL::MAIN_MENU);
    mainMenu->createAndAddButtonToScreen("button/play_button.png", "Test Button!", 960, 400, 1, 1, 1, bus, event2);
    // pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 800, 400, 1, 1, 1, bus, event3);
    // pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 1500, 800, 1, 1, 1, bus, event2);

    screenManager->registerScreen(mainMenu);
    screenManager->registerScreen(pauseScreen);
    screenManager->registerScreen(levelScreen);

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