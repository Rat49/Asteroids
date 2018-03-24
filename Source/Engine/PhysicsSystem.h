#pragma once
#include <Exports.h>
#include <UpdateMethod.h>
#include <Broadcaster.h>
#include <PhysicsMethod.h>

namespace sfe
{
	class ENGINE_EXPORT PhysicsSystem final : public Broadcaster<PhysicsMethod, const Collider&>, public UpdateMethod
	{
	public:
		PhysicsSystem();
		~PhysicsSystem() override;

		void OnUpdate(float deltaTime) override;
		void NotifyAll(const Collider& other) override;
	};
}
