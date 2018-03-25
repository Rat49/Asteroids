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
}

Ship::~Ship()
{
}

void Ship::OnUpdate(float deltaTime)
{
	const auto offset = GetMovement() * deltaTime;
	if (offset == Zero)
	{
		mExtinction -= 0.01f;
		if (mExtinction <= 0)
		{
			mExtinction = 0;
			return;
		}
	}
	else
	{
		mPrevMovement = offset;
		mExtinction = 1;
	}

	mShape.move(mPrevMovement * deltaTime * 10000 * mExtinction);
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

