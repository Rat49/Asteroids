#pragma once
#include "UpdateMethod.h"
#include <SFML\Graphics.hpp>

class PhysicsMethod
{

};

class PhysicsSystem : public UpdateMethod
{
public:
    void OnUpdate(float deltaTime) override;
};

namespace sf
{
    class LineShape : public Shape
    {
    };
}


