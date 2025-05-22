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

int main()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode({1920,1080}), "QE");
    window->setFramerateLimit(144);
    auto bus = std::make_shared<EventBus>();

    auto screenManager = std::make_shared<ScreenManager>("Screen Manager");
    auto soundListener = std::make_shared<SoundListener>();
    auto musicListener = std::make_shared<MusicListener>();
    bus->registerListener(musicListener);
    bus->registerListener(soundListener);
    bus->registerListener(screenManager);
    std::shared_ptr<MenuScreen> mainMenu = std::make_shared<MenuScreen>(window, SCREEN_LABEL::MAIN_MENU, "menu/mainmenu.png", bus);
    std::shared_ptr<MenuScreen> saveScreen = std::make_shared<MenuScreen>(window, SCREEN_LABEL::SAVE_MENU, "settings/settings1.png", bus);
    std::shared_ptr<LevelScreen> levelScreen = std::make_shared<LevelScreen>(window, SCREEN_LABEL::LEVEL_SCREEN_1,"grid.png", bus);
    //std::shared_ptr<AnimatedScreen> pauseScreen = std::make_shared<AnimatedScreen>(SCREEN_LABEL::PAUSE_MENU, "./assets/settings", 0.5, window);
    std::shared_ptr<Event> event1 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::PAUSE_MENU);
    std::shared_ptr<Event> event2 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::LEVEL_SCREEN_1);
    std::shared_ptr<Event> event3 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::MAIN_MENU);

    //ScreenChangeEvent event3(SCREEN_LABEL::MAIN_MENU);
    mainMenu->createAndAddButtonToScreen("button/play_button_tmp.png", "Test Button!", 707, 684, 1, 1, 1, bus, event2);
    // pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 800, 400, 1, 1, 1, bus, event3);
    // pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 1500, 800, 1, 1, 1, bus, event2);

    screenManager->registerScreen(mainMenu);
    screenManager->registerScreen(saveScreen);
    screenManager->registerScreen(levelScreen);

    levelScreen->setMusic("track2.wav");
    //mainMenu->addScreenSprite("mainmenusprite1.png",200,400,1);

    screenManager->setScreen(mainMenu);

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