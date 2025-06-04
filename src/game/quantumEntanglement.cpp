#include "quantumEntanglement.hpp"

QuantumEntanglement::QuantumEntanglement()
{
    srand(time(NULL));
    qe::PlayerData newData;
    qe::loadPlayerData(newData);
    newData.lastPlayed = "gsfdgs";
    newData.saveName = "test save";
    newData.timeCreated = "now";
    newData.playerStats.size = 1;
    newData.playerStats.speed = 1;
    newData.progress.energy = 57248572485;
    newData.progress.threshholds.emplace_back(qe::Threshholds::START);
    newData.progress.worth = 452453245; 
    qe::savePlayerData(newData);
    m_playerSave = std::make_shared<qe::PlayerData>(newData);

    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode({2560,1440}), "QE");
    m_window->setFramerateLimit(144);
    m_bus = std::make_shared<EventBus>();

    m_camera = std::make_shared<sf::View>(sf::FloatRect({0,0},{2560,1440}));

    m_screenManager = std::make_shared<ScreenManager>("Screen Manager", m_camera);
    auto soundListener = std::make_shared<SoundListener>();
    auto musicListener = std::make_shared<MusicListener>();
    m_bus->registerListener(musicListener);
    m_bus->registerListener(soundListener);
    m_bus->registerListener(m_screenManager);
    std::shared_ptr<MenuScreen> mainMenu = std::make_shared<MenuScreen>(m_window, SCREEN_LABEL::MAIN_MENU, "menu/mainmenu.png", m_bus);
    std::shared_ptr<MenuScreen> saveScreen = std::make_shared<MenuScreen>(m_window, SCREEN_LABEL::SAVE_MENU, "settings/settings1.png", m_bus);
    std::shared_ptr<LevelScreen> levelScreen = std::make_shared<LevelScreen>(m_window, SCREEN_LABEL::LEVEL_SCREEN_1,"grid.png", m_bus);
    //std::shared_ptr<AnimatedScreen> pauseScreen = std::make_shared<AnimatedScreen>(SCREEN_LABEL::PAUSE_MENU, "./assets/settings", 0.5, window);
    std::shared_ptr<Event> event1 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::SAVE_MENU);
    std::shared_ptr<Event> event2 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::LEVEL_SCREEN_1);
    std::shared_ptr<Event> event3 = std::make_shared<ScreenChangeEvent>(SCREEN_LABEL::MAIN_MENU);
    std::shared_ptr<Event> saveEvent = std::make_shared<Event>();

    //ScreenChangeEvent event3(SCREEN_LABEL::MAIN_MENU);
    mainMenu->createAndAddButtonToScreen("button/play_button_tmp.png", "Test Button!", 707, 684, 1, 1, 1, m_bus, event1);
    // pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 800, 400, 1, 1, 1, bus, event3);
    // pauseScreen->createAndAddButtonToScreen("button/testButton.png", "Test Button!", 1500, 800, 1, 1, 1, bus, event2);
    saveScreen->createAndAddButtonToScreen("button/testButton.png","",400,400,1,1,1, m_bus, event2);


    for(int i = 0; i < 50; i++)
    {
        auto entitytoadd = std::make_shared<ElectronEntity>("./assets/entity/player/playerDefault.png", sf::Vector2f(500 + i*90,500+i*120));
        levelScreen->addEntity(entitytoadd);
    }



    m_screenManager->registerScreen(mainMenu);
    m_screenManager->registerScreen(saveScreen);
    m_screenManager->registerScreen(levelScreen);

    levelScreen->setMusic("track2.wav");
    //mainMenu->addScreenSprite("mainmenusprite1.png",200,400,1);

    m_screenManager->setScreen(mainMenu);

}

void QuantumEntanglement::run()
{
    while (m_window->isOpen())
    {
        float dt = m_clock.restart().asSeconds();
        //std::cout << (int)dt.asSeconds() << std::endl;
        while (const std::optional event = m_window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                m_window->close();
        }
        m_bus->releaseEvents();


        m_window->clear();
        m_window->setView(*m_camera);
        m_screenManager->renderScreen();
        m_screenManager->updateScreen(dt);

        m_window->display();
    }
}
