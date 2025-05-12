#include "listener/screenManager.hpp"
#include "event/screenEvent.hpp"




ScreenManager::~ScreenManager() = default;
void ScreenManager::setNextScreenAndChange(std::shared_ptr<Screen> screen)
{
    this->setNextScreen(screen);
    safeToChange = true;
}
void ScreenManager::setNextScreen(std::shared_ptr<Screen> screen)
{
    nextScreen = screen;
}
void ScreenManager::setNextScreenByLabel(SCREEN_LABEL label)
{
    if(screenRegistry.at(label))
    {
        nextScreen = screenRegistry.at(label);
        return;
    }
    std::cout << "Screen: " << labelToString(label) << " Not in screen registry! Please make sure it is registered before you call this!" << std::endl;
}
void ScreenManager::setScreen(std::shared_ptr<Screen> screen)
{
    currentScreen = screen;
}
void ScreenManager::updateScreen(float dt) 
{
    if(nextScreen && safeToChange)
    {
        currentScreen->onExit();
        currentScreen = nextScreen;
        currentScreen->onEnter();
        safeToChange = false;
    }
    currentScreen->update(dt);
}

void ScreenManager::renderScreen()
{
    if(currentScreen)
        currentScreen->renderWindow();
}

void ScreenManager::changeScreenToNext()
{
    safeToChange = true;
}

void ScreenManager::onEventTrigger(const std::shared_ptr<Event> &event)
{
    std::cout << "Event Triggered! Event Info: ";
    printf("[%s] | [%s]\n", triggerToString(event->getTrigger()).c_str(), typeToString(event->getType()).c_str());
    if (shouldActOnEvent(event)) // technically, this is already handled in the bus. remove this. this is bad.
    {
        auto screenEvent = std::static_pointer_cast<ScreenChangeEvent>(event);
        
        std::cout << "Setting next screen by label: " << labelToString(screenEvent->label);
        this->setNextScreenByLabel(screenEvent->label);
        std::cout << "Next screen by label set to: " << labelToString(this->getNextScreen()->getLabel());
        this->changeScreenToNext();
    }

}

bool ScreenManager::shouldActOnEvent(const std::shared_ptr<Event> &event) const
{
    return event->getType() == EventType::SCREEN_CHANGE;
}

std::shared_ptr<Screen> ScreenManager::getCurrentScreen()
{
    return currentScreen;
}
std::shared_ptr<Screen> ScreenManager::getNextScreen()
{
    return nextScreen;
}

void ScreenManager::registerScreen(std::shared_ptr<Screen> screenToRegister)
{
    screenRegistry.insert({screenToRegister->getLabel(), screenToRegister});
}
