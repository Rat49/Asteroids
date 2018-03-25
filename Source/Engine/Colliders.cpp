#include <Colliders.h>
#include <cassert>

using namespace sfe;

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
		const auto distance = (a->GetOrigin() - b->GetOrigin()).SqrLength();
		const auto radiuses = std::powf(a->GetRadius() + b->GetRadius(), 2);
		return distance <= radiuses;
    }

    bool __Intersects(const RectangleCollider* a, const RectangleCollider* b)
    {
		const auto a1 = a->GetOrigin();
		const auto a2 = a->GetOppositePoint();
		const auto b1 = b->GetOrigin();
		const auto b2 = b->GetOppositePoint();

		const auto aMinX = std::min(a1.x, a2.x);
		const auto bMinX = std::min(b1.x, b2.x);
		const auto aMaxX = std::max(a1.x, a2.x);
		const auto bMaxX = std::max(b1.x, b2.x);
		if (aMinX > bMaxX || aMaxX < bMinX)
		{
			return false;
		}

		const auto aMinY = std::min(a1.y, a2.y);
		const auto bMinY = std::min(b1.y, b2.y);
		const auto aMaxY = std::max(a1.y, a2.y);
		const auto bMaxY = std::max(b1.y, b2.y);
		if (aMinY > bMaxY || aMaxY < bMinY)
		{
			return false;
		}

		//TODO: check case if one small rect is hidden in shadow of bigger rect
        return true;
    }

    bool __Intersects(const LineCollider* a, const CircleCollider* b)
    {
		const auto distance = a->GetOrigin() - b->GetOrigin();
		const auto ap = a->GetDirection() * a->GetDirection();
		const auto bp = distance * a->GetDirection();
		const auto cp = distance * distance - std::pow(b->GetRadius(), 2);

		const auto disc = bp * bp - ap * cp;
		return disc >= 0.0f;
    }

    bool __Intersects(const CircleCollider* a, const RectangleCollider* b)
    {
		const auto b1 = b->GetOrigin();
		const auto b3 = b->GetOppositePoint();
		const auto b2 = sfe::Vector2f(b1.x, b3.y);
		const auto b4 = sfe::Vector2f(b3.x, b1.y);
		const auto a1 = a->GetOrigin();
		const auto dist = std::pow(a->GetRadius(), 2);
		return (a1 - b1).SqrLength() <= dist
			|| (a1 - b2).SqrLength() <= dist
			|| (a1 - b3).SqrLength() <= dist
			|| (a1 - b4).SqrLength() <= dist;
    }

    bool __Intersects(const RectangleCollider* a, const LineCollider* b)
    {
		//TBD
        return false;
    }
}

Collider::Collider(const sf::Transformable* owner)
	: mOwner(owner)
	, mType(ColliderType::Invalid)
{
}

ColliderType Collider::GetType() const
{
	return mType;
}

Vector2f Collider::GetOrigin() const
{
	return Vector2f(mOwner->getPosition());
}

#pragma region -Line-collider-

LineCollider::LineCollider(const sf::Transformable* owner)
	: Collider(owner)
{
    mType = ColliderType::Line;
}

Vector2f LineCollider::GetDirection() const
{
	return mDirection;
}

bool LineCollider::Contains(Vector2f point) const
{
	return ((point.x - GetOrigin().x) / GetDirection().x) == ((point.y - GetOrigin().y) / GetDirection().y);
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

RectangleCollider::RectangleCollider(const sf::Transformable* owner)
	: Collider(owner)
{
	mType = ColliderType::Rectangle;
}

Vector2f RectangleCollider::GetOppositePoint() const
{
	return mOpposite;
}

bool RectangleCollider::Contains(Vector2f point) const
{
	if (std::fmin(GetOrigin().x, GetOppositePoint().x) > point.x) return false;
	if (std::fmin(GetOrigin().y, GetOppositePoint().y) > point.y) return false;
	if (std::fmax(GetOrigin().x, GetOppositePoint().x) < point.x) return false;
	if (std::fmax(GetOrigin().y, GetOppositePoint().y) < point.y) return false;
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

CircleCollider::CircleCollider(const sf::Transformable* owner)
	: Collider(owner)
{
	mType = ColliderType::Circle;
}

float CircleCollider::GetRadius() const
{
	return mRadius;
}

bool CircleCollider::Contains(Vector2f point) const
{
	return (GetOrigin() - point).SqrLength() <= (GetRadius() * GetRadius());
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
