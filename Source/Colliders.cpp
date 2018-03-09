#include "Colliders.h"
#include "VectorMath.h"
#include <SFML/Graphics.hpp>

namespace
{
    bool __Intersects(const LineCollider* a, const LineCollider* b)
    {
        return false;
    }

    bool __Intersects(const CircleCollider* a, const CircleCollider* b)
    {
        return false;
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

    bool _Intersects(const Collider* a, const Collider* b)
    {
        switch (a->GetType())
        {
        case ColliderType::Circle:
            switch (b->GetType())
            {
            case ColliderType::Circle:
                return __Intersects(static_cast<const CircleCollider*>(a), static_cast<const CircleCollider*>(b));
            case ColliderType::Line:
                return __Intersects(static_cast<const LineCollider*>(b), static_cast<const CircleCollider*>(a));
            case ColliderType::Rectangle:
                return __Intersects(static_cast<const CircleCollider*>(a), static_cast<const RectangleCollider*>(b));
            default:
                break;
            }
        case ColliderType::Line:
            switch (b->GetType())
            {
            case ColliderType::Circle:
                return __Intersects(static_cast<const LineCollider*>(a), static_cast<const CircleCollider*>(b));
            case ColliderType::Line:
                return __Intersects(static_cast<const LineCollider*>(a), static_cast<const LineCollider*>(b));
            case ColliderType::Rectangle:
                return __Intersects(static_cast<const RectangleCollider*>(b), static_cast<const LineCollider*>(a));
            default:
                break;
            }
        case ColliderType::Rectangle:
            switch (b->GetType())
            {
            case ColliderType::Circle:
                return __Intersects(static_cast<const CircleCollider*>(b), static_cast<const RectangleCollider*>(a));
            case ColliderType::Line:
                return __Intersects(static_cast<const RectangleCollider*>(a), static_cast<const LineCollider*>(b));
            case ColliderType::Rectangle:
                return __Intersects(static_cast<const RectangleCollider*>(a), static_cast<const RectangleCollider*>(b));
            default:
                break;
            }
        }
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
    return _Intersects(this, other);
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
    return _Intersects(this, other);
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
    return _Intersects(this, other);
}

#pragma endregion
