#include <Game/Ship.h>
#include <Engine/Context.h>
#include <SFML/Window/Window.hpp>
#include <cassert>

namespace
{
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

void Ship::SetDirection(sfe::Vector2f dir)
{
    mCurrentMovement = dir;
}

sfe::Vector2f Ship::GetPosition() const
{
    auto pos = sfe::Vector2f(mShape.getPosition());
    auto offset = sf::Vector2f(mShape.getLocalBounds().width, mShape.getLocalBounds().height);
    auto o = sfe::Vector2f(offset * 0.5f * mShape.getScale();
    pos += offset;
    return pos;
}

sfe::Vector2f Ship::GetDirection() const
{
    return mPrevMovement;
}

void Ship::OnUpdate(float deltaTime)
{
    if (mCurrentMovement == sfe::Vector2f::Zero())
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
        mPrevMovement = mCurrentMovement;
        mCurrentMovement = sfe::Vector2f::Zero();
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

