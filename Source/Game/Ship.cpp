#include <Game/Ship.h>
#include <Game/InputGameAction.h>
#include <Engine/Context.h>
#include <SFML/Window/Window.hpp>
#include <cassert>

namespace
{
    float GetActionNum(int32_t action)
    {
        return sfe::Context::Instance().GetInput()->IsPressed(action) ? 1.f : 0.f;
    }

    sfe::Vector2<float> GetMovement()
    {
        sfe::Vector2<float> result(
            GetActionNum(GameAction::MoveRight) - GetActionNum(GameAction::MoveLeft),
            GetActionNum(GameAction::MoveDown) - GetActionNum(GameAction::MoveUp));
        return result;
    }

    float MaxSpeed = 500;
    float AccumSpeed = 50;
    float BreakSpeed = 10;
}

Ship::Ship()
    : UpdateMethod(), PhysicsMethod(), RenderMethod(), mCollider(mShape)
{
    auto center = sfe::Context::Instance().GetLogic()->GetWindow()->getSize();
    auto loadResult = mTex.loadFromFile("Resources/ship.png");
    assert(loadResult && "Can't load ship texture");

    mShape.setTexture(mTex);
    mShape.setScale(0.1f, 0.1f);
    mShape.setColor(sf::Color::White);
    mShape.setPosition(center.x * 0.5f, center.y * 0.5f);
    mShape.setOrigin(0.5f, 0.5f);

    mSpeed = 0.f;
    mRenderEnabled = true;
}

Ship::~Ship()
{
}

void Ship::OnUpdate(float deltaTime)
{
    const sfe::Vector2f offset = GetMovement();
    if (offset == sfe::Vector2f::Zero())
    {
        mSpeed -= BreakSpeed;
        if (mSpeed <= 0.f)
        {
            mSpeed = 0.f;
            return;
        }
    }
    else
    {
        mSpeed = std::min(MaxSpeed, mSpeed + AccumSpeed);
        mPrevMovement = offset;
    }

    mShape.move(mPrevMovement * deltaTime * mSpeed);
}

void Ship::OnRender(sf::RenderTarget& data)
{
    data.draw(mShape);
}

void Ship::OnCollisionEnter(const sfe::Collider& other)
{
}

void Ship::OnCollisionExit(const sfe::Collider& other)
{
}

