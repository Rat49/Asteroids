#pragma once
#include <Engine/UpdateMethod.h>
#include <Engine/RenderMethod.h>
#include <Engine/PhysicsMethod.h>
#include <Engine/Vector.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class Ship : public sfe::UpdateMethod, public sfe::PhysicsMethod, public sfe::RenderMethod
{
public:
    Ship();
    ~Ship();

    void SetDirection(sfe::Vector2f dir);
    sfe::Vector2f GetPosition() const;
    sfe::Vector2f GetDirection() const;

    void OnUpdate(float deltaTime) override;
    void OnRender(sf::RenderTarget& data) override;
    void OnCollisionEnter(const sfe::Collider& other) override;
    void OnCollisionExit(const sfe::Collider& other) override;

private:
    sf::Texture mTex;
    sf::Sprite mShape;
    sfe::CircleCollider mCollider;
    sfe::Vector2f mPrevMovement;
    sfe::Vector2f mCurrentMovement;
    float mSpeed;
};

