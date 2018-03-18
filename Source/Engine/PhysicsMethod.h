#pragma once
#include <Exports.h>
#include <Colliders.h>

class ENGINE_EXPORT PhysicsMethod
{
public:
    PhysicsMethod();
    virtual ~PhysicsMethod();

    virtual void OnCollisionEnter(const Collider& other) = 0;
    virtual void OnCollisionExit(const Collider& other) = 0;

    bool IsPhysicsEnabled() const { return mPhysicsEnabled; }

protected:
    bool mPhysicsEnabled = false;
};