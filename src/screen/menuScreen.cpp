#include "screen/menuScreen.hpp"

MenuScreen::MenuScreen(std::shared_ptr<sf::RenderWindow> window) : backgroundSprite(backgroundTexture), Screen(SCREEN_LABEL::MAIN_MENU)
{
    //this->manager;
    this->window = window;
    std::cout << "Main Menu Screen Registered" << std::endl;
    //backgroundTexture.loadFromFile("./assets/testBackground.png", true);
    if(!backgroundTexture.loadFromFile("./assets/testBackground.png", true))
        std::cerr << "Error loading image" << std::endl;
    backgroundSprite.setTexture(backgroundTexture, true);
}
void MenuScreen::onEnter()
{

}
void MenuScreen::onExit()
{
    // set sprite/texture to default prob. Good for memory.
}

void MenuScreen::update(float dt)
{
    for(auto &button : buttons)
        button.update();
}

void MenuScreen::renderWindow()
{
    window->draw(backgroundSprite);
    for(auto buttonToDraw : buttons)
        buttonToDraw.drawButton();
}

void MenuScreen::handleEvent(const std::shared_ptr<Event> &event)
{
}

void MenuScreen::addButtonToScreen(Button button)
{
    buttons.emplace_back(button);
}

void MenuScreen::createAndAddButtonToScreen(const std::string &fileTexture, const std::string &buttonText, float xPos, float yPos, float xSize, float ySize, float scale, std::shared_ptr<EventBus> bus)
{
    Button newButton(fileTexture, buttonText, xPos, yPos, xSize, ySize, scale, bus, window);
    buttons.emplace_back(newButton);
}
