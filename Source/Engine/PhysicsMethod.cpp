#include <PhysicsMethod.h>
#include <Context.h>

PhysicsMethod::PhysicsMethod()
{
    Context::Instance().GetPhysics()->AddReceiver(this);
}

PhysicsMethod::~PhysicsMethod()
{
    Context::Instance().GetPhysics()->RemoveReceiver(this);
}
