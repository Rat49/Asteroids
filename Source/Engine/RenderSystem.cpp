#include <RenderSystem.h>
#include <Context.h>
#include <memory>

using namespace sfe;

RenderSystem::RenderSystem()
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::OnUpdate(float deltaTime)
{
	mRenderWindow->clear();
	NotifyAll(*mRenderWindow);
	mRenderWindow->display();
}

void RenderSystem::NotifyAll(const sf::RenderTarget& target)
{
    for (auto& receiver : mReceivers)
    {
        if (receiver->IsRenderEnabled())
        {
            receiver->OnRender(target);
        }
    }
}

void RenderSystem::SetWindow(std::shared_ptr<sf::RenderWindow> wnd)
{
	mRenderWindow = wnd;
}