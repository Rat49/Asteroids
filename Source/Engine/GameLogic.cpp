#include <Engine/GameLogic.h>
#include <Engine/Context.h>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>

using namespace sfe;

GameLogic::GameLogic()
{
}

GameLogic::~GameLogic()
{
}

void GameLogic::OnUpdate(float deltaTime)
{
    sf::Event systemEvent;
    if (mWindow != nullptr && mWindow->pollEvent(systemEvent))
    {
        Context::Instance().GetEvents()->Notify(EID::System, &systemEvent);
    }

    CustomUpdate(deltaTime);
}
