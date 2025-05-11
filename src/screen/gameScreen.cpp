#include "screen/gameScreen.hpp"
GameScreen::GameScreen() : backgroundSprite(backgroundTexture), Screen(SCREEN_LABEL::PAUSE_MENU)
{
    std::cout << "Game Screen Registered" << std::endl;
    //backgroundTexture.loadFromFile("./assets/test2Background.png", true);
    if(!backgroundTexture.loadFromFile("./assets/test2Background.png", true))
        std::cerr << "Error loading image" << std::endl;
    backgroundSprite.setTexture(backgroundTexture, true);
}
void GameScreen::onEnter()
{

}
void GameScreen::onExit()
{
    // set sprite/texture to default prob. Good for memory.
}

void GameScreen::update(float dt)
{
    
}

void GameScreen::renderWindow()
{
    window->draw(backgroundSprite);
}

void GameScreen::handleEvent(const std::shared_ptr<Event> &event)
{
}
