#include "screen/animatedScreen.hpp"
sf::Texture temp("./assets/pause/pause1.png");
AnimatedScreen::AnimatedScreen(SCREEN_LABEL label, const std::string filePth, float frameTime, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventBus> eventbus) : Screen(label, eventbus), m_frameDuration(frameTime), m_backgroundSprite(temp)
{
    this->window = window;
    loadTextures(filePth);
    if (!m_textures.empty())
        m_backgroundSprite.setTexture(*m_textures[0]);  // Set after textures are loaded
    else
        std::cerr << "No textures loaded for AnimatedScreen!\n";
}
void AnimatedScreen::loadTextures(std::string fileDir)
{
    for(const auto& fileName : getFileNamesInDirectory(fileDir))
    {
        auto texture = std::make_shared<sf::Texture>();
        if(texture->loadFromFile(fileName))
        {
            std::cout << "Loaded texture from file: " << fileName << std::endl;
            m_textures.push_back(texture);
            
        }
        else
        {
            std::cerr << "Failed to load texture from file: " << fileName << std::endl;
        }

    }
}
std::vector<std::string> AnimatedScreen::getFileNamesInDirectory(const std::string &fileDir)
{
    std::vector<std::string> fileNames;

    for(const auto &file : std::filesystem::directory_iterator(fileDir))
    {
        if(file.is_regular_file())
            fileNames.emplace_back(file.path().string());
    }
    return fileNames;
}
void AnimatedScreen::onEnter()
{

}
void AnimatedScreen::onExit()
{
    // set sprite/texture to default prob. Good for memory.
}
void AnimatedScreen::update(float dt)
{
    m_timeSinceLastFrame += dt;

    if (m_timeSinceLastFrame >= m_frameDuration)
    {
        m_timeSinceLastFrame = 0.f;
        m_currentFrame = (m_currentFrame + 1) % m_textures.size();
        m_backgroundSprite.setTexture(*m_textures[m_currentFrame]);
    }
}

void AnimatedScreen::renderWindow(std::shared_ptr<sf::View> camera)
{
    window->draw(m_backgroundSprite);
}

void AnimatedScreen::handleEvent(const std::shared_ptr<Event> &event)
{
}
