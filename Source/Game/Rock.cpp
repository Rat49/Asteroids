#include <Game/Rock.h>
#include <Engine/Context.h>
#include <SFML/Window/Window.hpp>
#include <cassert>

namespace
{
    sf::FloatRect ScreenSpace;
}

Rock::Rock()
    : UpdateMethod(), PhysicsMethod(), RenderMethod(), mCollider(mShape)
{
    auto loadResult = mTex.loadFromFile("Resources/rock.png");
    assert(loadResult && "Can't load rock texture");

    auto screenSize = sfe::Context::Instance().GetLogic()->GetWindow()->getSize();
    ScreenSpace = sf::FloatRect(sf::Vector2f(), sf::Vector2f(screenSize));

    mShape.setTexture(mTex);
    mShape.setScale(0.5f, 0.5f);
    mShape.setColor(sf::Color::White);
    mShape.setPosition(screenSize.x * 0.1f, screenSize.y * 0.1f);
    mShape.setOrigin(0.5f, 0.5f);

    mDirection = sfe::Vector2f(0.1f * (rand() % 16), 0.1f * (rand() % 16));
    mRenderEnabled = true;
}

Rock::~Rock()
{
}

void Rock::OnUpdate(float deltaTime)
{
    mShape.move(mDirection * deltaTime * 100);
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
