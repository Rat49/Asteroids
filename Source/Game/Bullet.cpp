#include <Game/Bullet.h>

Bullet::Bullet(sfe::Vector2f pos, sfe::Vector2f dir)
    : mCollider(mShape)
{
    mShape.setRadius(5);
    mShape.setFillColor(sf::Color::Yellow);
    mShape.setPosition(pos);
    mShape.setOrigin(0.5f, 0.5f);
    mDirection = dir;
}

Bullet::~Bullet()
{
}

void Bullet::OnUpdate(float deltaTime)
{
    mShape.move(mDirection * 100 * deltaTime);
    auto len = (static_cast<sfe::Vector2f>(mShape.getPosition()) - mPosition).SqrLength();
    if (len > 4000)
    {
        mShape.setFillColor(sf::Color::Transparent);
    }
}

void Bullet::OnRender(sf::RenderTarget& data)
{
    data.draw(mShape);
}

void Bullet::OnCollisionEnter(const sfe::Collider& other)
{
}

void Bullet::OnCollisionExit(const sfe::Collider& other)
{
}
