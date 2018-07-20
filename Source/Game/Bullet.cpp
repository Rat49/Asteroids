#include <Game/Bullet.h>

Bullet::Bullet()
    : mCollider(mShape)
{
    mShape.setRadius(5);
    mShape.setFillColor(sf::Color::Yellow);
    mShape.setOrigin(0.5f, 0.5f);
    mRenderEnabled = false;
    mUpdateEnabled = false;
}

Bullet::~Bullet()
{
}

void Bullet::Start(sfe::Vector2f pos, sfe::Vector2f dir, float distance)
{
    mShape.setPosition(pos);
    mPosition = pos;
    mDirection = dir;
    mMaxSqrDistance = distance * distance;
    mRenderEnabled = true;
    mUpdateEnabled = true;
}

bool Bullet::IsFlying() const
{
    return mRenderEnabled;
}

void Bullet::OnUpdate(float deltaTime)
{
    if (!mRenderEnabled)
    {
        return;
    }

    mShape.move(mDirection * deltaTime);

    auto len = (static_cast<sfe::Vector2f>(mShape.getPosition()) - mPosition).SqrLength();
    if (len > mMaxSqrDistance)
    {
        mRenderEnabled = false;
        mUpdateEnabled = false;
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
