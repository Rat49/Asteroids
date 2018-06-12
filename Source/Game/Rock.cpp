#include <Rock.h>
#include <Context.h>

namespace
{
	sf::FloatRect ScreenSpace;
}

Rock::Rock()
	: mCollider(&mShape) 
{
	if (mTex.loadFromFile("Resources/Rock.png"))
	{
		mShape.setTexture(mTex);
		mShape.setScale(0.5f, 0.5f);
	}

	auto screenSize = Context::GetRender()->GetWindow()->getSize();
	ScreenSpace = sf::FloatRect(sf::Vector2f(), sf::Vector2f(screenSize));

	mShape.setColor(sf::Color::White);
	mShape.setPosition(screenSize.x * 0.1f, screenSize.y * 0.1f);
	mShape.setOrigin(0.5f, 0.5f);

	mDirection = sfe::Vector2f(0.1f, 0.5f);
}

Rock::~Rock()
{
}

void Rock::OnUpdate(float deltaTime)
{
	mShape.move(mDirection * deltaTime * 1000);
	if (ScreenSpace.intersects(mShape.getGlobalBounds()))
	{
		return;
	}

	auto pos = mShape.getPosition();
	sf::Vector2f newPos(ScreenSpace.width - pos.x, ScreenSpace.height - pos.y);
	mShape.setPosition(newPos);
}

void Rock::OnRender(sf::RenderTarget& data)
{
	data.draw(mShape);
}

void Rock::OnCollisionEnter(const sfe::Collider& other)
{
}

void Rock::OnCollisionExit(const sfe::Collider& other)
{
}
