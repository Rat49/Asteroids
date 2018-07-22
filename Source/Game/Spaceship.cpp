#include <Game/Spaceship.h>
#include <Game/InputGameAction.h>
#include <Engine/Context.h>
#include <Engine/VectorMath.h>


SpaceShip::SpaceShip() : RenderMethod(), UpdateMethod()
{
    mShape.setRadius(100.f);
    mShape.setOutlineColor(sf::Color::Green);
    mShape.setFillColor(sf::Color::Magenta);
    mShape.setPosition(100, 100);
    mShape.setOrigin(50, 50);
    mRenderEnabled = true;
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::OnRender(sf::RenderTarget& data)
{
    data.draw(mShape);
}

void SpaceShip::OnUpdate(float deltaTime)
{
    sfe::InputSystem* input = sfe::Context::Instance().GetInput();
    sf::Vector2f movement;
    bool shooting = input->IsPressed(GameAction::Shoot);

    if (input->IsPressed(GameAction::MoveLeft))
    {
        movement.x -= 100;
    }
    if (input->IsPressed(GameAction::MoveRight))
    {
        movement.x += 100;
    }
    if (input->IsPressed(GameAction::MoveDown))
    {
        movement.y += 100;
    }
    if (input->IsPressed(GameAction::MoveUp))
    {
        movement.y -= 100;
    }
    if (shooting)
    {
        mShape.setOutlineColor(sf::Color::Yellow);
    }
    else
    {
        mShape.setOutlineColor(sf::Color::Blue);
    }

    movement *= deltaTime;
    mShape.move(movement);
}
