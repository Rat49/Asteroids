#pragma once
#include <Exports.h>
#include <Vector.h>
#include <SFML/Graphics/Transformable.hpp>

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
		Collider(const sf::Transformable* owner);

		ColliderType GetType() const;
		Vector2f GetOrigin() const;

		virtual bool Contains(Vector2f point) const = 0;
		virtual bool Intersects(const Collider* other) const = 0;

	protected:
		const sf::Transformable* mOwner;
		ColliderType mType;
	};

	class ENGINE_EXPORT LineCollider : public Collider
	{
	public:
		LineCollider(const sf::Transformable* owner);

		bool Contains(Vector2f point) const override;
		bool Intersects(const Collider* other) const override;

		Vector2f GetDirection() const;

	protected:
		Vector2f mDirection;
	};

	class ENGINE_EXPORT RectangleCollider : public Collider
	{
	public:
		RectangleCollider(const sf::Transformable* owner);

		bool Contains(Vector2f point) const override;
		bool Intersects(const Collider* other) const override;

		Vector2f GetOppositePoint() const;

	protected:
		Vector2f mOpposite;
	};

	class ENGINE_EXPORT CircleCollider : public Collider
	{
	public:
		CircleCollider(const sf::Transformable* owner);

		bool Contains(Vector2f point) const override;
		bool Intersects(const Collider* other) const override;

		float GetRadius() const;

	protected:
		float mRadius;
	};
}
