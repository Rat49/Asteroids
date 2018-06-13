#pragma once
#include <Engine/RenderMethod.h>
#include <Engine/UpdateMethod.h>
#include <SFML/Graphics/CircleShape.hpp>

class SpaceShip : public sfe::RenderMethod, public sfe::UpdateMethod
{
public:
    SpaceShip();
    ~SpaceShip();

    void OnRender(sf::RenderTarget& data) override;
    void OnUpdate(float deltaTime) override;

private:
    void ProcessInput(float deltaTime);

private:
    sf::CircleShape mShape;
};
