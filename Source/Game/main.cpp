#include <Engine/Context.h>
#include <Game/InputGameAction.h>
#include <Game/Spaceship.h>

#ifdef _WINDOWS
#include <Windows.h>
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
    /// INIT SCREEN
    Context::Instance().GetUpdate()->FixFrequency(75);

    /// INIT KEYBOARD
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

    /// GAME OBJECTS
    auto main_character = std::make_unique<SpaceShip>();

    /// MAIN CYCLE
    Context::Instance().GetUpdate()->Run();
    return 0;
}
