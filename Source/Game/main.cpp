#include <Context.h>

void WinMain()
{
    Context::Instance().GetUpdate()->FixFrequency(75);

    Context::Instance().GetInput()->BindAction(GameAction::MoveUp, sf::Keyboard::W);
    Context::Instance().GetInput()->BindAction(GameAction::MoveUp, sf::Keyboard::Up);
    Context::Instance().GetInput()->BindAction(GameAction::MoveDown, sf::Keyboard::S);
    Context::Instance().GetInput()->BindAction(GameAction::MoveDown, sf::Keyboard::Down);
    Context::Instance().GetInput()->BindAction(GameAction::MoveLeft, sf::Keyboard::A);
    Context::Instance().GetInput()->BindAction(GameAction::MoveLeft, sf::Keyboard::Left);
    Context::Instance().GetInput()->BindAction(GameAction::MoveRight, sf::Keyboard::D);
    Context::Instance().GetInput()->BindAction(GameAction::MoveRight, sf::Keyboard::Right);
    Context::Instance().GetInput()->BindAction(GameAction::Shoot, sf::Keyboard::Space);
    Context::Instance().GetInput()->BindAction(GameAction::Menu, sf::Keyboard::Escape);


    Context::Instance().GetUpdate()->Run();
}
