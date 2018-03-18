#include <UpdateSystem.h>
#include <EventIds.h>
#include <Context.h>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

UpdateSystem::UpdateSystem()
{
}

UpdateSystem::~UpdateSystem()
{
}

void UpdateSystem::FixFrequency(int framesPerSecond)
{
    mSecBeforeUpdate = 1.f / framesPerSecond;
}

void UpdateSystem::Run()
{
    Context::Instance().GetEvents()->AddReceiver(EID::WinClose, this);
    Context::Instance().GetEvents()->AddReceiver(EID::System, this);

    sf::Clock clock;
    sf::Time elapsedTime;
    float deltaTime;
    while (!mStopCycle)
    {
        elapsedTime += clock.restart();
        deltaTime = elapsedTime.asSeconds();

        if (deltaTime < mSecBeforeUpdate)
        {
            continue;
        }

        NotifyAll(deltaTime);
        elapsedTime = sf::Time::Zero;
    }

    Context::Instance().GetEvents()->RemoveReceiver(EID::System, this);
    Context::Instance().GetEvents()->RemoveReceiver(EID::WinClose, this);
}

void UpdateSystem::NotifyAll(float data)
{
    for (auto& receiver : mReceivers)
    {
        if (receiver->IsUpdateEnabled())
        {
            receiver->OnUpdate(data);
        }
    }
}

void UpdateSystem::OnEvent(const std::pair<uint32_t, void*>& data)
{
    switch (data.first)
    {
    case EID::System:
        {
            sf::Event* systemEvent = reinterpret_cast<sf::Event*>(data.second);
            switch (systemEvent->type)
            {
            case sf::Event::Closed:
                break;
            //case sf::Event::KeyPressed:
            //    if (!systemEvent->key.alt || systemEvent->key.code != sf::Keyboard::F4)
            //        return;
            //    break;
            default:
                return;
            }
        }
    __fallthrough
    case EID::WinClose:
        mStopCycle = true;
        break;

    default:
        break;
    }
}
