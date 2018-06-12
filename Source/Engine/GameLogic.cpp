#include <Engine/GameLogic.h>
#include <Engine/Context.h>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>

GameLogic::GameLogic()
{
}

GameLogic::~GameLogic()
{
}

void GameLogic::OnUpdate(float)
{
    if (mWindow == nullptr)
    {
        return;
    }

    sf::Event systemEvent;
    if (!mWindow->pollEvent(systemEvent))
    {
        return;
    }

    Context::Instance().GetEvents()->Notify(EID::System, &systemEvent);
}
