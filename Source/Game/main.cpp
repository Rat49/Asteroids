#include <Engine/Context.h>
#include <Game/InputGameAction.h>
#include <Game/AsteroidsLogic.h>

#ifdef _WINDOWS
#include <Windows.h>
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
    /// INIT SCREEN
    sfe::Context::Instance().GetUpdate()->FixFrequency(75);

    /// INIT KEYBOARD
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveUp, sf::Keyboard::W);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveUp, sf::Keyboard::Up);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveDown, sf::Keyboard::S);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveDown, sf::Keyboard::Down);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveLeft, sf::Keyboard::A);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveLeft, sf::Keyboard::Left);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveRight, sf::Keyboard::D);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::MoveRight, sf::Keyboard::Right);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::Shoot, sf::Keyboard::Space);
    sfe::Context::Instance().GetInput()->BindAction(GameAction::Menu, sf::Keyboard::Escape);

    /// GAME LOGIC
    auto logic = std::make_unique<AsteroidsLogic>();
    logic->Start();

    /// MAIN CYCLE
    sfe::Context::Instance().GetUpdate()->Run();
    return 0;
}
