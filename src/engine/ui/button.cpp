#include "ui/button.hpp"

sf::Font myFont("./assets/font/Inconsolata-VariableFont_wdth,wght.ttf");
void Button::createButton(std::string fileTexture, std::string buttonText, float xPos, float yPos, float xSize, float ySize, float scale)
{
    auto texture = qe::textureFromString(fileTexture);
    buttonSprite.setTexture(*texture);
    //this->buttonText.setString(buttonText);
    //this->buttonText.setPosition({xPos, yPos});
    //this->buttonText.setScale({xSize, ySize});
    buttonSprite.setPosition({xPos, yPos});
    buttonSprite.setScale({xSize, ySize});
}

void Button::drawButton()
{
    //window->draw(buttonText);
    window->draw(buttonSprite);
}
Button::Button(const std::string &fileTexture, const std::string &buttonText, float xPos, float yPos, float xSize, float ySize, float scale, std::shared_ptr<EventBus> bus, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Event> buttonEvent) : buttonTexture(qe::textureFromString(fileTexture)), buttonSprite(*buttonTexture)//, buttonText(myFont)
{
    this->buttonEvent = buttonEvent;
    this->window = window;
    this->bus = bus;
    this->buttonSprite.setTexture(*buttonTexture);
    //this->buttonText.setString(buttonText);
    //this->buttonText.setPosition({xPos, yPos});
    //this->buttonText.setScale({xSize, ySize});
    //this->buttonText.setFillColor(sf::Color(00000));
    buttonSprite.setPosition({xPos, yPos});
    buttonSprite.setScale({xSize, ySize});
}

bool Button::onLeftClick() // rename this shit
{
    return (qe::leftClick() && !pressedLastFrame) && qe::withinBounds(buttonSprite.getPosition().x, buttonSprite.getPosition().x + buttonTexture->getSize().x, buttonSprite.getPosition().y, buttonSprite.getPosition().y + buttonTexture->getSize().y, window);
}

void Button::sendButtonEvent()
{
    bus->queueEvent(buttonEvent);
}
void Button::sendButtonScreenChangeEvent()
{
    std::cout << "Sending button event to event bus..." << std::endl;
    if(buttonEvent)
    {
        bus->queueEvent(buttonEvent);
        std::cout << "Button event sent to bus! " << typeToString(buttonEvent->type) << std::endl;
    }

}
void Button::update()
{
    if(this->onLeftClick())
    {
        // if(buttonEvent->type == EventType::SCREEN_CHANGE)
                this->sendButtonEvent();
    }
    pressedLastFrame = qe::leftClick();

}
bool Button::onRightClick()
{
    return false;
}