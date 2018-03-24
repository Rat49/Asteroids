#include <Context.h>
#include <InputGameAction.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class AsteroidsLogic : sfe::GameLogic
{
public:
	void CustomUpdate(float deltaTime) override
	{
	}
};

void WinMain()
{
	sf::String Title = { "Asteroids" };
	std::shared_ptr<sf::RenderWindow> wnd;

#ifdef _DEBUG
	wnd = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), Title, sf::Style::Default);
#else
	wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), Title, sf::Style::Fullscreen);
#endif
	Context::GetRender()->SetWindow(wnd);

	//init update
    Context::GetUpdate()->FixFrequency(75);

	//init input
    Context::GetInput()->BindAction(GameAction::MoveUp, sf::Keyboard::W);
    Context::GetInput()->BindAction(GameAction::MoveUp, sf::Keyboard::Up);
    Context::GetInput()->BindAction(GameAction::MoveDown, sf::Keyboard::S);
    Context::GetInput()->BindAction(GameAction::MoveDown, sf::Keyboard::Down);
    Context::GetInput()->BindAction(GameAction::MoveLeft, sf::Keyboard::A);
    Context::GetInput()->BindAction(GameAction::MoveLeft, sf::Keyboard::Left);
    Context::GetInput()->BindAction(GameAction::MoveRight, sf::Keyboard::D);
    Context::GetInput()->BindAction(GameAction::MoveRight, sf::Keyboard::Right);
    Context::GetInput()->BindAction(GameAction::Shoot, sf::Keyboard::Space);
    Context::GetInput()->BindAction(GameAction::Menu, sf::Keyboard::Escape);

	AsteroidsLogic logic;

	//start update
    Context::GetUpdate()->Run();
}
