#include <Engine/PhysicsMethod.h>
#include <Engine/Context.h>

PhysicsMethod::PhysicsMethod()
{
    Context::Instance().GetPhysics()->AddReceiver(this);
}

PhysicsMethod::~PhysicsMethod()
{
    Context::Instance().GetPhysics()->RemoveReceiver(this);
}
