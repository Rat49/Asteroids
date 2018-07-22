#include <Engine/RenderSystem.h>
#include <Engine/Context.h>
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sfe;

namespace
{
    const sf::String Title = { "Asteroids" };

    std::unique_ptr<sf::RenderWindow> s_renderWindow;
}


RenderSystem::RenderSystem()
{
#ifdef _DEBUG
    s_renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 480), Title, sf::Style::Default);
#else
    s_renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), Title, sf::Style::Default);
#endif
    Context::Instance().GetLogic()->SetWindow(s_renderWindow.get());
}

RenderSystem::~RenderSystem()
{
    s_renderWindow->close();
    s_renderWindow.reset(nullptr);
}

void RenderSystem::OnUpdate(float)
{
    s_renderWindow->clear();
    NotifyAll(*s_renderWindow);
    s_renderWindow->display();
}

void RenderSystem::NotifyAll(const sf::RenderTarget& target)
{
    auto& t = const_cast<sf::RenderTarget&>(target);
    for (auto& receiver : mReceivers)
    {
        if (receiver->IsRenderEnabled())
        {
            receiver->OnRender(t);
        }
    }
}
