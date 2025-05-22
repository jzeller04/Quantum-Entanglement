#include "screen/menuScreen.hpp"

MenuScreen::MenuScreen(std::shared_ptr<sf::RenderWindow> window, SCREEN_LABEL label, const std::string &fileName, std::shared_ptr<EventBus> eventBus) : backgroundSprite(backgroundTexture), Screen(label, eventBus)
{
    //this->manager;
    this->window = window;
    std::cout << "Menu screen registered: [" << labelToString(label) << "]" << std::endl;
    //backgroundTexture.loadFromFile("./assets/testBackground.png", true);
    if(!backgroundTexture.loadFromFile("./assets/" + fileName))
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
    for(auto sprites : m_xtraSprites)
        window->draw(*sprites);
}

void MenuScreen::handleEvent(const std::shared_ptr<Event> &event)
{
}

void MenuScreen::addButtonToScreen(Button button)
{
    buttons.emplace_back(button);
}

void MenuScreen::createAndAddButtonToScreen(const std::string &fileTexture, const std::string &buttonText, float xPos, float yPos, float xSize, float ySize, float scale, std::shared_ptr<EventBus> bus, std::shared_ptr<Event> buttonEvent)
{
    Button newButton(fileTexture, buttonText, xPos, yPos, xSize, ySize, scale, bus, window, buttonEvent);
    buttons.emplace_back(newButton);
}

void MenuScreen::addScreenSprite(const std::string &filename, float x, float y, float scale)
{
    std::shared_ptr<sf::Texture> newTexture = std::make_shared<sf::Texture>();
    if (newTexture->loadFromFile("./assets/menu/" + filename))
    {
        m_xtraTextures.emplace_back(newTexture); // <- Keep texture alive (thank you gippity! was unaware of this pointer interaction...)
        auto newSprite = std::make_shared<sf::Sprite>(*newTexture);
        newSprite->setPosition({x,y});
        newSprite->setScale({scale,scale});
        m_xtraSprites.emplace_back(newSprite);
    }
    else
    {
        std::cout << "Image: [" << filename << "] failed to load!" << std::endl;
    }
}
