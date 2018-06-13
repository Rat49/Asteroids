#pragma once
#include <Engine/RenderMethod.h>
#include <Engine/PhysicsMethod.h>
#include <Engine/UpdateMethod.h>
#include <Engine/Vector.h>
#include <SFML/Graphics/CircleShape.hpp>

class Bullet : public sfe::UpdateMethod, public sfe::PhysicsMethod, public sfe::RenderMethod
{
public:
    Bullet(sfe::Vector2f pos, sfe::Vector2f dir);
    ~Bullet();

    void OnUpdate(float deltaTime) override;
    void OnRender(sf::RenderTarget& data) override;
    void OnCollisionEnter(const sfe::Collider& other) override;
    void OnCollisionExit(const sfe::Collider& other) override;

private:
    sf::CircleShape mShape;
    sfe::CircleCollider mCollider;
    sfe::Vector2f mDirection;
    sfe::Vector2f mPosition;
};

