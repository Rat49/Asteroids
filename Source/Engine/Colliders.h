#pragma once
#include <Engine/Exports.h>
#include <Engine/Vector.h>
#include <SFML/System/Vector2.hpp>
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
        explicit Collider(const sf::Transformable& owner) : mOwner(owner), mType(ColliderType::Invalid) {}

        virtual bool Contains(sfe::Vector2f point) const = 0;
        virtual bool Intersects(const Collider* other) const = 0;

        sfe::Vector2f GetOrigin() const { return mOrigin; }
        ColliderType GetType() const { return mType; }
        const sf::Transformable& GetOwner() const { return mOwner; }

    protected:
        const sf::Transformable& mOwner;
        ColliderType mType;
        sfe::Vector2f mOrigin;
    };

    class ENGINE_EXPORT LineCollider : public Collider
    {
    public:
        explicit LineCollider(const sf::Transformable& owner);

        bool Contains(sfe::Vector2f point) const override;
        bool Intersects(const Collider* other) const override;

        sfe::Vector2f GetDirection() const { return mDirection; }

    protected:
        sfe::Vector2f mDirection;
    };

    class ENGINE_EXPORT RectangleCollider : public Collider
    {
    public:
        explicit RectangleCollider(const sf::Transformable& owner);

        bool Contains(sfe::Vector2f point) const override;
        bool Intersects(const Collider* other) const override;

        sfe::Vector2f GetOppositePoint() const { return mOpposite; }

    protected:
        sfe::Vector2f mOpposite;
    };

    class ENGINE_EXPORT CircleCollider : public Collider
    {
    public:
        explicit CircleCollider(const sf::Transformable& owner);

        bool Contains(sfe::Vector2f point) const override;
        bool Intersects(const Collider* other) const override;

        float GetRadius() const { return mRadius; }

    protected:
        float mRadius;
    };
}
