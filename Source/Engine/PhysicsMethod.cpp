#include <PhysicsMethod.h>
#include <Context.h>

using namespace sfe;

PhysicsMethod::PhysicsMethod()
{
    Context::GetPhysics()->AddReceiver(this);
}

PhysicsMethod::~PhysicsMethod()
{
    Context::GetPhysics()->RemoveReceiver(this);
}
