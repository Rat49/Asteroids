#include <GameLogic.h>
#include <Context.h>
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
	auto wnd = Context::GetRender()->GetWindow();
	if (!wnd)
	{
		return;
	}

	CustomUpdate(deltaTime);

	sf::Event systemEvent;
	if (!wnd->pollEvent(systemEvent))
	{
		return;
	}

	Context::GetEvents()->Notify(EID::System, &systemEvent);
}

void GameLogic::CustomUpdate(float)
{
}
