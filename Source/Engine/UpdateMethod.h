#pragma once
#include <Exports.h>

namespace sfe
{
	class ENGINE_EXPORT UpdateMethod
	{
	public:
		UpdateMethod();
		virtual ~UpdateMethod();

		virtual void OnUpdate(float deltaTime) = 0;

		bool IsUpdateEnabled() const { return mUpdateEnabled; }

	protected:
		bool mUpdateEnabled = true;
	};
}
