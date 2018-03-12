#include "Colliders.h"
#include "VectorMath.h"
#include <cassert>
#include <SFML/Graphics.hpp>

namespace
{
    bool __Intersects(const LineCollider* a, const LineCollider* b)
    {
		const auto dir1 = a->GetDirection();
		const auto dir2 = a->GetDirection();
		return (dir1.y / dir1.x) != (dir2.y / dir2.x);
    }

    bool __Intersects(const CircleCollider* a, const CircleCollider* b)
    {
		const auto distance = VectorMath::SqrLength(a->GetOrigin() - b->GetOrigin());
		const auto radiuses = std::powf(a->GetRadius() + b->GetRadius(), 2);
		return distance <= radiuses;
    }

    bool __Intersects(const RectangleCollider* a, const RectangleCollider* b)
    {

        return false;
    }

    bool __Intersects(const LineCollider* a, const CircleCollider* b)
    {
        return false;
    }

    bool __Intersects(const CircleCollider* a, const RectangleCollider* b)
    {
        return false;
    }

    bool __Intersects(const RectangleCollider* a, const LineCollider* b)
    {
        return false;
    }
}

#pragma region -Line-collider-

LineCollider::LineCollider(const sf::LineShape* owner) : mOwner(owner)
{
    mType = ColliderType::Line;
}

bool LineCollider::Contains(sf::Vector2f point) const
{
	return ((point.x - mOrigin.x) / mDirection.x) == ((point.y - mOrigin.y) / mDirection.y);
}

bool LineCollider::Intersects(const Collider* other) const
{
	assert(other != nullptr);
	switch (other->GetType())
	{
	case ColliderType::Circle:
		return __Intersects(this, static_cast<const CircleCollider*>(other));
	case ColliderType::Line:
		return __Intersects(this, static_cast<const LineCollider*>(other));
	case ColliderType::Rectangle:
		return __Intersects(static_cast<const RectangleCollider*>(other), this);
	default:
		return false;
	}
}

#pragma endregion
#pragma region -Rectangle-collider-

RectangleCollider::RectangleCollider(const sf::RectangleShape* owner) : mOwner(owner)
{
    mType = ColliderType::Rectangle;
}

bool RectangleCollider::Contains(sf::Vector2f point) const
{
	if (std::fmin(mOrigin.x, mOpposite.x) > point.x) return false;
	if (std::fmin(mOrigin.y, mOpposite.y) > point.y) return false;
	if (std::fmax(mOrigin.x, mOpposite.x) < point.x) return false;
	if (std::fmax(mOrigin.y, mOpposite.y) < point.y) return false;
	return true;
}

bool RectangleCollider::Intersects(const Collider* other) const
{
	assert(other != nullptr);
	switch (other->GetType())
	{
	case ColliderType::Circle:
		return __Intersects(static_cast<const CircleCollider*>(other), static_cast<const RectangleCollider*>(other));
	case ColliderType::Line:
		return __Intersects(this, static_cast<const LineCollider*>(other));
	case ColliderType::Rectangle:
		return __Intersects(this, static_cast<const RectangleCollider*>(other));
	default:
		return false;
	}
}

#pragma endregion
#pragma region -Circle-collider-

CircleCollider::CircleCollider(const sf::CircleShape* owner) : mOwner(owner)
{
    mType = ColliderType::Circle;
}

bool CircleCollider::Contains(sf::Vector2f point) const
{
	return VectorMath::SqrLength(mOrigin - point) <= (mRadius * mRadius);
}

bool CircleCollider::Intersects(const Collider* other) const
{
	assert(other != nullptr);
	switch (other->GetType())
	{
	case ColliderType::Circle:
		return __Intersects(this, static_cast<const CircleCollider*>(other));
	case ColliderType::Line:
		return __Intersects(static_cast<const LineCollider*>(other), this);
	case ColliderType::Rectangle:
		return __Intersects(this, static_cast<const RectangleCollider*>(other));
	default:
		return false;
	}
}

#pragma endregion
