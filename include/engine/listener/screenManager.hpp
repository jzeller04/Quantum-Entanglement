#pragma once
#include "listener/listener.hpp"
#include <memory>
#include <screen/screen.hpp>
#include <iostream>
#include <unordered_map>
class ScreenManager : public EventListener
{
private:
    std::shared_ptr<Screen> currentScreen;
    std::shared_ptr<Screen> nextScreen;
    std::unordered_map<SCREEN_LABEL ,std::shared_ptr<Screen>> screenRegistry;
    bool safeToChange = false;
public:
    void setNextScreen(std::shared_ptr<Screen> screen);
    void setNextScreenAndChange(std::shared_ptr<Screen> screen);
    void setNextScreenByLabel(SCREEN_LABEL label);
    //only use on init.
    void setScreen(std::shared_ptr<Screen> screen);
    void updateScreen(float dt);
    void renderScreen();
    void changeScreenToNext();
    void onEventTrigger(const Event &event) override;
    bool shouldActOnEvent(const Event& event) const override;
    std::shared_ptr<Screen> getCurrentScreen();
    std::shared_ptr<Screen> getNextScreen();

    void registerScreen(std::shared_ptr<Screen> screenToRegister);

    ScreenManager(std::string name) : EventListener(name){};
    ~ScreenManager();

};