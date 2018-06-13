#pragma once
#include <Engine/UpdateMethod.h>
#include <Engine/RenderMethod.h>
#include <Engine/PhysicsMethod.h>
#include <Engine/Vector.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Rock : public sfe::UpdateMethod, public sfe::PhysicsMethod, public sfe::RenderMethod
{
public:
    Rock();
    ~Rock();

    void OnUpdate(float deltaTime) override;
    void OnRender(sf::RenderTarget& data) override;
    void OnCollisionEnter(const sfe::Collider& other) override;
    void OnCollisionExit(const sfe::Collider& other) override;

private:
    sf::Texture mTex;
    sf::Sprite mShape;
    sfe::CircleCollider mCollider;
    sfe::Vector2f mDirection;
};

