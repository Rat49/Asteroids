#include <Ship.h>
#include <InputGameAction.h>
#include <Context.h>

namespace
{
	float GetActionNum(int32_t action)
	{
		return Context::GetInput()->IsInProgress(action) ? 1.f : 0.f;
	}

	sfe::Vector2<float> GetMovement()
	{
		sfe::Vector2<float> result(
			GetActionNum(GameAction::MoveRight) - GetActionNum(GameAction::MoveLeft),
			GetActionNum(GameAction::MoveDown) - GetActionNum(GameAction::MoveUp));
		return result;
	}

	sfe::Vector2<float> Zero;
	float MaxSpeed = 500;
	float AccumSpeed = 50;
	float BreakSpeed = 10;
}

Ship::Ship()
	: mCollider(&mShape)
{
	if (mTex.loadFromFile("Resources/Ship.png"))
	{
		mShape.setTexture(mTex);
		mShape.setScale(0.1f, 0.1f);
	}

	auto center = Context::GetRender()->GetWindow()->getSize();

	mShape.setColor(sf::Color::White);
	mShape.setPosition(center.x * 0.5f, center.y * 0.5f);
	mShape.setOrigin(0.5f, 0.5f);

	mSpeed = 0.f;
}

Ship::~Ship()
{
}

void Ship::OnUpdate(float deltaTime)
{
	const auto offset = GetMovement();
	if (offset == Zero)
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

