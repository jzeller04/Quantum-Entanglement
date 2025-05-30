#include "listener/screenManager.hpp"
#include "event/screenEvent.hpp"




ScreenManager::~ScreenManager() = default;
void ScreenManager::setNextScreenAndChange(const std::shared_ptr<Screen> &screen)
{
    this->setNextScreen(screen);
    safeToChange = true;
}
void ScreenManager::setNextScreen(const std::shared_ptr<Screen> &screen)
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
void ScreenManager::setScreen(const std::shared_ptr<Screen> &screen)
{
    currentScreen = screen;
    currentScreen->playMusic();
}
void ScreenManager::updateScreen(float dt) 
{
    if(nextScreen && safeToChange)
    {
        currentScreen->onExit();
        currentScreen = nextScreen;
        currentScreen->onEnter();
        nextScreen->playMusic();
        safeToChange = false;
    }
    currentScreen->update(dt);
}

void ScreenManager::renderScreen()
{
    if(currentScreen)
        currentScreen->renderWindow(m_camera);
}

void ScreenManager::changeScreenToNext()
{
    safeToChange = true;
}

void ScreenManager::onEventTrigger(const Event &event)
{
    std::cout << "Event Triggered! Event Info: ";
    printf("[%s] | [%s]\n", triggerToString(event.getTrigger()).c_str(), typeToString(event.getType()).c_str());
    if (shouldActOnEvent(event)) // technically, this is already handled in the bus. remove this. this is bad.
    {
        const auto& screenEvent = static_cast<const ScreenChangeEvent&>(event);
                std::cout << "Setting next screen by label: " << labelToString(screenEvent.label) << std::endl;
                this->setNextScreenByLabel(screenEvent.label);
                std::cout << "Next screen by label set to: " << labelToString(this->getNextScreen()->getLabel()) << std::endl;
                this->changeScreenToNext();   
    }

}

bool ScreenManager::shouldActOnEvent(const Event &event) const
{
    return event.getType() == EventType::SCREEN_CHANGE;
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
