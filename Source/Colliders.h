#pragma once
#include <SFML/System/Vector2.hpp>

namespace sf
{
    class LineShape;
    class CircleShape;
    class RectangleShape;
}

enum class ColliderType
{
    Invalid,
    Line,
    Circle,
    Rectangle
};

class Collider
{
public:
    Collider() : mType(ColliderType::Invalid) {}
    ColliderType GetType() const { return mType; }

    virtual bool Contains(sf::Vector2f point) const = 0;
    virtual bool Intersects(const Collider* other) const = 0;

	sf::Vector2f GetOrigin() const { return mOrigin; }

protected:
    ColliderType mType;
	sf::Vector2f mOrigin;
};

class LineCollider : public Collider
{
public:
    explicit LineCollider(const sf::LineShape* owner);

    bool Contains(sf::Vector2f point) const override;
    bool Intersects(const Collider* other) const override;

	sf::Vector2f GetDirection() const { return mDirection; }

protected:
    const sf::LineShape* mOwner;
    sf::Vector2f mDirection;
};

class RectangleCollider : public Collider
{
public:
    explicit RectangleCollider(const sf::RectangleShape* owner);

    bool Contains(sf::Vector2f point) const override;
    bool Intersects(const Collider* other) const override;

	sf::Vector2f GetOppositePoint() const { return mOpposite; }

protected:
    const sf::RectangleShape* mOwner;
	sf::Vector2f mOpposite;
};

class CircleCollider : public Collider
{
public:
    explicit CircleCollider(const sf::CircleShape* owner);

    bool Contains(sf::Vector2f point) const override;
    bool Intersects(const Collider* other) const override;

	float GetRadius() const { return mRadius; }

protected:
    const sf::CircleShape* mOwner;
	float mRadius;
};
