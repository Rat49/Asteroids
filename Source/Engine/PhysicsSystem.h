#pragma once
#include <Engine/Exports.h>
#include <Engine/UpdateMethod.h>
#include <Engine/Broadcaster.h>
#include <Engine/PhysicsMethod.h>

class ENGINE_EXPORT PhysicsSystem final : public Broadcaster<PhysicsMethod, const Collider&>, public UpdateMethod
{
public:
    PhysicsSystem();
    ~PhysicsSystem() override;

    void OnUpdate(float deltaTime) override;
    void NotifyAll(const Collider& other) override;
};


