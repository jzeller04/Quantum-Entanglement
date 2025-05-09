#include "screen/mainMenuScreen.hpp"
MainMenuScreen::MainMenuScreen() : backgroundSprite(backgroundTexture), Screen(SCREEN_LABEL::MAIN_MENU)
{
    
    std::cout << "Main Menu Screen Registered" << std::endl;
    //backgroundTexture.loadFromFile("./assets/testBackground.png", true);
    if(!backgroundTexture.loadFromFile("./assets/testBackground.png", true))
        std::cerr << "Error loading image" << std::endl;
    backgroundSprite.setTexture(backgroundTexture, true);
}
void MainMenuScreen::onEnter()
{

}
void MainMenuScreen::onExit()
{
    // set sprite/texture to default prob. Good for memory.
}

void MainMenuScreen::update(float dt)
{
}

void MainMenuScreen::renderWindow(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
}

void MainMenuScreen::handleEvent(const std::shared_ptr<Event> &event)
{
}
