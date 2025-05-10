#include "ui/button.hpp"

sf::Font myFont("./assets/font/Inconsolata-VariableFont_wdth,wght.ttf");
void Button::createButton(std::string fileTexture, std::string buttonText, float xPos, float yPos, float xSize, float ySize, float scale)
{
    sf::Texture texture = qe::textureFromString(fileTexture);
    buttonSprite.setTexture(texture);
    this->buttonText.setString(buttonText);
    this->buttonText.setPosition({xPos, yPos});
    this->buttonText.setScale({xSize, ySize});
    buttonSprite.setPosition({xPos, yPos});
    buttonSprite.setScale({xSize, ySize});
}

void Button::drawButton()
{
    window->draw(buttonSprite);
    window->draw(buttonText);
}
Button::Button(std::string fileTexture, std::string buttonText, float xPos, float yPos, float xSize, float ySize, float scale, std::shared_ptr<EventBus> bus) : buttonTexture(qe::textureFromString(fileTexture)), buttonSprite(buttonTexture), buttonText(myFont)
{
    this->bus = bus;
    this->buttonSprite.setTexture(buttonTexture);
    this->buttonText.setString(buttonText);
    this->buttonText.setPosition({xPos, yPos});
    this->buttonText.setScale({xSize, ySize});
    this->buttonText.setFillColor(sf::Color(00000));
    buttonSprite.setPosition({xPos, yPos});
    buttonSprite.setScale({xSize, ySize});
}

bool Button::onLeftClick()
{
    return qe::leftClick() && qe::withinBounds(buttonSprite.getPosition().x, buttonSprite.getPosition().x + buttonTexture.getSize().x, buttonSprite.getPosition().y, buttonSprite.getPosition().x + buttonTexture.getSize().y, *window);
}

void Button::sendButtonEvent()
{
    bus->queueEvent(std::make_shared<TestEvent>(EventTrigger::LEFT_CLICK, EventType::SCREEN_CHANGE));
}