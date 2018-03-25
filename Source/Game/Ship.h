#pragma once
#include <UpdateMethod.h>
#include <RenderMethod.h>
#include <PhysicsMethod.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class Ship : public sfe::UpdateMethod, public sfe::PhysicsMethod, public sfe::RenderMethod
{
public:
	Ship();
	~Ship();

	void OnUpdate(float deltaTime) override;
	void OnRender(sf::RenderTarget& data) override;
	void OnCollisionEnter(const sfe::Collider& other) override;
	void OnCollisionExit(const sfe::Collider& other) override;

private:
	sf::Texture mTex;
	sf::Sprite mShape;
	sfe::CircleCollider mCollider;
	sfe::Vector2<float> mPrevMovement;
	float mExtinction;
};

