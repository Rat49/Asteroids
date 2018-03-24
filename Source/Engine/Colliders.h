#pragma once
#include <Exports.h>
#include <Vector.h>

namespace sf
{
    class LineShape;
    class CircleShape;
    class RectangleShape;
}

namespace sfe
{
	enum class ColliderType
	{
		Invalid,
		Line,
		Circle,
		Rectangle
	};

	class ENGINE_EXPORT Collider
	{
	public:
		Collider() : mType(ColliderType::Invalid) {}
		ColliderType GetType() const { return mType; }

		virtual bool Contains(Vector2f point) const = 0;
		virtual bool Intersects(const Collider* other) const = 0;

		Vector2f GetOrigin() const { return mOrigin; }

	protected:
		ColliderType mType;
		Vector2f mOrigin;
	};

	class LineCollider : public Collider
	{
	public:
		explicit LineCollider(const sf::LineShape* owner);

		bool Contains(Vector2f point) const override;
		bool Intersects(const Collider* other) const override;

		Vector2f GetDirection() const { return mDirection; }

	protected:
		const sf::LineShape* mOwner;
		Vector2f mDirection;
	};

	class RectangleCollider : public Collider
	{
	public:
		explicit RectangleCollider(const sf::RectangleShape* owner);

		bool Contains(Vector2f point) const override;
		bool Intersects(const Collider* other) const override;

		Vector2f GetOppositePoint() const { return mOpposite; }

	protected:
		const sf::RectangleShape* mOwner;
		Vector2f mOpposite;
	};

	class CircleCollider : public Collider
	{
	public:
		explicit CircleCollider(const sf::CircleShape* owner);

		bool Contains(Vector2f point) const override;
		bool Intersects(const Collider* other) const override;

		float GetRadius() const { return mRadius; }

	protected:
		const sf::CircleShape* mOwner;
		float mRadius;
	};
}
